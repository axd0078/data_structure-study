from __future__ import annotations


def normalize_output(text: str) -> str:
    """Normalize only platform newline representation.

    Every other character is significant: spaces, tabs, blank lines, and the
    final trailing newline must match the saved .out file exactly.
    """
    return text.replace("\r\n", "\n").replace("\r", "\n")


def outputs_match(actual: str, expected: str) -> bool:
    return normalize_output(actual) == normalize_output(expected)
