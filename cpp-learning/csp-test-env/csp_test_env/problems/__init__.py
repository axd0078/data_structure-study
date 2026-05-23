from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from typing import Callable


CaseGenerator = Callable[[], list[str]]
Solver = Callable[[str], str]


@dataclass(frozen=True)
class ProblemDefinition:
    key: str
    generate_cases: CaseGenerator
    solve: Solver | None = None
    reference_source: Path | None = None
