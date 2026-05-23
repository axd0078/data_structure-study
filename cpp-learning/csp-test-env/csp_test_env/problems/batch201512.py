from __future__ import annotations

from . import ProblemDefinition


def cases_201512_1() -> list[str]:
    return ["0\n", "9\n", "10\n", "99\n", "100\n", "12345\n", "20151220\n", "999999999\n", "1000000000\n", "987654321\n"]


def _board_case(board: list[list[int]]) -> str:
    return f"{len(board)} {len(board[0])}\n" + "\n".join(" ".join(map(str, row)) for row in board) + "\n"


def cases_201512_2() -> list[str]:
    return [
        _board_case([[1, 2], [3, 4]]),
        _board_case([[1, 1, 1]]),
        _board_case([[1], [1], [1]]),
        _board_case([[2, 2, 3, 1, 2], [3, 4, 5, 1, 4], [2, 3, 2, 1, 3], [2, 2, 2, 4, 4]]),
        _board_case([[2, 2, 3, 1, 2], [3, 1, 1, 1, 1], [2, 3, 2, 1, 3], [2, 2, 3, 3, 3]]),
        _board_case([[1, 2, 3, 4, 5], [1, 2, 3, 4, 5], [1, 2, 3, 4, 5]]),
        _board_case([[7] * 6 for _ in range(6)]),
        _board_case([[(i + j) % 5 + 1 for j in range(10)] for i in range(10)]),
        _board_case([[(i * j + 3) % 9 + 1 for j in range(30)] for i in range(30)]),
        _board_case([[((i // 3) + (j // 3)) % 6 + 1 for j in range(30)] for i in range(30)]),
    ]


def _draw_case(width: int, height: int, ops: list[str]) -> str:
    return f"{width} {height} {len(ops)}\n" + "\n".join(ops) + "\n"


def cases_201512_3() -> list[str]:
    return [
        _draw_case(1, 1, ["1 0 0 A"]),
        _draw_case(4, 2, ["1 0 0 B", "0 1 0 2 0", "1 0 0 A"]),
        _draw_case(5, 5, ["0 0 0 4 0", "0 0 0 0 4", "1 1 1 C"]),
        _draw_case(8, 6, ["0 1 1 6 1", "0 6 1 6 4", "0 6 4 1 4", "0 1 4 1 1", "1 2 2 D"]),
        _draw_case(10, 10, ["0 0 0 9 0", "0 9 0 9 9", "0 9 9 0 9", "0 0 9 0 0", "1 5 5 X", "1 0 0 Y"]),
        _draw_case(20, 10, ["0 2 2 17 2", "0 2 7 17 7", "0 2 2 2 7", "0 17 2 17 7", "1 3 3 A", "1 0 0 B"]),
        _draw_case(30, 20, [f"0 {i} 0 {i} 19" for i in range(0, 30, 5)] + ["1 1 1 C"]),
        _draw_case(40, 30, [f"0 0 {i} 39 {i}" for i in range(0, 30, 4)] + ["1 2 2 D"]),
        _draw_case(80, 60, ["0 10 10 70 10", "0 70 10 70 50", "0 70 50 10 50", "0 10 50 10 10", "1 20 20 E", "1 0 0 F"]),
        _draw_case(100, 100, [f"0 {i} 0 {i} 99" for i in range(0, 100, 10)] + [f"0 0 {i} 99 {i}" for i in range(0, 100, 10)] + ["1 1 1 Z"]),
    ]


def _euler_case(n: int, edges: list[tuple[int, int]]) -> str:
    return f"{n} {len(edges)}\n" + "\n".join(f"{u} {v}" for u, v in edges) + "\n"


def cases_201512_4() -> list[str]:
    return [
        _euler_case(1, []),
        _euler_case(2, [(1, 2)]),
        _euler_case(3, [(1, 2), (2, 3)]),
        _euler_case(3, [(1, 2), (2, 3), (3, 1)]),
        _euler_case(4, [(1, 2), (1, 3), (1, 4), (2, 4), (3, 4)]),
        _euler_case(4, [(1, 2), (1, 3), (1, 4), (2, 4), (3, 4), (2, 3)]),
        _euler_case(6, [(1, 2), (2, 3), (3, 1), (3, 4), (4, 5), (5, 6), (6, 4)]),
        _euler_case(10, [(i, i + 1) for i in range(1, 10)]),
        _euler_case(100, [(i, i + 1) for i in range(1, 100)]),
        _euler_case(1000, [(i, i + 1) for i in range(1, 1000)]),
    ]


def _matrix_case(m: int, queries: list[int]) -> str:
    rows = []
    for i in range(m):
        row = ["0"] * m
        row[i] = "1"
        if i + 1 < m and i % 3 == 0:
            row[i + 1] = "1"
        rows.append("".join(row))
    vector = "".join("1" if i % 2 else "0" for i in range(m))
    return f"{m}\n" + "\n".join(rows) + f"\n{vector}\n{len(queries)}\n" + "\n".join(map(str, queries)) + "\n"


def cases_201512_5() -> list[str]:
    return [
        _matrix_case(1, [0, 1, 2]),
        _matrix_case(2, [0, 1, 2, 3]),
        _matrix_case(3, [0, 2, 3, 14]),
        _matrix_case(5, [1, 2, 3, 5, 8]),
        _matrix_case(10, [0, 1, 10, 1000]),
        _matrix_case(20, [0, 7, 12345, 999999]),
        _matrix_case(30, [1, 2, 3, 10**9]),
        _matrix_case(50, [0, 1, 2, 3, 4, 10**9]),
        _matrix_case(80, [5, 123, 456789, 10**9]),
        _matrix_case(100, [0, 1, 10, 1000, 10**9]),
    ]


REGISTRY: dict[str, ProblemDefinition] = {
    "CSP201512-1": ProblemDefinition("CSP201512-1", cases_201512_1),
    "CSP201512-2": ProblemDefinition("CSP201512-2", cases_201512_2),
    "CSP201512-3": ProblemDefinition("CSP201512-3", cases_201512_3),
    "CSP201512-4": ProblemDefinition("CSP201512-4", cases_201512_4),
    "CSP201512-5": ProblemDefinition("CSP201512-5", cases_201512_5),
}
