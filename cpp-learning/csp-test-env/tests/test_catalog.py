from __future__ import annotations

import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from csp_test_env.catalog import fixed_submission_path, fixed_submission_relative_path  # noqa: E402


class CatalogTests(unittest.TestCase):
    def test_fixed_submission_path_uses_contest_and_problem_numbers(self) -> None:
        path = fixed_submission_path(1, 2)
        self.assertEqual(path.parts[-5:], ("programming", "test", "csp", "1", "2.cpp"))

    def test_fixed_submission_relative_path_stays_repo_relative(self) -> None:
        path = fixed_submission_relative_path(1, 2)
        self.assertFalse(path.is_absolute())
        self.assertEqual(path.parts, ("programming", "test", "csp", "1", "2.cpp"))


if __name__ == "__main__":
    unittest.main()
