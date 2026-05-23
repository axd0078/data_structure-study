from __future__ import annotations

from dataclasses import dataclass
from datetime import datetime
import json
from pathlib import Path


PACKAGE_ROOT = Path(__file__).resolve().parent
TOOL_ROOT = PACKAGE_ROOT.parent
CPP_LEARNING_ROOT = TOOL_ROOT.parent
REPO_ROOT = CPP_LEARNING_ROOT.parent
PROBLEM_ROOT = CPP_LEARNING_ROOT / "csp-certification-problems"
MANIFEST_PATH = PROBLEM_ROOT / "manifest.json"
SAMPLE_ZIP_ROOT = PROBLEM_ROOT / "assets" / "staticdata" / "down"
FIXED_SUBMISSION_RELATIVE_ROOT = Path("programming") / "test" / "csp"
FIXED_SUBMISSION_ROOT = REPO_ROOT / FIXED_SUBMISSION_RELATIVE_ROOT
REFERENCE_SOLUTION_ROOT = TOOL_ROOT / "reference_solutions"
TEST_DATA_ROOT = TOOL_ROOT / "test_data"


@dataclass(frozen=True)
class ProblemMeta:
    key: str
    contest_id: int
    contest_title: str
    contest_month: str
    position: int
    problem_id: int
    title: str
    markdown_path: Path


@dataclass(frozen=True)
class ContestMeta:
    contest_id: int
    title: str
    contest_month: str
    directory: Path
    problems: tuple[ProblemMeta, ...]


def load_catalog(manifest_path: Path = MANIFEST_PATH) -> tuple[ContestMeta, ...]:
    data = json.loads(manifest_path.read_text(encoding="utf-8"))
    contests: list[ContestMeta] = []
    for contest in data["contests"]:
        month = datetime.fromtimestamp(contest["startTime"] / 1000).strftime("%Y%m")
        contest_dir = PROBLEM_ROOT / contest["directory"]
        problems: list[ProblemMeta] = []
        for problem in contest["problems"]:
            position = int(problem["position"])
            key = f"CSP{month}-{position}"
            problems.append(
                ProblemMeta(
                    key=key,
                    contest_id=int(contest["id"]),
                    contest_title=str(contest["title"]),
                    contest_month=month,
                    position=position,
                    problem_id=int(problem["id"]),
                    title=str(problem["title"]),
                    markdown_path=contest_dir / problem["file"],
                )
            )
        contests.append(
            ContestMeta(
                contest_id=int(contest["id"]),
                title=str(contest["title"]),
                contest_month=month,
                directory=contest_dir,
                problems=tuple(problems),
            )
        )
    return tuple(contests)


def all_problem_keys() -> list[str]:
    return [problem.key for contest in load_catalog() for problem in contest.problems]


def fixed_submission_path(contest_id: int, position: int) -> Path:
    return FIXED_SUBMISSION_ROOT / str(contest_id) / f"{position}.cpp"


def fixed_submission_relative_path(contest_id: int, position: int) -> Path:
    return FIXED_SUBMISSION_RELATIVE_ROOT / str(contest_id) / f"{position}.cpp"


def reference_solution_path(contest_id: int, position: int) -> Path:
    return REFERENCE_SOLUTION_ROOT / str(contest_id) / f"{position}.cpp"


def test_data_dir(contest_id: int, position: int) -> Path:
    return TEST_DATA_ROOT / str(contest_id) / str(position)


def problem_meta_by_key() -> dict[str, ProblemMeta]:
    return {problem.key: problem for contest in load_catalog() for problem in contest.problems}
