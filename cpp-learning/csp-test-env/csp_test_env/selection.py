from __future__ import annotations

import argparse
from collections.abc import Iterable

from .catalog import ProblemMeta


def add_key_selection_args(parser: argparse.ArgumentParser) -> None:
    parser.add_argument(
        "--key",
        action="append",
        default=[],
        help="Only process this problem key, such as CSP201403-1. May be repeated.",
    )
    parser.add_argument(
        "--problem",
        action="append",
        default=[],
        metavar="CONTEST/POSITION",
        help="Only process a contest/position pair, such as 1/1 or 41/5. May be repeated.",
    )


def has_key_selection(args: argparse.Namespace) -> bool:
    return bool(args.key or args.problem)


def resolve_selected_keys(
    args: argparse.Namespace,
    meta_by_key: dict[str, ProblemMeta],
    default_keys: Iterable[str],
) -> list[str]:
    selected = set(args.key or [])
    meta_by_pair = {
        (meta.contest_id, meta.position): key
        for key, meta in meta_by_key.items()
    }

    for raw in args.problem or []:
        normalized = raw.replace(":", "/").replace("-", "/")
        parts = normalized.split("/")
        if len(parts) != 2:
            raise ValueError(f"invalid --problem value: {raw!r}; expected CONTEST/POSITION")
        try:
            contest_id = int(parts[0])
            position = int(parts[1])
        except ValueError as exc:
            raise ValueError(f"invalid --problem value: {raw!r}; contest and position must be integers") from exc
        key = meta_by_pair.get((contest_id, position))
        if key is None:
            raise ValueError(f"unknown problem pair: {contest_id}/{position}")
        selected.add(key)

    default_list = list(default_keys)
    if not selected:
        return default_list

    unknown = sorted(selected - set(meta_by_key))
    if unknown:
        raise ValueError(f"unknown problem key(s): {', '.join(unknown)}")

    return [key for key in default_list if key in selected]
