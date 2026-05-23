from __future__ import annotations

from dataclasses import dataclass

from .catalog import problem_meta_by_key, test_data_dir


@dataclass(frozen=True)
class SavedCase:
    index: int
    input_text: str
    expected_output: str


def saved_case_dir(problem_key: str):
    meta = problem_meta_by_key().get(problem_key)
    if meta is None:
        raise ValueError(f"unknown problem key: {problem_key}")
    return test_data_dir(meta.contest_id, meta.position)


def load_saved_cases(problem_key: str) -> list[SavedCase]:
    directory = saved_case_dir(problem_key)
    if not directory.exists():
        raise FileNotFoundError(f"test data directory not found: {directory}")

    cases: list[SavedCase] = []
    for index in range(1, 11):
        input_path = directory / f"{index:02d}.in"
        output_path = directory / f"{index:02d}.out"
        if not input_path.exists():
            raise FileNotFoundError(f"missing test input: {input_path}")
        if not output_path.exists():
            raise FileNotFoundError(f"missing expected output: {output_path}")
        cases.append(
            SavedCase(
                index=index,
                input_text=input_path.read_text(encoding="utf-8"),
                expected_output=output_path.read_text(encoding="utf-8"),
            )
        )
    return cases
