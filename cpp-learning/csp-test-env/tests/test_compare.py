from __future__ import annotations

import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from csp_test_env.compare import outputs_match  # noqa: E402


class CompareTests(unittest.TestCase):
    def test_treats_crlf_and_lf_as_same_newline(self) -> None:
        self.assertTrue(outputs_match("1 2\r\n3\n", "1 2\n3\n"))

    def test_preserves_internal_spacing(self) -> None:
        self.assertFalse(outputs_match("1  2\n", "1 2\n"))

    def test_trailing_spaces_are_significant(self) -> None:
        self.assertFalse(outputs_match("1 2  \n", "1 2\n"))

    def test_final_blank_lines_are_significant(self) -> None:
        self.assertFalse(outputs_match("1 2\n\n", "1 2\n"))

    def test_missing_final_newline_is_significant(self) -> None:
        self.assertFalse(outputs_match("1 2", "1 2\n"))


if __name__ == "__main__":
    unittest.main()
