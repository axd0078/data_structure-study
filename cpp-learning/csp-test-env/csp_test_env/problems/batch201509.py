from __future__ import annotations

from . import ProblemDefinition


def cases_201509_2() -> list[str]:
    return [
        "1900\n1\n",
        "1900\n59\n",
        "1900\n60\n",
        "2000\n60\n",
        "2000\n366\n",
        "2015\n365\n",
        "2012\n60\n",
        "2012\n366\n",
        "1999\n123\n",
        "2015\n300\n",
    ]


def _template_case(lines: list[str], vars_: dict[str, str]) -> str:
    out = [f"{len(lines)} {len(vars_)}"]
    out.extend(lines)
    for key, value in vars_.items():
        out.append(f'{key} "{value}"')
    return "\n".join(out) + "\n"


def cases_201509_3() -> list[str]:
    big_lines = [f"line{i}: {{ {{ missing{i} }} }} {{ {{ v{i % 10} }} }}" for i in range(100)]
    # Build valid markers after f-string escaping.
    big_lines = [line.replace("{ {", "{{").replace("} }", "}}") for line in big_lines]
    big_vars = {f"v{i}": f"value_{i}" for i in range(10)}
    return [
        _template_case(["hello {{ name }}"], {"name": "world"}),
        _template_case(["{{ a }}{{ b }}{{ c }}"], {"a": "1", "b": "2"}),
        _template_case(["plain text", "{{ missing }}"], {}),
        _template_case(["<p>{{ name }}</p>", "<p>{{ email }}</p>"], {"name": "David Beckham", "email": "david@beckham.com"}),
        _template_case(["{{ x }} {{ x }} {{ y }}"], {"x": "{{ y }}", "y": "done"}),
        _template_case(["A{{ upper }}B{{ lower }}C"], {"upper": "UP", "lower": "down"}),
        _template_case(["{{ a_b1 }}", "{{ A_b1 }}"], {"a_b1": "left", "A_b1": "right"}),
        _template_case(["prefix {{ mid }} suffix {{ none }}"], {"mid": "middle value"}),
        _template_case(["{{ long }}"] * 20, {"long": "x" * 100}),
        _template_case(big_lines, big_vars),
    ]


def _directed_case(n: int, edges: list[tuple[int, int]]) -> str:
    return f"{n} {len(edges)}\n" + "\n".join(f"{u} {v}" for u, v in edges) + "\n"


def cases_201509_4() -> list[str]:
    edges10 = [(i, i + 1) for i in range(1, 10000)] + [(10000, 1)]
    return [
        _directed_case(2, [(1, 2)]),
        _directed_case(2, [(1, 2), (2, 1)]),
        _directed_case(5, [(1, 2), (2, 3), (3, 4), (4, 2), (3, 5)]),
        _directed_case(5, [(1, 2), (2, 1), (3, 4), (4, 5), (5, 3)]),
        _directed_case(6, [(1, 2), (2, 3), (3, 1), (3, 4), (4, 5), (5, 4), (5, 6)]),
        _directed_case(10, [(i, i + 1) for i in range(1, 10)]),
        _directed_case(10, [(i, i % 10 + 1) for i in range(1, 11)]),
        _directed_case(100, [(i, i % 100 + 1) for i in range(1, 101)] + [(i, i + 50) for i in range(1, 51)]),
        _directed_case(1000, [(i, i + 1) for i in range(1, 1000)] + [(i + 1, i) for i in range(1, 1000, 2)]),
        _directed_case(10000, edges10),
    ]


def _article_case(m: int, words: list[str]) -> str:
    return f"{len(words)} {m}\n" + "\n".join(words) + "\n"


def cases_201509_5() -> list[str]:
    return [
        _article_case(1, ["a"]),
        _article_case(5, ["a", "aa"]),
        _article_case(10, ["ab", "ba"]),
        _article_case(15, ["agva", "agvagva", "gvagva"]),
        _article_case(20, ["abc", "bc", "c"]),
        _article_case(100, ["a", "b", "ab", "ba"]),
        _article_case(2000, ["a" * 40, "b" * 40, "ab" * 20]),
        _article_case(100000, ["abc", "bca", "cab", "abcabc"]),
        _article_case(10**12, ["a", "aa", "aaa", "aaaa"]),
        _article_case(10**15, ["a", "aa", "aaa", "aaaa", "aaaaa", "b", "bb", "bbb"]),
    ]


REGISTRY: dict[str, ProblemDefinition] = {
    "CSP201509-2": ProblemDefinition("CSP201509-2", cases_201509_2),
    "CSP201509-3": ProblemDefinition("CSP201509-3", cases_201509_3),
    "CSP201509-4": ProblemDefinition("CSP201509-4", cases_201509_4),
    "CSP201509-5": ProblemDefinition("CSP201509-5", cases_201509_5),
}
