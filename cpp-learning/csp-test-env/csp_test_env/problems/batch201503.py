from __future__ import annotations

from . import ProblemDefinition


def _matrix_case(n: int, m: int) -> str:
    rows = []
    for i in range(n):
        rows.append(" ".join(str((i * 97 + j * 31) % 1000) for j in range(m)))
    return f"{n} {m}\n" + "\n".join(rows) + "\n"


def cases_201503_1() -> list[str]:
    return [
        "1 1\n7\n",
        "1 5\n1 2 3 4 5\n",
        "4 1\n1\n2\n3\n4\n",
        "2 2\n1 2\n3 4\n",
        "3 4\n1 2 3 4\n5 6 7 8\n9 10 11 12\n",
        _matrix_case(6, 7),
        _matrix_case(10, 3),
        _matrix_case(3, 10),
        _matrix_case(20, 20),
        _matrix_case(120, 130),
    ]


def cases_201503_2() -> list[str]:
    return [
        "1\n0\n",
        "5\n1 1 1 1 1\n",
        "6\n5 4 3 2 1 0\n",
        "8\n2 2 3 3 1 1 1 0\n",
        "10\n10 10 9 9 9 8 8 7 7 7\n",
        "12\n0 1000 0 999 999 1000 500 500 500 1 1 1\n",
        "20\n" + " ".join(str(i % 5) for i in range(20)) + "\n",
        "30\n" + " ".join(str((i * 7) % 11) for i in range(30)) + "\n",
        "100\n" + " ".join(str(i % 17) for i in range(100)) + "\n",
        "1000\n" + " ".join(str((i * i + 17 * i) % 1001) for i in range(1000)) + "\n",
    ]


def cases_201503_3() -> list[str]:
    return [
        "1 1 1 1850 1850\n",
        "2 5 7 1850 1855\n",
        "5 2 7 2016 2020\n",
        "2 5 1 1900 1905\n",
        "2 5 1 2000 2005\n",
        "12 4 5 1990 1999\n",
        "1 3 2 1850 1900\n",
        "7 5 7 2040 2050\n",
        "11 1 4 1950 1975\n",
        "2 5 1 1850 2050\n",
    ]


def _network_case(n: int, m: int, parents: list[int], computers: list[int]) -> str:
    parent_line = " ".join(map(str, parents)) if parents else ""
    return f"{n} {m}\n{parent_line}\n" + " ".join(map(str, computers)) + "\n"


def cases_201503_4() -> list[str]:
    chain_n = 10000
    return [
        _network_case(1, 1, [], [1]),
        _network_case(2, 1, [1], [2]),
        _network_case(4, 2, [1, 1, 3], [2, 1]),
        _network_case(4, 4, [1, 2, 2], [3, 4, 4, 4]),
        _network_case(5, 3, [1, 1, 2, 2], [4, 5, 3]),
        _network_case(8, 6, [1, 1, 2, 2, 3, 3, 6], [4, 5, 7, 8, 1, 6]),
        _network_case(10, 10, [1, 1, 1, 2, 2, 3, 3, 4, 4], [5, 6, 7, 8, 9, 10, 1, 2, 3, 4]),
        _network_case(20, 20, [max(1, i // 2) for i in range(2, 21)], [(i * 7) % 20 + 1 for i in range(20)]),
        _network_case(200, 200, [max(1, i - 3) for i in range(2, 201)], [(i * 37) % 200 + 1 for i in range(200)]),
        _network_case(chain_n, chain_n, list(range(1, chain_n)), list(range(1, chain_n + 1))),
    ]


def _min_cost_case(prices: list[int], edges: list[tuple[int, int, int]], queries: list[tuple[int, int]]) -> str:
    out = [f"{len(prices)} {len(queries)}", " ".join(map(str, prices))]
    out.extend(f"{u} {v} {w}" for u, v, w in edges)
    out.extend(f"{s} {t}" for s, t in queries)
    return "\n".join(out) + "\n"


def cases_201503_5() -> list[str]:
    def path_case(n: int, q: int) -> str:
        prices = [(i * 37) % 1000000 + 1 for i in range(1, n + 1)]
        edges = [(i, i + 1, i % 10000 + 1) for i in range(1, n)]
        queries = []
        for i in range(q):
            a = i % n + 1
            b = n - (i * 17) % n
            queries.append((a, b))
        return _min_cost_case(prices, edges, queries)

    return [
        _min_cost_case([5], [], [(1, 1)]),
        _min_cost_case([1, 7], [(1, 2, 4)], [(1, 2), (2, 1)]),
        _min_cost_case([3, 2, 5], [(1, 2, 2), (2, 3, 3)], [(1, 3), (3, 1)]),
        _min_cost_case([1, 7, 3, 2, 5, 6], [(1, 2, 4), (1, 3, 5), (2, 4, 1), (3, 5, 2), (3, 6, 1)], [(2, 5), (4, 6), (6, 4), (5, 6)]),
        _min_cost_case([9, 4, 8, 2, 7], [(1, 2, 10), (1, 3, 1), (3, 4, 5), (3, 5, 7)], [(2, 4), (4, 2), (5, 1)]),
        path_case(20, 20),
        path_case(100, 50),
        path_case(500, 80),
        path_case(1000, 100),
        path_case(5000, 200),
    ]


REGISTRY: dict[str, ProblemDefinition] = {
    "CSP201503-1": ProblemDefinition("CSP201503-1", cases_201503_1),
    "CSP201503-2": ProblemDefinition("CSP201503-2", cases_201503_2),
    "CSP201503-3": ProblemDefinition("CSP201503-3", cases_201503_3),
    "CSP201503-4": ProblemDefinition("CSP201503-4", cases_201503_4),
    "CSP201503-5": ProblemDefinition("CSP201503-5", cases_201503_5),
}
