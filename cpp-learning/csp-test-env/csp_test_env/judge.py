from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
import os
import shutil
import subprocess
import tempfile

from .compare import outputs_match
from .problem_bank import get_problem
from .problems import ProblemDefinition
from .sample_guard import assert_not_official_samples
from .test_data import SavedCase, load_saved_cases


CORRECT = "答案正确"
WRONG = "答案错误"
TIMEOUT = "运行超时"
RUNTIME_ERROR = "运行时错误"


@dataclass(frozen=True)
class CaseResult:
    index: int
    score: int
    status: str


@dataclass(frozen=True)
class JudgeReport:
    total_score: int
    case_results: tuple[CaseResult, ...]
    compile_error: str | None = None
    setup_error: str | None = None

    def to_display_text(self) -> str:
        lines = [f"总分：{self.total_score}"]
        if self.compile_error:
            lines.append(f"编译错误：{self.compile_error}")
            return "\n".join(lines)
        if self.setup_error:
            lines.append(f"测试环境错误：{self.setup_error}")
            return "\n".join(lines)
        for result in self.case_results:
            lines.append(f"测试点{result.index} {result.score}/10 {result.status}")
        return "\n".join(lines)


def _decode_output(data: bytes) -> str:
    for encoding in ("utf-8", "gbk"):
        try:
            return data.decode(encoding)
        except UnicodeDecodeError:
            continue
    return data.decode("utf-8", errors="replace")


def _short_error(stdout: bytes, stderr: bytes, limit: int = 4000) -> str:
    text = (_decode_output(stderr) + "\n" + _decode_output(stdout)).strip()
    if len(text) > limit:
        return text[:limit].rstrip() + "\n..."
    return text or "无错误输出"


def _creation_flags() -> int:
    return getattr(subprocess, "CREATE_NO_WINDOW", 0) if os.name == "nt" else 0


def compile_cpp(source_path: Path, build_dir: Path) -> tuple[Path | None, str | None]:
    compiler = shutil.which("g++")
    if compiler is None:
        return None, "未找到 g++，请确认 MinGW 的 bin 目录已加入 PATH"
    exe_path = build_dir / ("submission.exe" if os.name == "nt" else "submission")
    command = [
        compiler,
        "-std=c++17",
        "-O2",
        "-pipe",
        str(source_path),
        "-o",
        str(exe_path),
    ]
    try:
        completed = subprocess.run(
            command,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            creationflags=_creation_flags(),
            timeout=30,
        )
    except subprocess.TimeoutExpired:
        return None, "编译超时（超过 30 秒）"
    if completed.returncode != 0:
        return None, _short_error(completed.stdout, completed.stderr)
    return exe_path, None


def _run_executable(exe_path: Path, input_text: str, timeout_seconds: float) -> tuple[str, int | None, bool]:
    try:
        completed = subprocess.run(
            [str(exe_path)],
            input=input_text.encode("utf-8"),
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            creationflags=_creation_flags(),
            timeout=timeout_seconds,
        )
        return _decode_output(completed.stdout), completed.returncode, False
    except subprocess.TimeoutExpired as exc:
        stdout = exc.stdout if isinstance(exc.stdout, bytes) else b""
        return _decode_output(stdout), None, True


def _warm_up_executable(exe_path: Path, timeout_seconds: float) -> None:
    try:
        subprocess.run(
            [str(exe_path)],
            input=b"",
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            creationflags=_creation_flags(),
            timeout=timeout_seconds,
        )
    except subprocess.TimeoutExpired:
        pass


def _expected_outputs(problem: ProblemDefinition, cases: list[str]) -> list[str]:
    if problem.solve is not None:
        return [problem.solve(case) for case in cases]
    if problem.reference_source is None:
        raise ValueError(f"{problem.key} 未配置标准答案来源")
    reference_source = problem.reference_source.expanduser().resolve()
    if not reference_source.exists():
        raise ValueError(f"参考程序不存在：{reference_source}")
    with tempfile.TemporaryDirectory(prefix="csp-ref-") as tmp:
        exe_path, compile_error = compile_cpp(reference_source, Path(tmp))
        if compile_error is not None or exe_path is None:
            raise ValueError(f"参考程序编译失败：{compile_error}")
        outputs: list[str] = []
        for index, case in enumerate(cases, start=1):
            actual, return_code, timed_out = _run_executable(exe_path, case, 10.0)
            if timed_out:
                raise ValueError(f"参考程序在测试点{index}运行超时")
            if return_code != 0:
                raise ValueError(f"参考程序在测试点{index}运行时错误")
            outputs.append(actual)
        return outputs


def _validate_source(source_path: Path) -> str | None:
    if not source_path.exists():
        return f"源码文件不存在：{source_path}"
    if source_path.suffix.lower() not in {".cpp", ".cc", ".cxx"}:
        return "仅支持 C++ 源码文件（.cpp/.cc/.cxx）"
    return None


def judge_saved_cases(
    cases: list[SavedCase],
    source_path: Path,
    timeout_seconds: float = 2.0,
) -> JudgeReport:
    source_path = source_path.expanduser().resolve()
    source_error = _validate_source(source_path)
    if source_error is not None:
        return JudgeReport(0, tuple(), setup_error=source_error)
    if len(cases) != 10:
        return JudgeReport(0, tuple(), setup_error=f"测试数据必须是 10 个测试点，当前为 {len(cases)} 个")

    with tempfile.TemporaryDirectory(prefix="csp-test-") as tmp:
        exe_path, compile_error = compile_cpp(source_path, Path(tmp))
        if compile_error is not None:
            return JudgeReport(0, tuple(), compile_error=compile_error)

        _warm_up_executable(exe_path, timeout_seconds)

        results: list[CaseResult] = []
        for case in cases:
            actual, return_code, timed_out = _run_executable(exe_path, case.input_text, timeout_seconds)
            if timed_out:
                results.append(CaseResult(case.index, 0, TIMEOUT))
            elif return_code != 0:
                results.append(CaseResult(case.index, 0, RUNTIME_ERROR))
            elif outputs_match(actual, case.expected_output):
                results.append(CaseResult(case.index, 10, CORRECT))
            else:
                results.append(CaseResult(case.index, 0, WRONG))

    return JudgeReport(sum(result.score for result in results), tuple(results))


def judge_problem(
    problem: ProblemDefinition,
    source_path: Path,
    timeout_seconds: float = 2.0,
    validate_samples: bool = True,
) -> JudgeReport:
    try:
        cases = problem.generate_cases()
        if len(cases) != 10:
            raise ValueError(f"{problem.key} 必须生成 10 个测试点，当前为 {len(cases)} 个")
        if validate_samples:
            assert_not_official_samples(problem.key, cases)
        expected_outputs = _expected_outputs(problem, cases)
        saved_cases = [
            SavedCase(index=index, input_text=case, expected_output=expected)
            for index, (case, expected) in enumerate(zip(cases, expected_outputs), start=1)
        ]
    except Exception as exc:  # noqa: BLE001 - surface problem module failures in tests/tools.
        return JudgeReport(0, tuple(), setup_error=str(exc))
    return judge_saved_cases(saved_cases, source_path, timeout_seconds)


def judge_submission(problem_key: str, source_path: Path, timeout_seconds: float = 2.0) -> JudgeReport:
    if get_problem(problem_key) is None:
        return JudgeReport(
            0,
            tuple(),
            setup_error=f"{problem_key} 暂未配置题目测试数据和参考程序",
        )
    try:
        cases = load_saved_cases(problem_key)
    except Exception as exc:  # noqa: BLE001 - show data setup errors in GUI.
        return JudgeReport(0, tuple(), setup_error=str(exc))
    return judge_saved_cases(cases, source_path, timeout_seconds)
