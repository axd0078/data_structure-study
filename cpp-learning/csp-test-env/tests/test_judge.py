from __future__ import annotations

import sys
import tempfile
import textwrap
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from csp_test_env.judge import (  # noqa: E402
    CORRECT,
    RUNTIME_ERROR,
    TIMEOUT,
    WRONG,
    judge_problem,
)
from csp_test_env.problems import ProblemDefinition  # noqa: E402


def toy_cases() -> list[str]:
    return [f"{i}\n" for i in range(10)]


def toy_solve(input_text: str) -> str:
    return input_text


class JudgeTests(unittest.TestCase):
    def setUp(self) -> None:
        self.temp_dir = tempfile.TemporaryDirectory()
        self.root = Path(self.temp_dir.name)
        self.problem = ProblemDefinition("TOY-1", toy_cases, toy_solve)

    def tearDown(self) -> None:
        self.temp_dir.cleanup()

    def write_cpp(self, name: str, code: str) -> Path:
        path = self.root / name
        path.write_text(textwrap.dedent(code), encoding="utf-8")
        return path

    def test_correct_submission(self) -> None:
        source = self.write_cpp(
            "correct.cpp",
            r"""
            #include <bits/stdc++.h>
            using namespace std;
            int main() { long long x; if (cin >> x) cout << x << "\n"; }
            """,
        )
        report = judge_problem(self.problem, source, timeout_seconds=1, validate_samples=False)
        self.assertEqual(report.total_score, 100)
        self.assertTrue(all(result.status == CORRECT for result in report.case_results))

    def test_wrong_answer(self) -> None:
        source = self.write_cpp(
            "wrong.cpp",
            r"""
            #include <bits/stdc++.h>
            using namespace std;
            int main() { cout << 999 << "\n"; }
            """,
        )
        report = judge_problem(self.problem, source, timeout_seconds=1, validate_samples=False)
        self.assertEqual(report.total_score, 0)
        self.assertTrue(all(result.status == WRONG for result in report.case_results))

    def test_timeout(self) -> None:
        source = self.write_cpp(
            "timeout.cpp",
            r"""
            int main() { while (true) {} }
            """,
        )
        report = judge_problem(self.problem, source, timeout_seconds=0.2, validate_samples=False)
        self.assertEqual(report.case_results[0].status, TIMEOUT)

    def test_runtime_error(self) -> None:
        source = self.write_cpp(
            "runtime.cpp",
            r"""
            int main() { return 3; }
            """,
        )
        report = judge_problem(self.problem, source, timeout_seconds=1, validate_samples=False)
        self.assertEqual(report.case_results[0].status, RUNTIME_ERROR)

    def test_compile_error(self) -> None:
        source = self.write_cpp("compile_error.cpp", "int main( {")
        report = judge_problem(self.problem, source, timeout_seconds=1, validate_samples=False)
        self.assertEqual(report.total_score, 0)
        self.assertIsNotNone(report.compile_error)
        self.assertEqual(tuple(), report.case_results)


if __name__ == "__main__":
    unittest.main()

