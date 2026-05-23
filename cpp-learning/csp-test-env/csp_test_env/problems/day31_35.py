from __future__ import annotations

from collections import deque
from math import cos, sin
from . import ProblemDefinition


WATERMARK = [
    "*********",
    "*--*--*-*",
    "*--*****-",
    "*----**--",
    "*******--",
]


def _lines(values: list[str] | list[int]) -> str:
    return "\n".join(map(str, values)) + "\n"


def _matrix(rows: list[list[int]]) -> str:
    return "\n".join(" ".join(map(str, row)) for row in rows) + "\n"


def cases_202305_2() -> list[str]:
    def build(n: int, d: int, seed: int) -> str:
        q = [[((i + 1) * (j + 2) + seed) % 21 - 10 for j in range(d)] for i in range(n)]
        k = [[((i + 3) * (j + 1) + seed * 2) % 23 - 11 for j in range(d)] for i in range(n)]
        v = [[((i * 5 + j * 7 + seed) % 25) - 12 for j in range(d)] for i in range(n)]
        w = [((i * 13 + seed) % 17) - 8 for i in range(n)]
        lines = [f"{n} {d}"]
        lines.extend(" ".join(map(str, row)) for row in q)
        lines.extend(" ".join(map(str, row)) for row in k)
        lines.extend(" ".join(map(str, row)) for row in v)
        lines.append(" ".join(map(str, w)))
        return "\n".join(lines) + "\n"

    return [
        build(1, 1, 1),
        build(2, 2, 3),
        build(3, 2, 5),
        build(5, 3, 7),
        build(20, 4, 11),
        build(100, 10, 13),
        build(500, 12, 17),
        build(1000, 20, 19),
        build(3000, 20, 23),
        build(10000, 20, 29),
    ]


def solve_202305_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, d = nums[:2]
    offset = 2
    q = [nums[offset + i * d : offset + (i + 1) * d] for i in range(n)]
    offset += n * d
    k = [nums[offset + i * d : offset + (i + 1) * d] for i in range(n)]
    offset += n * d
    v = [nums[offset + i * d : offset + (i + 1) * d] for i in range(n)]
    offset += n * d
    w = nums[offset : offset + n]
    ktv = [[0] * d for _ in range(d)]
    for row in range(d):
        for col in range(d):
            ktv[row][col] = sum(k[i][row] * v[i][col] for i in range(n))
    out: list[str] = []
    for i in range(n):
        row = []
        for col in range(d):
            value = sum(q[i][mid] * ktv[mid][col] for mid in range(d)) * w[i]
            row.append(str(value))
        out.append(" ".join(row))
    return "\n".join(out) + "\n"


def cases_202309_2() -> list[str]:
    def build(ops: list[tuple[int, float]], queries: list[tuple[int, int, int, int]]) -> str:
        lines = [f"{len(ops)} {len(queries)}"]
        lines.extend(f"{kind} {value:.6f}" for kind, value in ops)
        lines.extend(f"{i} {j} {x} {y}" for i, j, x, y in queries)
        return "\n".join(lines) + "\n"

    ops10 = [(1 if i % 3 else 2, 1.0 + (i % 11) / 20 if i % 3 else (i * 0.137) % 6.0) for i in range(1, 100001)]
    queries10 = [(i, min(100000, i + 999), (i * 37) % 1000000 - 500000, (i * 91) % 1000000 - 500000) for i in range(1, 100001, 1000)]
    return [
        build([(1, 2.0)], [(1, 1, 3, 4)]),
        build([(2, 1.570796)], [(1, 1, 10, 0), (1, 1, 0, 10)]),
        build([(1, 0.5), (2, 3.141593), (1, 2.0)], [(1, 3, 7, -8)]),
        build([(2, 0.25), (2, 0.75), (1, 1.25), (2, 1.0)], [(1, 4, 100, 200), (2, 3, -50, 80)]),
        build([(1, 1.1), (1, 0.9), (2, 2.2), (1, 1.3), (2, 0.4)], [(1, 5, 1, 1), (3, 5, -3, 4)]),
        build([(1 if i % 2 else 2, 0.75 + i / 100 if i % 2 else i / 10) for i in range(1, 21)], [(1, 20, 123, -456), (5, 12, -999, 300)]),
        build([(1 if i % 4 else 2, 1.0 + (i % 5) * 0.1 if i % 4 else i * 0.03) for i in range(1, 1001)], [(1, 1000, 10, 20), (100, 900, -30, 40), (500, 500, 7, 8)]),
        build([(1 if i % 5 else 2, 0.8 + (i % 7) * 0.03 if i % 5 else i * 0.002) for i in range(1, 5000)], [(1, 4999, 1000, -1000), (20, 4500, -12345, 67890)]),
        build([(1 if i % 6 else 2, 0.95 + (i % 9) * 0.01 if i % 6 else i * 0.001) for i in range(1, 20000)], [(1, 19999, 100000, -200000), (333, 12345, -1, 2)]),
        build(ops10, queries10),
    ]


def solve_202309_2(input_text: str) -> str:
    tokens = input_text.split()
    n, m = int(tokens[0]), int(tokens[1])
    scale = [1.0] * (n + 1)
    angle = [0.0] * (n + 1)
    offset = 2
    for i in range(1, n + 1):
        kind = int(tokens[offset])
        value = float(tokens[offset + 1])
        offset += 2
        scale[i] = scale[i - 1]
        angle[i] = angle[i - 1]
        if kind == 1:
            scale[i] *= value
        else:
            angle[i] += value
    out = []
    for _ in range(m):
        left = int(tokens[offset])
        right = int(tokens[offset + 1])
        x = float(tokens[offset + 2])
        y = float(tokens[offset + 3])
        offset += 4
        s = scale[right] / scale[left - 1]
        theta = angle[right] - angle[left - 1]
        nx = s * (x * cos(theta) - y * sin(theta))
        ny = s * (x * sin(theta) + y * cos(theta))
        out.append(f"{nx:.10f} {ny:.10f}")
    return "\n".join(out) + "\n"


def cases_202312_2() -> list[str]:
    groups = [
        [(8, 2)],
        [(12, 2), (18, 3)],
        [(72, 2), (72, 3), (72, 4)],
        [(99991, 2), (100000, 2), (100000, 5)],
        [(2**10 * 3**4 * 5, 3), (2**5 * 7**2, 2)],
        [(10**10 - 1, 2), (9999999967, 2), (9999508849, 3)],
        [(2**30, 10), (3**20, 11), (2**20 * 3**10, 10)],
        [(1234567890, 2), (9876543210, 3), (9999999370, 2)],
        [(10000000000, 2), (10000000000, 5), (9999508849, 2), (9999508849, 10)],
        [(9999999967, 10), (2**20 * 5**10, 10), (99991 * 99991, 2), (99991 * 99991, 3), (10**10, 10), (9876543120, 4), (36, 2), (36, 3), (72, 2), (72, 4)],
    ]
    return [f"{len(group)}\n" + "\n".join(f"{n} {k}" for n, k in group) + "\n" for group in groups]


def solve_202312_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    q = nums[0]
    out = []
    offset = 1
    for _ in range(q):
        value, threshold = nums[offset], nums[offset + 1]
        offset += 2
        n = value
        result = 1
        p = 2
        while p * p <= n:
            count = 0
            while n % p == 0:
                n //= p
                count += 1
            if count >= threshold:
                result *= p**count
            p += 1 if p == 2 else 2
        if n > 1 and threshold <= 1:
            result *= n
        out.append(str(result))
    return "\n".join(out) + "\n"


def cases_202403_2() -> list[str]:
    def build(a: list[str], b: list[str]) -> str:
        return f"{len(a)} {len(b)}\n" + " ".join(a) + "\n" + " ".join(b) + "\n"

    return [
        build(["A"], ["a"]),
        build(["alpha", "beta", "alpha"], ["BETA", "gamma"]),
        build(["One", "Two", "Three"], ["four", "five"]),
        build(["CPP", "Csp", "Data", "DATA"], ["csp", "graph", "cpp"]),
        build(["The", "quick", "Brown", "fox"], ["the", "slow", "brown", "bear"]),
        build([f"Word{i%20}" for i in range(100)], [f"word{i%30}" for i in range(100)]),
        build([f"A{i}" for i in range(1000)], [f"a{i}" for i in range(500, 1500)]),
        build([f"Mix{i%777}" for i in range(10000)], [f"mix{i%999}" for i in range(10000)]),
        build([f"X{i}" for i in range(10000)], [f"Y{i}" for i in range(10000)]),
        build([f"Token{i%5000}" for i in range(10000)], [f"token{i%7000}" for i in range(10000)]),
    ]


def solve_202403_2(input_text: str) -> str:
    tokens = input_text.split()
    n, m = int(tokens[0]), int(tokens[1])
    a = {word.lower() for word in tokens[2 : 2 + n]}
    b = {word.lower() for word in tokens[2 + n : 2 + n + m]}
    return f"{len(a & b)}\n{len(a | b)}\n"


def cases_202406_2() -> list[str]:
    def build(n: int, m: int, matrix: list[list[int]], ops: list[tuple[int, int, int]]) -> str:
        lines = [f"{n} {m} {len(ops)}"]
        lines.extend(" ".join(map(str, row)) for row in matrix)
        lines.extend(f"{op} {a} {b}" for op, a, b in ops)
        return "\n".join(lines) + "\n"

    base = [[i * 10 + j for j in range(4)] for i in range(3)]
    ops10: list[tuple[int, int, int]] = []
    rows, cols = 100, 100
    for i in range(100000):
        if i % 1000 == 0:
            ops10.append((2, 0, 0))
            rows, cols = cols, rows
        elif i % 10 == 0:
            ops10.append((1, rows, cols))
        else:
            ops10.append((3, (i * 17) % rows, (i * 31) % cols))
    return [
        build(1, 1, [[7]], [(3, 0, 0)]),
        build(2, 3, [[1, 2, 3], [4, 5, 6]], [(3, 1, 2), (1, 3, 2), (3, 2, 1)]),
        build(2, 3, [[1, 2, 3], [4, 5, 6]], [(2, 0, 0), (3, 2, 1), (1, 2, 3), (3, 1, 2)]),
        build(3, 4, base, [(3, 2, 3), (1, 2, 6), (3, 1, 5), (2, 0, 0), (3, 5, 1)]),
        build(4, 5, [[i * 5 + j for j in range(5)] for i in range(4)], [(1, 2, 10), (3, 1, 9), (2, 0, 0), (3, 9, 1), (1, 5, 4), (3, 4, 3)]),
        build(10, 10, [[i * 100 + j for j in range(10)] for i in range(10)], [(3, i, 9 - i) for i in range(10)]),
        build(20, 50, [[(i * 50 + j) % 1000 for j in range(50)] for i in range(20)], [(1, 25, 40), (2, 0, 0)] + [(3, i % 40, (i * 7) % 25) for i in range(50)]),
        build(100, 100, [[i * 100 + j for j in range(100)] for i in range(100)], [(3, i, i) for i in range(100)]),
        build(100, 100, [[(i * 131 + j * 17) % 2001 - 1000 for j in range(100)] for i in range(100)], [(2, 0, 0) if i % 500 == 0 else (3, (i * 7) % 100, (i * 11) % 100) for i in range(5000)]),
        build(100, 100, [[(i * 97 + j * 53) % 2001 - 1000 for j in range(100)] for i in range(100)], ops10),
    ]


def solve_202406_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m, t = nums[:3]
    total = n * m
    flat = nums[3 : 3 + total]
    rows, cols = n, m
    offset = 3 + total
    out = []
    for _ in range(t):
        op, a, b = nums[offset], nums[offset + 1], nums[offset + 2]
        offset += 3
        if op == 1:
            rows, cols = a, b
        elif op == 2:
            new_flat = [0] * total
            for i in range(rows):
                for j in range(cols):
                    new_flat[j * rows + i] = flat[i * cols + j]
            flat = new_flat
            rows, cols = cols, rows
        else:
            out.append(str(flat[a * cols + b]))
    return "\n".join(out) + "\n"


def cases_202409_2() -> list[str]:
    def build(s: str, pairs: list[tuple[str, str]], queries: list[int]) -> str:
        lines = [f"#{s}#", str(len(pairs))]
        lines.extend(f"#{a}{b}#" for a, b in pairs)
        lines.append(str(len(queries)))
        lines.append(" ".join(map(str, queries)))
        return "\n".join(lines) + "\n"

    chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 "

    def cycle_pairs(text: str) -> list[tuple[str, str]]:
        return [(text[i], text[(i + 1) % len(text)]) for i in range(len(text))]

    cycle = cycle_pairs(chars)
    return [
        build("a", [("a", "a")], [1, 2, 3]),
        build("Hello", cycle_pairs("HheEl1"), [1, 5]),
        build("a b", cycle_pairs("abc d"), [1, 2, 10]),
        build("012345", [(str(i), str((i + 1) % 10)) for i in range(10)], [1, 9, 10, 100]),
        build("Az 09", cycle_pairs("AaZz 0") + [("9", "9")], [1, 2, 3]),
        build("CSP202409", cycle_pairs(chars[:20]), [1, 2, 31, 1000]),
        build("The Quick Brown Fox", cycle_pairs(chars[10:50]), [7, 63, 64, 1000000000]),
        build(chars[:50], cycle, [1, 2, 3, 63, 64]),
        build(chars, cycle, [999999937, 999999938, 1000000000]),
        build((chars * 2)[:100], cycle, [1, 5, 17, 63, 123456789, 1000000000]),
    ]


def solve_202409_2(input_text: str) -> str:
    lines = input_text.splitlines()
    s = lines[0][1:-1]
    count = int(lines[1])
    mapping = {chr(i): chr(i) for i in range(128)}
    for i in range(count):
        pair = lines[2 + i]
        mapping[pair[1]] = pair[2]
    query_count = int(lines[2 + count])
    queries = list(map(int, lines[3 + count].split()))[:query_count]
    jump = [mapping]
    for _ in range(31):
        prev = jump[-1]
        jump.append({chr(i): prev[prev[chr(i)]] for i in range(128)})
    out = []
    for k in queries:
        chars = []
        for ch in s:
            cur = ch
            bit = 0
            value = k
            while value:
                if value & 1:
                    cur = jump[bit][cur]
                value >>= 1
                bit += 1
            chars.append(cur)
        out.append("#" + "".join(chars) + "#")
    return "\n".join(out) + "\n"


def cases_202412_2() -> list[str]:
    def build(a: list[int], b: list[int]) -> str:
        return f"{len(b)}\n" + " ".join(map(str, a)) + "\n" + " ".join(map(str, b)) + "\n"

    return [
        build([1, 1], [0]),
        build([5, 5, 5, 6], [0, 100, 0]),
        build([9, 4, 6, 3], [9, 4, 6]),
        build([3, 10, 2, 8, 5], [1, 20, 0, 7]),
        build([i % 7 + 1 for i in range(11)], [(i * 3) % 20 for i in range(1, 11)]),
        build([1000] * 101, [0] * 100),
        build([(i * 13) % 1000 for i in range(1001)], [(i * 17) % 1000 for i in range(1, 1001)]),
        build([(i * 7) % 1000 for i in range(10001)], [(i * 11) % 1000 for i in range(1, 10001)]),
        build([1000 if i % 2 else 0 for i in range(50001)], [1000 if i % 3 == 0 else 0 for i in range(1, 50001)]),
        build([(i * 37) % 1001 for i in range(100001)], [(i * 91) % 1001 for i in range(1, 100001)]),
    ]


def solve_202412_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    a = nums[1 : n + 2]
    b = [0] + nums[n + 2 : n + 2 + n]
    need = []
    prefix_a = prefix_b = 0
    for j in range(n + 1):
        prefix_a += a[j]
        if j > 0:
            prefix_b += b[j]
        need.append(prefix_a - prefix_b)
    prefix_max = need[:]
    for i in range(1, n + 1):
        prefix_max[i] = max(prefix_max[i], prefix_max[i - 1])
    suffix_max = need[:]
    for i in range(n - 1, -1, -1):
        suffix_max[i] = max(suffix_max[i], suffix_max[i + 1])
    out = [str(max(prefix_max[i - 1], suffix_max[i] + b[i])) for i in range(1, n + 1)]
    return " ".join(out) + "\n"


def cases_202503_2() -> list[str]:
    def build(n: int, rewards: list[int]) -> str:
        return f"{n} {len(rewards)}\n" + " ".join(map(str, rewards)) + "\n"

    return [
        build(1, [5]),
        build(11, [1, 3, 5, 3, 1]),
        build(5, [1, 60, 100]),
        build(50, [i * i % 100 for i in range(1, 6)]),
        build(60, [i * 17 % 101 for i in range(1, 7)]),
        build(500, [(i * 31) % 1000 for i in range(1, 21)]),
        build(1000, [(i * 97) % 10000 for i in range(1, 51)]),
        build(5000, [(i * 131) % 100000 for i in range(1, 101)]),
        build(10000, [100000 if i == 100 else i for i in range(1, 101)]),
        build(10000, [(i * 1009) % 100001 for i in range(1, 101)]),
    ]


def solve_202503_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m = nums[:2]
    reward = [0] + nums[2 : 2 + m]
    dp = [0] * (n + 1)
    for apples in range(1, n + 1):
        dp[apples] = max(dp[apples - take] + reward[take] for take in range(1, min(m, apples) + 1))
    return f"{dp[n]}\n"


def cases_202506_2() -> list[str]:
    return [
        "1 1\n1 1\n",
        "4 1\n1 2\n",
        "4 2\n1 2\n",
        "8 3\n4 4\n",
        "10 3\n1 10\n",
        "20 10\n10 10\n",
        "50 20\n1 1\n",
        "100 3\n50 50\n",
        "100 50\n1 100\n",
        "100 100\n50 50\n",
    ]


def solve_202506_2(input_text: str) -> str:
    n, k, x, y = map(int, input_text.split())
    moves = [(1, 2), (2, 1), (-1, 2), (-2, 1), (1, -2), (2, -1), (-1, -2), (-2, -1)]
    seen = [[False] * (n + 1) for _ in range(n + 1)]
    seen[x][y] = True
    q: deque[tuple[int, int, int]] = deque([(x, y, 0)])
    ans = 1
    while q:
        cx, cy, dist = q.popleft()
        if dist == k:
            continue
        for dx, dy in moves:
            nx, ny = cx + dx, cy + dy
            if 1 <= nx <= n and 1 <= ny <= n and not seen[nx][ny]:
                seen[nx][ny] = True
                ans += 1
                q.append((nx, ny, dist + 1))
    return f"{ans}\n"


def _watermark_matrix(n: int, limit: int, placements: list[tuple[int, int, int, int]]) -> list[list[int]]:
    matrix = [[0] * n for _ in range(n)]
    for top, left, low, high in placements:
        for i, row in enumerate(WATERMARK):
            for j, ch in enumerate(row):
                matrix[top + i][left + j] = high if ch == "*" else low - 1
    for i in range(n):
        for j in range(n):
            if matrix[i][j] == 0:
                matrix[i][j] = (i * 17 + j * 31) % max(1, limit)
    return matrix


def cases_202509_2() -> list[str]:
    def build(n: int, limit: int, matrix: list[list[int]]) -> str:
        return f"{n} {limit}\n" + _matrix(matrix)

    return [
        build(9, 256, _watermark_matrix(9, 256, [(0, 0, 3, 8)])),
        build(10, 256, _watermark_matrix(10, 256, [(5, 1, 10, 20)])),
        build(12, 256, _watermark_matrix(12, 256, [(0, 0, 1, 1), (7, 3, 30, 40)])),
        build(20, 256, _watermark_matrix(20, 256, [(2, 2, 50, 100), (10, 5, 60, 80)])),
        build(50, 256, _watermark_matrix(50, 256, [(0, 0, 100, 150), (40, 41, 20, 30)])),
        build(80, 256, _watermark_matrix(80, 256, [(i * 7 % 70, i * 11 % 70, 30 + i, 40 + i) for i in range(5)])),
        build(120, 65536, _watermark_matrix(120, 65536, [(10, 10, 1000, 2000), (50, 70, 12345, 23456)])),
        build(200, 256, _watermark_matrix(200, 256, [(i * 13 % 190, i * 17 % 190, 10 + i, 20 + i) for i in range(10)])),
        build(200, 65536, _watermark_matrix(200, 65536, [(0, 0, 1, 65535), (100, 100, 30000, 40000)])),
        build(200, 65536, _watermark_matrix(200, 65536, [(i * 19 % 190, i * 23 % 190, 1000 + i * 100, 2000 + i * 100) for i in range(20)])),
    ]


def solve_202509_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, limit = nums[:2]
    values = nums[2:]
    matrix = [values[i * n : (i + 1) * n] for i in range(n)]
    diff = [0] * (limit + 1)
    for top in range(n - 4):
        for left in range(n - 8):
            min_white = limit - 1
            max_black = -1
            for i, row in enumerate(WATERMARK):
                for j, ch in enumerate(row):
                    value = matrix[top + i][left + j]
                    if ch == "*":
                        min_white = min(min_white, value)
                    else:
                        max_black = max(max_black, value)
            low = max_black + 1
            high = min_white
            if low <= high:
                diff[low] += 1
                diff[high + 1] -= 1
    out = []
    active = 0
    for k in range(limit):
        active += diff[k]
        if active > 0:
            out.append(str(k))
    return "\n".join(out) + "\n"


REGISTRY: dict[str, ProblemDefinition] = {
    "CSP202305-2": ProblemDefinition("CSP202305-2", cases_202305_2, solve_202305_2),
    "CSP202309-2": ProblemDefinition("CSP202309-2", cases_202309_2, solve_202309_2),
    "CSP202312-2": ProblemDefinition("CSP202312-2", cases_202312_2, solve_202312_2),
    "CSP202403-2": ProblemDefinition("CSP202403-2", cases_202403_2, solve_202403_2),
    "CSP202406-2": ProblemDefinition("CSP202406-2", cases_202406_2, solve_202406_2),
    "CSP202409-2": ProblemDefinition("CSP202409-2", cases_202409_2, solve_202409_2),
    "CSP202412-2": ProblemDefinition("CSP202412-2", cases_202412_2, solve_202412_2),
    "CSP202503-2": ProblemDefinition("CSP202503-2", cases_202503_2, solve_202503_2),
    "CSP202506-2": ProblemDefinition("CSP202506-2", cases_202506_2, solve_202506_2),
    "CSP202509-2": ProblemDefinition("CSP202509-2", cases_202509_2, solve_202509_2),
}
