from __future__ import annotations

import argparse
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from csp_test_env.catalog import problem_meta_by_key, reference_solution_path  # noqa: E402
from csp_test_env.compare import outputs_match  # noqa: E402
from csp_test_env.judge import _creation_flags, _decode_output, compile_cpp  # noqa: E402
from csp_test_env.problem_bank import REGISTRY  # noqa: E402
from csp_test_env.selection import add_key_selection_args, resolve_selected_keys  # noqa: E402
from csp_test_env.test_data import load_saved_cases  # noqa: E402


def main() -> int:
    parser = argparse.ArgumentParser(description="Validate reference solutions against saved test data.")
    add_key_selection_args(parser)
    args = parser.parse_args()

    failures: list[str] = []
    meta_by_key = problem_meta_by_key()
    try:
        selected_keys = resolve_selected_keys(args, meta_by_key, sorted(REGISTRY))
    except ValueError as exc:
        print(f"REFERENCE VALIDATION FAILED\n{exc}")
        return 1

    for key in selected_keys:
        meta = meta_by_key.get(key)
        if meta is None:
            failures.append(f"{key}: not found in manifest")
            continue
        reference = reference_solution_path(meta.contest_id, meta.position)
        if not reference.exists():
            failures.append(f"{key}: missing reference source {reference}")
            continue
        try:
            cases = load_saved_cases(key)
            empty_outputs = [case.index for case in cases if case.expected_output == ""]
            if empty_outputs:
                raise ValueError(f"empty .out files at cases: {empty_outputs}")
        except Exception as exc:  # noqa: BLE001
            failures.append(f"{key}: saved test data error: {exc}")
            continue

        with tempfile.TemporaryDirectory(prefix="csp-ref-") as tmp:
            exe, compile_error = compile_cpp(reference, Path(tmp))
            if compile_error is not None or exe is None:
                failures.append(f"{key}: reference compile failed: {compile_error}")
                continue
            for case in cases:
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
        print("REFERENCE VALIDATION FAILED")
        print("\n".join(failures))
        return 1

    print(f"REFERENCE VALIDATION PASSED: {len(selected_keys)} references against saved .out files")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
