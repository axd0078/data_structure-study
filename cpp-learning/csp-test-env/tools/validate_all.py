from __future__ import annotations

import argparse
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from csp_test_env.catalog import all_problem_keys, problem_meta_by_key, reference_solution_path  # noqa: E402
from csp_test_env.problem_bank import get_problem, registered_keys  # noqa: E402
from csp_test_env.sample_guard import assert_not_official_samples  # noqa: E402
from csp_test_env.selection import add_key_selection_args, has_key_selection, resolve_selected_keys  # noqa: E402
from csp_test_env.test_data import load_saved_cases  # noqa: E402


def _validate_saved_cases(key: str) -> list[str]:
    failures: list[str] = []
    try:
        saved_cases = load_saved_cases(key)
    except Exception as exc:  # noqa: BLE001
        return [f"saved test data error: {exc}"]

    if len(saved_cases) != 10:
        failures.append(f"expected 10 saved cases, got {len(saved_cases)}")
        return failures

    inputs = [case.input_text for case in saved_cases]
    outputs = [case.expected_output for case in saved_cases]
    try:
        assert_not_official_samples(key, inputs)
    except Exception as exc:  # noqa: BLE001
        failures.append(str(exc))

    empty_outputs = [case.index for case in saved_cases if case.expected_output.strip() == ""]
    if empty_outputs:
        failures.append(f"empty .out files at cases: {empty_outputs}")

    max_input_size = max(len(case) for case in inputs)
    if len(inputs[9]) < max_input_size:
        failures.append("case 10 is not the largest or tied-largest saved input")

    if len(set(inputs)) != 10:
        failures.append("duplicate saved .in files")
    if any(not output.endswith("\n") for output in outputs):
        failures.append("every .out must end with a newline for strict output checking")

    return failures


def main() -> int:
    parser = argparse.ArgumentParser(description="Validate CSP problem registrations and saved test data.")
    add_key_selection_args(parser)
    args = parser.parse_args()

    expected_keys = all_problem_keys()
    expected_set = set(expected_keys)
    registered = registered_keys()
    meta_by_key = problem_meta_by_key()
    try:
        selected_keys = resolve_selected_keys(args, meta_by_key, expected_keys)
    except ValueError as exc:
        print(f"VALIDATION FAILED\n{exc}")
        return 1
    filtered = has_key_selection(args)
    failures: list[str] = []

    if not filtered:
        missing = [key for key in expected_keys if key not in registered]
        extra = sorted(registered - expected_set)
        if missing:
            failures.append(f"missing problem modules: {len(missing)}")
            failures.extend(f"  {key}" for key in missing[:60])
            if len(missing) > 60:
                failures.append("  ...")
        if extra:
            failures.append(f"extra problem modules: {', '.join(extra)}")

    for key in selected_keys:
        if key not in registered:
            failures.append(f"{key}: missing problem registration")
            continue
        problem = get_problem(key)
        meta = meta_by_key[key]
        reference = reference_solution_path(meta.contest_id, meta.position)
        if problem is None:
            failures.append(f"{key}: registry returned None")
            continue
        try:
            generated_cases = problem.generate_cases()
            if len(generated_cases) != 10:
                failures.append(f"{key}: generator expected 10 cases, got {len(generated_cases)}")
        except Exception as exc:  # noqa: BLE001
            failures.append(f"{key}: generator failed: {exc}")

        if not reference.exists():
            failures.append(f"{key}: missing reference source {reference}")

        for failure in _validate_saved_cases(key):
            failures.append(f"{key}: {failure}")

    if failures:
        print("VALIDATION FAILED")
        print("\n".join(failures))
        return 1

    print(f"VALIDATION PASSED: {len(selected_keys)} problems")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
