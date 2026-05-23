from __future__ import annotations

from pathlib import Path
import zipfile

from .catalog import SAMPLE_ZIP_ROOT


def _canonical_input_identity(text: str) -> str:
    text = text.replace("\r\n", "\n").replace("\r", "\n")
    return text.strip()


def sample_inputs_for(problem_key: str, sample_root: Path = SAMPLE_ZIP_ROOT) -> set[str]:
    zip_path = sample_root / f"{problem_key}.zip"
    if not zip_path.exists():
        return set()
    samples: set[str] = set()
    with zipfile.ZipFile(zip_path) as archive:
        for entry in archive.infolist():
            if entry.is_dir() or not entry.filename.lower().endswith(".in"):
                continue
            data = archive.read(entry)
            text = data.decode("utf-8", errors="replace")
            samples.add(_canonical_input_identity(text))
    return samples


def assert_not_official_samples(problem_key: str, cases: list[str]) -> None:
    official_samples = sample_inputs_for(problem_key)
    if not official_samples:
        return
    repeated = [
        index
        for index, case in enumerate(cases, start=1)
        if _canonical_input_identity(case) in official_samples
    ]
    if repeated:
        numbers = ", ".join(map(str, repeated))
        raise ValueError(f"{problem_key} test case(s) {numbers} duplicate official sample input")

