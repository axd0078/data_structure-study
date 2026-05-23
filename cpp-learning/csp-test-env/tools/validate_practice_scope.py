from __future__ import annotations

import argparse
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from csp_test_env.catalog import FIXED_SUBMISSION_ROOT, problem_meta_by_key, reference_solution_path  # noqa: E402
from csp_test_env.compare import outputs_match  # noqa: E402
from csp_test_env.judge import _creation_flags, _decode_output, compile_cpp  # noqa: E402
from csp_test_env.problem_bank import get_problem  # noqa: E402
from csp_test_env.sample_guard import assert_not_official_samples  # noqa: E402
from csp_test_env.selection import add_key_selection_args, resolve_selected_keys  # noqa: E402
from csp_test_env.test_data import load_saved_cases  # noqa: E402


def _practice_keys() -> list[tuple[int, int, str]]:
    meta_by_pair = {
        (meta.contest_id, meta.position): meta.key
        for meta in problem_meta_by_key().values()
    }
    found: list[tuple[int, int, str]] = []
    for source in sorted(FIXED_SUBMISSION_ROOT.glob("*/*.cpp")):
        try:
            contest_id = int(source.parent.name)
            position = int(source.stem)
        except ValueError:
            continue
        key = meta_by_pair.get((contest_id, position))
        if key is not None:
            found.append((contest_id, position, key))
    return found


def main() -> int:
    parser = argparse.ArgumentParser(description="Validate practice sources have registered problems and test data.")
    add_key_selection_args(parser)
    args = parser.parse_args()

    failures: list[str] = []
    meta_by_key = problem_meta_by_key()
    try:
        selected_keys = set(resolve_selected_keys(args, meta_by_key, sorted(meta_by_key)))
    except ValueError as exc:
        print(f"PRACTICE SCOPE VALIDATION FAILED\n{exc}")
        return 1

    found = _practice_keys()
    found = [item for item in found if item[2] in selected_keys]
    if not found:
        failures.append(f"no .cpp files found under {FIXED_SUBMISSION_ROOT}")

    for contest_id, position, key in found:
        problem = get_problem(key)
        if problem is None:
            failures.append(f"{contest_id}/{position}.cpp -> {key}: missing problem registration")
            continue
        reference = reference_solution_path(contest_id, position)
        if not reference.exists():
            failures.append(f"{key}: missing reference source {reference}")
            continue

        try:
            saved_cases = load_saved_cases(key)
            if len(saved_cases) != 10:
                raise ValueError(f"expected 10 saved cases, got {len(saved_cases)}")
            empty_outputs = [case.index for case in saved_cases if case.expected_output == ""]
            if empty_outputs:
                raise ValueError(f"empty .out files at cases: {empty_outputs}")
            assert_not_official_samples(key, [case.input_text for case in saved_cases])
        except Exception as exc:  # noqa: BLE001
            failures.append(f"{key}: bad saved test data: {exc}")
            continue

        with tempfile.TemporaryDirectory(prefix="csp-ref-") as tmp:
            exe, compile_error = compile_cpp(reference, Path(tmp))
            if compile_error is not None or exe is None:
                failures.append(f"{key}: reference compile failed: {compile_error}")
                continue
            for case in saved_cases:
                completed = subprocess.run(
                    [str(exe)],
                    input=case.input_text.encode("utf-8"),
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    timeout=5,
                    creationflags=_creation_flags(),
                )
                if completed.returncode != 0:
                    failures.append(f"{key} case {case.index}: reference runtime error")
                    break
                actual = _decode_output(completed.stdout)
                if not outputs_match(actual, case.expected_output):
                    failures.append(f"{key} case {case.index}: reference output mismatch")
                    break

    if failures:
        print("PRACTICE SCOPE VALIDATION FAILED")
        print("\n".join(failures))
        return 1

    print(f"PRACTICE SCOPE VALIDATION PASSED: {len(found)} source files covered")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
