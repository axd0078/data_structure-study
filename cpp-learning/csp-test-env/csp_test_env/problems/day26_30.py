from __future__ import annotations

from . import ProblemDefinition


def _lines(values: list[str] | list[int]) -> str:
    return "\n".join(map(str, values)) + "\n"


def _matrix(rows: list[list[int]]) -> str:
    return "\n".join(" ".join(map(str, row)) for row in rows) + "\n"


def cases_202009_2() -> list[str]:
    def build(n: int, k: int, t: int, rect: tuple[int, int, int, int], people: list[list[tuple[int, int]]]) -> str:
        xl, yd, xr, yu = rect
        lines = [f"{n} {k} {t} {xl} {yd} {xr} {yu}"]
        for person in people:
            values: list[int] = []
            for x, y in person:
                values.extend([x, y])
            lines.append(" ".join(map(str, values)))
        return "\n".join(lines) + "\n"

    case10_people: list[list[tuple[int, int]]] = []
    for person in range(20):
        path = []
        for step in range(1000):
            if person % 4 == 0 and 200 <= step < 800:
                path.append((step % 101, (step * 3) % 101))
            elif person % 4 == 1 and step % 100 == 0:
                path.append((50, 50))
            else:
                path.append((1000 + person, -1000 - step))
        case10_people.append(path)

    return [
        build(1, 1, 1, (0, 0, 10, 10), [[(5, 5)]]),
        build(2, 2, 3, (0, 0, 5, 5), [[(6, 6), (1, 1), (6, 6)], [(0, 0), (5, 5), (6, 6)]]),
        build(3, 3, 5, (-2, -2, 2, 2), [[(-3, 0), (0, 0), (1, 1), (2, 2), (3, 3)], [(9, 9)] * 5, [(-2, -2), (-1, -1), (0, 0), (3, 0), (3, 1)]]),
        build(4, 2, 4, (10, 10, 20, 20), [[(10, 10), (20, 20), (30, 30), (40, 40)], [(15, 15)] * 4, [(1, 1)] * 4, [(9, 10), (10, 9), (21, 20), (20, 21)]]),
        build(5, 4, 6, (100, 100, 200, 200), [[(100 + i, 150) for i in range(6)], [(50, 50), (120, 120), (121, 121), (122, 122), (123, 123), (50, 50)], [(201, 100)] * 6, [(150, 99), (150, 100), (150, 101), (150, 102), (150, 103), (150, 99)], [(0, 0)] * 6]),
        build(6, 2, 8, (-10, -10, 10, 10), [[(i - 4, 0) for i in range(8)], [(20, 20)] * 8, [(-10, -10), (-11, -10), (-10, -10), (-11, -10), (-10, -10), (-11, -10), (-10, -10), (-11, -10)], [(0, 0), (0, 0)] + [(30, 30)] * 6, [(30, 30)] * 3 + [(1, 1)] * 5, [(11, 0)] * 8]),
        build(8, 5, 10, (0, 0, 3, 3), [[(i % 4, i // 4) for i in range(10)] for _ in range(3)] + [[(10, i) for i in range(10)] for _ in range(5)]),
        build(10, 7, 12, (-100, -100, 100, 100), [[((i * j) % 300 - 150, (i * 7 + j * 11) % 300 - 150) for j in range(12)] for i in range(10)]),
        build(20, 10, 100, (0, 0, 50, 50), [[((i * 17 + j * 5) % 70, (i * 13 + j * 3) % 70) for j in range(100)] for i in range(20)]),
        build(20, 500, 1000, (0, 0, 100, 100), case10_people),
    ]


def solve_202009_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, k, t, xl, yd, xr, yu = nums[:7]
    offset = 7
    passed = stayed = 0
    for _ in range(n):
        best = cur = 0
        for _ in range(t):
            x, y = nums[offset], nums[offset + 1]
            offset += 2
            if xl <= x <= xr and yd <= y <= yu:
                cur += 1
                best = max(best, cur)
            else:
                cur = 0
        passed += best > 0
        stayed += best >= k
    return f"{passed}\n{stayed}\n"


def cases_202012_2() -> list[str]:
    def build(pairs: list[tuple[int, int]]) -> str:
        return f"{len(pairs)}\n" + "\n".join(f"{y} {result}" for y, result in pairs) + "\n"

    return [
        build([(1, 1), (2, 0)]),
        build([(2, 0), (4, 0), (6, 1), (8, 1)]),
        build([(5, 1), (5, 1), (5, 0), (6, 0), (7, 1)]),
        build([(0, 0), (1, 1), (2, 0), (3, 1), (4, 0), (5, 1)]),
        build([(10, 0), (10, 0), (20, 1), (20, 0), (30, 1), (40, 1), (40, 0)]),
        build([(i, 1 if i % 3 else 0) for i in range(1, 101)]),
        build([(1000 - i, 0 if i < 50 else 1) for i in range(100)]),
        build([((i * 37) % 100000, (i * 13) % 2) for i in range(1, 1001)]),
        build([(i // 3, 1 if i % 5 else 0) for i in range(1, 10000)]),
        build([(i * 1000, 1 if i > 50000 else 0) for i in range(1, 100001)]),
    ]


def solve_202012_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    m = nums[0]
    pairs = [(nums[1 + 2 * i], nums[2 + 2 * i]) for i in range(m)]
    pairs.sort()
    correct = sum(result for _, result in pairs)
    best = -1
    answer = pairs[0][0]
    i = 0
    while i < m:
        y = pairs[i][0]
        if correct >= best:
            best = correct
            answer = y
        zeros = ones = 0
        while i < m and pairs[i][0] == y:
            if pairs[i][1] == 0:
                zeros += 1
            else:
                ones += 1
            i += 1
        correct += zeros - ones
    return f"{answer}\n"


def cases_202104_2() -> list[str]:
    def build(n: int, limit: int, radius: int, threshold: int, matrix: list[list[int]]) -> str:
        return f"{n} {limit} {radius} {threshold}\n" + _matrix(matrix)

    return [
        build(1, 10, 1, 2, [[1]]),
        build(2, 20, 1, 5, [[1, 9], [2, 8]]),
        build(3, 30, 1, 10, [[i * 3 + j for j in range(3)] for i in range(3)]),
        build(5, 50, 2, 12, [[(i + j) * 3 for j in range(5)] for i in range(5)]),
        build(10, 100, 3, 30, [[(i * i + j * 7) % 100 for j in range(10)] for i in range(10)]),
        build(20, 256, 5, 80, [[(i * 11 + j * 17) % 256 for j in range(20)] for i in range(20)]),
        build(60, 256, 10, 120, [[(i * 31 + j * 19 + i * j) % 256 for j in range(60)] for i in range(60)]),
        build(100, 256, 20, 100, [[0 if (i + j) % 7 == 0 else 200 for j in range(100)] for i in range(100)]),
        build(200, 256, 100, 90, [[(i + j) % 256 for j in range(200)] for i in range(200)]),
        build(600, 256, 100, 100, [[(i * 17 + j * 23) % 256 for j in range(600)] for i in range(600)]),
    ]


def solve_202104_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, _, radius, threshold = nums[:4]
    values = nums[4:]
    prefix = [[0] * (n + 1) for _ in range(n + 1)]
    for i in range(n):
        row_sum = 0
        for j in range(n):
            row_sum += values[i * n + j]
            prefix[i + 1][j + 1] = prefix[i][j + 1] + row_sum
    ans = 0
    for i in range(n):
        x1, x2 = max(0, i - radius), min(n - 1, i + radius)
        for j in range(n):
            y1, y2 = max(0, j - radius), min(n - 1, j + radius)
            total = prefix[x2 + 1][y2 + 1] - prefix[x1][y2 + 1] - prefix[x2 + 1][y1] + prefix[x1][y1]
            count = (x2 - x1 + 1) * (y2 - y1 + 1)
            if total <= threshold * count:
                ans += 1
    return f"{ans}\n"


def cases_202109_2() -> list[str]:
    arrays = [
        [1],
        [0, 0, 1, 0],
        [2, 1, 2],
        [5, 4, 3, 2, 1],
        [1, 3, 0, 3, 1, 0, 2, 2],
        [0, 5, 1, 20, 10, 10, 15, 1, 5, 0],
        [(i * 7) % 9 for i in range(1, 101)],
        [0 if i % 10 == 0 else (i % 100) + 1 for i in range(1000)],
        [(i * 97) % 10001 for i in range(20000)],
        [(i * 37) % 10001 for i in range(500000)],
    ]
    return [f"{len(arr)}\n" + " ".join(map(str, arr)) + "\n" for arr in arrays]


def solve_202109_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    arr = nums[1 : 1 + n]
    max_value = max(arr) if arr else 0
    buckets: list[list[int]] = [[] for _ in range(max_value + 1)]
    for idx, value in enumerate(arr, 1):
        if value > 0:
            buckets[value].append(idx)
    active = [False] * (n + 2)
    segments = answer = 0
    for value in range(max_value, 0, -1):
        for idx in buckets[value]:
            left = active[idx - 1]
            right = active[idx + 1]
            if not left and not right:
                segments += 1
            elif left and right:
                segments -= 1
            active[idx] = True
        answer = max(answer, segments)
    return f"{answer}\n"


def cases_202112_2() -> list[str]:
    def build(n: int, big_n: int, arr: list[int]) -> str:
        return f"{n} {big_n}\n" + " ".join(map(str, arr)) + "\n"

    return [
        build(1, 5, [2]),
        build(2, 12, [3, 8]),
        build(3, 20, [1, 7, 15]),
        build(5, 100, [5, 20, 35, 60, 80]),
        build(10, 1000, [i * 70 + 3 for i in range(1, 11)]),
        build(100, 10000, [i * 90 for i in range(1, 101)]),
        build(1000, 1000000, [i * 900 for i in range(1, 1001)]),
        build(10000, 100000000, [i * 9000 for i in range(1, 10001)]),
        build(100000, 200000, list(range(1, 100001))),
        build(100000, 1000000000, [i * 9000 for i in range(1, 100001)]),
    ]


def solve_202112_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, big_n = nums[:2]
    arr = [0] + nums[2 : 2 + n] + [big_n]
    r = big_n // (n + 1)
    x = 0
    idx = 0
    ans = 0
    while x < big_n:
        while idx + 1 < len(arr) and arr[idx + 1] <= x:
            idx += 1
        f_value = idx
        g_value = x // r
        end = min(big_n, arr[idx + 1], (g_value + 1) * r)
        ans += (end - x) * abs(g_value - f_value)
        x = end
    return f"{ans}\n"


def cases_202203_2() -> list[str]:
    def build(plans: list[tuple[int, int]], k: int, queries: list[int]) -> str:
        lines = [f"{len(plans)} {len(queries)} {k}"]
        lines.extend(f"{t} {c}" for t, c in plans)
        lines.extend(map(str, queries))
        return "\n".join(lines) + "\n"

    return [
        build([(5, 3)], 1, [1, 2, 3]),
        build([(10, 5), (20, 10)], 2, [3, 8, 13]),
        build([(5, 24), (12, 12), (30, 30), (40, 1)], 5, [1, 10, 20, 35]),
        build([(i * 10, 15) for i in range(1, 11)], 3, [1, 5, 10, 15, 20]),
        build([(i * 3, i % 20 + 1) for i in range(1, 101)], 10, list(range(1, 51))),
        build([(i * 5, 100) for i in range(1, 501)], 50, list(range(1, 501, 2))),
        build([(i, 200000) for i in range(1, 1001)], 1000, list(range(1, 1001))),
        build([(min(200000, i * 2), i % 200000 + 1) for i in range(1, 10001)], 100000, list(range(1, 10001))),
        build([(min(200000, i * 4), i % 1000 + 1) for i in range(1, 50001)], 999, list(range(1, 50001))),
        build([(min(200000, i * 2), i % 200000 + 1) for i in range(1, 100001)], 100000, list(range(1, 100001))),
    ]


def solve_202203_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m, k = nums[:3]
    offset = 3
    max_time = 200000
    diff = [0] * (max_time + 3)
    for _ in range(n):
        t, c = nums[offset], nums[offset + 1]
        offset += 2
        left = t - c - k + 1
        right = t - k
        if right < 1:
            continue
        left = max(left, 1)
        right = min(right, max_time)
        if left <= right:
            diff[left] += 1
            diff[right + 1] -= 1
    for i in range(1, max_time + 1):
        diff[i] += diff[i - 1]
    return _lines([diff[nums[offset + i]] for i in range(m)])


def cases_202206_2() -> list[str]:
    def build(points: list[tuple[int, int]], limit: int, size: int, pattern: list[list[int]]) -> str:
        lines = [f"{len(points)} {limit} {size}"]
        lines.extend(f"{x} {y}" for x, y in points)
        for row in range(size, -1, -1):
            lines.append(" ".join(str(pattern[row][col]) for col in range(size + 1)))
        return "\n".join(lines) + "\n"

    p1 = [[1]]
    p2 = [[1, 0], [0, 1]]
    p3 = [[1, 1], [1, 0]]
    p4 = [[1, 0, 1], [0, 1, 0], [1, 0, 0]]
    sparse_points = [(i * 1000, i * 1000 + 7) for i in range(1000)]
    return [
        build([(0, 0)], 10, 0, p1),
        build([(0, 0), (1, 1), (5, 5)], 10, 1, p2),
        build([(0, 0), (1, 0), (0, 1), (5, 5)], 10, 1, p3),
        build([(0, 0), (1, 1), (2, 0), (10, 10), (11, 11), (12, 10)], 20, 2, p4),
        build([(i, i) for i in range(10)], 100, 2, p4),
        build([(i, j) for i in range(5) for j in range(5)], 20, 1, [[1, 1], [1, 1]]),
        build([(i * 3, j * 3) for i in range(20) for j in range(20)][:1000], 1000, 2, p4),
        build([(i, (i * i) % 2000) for i in range(1000)], 2000, 3, [[1 if (i + j) % 2 == 0 else 0 for j in range(4)] for i in range(4)]),
        build(sparse_points, 10**9, 50, [[1 if i == j else 0 for j in range(51)] for i in range(51)]),
        build([(i * 1000000 + j, i * 1000000 + 2 * j) for i in range(20) for j in range(50)], 10**9, 50, [[1 if (i * 7 + j * 11) % 13 == 0 or (i == 0 and j == 0) else 0 for j in range(51)] for i in range(51)]),
    ]


def solve_202206_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, limit, size = nums[:3]
    offset = 3
    points: set[tuple[int, int]] = set()
    ordered: list[tuple[int, int]] = []
    for _ in range(n):
        x, y = nums[offset], nums[offset + 1]
        offset += 2
        points.add((x, y))
        ordered.append((x, y))
    pattern = [[0] * (size + 1) for _ in range(size + 1)]
    for row in range(size, -1, -1):
        for col in range(size + 1):
            pattern[row][col] = nums[offset]
            offset += 1
    ans = 0
    for x, y in ordered:
        if x + size > limit or y + size > limit:
            continue
        ok = True
        for i in range(size + 1):
            if not ok:
                break
            for j in range(size + 1):
                if (((x + i, y + j) in points) != (pattern[i][j] == 1)):
                    ok = False
                    break
        ans += ok
    return f"{ans}\n"


def cases_202209_2() -> list[str]:
    def build(target: int, prices: list[int]) -> str:
        return f"{len(prices)} {target}\n" + "\n".join(map(str, prices)) + "\n"

    return [
        build(10, [10]),
        build(50, [20, 40, 30]),
        build(100, [45, 45, 20, 80]),
        build(120, [30, 30, 30, 30, 30]),
        build(999, [500, 499, 1, 700]),
        build(1500, [i * 37 % 200 + 1 for i in range(1, 16)] + [1500]),
        build(3000, [100] * 30),
        build(12000, [i * 313 % 10000 + 1 for i in range(1, 31)]),
        build(200000, [10000] * 30),
        build(150000, [i * 997 % 10000 + 1 for i in range(1, 31)]),
    ]


def solve_202209_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, target = nums[:2]
    prices = nums[2 : 2 + n]
    total = sum(prices)
    dp = [False] * (total + 1)
    dp[0] = True
    for price in prices:
        for s in range(total - price, -1, -1):
            if dp[s]:
                dp[s + price] = True
    for s in range(target, total + 1):
        if dp[s]:
            return f"{s}\n"
    raise AssertionError("input guarantees a reachable sum")


def cases_202212_2() -> list[str]:
    def build(days: int, parents: list[int], durations: list[int]) -> str:
        return f"{days} {len(parents)}\n" + " ".join(map(str, parents)) + "\n" + " ".join(map(str, durations)) + "\n"

    return [
        build(5, [0], [1]),
        build(10, [0, 1, 2], [2, 3, 4]),
        build(5, [0, 1, 2], [3, 3, 3]),
        build(20, [0, 0, 1, 1, 2], [3, 4, 5, 2, 6]),
        build(30, [0, 1, 1, 2, 2, 3, 3], [2, 3, 4, 5, 6, 7, 8]),
        build(60, [0] + [i for i in range(1, 20)], [2] * 20),
        build(100, [0 if i % 5 == 1 else i - 1 for i in range(1, 51)], [(i * 7) % 20 + 1 for i in range(1, 51)]),
        build(365, [0 if i <= 10 else i - 10 for i in range(1, 101)], [(i * 11) % 30 + 1 for i in range(1, 101)]),
        build(120, [0] + [i for i in range(1, 100)], [2] * 100),
        build(365, [0 if i % 3 == 1 else i - 1 for i in range(1, 101)], [(i * 13) % 40 + 1 for i in range(1, 101)]),
    ]


def solve_202212_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    days, m = nums[:2]
    parents = nums[2 : 2 + m]
    durations = nums[2 + m : 2 + 2 * m]
    earliest = [1] * m
    for i in range(m):
        if parents[i] != 0:
            parent = parents[i] - 1
            earliest[i] = earliest[parent] + durations[parent]
    output = [" ".join(map(str, earliest))]
    if all(earliest[i] + durations[i] - 1 <= days for i in range(m)):
        latest = [days - durations[i] + 1 for i in range(m)]
        for i in range(m - 1, -1, -1):
            if parents[i] != 0:
                parent = parents[i] - 1
                latest[parent] = min(latest[parent], latest[i] - durations[parent])
        output.append(" ".join(map(str, latest)))
    return "\n".join(output) + "\n"


def cases_202303_2() -> list[str]:
    def build(budget: int, lower: int, fields: list[tuple[int, int]]) -> str:
        return f"{len(fields)} {budget} {lower}\n" + "\n".join(f"{t} {c}" for t, c in fields) + "\n"

    return [
        build(1, 1, [(5, 1)]),
        build(10, 2, [(6, 1), (8, 3)]),
        build(100, 3, [(10, 10), (20, 1), (5, 5)]),
        build(9, 2, [(6, 1), (5, 1), (6, 2), (8, 1)]),
        build(1000, 1, [(i * 10, i % 7 + 1) for i in range(1, 21)]),
        build(10**6, 10, [(i * 100, i * 3 + 1) for i in range(1, 101)]),
        build(10**9, 1, [(100000, 1) for _ in range(1000)]),
        build(123456789, 100, [((i * 97) % 100000 + 100, (i * 53) % 100000 + 1) for i in range(1, 10000)]),
        build(987654321, 1, [((i * 37) % 100000 + 1, (i * 91) % 100000 + 1) for i in range(1, 50000)]),
        build(10**9, 1, [((i * 17) % 100000 + 1, (i * 31) % 100000 + 1) for i in range(1, 100001)]),
    ]


def solve_202303_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, budget, lower = nums[:3]
    fields = [(nums[3 + 2 * i], nums[4 + 2 * i]) for i in range(n)]
    left, right = lower, max(t for t, _ in fields)
    while left < right:
        mid = (left + right) // 2
        cost = sum(max(0, t - mid) * c for t, c in fields)
        if cost <= budget:
            right = mid
        else:
            left = mid + 1
    return f"{left}\n"


REGISTRY: dict[str, ProblemDefinition] = {
    "CSP202009-2": ProblemDefinition("CSP202009-2", cases_202009_2, solve_202009_2),
    "CSP202012-2": ProblemDefinition("CSP202012-2", cases_202012_2, solve_202012_2),
    "CSP202104-2": ProblemDefinition("CSP202104-2", cases_202104_2, solve_202104_2),
    "CSP202109-2": ProblemDefinition("CSP202109-2", cases_202109_2, solve_202109_2),
    "CSP202112-2": ProblemDefinition("CSP202112-2", cases_202112_2, solve_202112_2),
    "CSP202203-2": ProblemDefinition("CSP202203-2", cases_202203_2, solve_202203_2),
    "CSP202206-2": ProblemDefinition("CSP202206-2", cases_202206_2, solve_202206_2),
    "CSP202209-2": ProblemDefinition("CSP202209-2", cases_202209_2, solve_202209_2),
    "CSP202212-2": ProblemDefinition("CSP202212-2", cases_202212_2, solve_202212_2),
    "CSP202303-2": ProblemDefinition("CSP202303-2", cases_202303_2, solve_202303_2),
}
