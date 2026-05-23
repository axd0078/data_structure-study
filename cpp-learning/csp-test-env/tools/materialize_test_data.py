from __future__ import annotations

import argparse
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from csp_test_env.catalog import problem_meta_by_key, reference_solution_path, test_data_dir  # noqa: E402
from csp_test_env.judge import _creation_flags, _decode_output, compile_cpp  # noqa: E402
from csp_test_env.problem_bank import REGISTRY  # noqa: E402
from csp_test_env.sample_guard import assert_not_official_samples  # noqa: E402
from csp_test_env.selection import add_key_selection_args, resolve_selected_keys  # noqa: E402


def _run_reference(exe: Path, input_text: str, timeout_seconds: float = 2.0) -> str:
    completed = subprocess.run(
        [str(exe)],
        input=input_text.encode("utf-8"),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        timeout=timeout_seconds,
        creationflags=_creation_flags(),
    )
    if completed.returncode != 0:
        stderr = _decode_output(completed.stderr).strip()
        raise RuntimeError(f"reference runtime error: {stderr or completed.returncode}")
    return _decode_output(completed.stdout)


def main() -> int:
    parser = argparse.ArgumentParser(description="Generate saved CSP test data.")
    add_key_selection_args(parser)
    args = parser.parse_args()

    meta_by_key = problem_meta_by_key()
    try:
        selected_keys = resolve_selected_keys(args, meta_by_key, sorted(REGISTRY))
    except ValueError as exc:
        print(f"MATERIALIZE FAILED\n{exc}")
        return 1

    written = 0
    failures: list[str] = []

    for key in selected_keys:
        problem = REGISTRY[key]
        meta = meta_by_key.get(key)
        if meta is None:
            failures.append(f"{key}: not found in manifest")
            continue

        reference = reference_solution_path(meta.contest_id, meta.position)
        if not reference.exists():
            failures.append(f"{key}: missing reference source: {reference}")
            continue

        try:
            cases = problem.generate_cases()
            if len(cases) != 10:
                raise ValueError(f"expected 10 cases, got {len(cases)}")
            largest_index = max(range(10), key=lambda index: len(cases[index]))
            cases[9], cases[largest_index] = cases[largest_index], cases[9]
            assert_not_official_samples(key, cases)

            with tempfile.TemporaryDirectory(prefix="csp-ref-") as tmp:
                exe, compile_error = compile_cpp(reference, Path(tmp))
                if compile_error is not None or exe is None:
                    raise RuntimeError(f"reference compile failed: {compile_error}")

                directory = test_data_dir(meta.contest_id, meta.position)
                directory.mkdir(parents=True, exist_ok=True)
                for index, case in enumerate(cases, start=1):
                    output = _run_reference(exe, case, timeout_seconds=10.0)
                    if output.strip() == "":
                        raise ValueError(f"case {index} produced an empty .out file")
                    (directory / f"{index:02d}.in").write_text(case, encoding="utf-8", newline="")
                    (directory / f"{index:02d}.out").write_text(output, encoding="utf-8", newline="")
            written += 1
        except Exception as exc:  # noqa: BLE001 - report every data generation failure.
            failures.append(f"{key}: {exc}")

    if failures:
        print("MATERIALIZE FAILED")
        print("\n".join(failures))
        return 1

    print(f"MATERIALIZE PASSED: wrote test data for {written} problems")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
