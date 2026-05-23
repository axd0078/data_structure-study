from __future__ import annotations

from .catalog import problem_meta_by_key, reference_solution_path
from .problems import ProblemDefinition
from .problems.batch201503 import REGISTRY as BATCH201503_REGISTRY
from .problems.batch201509 import REGISTRY as BATCH201509_REGISTRY
from .problems.batch201512 import REGISTRY as BATCH201512_REGISTRY
from .problems.day21_25 import REGISTRY as DAY21_25_REGISTRY
from .problems.day26_30 import REGISTRY as DAY26_30_REGISTRY
from .problems.day31_35 import REGISTRY as DAY31_35_REGISTRY
from .problems.manual import REGISTRY as MANUAL_REGISTRY
from .problems.practice import REGISTRY as PRACTICE_REGISTRY


REGISTRY: dict[str, ProblemDefinition] = {}
REGISTRY.update(MANUAL_REGISTRY)
REGISTRY.update(PRACTICE_REGISTRY)
REGISTRY.update(BATCH201503_REGISTRY)
REGISTRY.update(BATCH201509_REGISTRY)
REGISTRY.update(BATCH201512_REGISTRY)
REGISTRY.update(DAY21_25_REGISTRY)
REGISTRY.update(DAY26_30_REGISTRY)
REGISTRY.update(DAY31_35_REGISTRY)

_META_BY_KEY = problem_meta_by_key()
for _key, _problem in list(REGISTRY.items()):
    _meta = _META_BY_KEY.get(_key)
    if _meta is None:
        continue
    _reference = reference_solution_path(_meta.contest_id, _meta.position)
    REGISTRY[_key] = ProblemDefinition(
        key=_problem.key,
        generate_cases=_problem.generate_cases,
        solve=_problem.solve,
        reference_source=_reference if _reference.exists() else _problem.reference_source,
    )


def get_problem(key: str) -> ProblemDefinition | None:
    return REGISTRY.get(key)


def registered_keys() -> set[str]:
    return set(REGISTRY)
