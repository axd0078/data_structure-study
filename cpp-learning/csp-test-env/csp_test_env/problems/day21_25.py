from __future__ import annotations

from . import ProblemDefinition


def _lines(values: list[str] | list[int]) -> str:
    return "\n".join(map(str, values)) + "\n"


def _matrix(rows: list[list[int]]) -> str:
    return "\n".join(" ".join(map(str, row)) for row in rows) + "\n"


def _tetris_case(board: list[list[int]], block: list[list[int]], col: int) -> str:
    return _matrix(board) + _matrix(block) + f"{col}\n"


def cases_201604_2() -> list[str]:
    empty = [[0] * 10 for _ in range(15)]
    square = [[1, 1, 0, 0], [1, 1, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
    line = [[1, 0, 0, 0], [1, 0, 0, 0], [1, 0, 0, 0], [1, 0, 0, 0]]
    tee = [[0, 1, 0, 0], [1, 1, 1, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
    ell = [[1, 0, 0, 0], [1, 0, 0, 0], [1, 1, 0, 0], [0, 0, 0, 0]]

    def base(filled_rows: int) -> list[list[int]]:
        board = [[0] * 10 for _ in range(15)]
        for i in range(15 - filled_rows, 15):
            board[i] = [1 if (i + j) % 3 else 0 for j in range(10)]
        return board

    b4 = base(4)
    b4[12][3] = b4[12][4] = b4[11][4] = 1
    b8 = base(8)
    for i in range(9, 15):
        b8[i][6] = 1

    return [
        _tetris_case(empty, square, 1),
        _tetris_case(empty, line, 5),
        _tetris_case(base(1), tee, 3),
        _tetris_case(base(2), ell, 7),
        _tetris_case(b4, square, 4),
        _tetris_case(b4, line, 2),
        _tetris_case(b8, tee, 5),
        _tetris_case(base(10), ell, 1),
        _tetris_case([[1 if i > 10 and j in (0, 9) else 0 for j in range(10)] for i in range(15)], square, 8),
        _tetris_case([[1 if i >= 8 and (i * 7 + j * 5) % 4 == 0 else 0 for j in range(10)] for i in range(15)], tee, 4),
    ]


def solve_201604_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    board = [nums[i * 10 : (i + 1) * 10] for i in range(15)]
    offset = 150
    block = [nums[offset + i * 4 : offset + (i + 1) * 4] for i in range(4)]
    col = nums[offset + 16] - 1
    cells = [(i, j) for i in range(4) for j in range(4) if block[i][j] == 1]

    def can_place(top: int) -> bool:
        for r, c in cells:
            nr, nc = top + r, col + c
            if nr < 0 or nr >= 15 or nc < 0 or nc >= 10 or board[nr][nc]:
                return False
        return True

    top = 0
    while can_place(top + 1):
        top += 1
    for r, c in cells:
        board[top + r][col + c] = 1
    return _matrix(board)


def cases_201609_2() -> list[str]:
    requests = [
        [1],
        [5],
        [3, 2, 1],
        [4, 4, 2, 3],
        [5, 5, 5, 5],
        [2, 2, 2, 2, 2, 2],
        [1, 5, 1, 5, 1, 5, 1],
        [4, 1, 4, 1, 4, 1, 4, 1],
        [3] * 20,
        [2] * 45 + [1] * 10,
    ]
    return [f"{len(req)}\n" + " ".join(map(str, req)) + "\n" for req in requests]


def solve_201609_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    requests = nums[1 : 1 + n]
    occupied = [[False] * 5 for _ in range(20)]
    out: list[str] = []
    for amount in requests:
        assigned: list[int] = []
        for row in range(20):
            if assigned:
                break
            for start in range(0, 6 - amount):
                if all(not occupied[row][col] for col in range(start, start + amount)):
                    for col in range(start, start + amount):
                        occupied[row][col] = True
                        assigned.append(row * 5 + col + 1)
                    break
        if not assigned:
            for row in range(20):
                for col in range(5):
                    if not occupied[row][col] and len(assigned) < amount:
                        occupied[row][col] = True
                        assigned.append(row * 5 + col + 1)
        out.append(" ".join(map(str, assigned)))
    return _lines(out)


def _after_tax(gross: int) -> float:
    taxable = max(0, gross - 3500)
    brackets = [
        (1500, 0.03, 0),
        (4500, 0.10, 105),
        (9000, 0.20, 555),
        (35000, 0.25, 1005),
        (55000, 0.30, 2755),
        (80000, 0.35, 5505),
        (10**18, 0.45, 13505),
    ]
    tax = 0.0
    for limit, rate, quick in brackets:
        if taxable <= limit:
            tax = taxable * rate - quick
            break
    return gross - tax


def cases_201612_2() -> list[str]:
    gross_values = [1000, 3500, 5000, 8000, 12000, 20000, 40000, 60000, 90000, 150000]
    return [f"{int(_after_tax(value))}\n" for value in gross_values]


def solve_201612_2(input_text: str) -> str:
    target = float(input_text.strip())
    lo, hi = 0, 1000000
    while lo < hi:
        mid = (lo + hi) // 2
        if _after_tax(mid) < target:
            lo = mid + 1
        else:
            hi = mid
    return f"{lo}\n"


def cases_201703_2() -> list[str]:
    def build(n: int, ops: list[tuple[int, int]]) -> str:
        return f"{n}\n{len(ops)}\n" + "\n".join(f"{p} {q}" for p, q in ops) + "\n"

    return [
        build(3, [(1, 1)]),
        build(5, [(5, -4), (1, 3)]),
        build(8, [(3, 2), (8, -3), (3, -2)]),
        build(10, [(1, 9), (10, -8), (5, 2), (6, -3)]),
        build(12, [(i, 1 if i % 2 else -1) for i in range(2, 11)]),
        build(20, [(10, -5), (3, 7), (18, -10), (1, 5), (20, -4)]),
        build(30, [(i, (i % 5) - 2) for i in range(5, 25)]),
        build(50, [(i, 1) for i in range(1, 30)]),
        build(100, [(i, -1) for i in range(100, 60, -1)]),
        build(1000, [(i, 1) for i in range(1, 501)]),
    ]


def solve_201703_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m = nums[0], nums[1]
    queue = list(range(1, n + 1))
    offset = 2
    for _ in range(m):
        student, delta = nums[offset], nums[offset + 1]
        offset += 2
        pos = queue.index(student)
        queue.pop(pos)
        queue.insert(pos + delta, student)
    return " ".join(map(str, queue)) + "\n"


def cases_201709_2() -> list[str]:
    def build(n: int, records: list[tuple[int, int, int]]) -> str:
        return f"{n} {len(records)}\n" + "\n".join(f"{w} {s} {c}" for w, s, c in records) + "\n"

    return [
        build(3, [(1, 1, 1)]),
        build(5, [(4, 3, 3), (2, 2, 7)]),
        build(5, [(1, 1, 3), (2, 1, 3), (3, 4, 2)]),
        build(6, [(1, 1, 5), (2, 2, 3), (3, 3, 1), (4, 6, 2)]),
        build(8, [(i, i, 10 - i) for i in range(1, 6)]),
        build(10, [(3, 1, 10), (7, 1, 10), (3, 12, 1), (7, 13, 1)]),
        build(12, [(i, i * 2, 5) for i in range(1, 10)]),
        build(20, [(i, (i * 3) % 17 + 1, i % 5 + 1) for i in range(1, 16)]),
        build(50, [(i, i, 50 - i) for i in range(1, 31)]),
        build(100, [(i % 100 + 1, i * 2, i % 20 + 1) for i in range(80)]),
    ]


def solve_201709_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, k = nums[:2]
    events: list[tuple[int, int, int]] = []
    offset = 2
    for _ in range(k):
        key, start, duration = nums[offset], nums[offset + 1], nums[offset + 2]
        offset += 3
        events.append((start, 1, key))
        events.append((start + duration, 0, key))
    events.sort()
    box = list(range(1, n + 1))
    for _, kind, key in events:
        if kind == 1:
            box[box.index(key)] = 0
        else:
            box[box.index(0)] = key
    return " ".join(map(str, box)) + "\n"


def cases_201712_2() -> list[str]:
    return ["1 1\n", "5 2\n", "7 3\n", "10 7\n", "20 4\n", "30 9\n", "100 6\n", "300 8\n", "700 5\n", "1000 9\n"]


def solve_201712_2(input_text: str) -> str:
    n, k = map(int, input_text.split())
    children = list(range(1, n + 1))
    index = 0
    number = 1
    while len(children) > 1:
        if number % k == 0 or number % 10 == k:
            children.pop(index)
            index %= len(children)
        else:
            index = (index + 1) % len(children)
        number += 1
    return f"{children[0]}\n"


def cases_201803_2() -> list[str]:
    def build(length: int, time: int, positions: list[int]) -> str:
        return f"{len(positions)} {length} {time}\n" + " ".join(map(str, positions)) + "\n"

    return [
        build(10, 1, [2]),
        build(10, 5, [2, 8]),
        build(12, 4, [2, 4, 10]),
        build(20, 10, [2, 6, 14, 18]),
        build(30, 15, [4, 8, 12, 16, 20]),
        build(40, 20, [2, 10, 18, 26, 34]),
        build(100, 50, list(range(2, 42, 4))),
        build(200, 80, list(range(2, 102, 10))),
        build(500, 100, list(range(2, 202, 4))),
        build(1000, 100, list(range(2, 202, 2))),
    ]


def solve_201803_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, length, time = nums[:3]
    positions = nums[3 : 3 + n]
    direction = [1] * n
    for _ in range(time):
        for i in range(n):
            positions[i] += direction[i]
            if positions[i] == 0 or positions[i] == length:
                direction[i] *= -1
        for i in range(n):
            for j in range(i + 1, n):
                if positions[i] == positions[j]:
                    direction[i] *= -1
                    direction[j] *= -1
    return " ".join(map(str, positions)) + "\n"


def cases_201809_2() -> list[str]:
    def build(a: list[tuple[int, int]], b: list[tuple[int, int]]) -> str:
        lines = [str(len(a))]
        lines.extend(f"{l} {r}" for l, r in a)
        lines.extend(f"{l} {r}" for l, r in b)
        return "\n".join(lines) + "\n"

    return [
        build([(1, 2)], [(2, 3)]),
        build([(1, 5)], [(2, 4)]),
        build([(0, 3), (5, 8)], [(1, 2), (6, 10)]),
        build([(1, 4), (10, 20)], [(3, 12), (18, 25)]),
        build([(i * 10, i * 10 + 5) for i in range(5)], [(i * 10 + 3, i * 10 + 9) for i in range(5)]),
        build([(0, 100), (200, 300)], [(50, 250), (260, 400)]),
        build([(i * 7, i * 7 + 4) for i in range(20)], [(i * 7 + 2, i * 7 + 6) for i in range(20)]),
        build([(i * 100, i * 100 + 80) for i in range(50)], [(i * 100 + 20, i * 100 + 60) for i in range(50)]),
        build([(i * 3, i * 3 + 2) for i in range(100)], [(i * 3 + 1, i * 3 + 3) for i in range(100)]),
        build([(i * 5, i * 5 + 4) for i in range(1000)], [(i * 5 + 2, i * 5 + 5) for i in range(1000)]),
    ]


def solve_201809_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    values = nums[1:]
    a = [(values[i * 2], values[i * 2 + 1]) for i in range(n)]
    b_offset = 2 * n
    b = [(values[b_offset + i * 2], values[b_offset + i * 2 + 1]) for i in range(n)]
    i = j = ans = 0
    while i < n and j < n:
        ans += max(0, min(a[i][1], b[j][1]) - max(a[i][0], b[j][0]))
        if a[i][1] < b[j][1]:
            i += 1
        else:
            j += 1
    return f"{ans}\n"


def cases_201812_2() -> list[str]:
    def build(r: int, y: int, g: int, events: list[tuple[int, int]]) -> str:
        return f"{r} {y} {g}\n{len(events)}\n" + "\n".join(f"{k} {t}" for k, t in events) + "\n"

    def generated_light_event(i: int) -> tuple[int, int]:
        kind = i % 4
        if kind == 0:
            return 0, (i * 7) % 30 + 1
        if kind == 1:
            return 1, (i * 7) % 30 + 1
        if kind == 2:
            return 2, i % 3 + 1
        return 3, (i * 11) % 30 + 1

    return [
        build(10, 5, 10, [(0, 3)]),
        build(10, 5, 10, [(1, 3), (0, 2)]),
        build(20, 3, 10, [(3, 2), (0, 5), (2, 1)]),
        build(30, 3, 30, [(0, 10), (1, 5), (0, 11), (2, 2)]),
        build(50, 5, 40, [(0, 7), (3, 12), (0, 9), (1, 20), (0, 4)]),
        build(100, 100, 100, [(i % 4, (i * 13) % 90 + 1) for i in range(1, 20)]),
        build(7, 2, 5, [(0, 1), (1, 7), (2, 2), (3, 5)] * 5),
        build(1000, 100, 1000, [(0, 999), (1, 1000), (2, 100), (3, 1000)] * 10),
        build(30, 3, 30, [generated_light_event(i) for i in range(1, 80)]),
        build(1000000, 1000000, 1000000, [(i % 4, (i * 99991) % 1000000 + 1) for i in range(1, 1000)]),
    ]


def solve_201812_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    r, y, g = nums[:3]
    n = nums[3]
    cycle = r + y + g
    total = 0
    offset = 4

    def wait(kind: int, remain: int, elapsed: int) -> int:
        if kind == 1:
            start = r - remain
        elif kind == 2:
            start = r + g + (y - remain)
        else:
            start = r + (g - remain)
        cur = (start + elapsed) % cycle
        if cur < r:
            return r - cur
        if cur < r + g:
            return 0
        return cycle - cur

    for _ in range(n):
        kind, value = nums[offset], nums[offset + 1]
        offset += 2
        if kind == 0:
            total += value
        else:
            total += wait(kind, value, total)
    return f"{total}\n"


def cases_201903_2() -> list[str]:
    groups = [
        ["1+2+3+4"],
        ["9+3+4x3", "5x6/5x4"],
        ["6x4+4/5", "8x3+1-1", "7x3+3/1"],
        ["1x1+9-9", "9x9/9+5", "8/2x6+1"],
        ["3+5+7+9", "9+9+9-3", "4x4+4x2"],
        ["7-9-9+8", "2x3x4+1", "9x3-3/1"],
        ["5+4x5x5", "1x9-5/9", "8/5+6x9"],
        ["2x9+3x2", "9+9+9-3", "4x6/2x2"],
        ["1+2x3+4", "9x2+6", "6x7-3x6", "7x4-8/2"],
        ["9+3+4x3", "5+4x5x5", "7-9-9+8", "5x6/5x4", "3+5+7+9", "1x1+9-9", "1x9-5/9", "8/5+6x9", "6x7-3x6", "9x2+6/1"],
    ]
    return [f"{len(group)}\n" + "\n".join(group) + "\n" for group in groups]


def solve_201903_2(input_text: str) -> str:
    tokens = input_text.split()
    n = int(tokens[0])

    def eval_expr(expr: str) -> int:
        nums = [int(expr[0])]
        ops: list[str] = []
        for i in range(1, len(expr), 2):
            op, value = expr[i], int(expr[i + 1])
            if op == "x":
                nums[-1] *= value
            elif op == "/":
                nums[-1] //= value
            else:
                ops.append(op)
                nums.append(value)
        result = nums[0]
        for op, value in zip(ops, nums[1:]):
            result = result + value if op == "+" else result - value
        return result

    return _lines(["Yes" if eval_expr(expr) == 24 else "No" for expr in tokens[1 : 1 + n]])


def cases_201909_2() -> list[str]:
    def build(rows: list[list[int]]) -> str:
        return f"{len(rows)}\n" + "\n".join(f"{len(row)} " + " ".join(map(str, row)) for row in rows) + "\n"

    return [
        build([[10, -1]]),
        build([[10, 8], [9, -1]]),
        build([[10, -2, 7], [10, 8], [10, -3]]),
        build([[20, -3, -4], [18, 10, -1], [15, -5], [12, 9]]),
        build([[10, 0, 9, 0], [10, -2, 6, 0], [10, 0], [10, -3, 5, 0], [10, -1, 8, 0]]),
        build([[100, -1, -2, 90], [80, -10, 60], [70, -5], [60, 50], [55, -1]]),
        build([[50, -1, 45, -2], [51, 50], [52, -2, 48], [53, -3], [54, 52], [55, -5, 40]]),
        build([[100, -i, 100 - i - 1] for i in range(1, 11)]),
        build([[1000, -10, -20, 900, -5] for _ in range(100)]),
        build([[1000000, -i, 999000 - i, -1] for i in range(1, 1001)]),
    ]


def solve_201909_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    offset = 1
    total = 0
    dropped = [False] * n
    for i in range(n):
        m = nums[offset]
        offset += 1
        current = nums[offset]
        offset += 1
        for _ in range(m - 1):
            value = nums[offset]
            offset += 1
            if value <= 0:
                current += value
            else:
                if value < current:
                    dropped[i] = True
                current = value
        total += current
    d = sum(dropped)
    e = sum(1 for i in range(n) if dropped[(i - 1) % n] and dropped[i] and dropped[(i + 1) % n])
    return f"{total} {d} {e}\n"


def cases_201912_2() -> list[str]:
    def build(points: list[tuple[int, int]]) -> str:
        return f"{len(points)}\n" + "\n".join(f"{x} {y}" for x, y in points) + "\n"

    return [
        build([(0, 0)]),
        build([(0, 0), (1, 0), (-1, 0), (0, 1), (0, -1)]),
        build([(0, 0), (1, 0), (-1, 0), (0, 1), (0, -1), (1, 1)]),
        build([(0, 0), (1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (-1, 1), (1, -1), (-1, -1)]),
        build([(i, 0) for i in range(10)] + [(5, 1), (5, -1), (4, 1), (6, 1)]),
        build([(x, y) for x in range(3) for y in range(3)]),
        build([(x, y) for x in range(-2, 3) for y in range(-2, 3) if abs(x) + abs(y) <= 3]),
        build([(i, i * i % 17) for i in range(50)]),
        build([(x, y) for x in range(10) for y in range(10)]),
        build([(x, y) for x in range(30) for y in range(30)]),
    ]


def solve_201912_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    points = {(nums[1 + 2 * i], nums[2 + 2 * i]) for i in range(n)}
    ans = [0] * 5
    for x, y in points:
        if all((x + dx, y + dy) in points for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1))):
            score = sum((x + dx, y + dy) in points for dx, dy in ((1, 1), (1, -1), (-1, 1), (-1, -1)))
            ans[score] += 1
    return _lines(ans)


def cases_202006_2() -> list[str]:
    def build(dim: int, a: list[tuple[int, int]], b: list[tuple[int, int]]) -> str:
        lines = [f"{dim} {len(a)} {len(b)}"]
        lines.extend(f"{i} {v}" for i, v in a)
        lines.extend(f"{i} {v}" for i, v in b)
        return "\n".join(lines) + "\n"

    return [
        build(10, [(1, 2)], [(1, 3)]),
        build(10, [(1, 2)], [(2, 3)]),
        build(20, [(2, -1), (5, 4)], [(2, 3), (5, -2)]),
        build(100, [(1, 10), (50, 20), (100, 30)], [(1, -1), (100, 2)]),
        build(1000, [(i, i % 7 - 3) for i in range(1, 100, 10)], [(i, i % 5 - 2) for i in range(1, 100, 5)]),
        build(10**6, [(10, 1000000), (999999, -2)], [(10, -3), (999999, 4)]),
        build(5000, [(i, i) for i in range(1, 101)], [(i, -i) for i in range(50, 151)]),
        build(10000, [(i * 3, i % 11) for i in range(1, 500)], [(i * 5, i % 13 - 6) for i in range(1, 500)]),
        build(10**9, [(i * 1000, i) for i in range(1, 1000)], [(i * 1000, -i) for i in range(1, 1000)]),
        build(10**9, [(i * 2, (i % 17) - 8) for i in range(1, 5001)], [(i * 2, (i % 19) - 9) for i in range(2500, 7501)]),
    ]


def solve_202006_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    _, a_count, b_count = nums[:3]
    offset = 3
    a = [(nums[offset + 2 * i], nums[offset + 2 * i + 1]) for i in range(a_count)]
    offset += 2 * a_count
    b = [(nums[offset + 2 * i], nums[offset + 2 * i + 1]) for i in range(b_count)]
    i = j = 0
    ans = 0
    while i < a_count and j < b_count:
        if a[i][0] == b[j][0]:
            ans += a[i][1] * b[j][1]
            i += 1
            j += 1
        elif a[i][0] < b[j][0]:
            i += 1
        else:
            j += 1
    return f"{ans}\n"


REGISTRY: dict[str, ProblemDefinition] = {
    "CSP201604-2": ProblemDefinition("CSP201604-2", cases_201604_2, solve_201604_2),
    "CSP201609-2": ProblemDefinition("CSP201609-2", cases_201609_2, solve_201609_2),
    "CSP201612-2": ProblemDefinition("CSP201612-2", cases_201612_2, solve_201612_2),
    "CSP201703-2": ProblemDefinition("CSP201703-2", cases_201703_2, solve_201703_2),
    "CSP201709-2": ProblemDefinition("CSP201709-2", cases_201709_2, solve_201709_2),
    "CSP201712-2": ProblemDefinition("CSP201712-2", cases_201712_2, solve_201712_2),
    "CSP201803-2": ProblemDefinition("CSP201803-2", cases_201803_2, solve_201803_2),
    "CSP201809-2": ProblemDefinition("CSP201809-2", cases_201809_2, solve_201809_2),
    "CSP201812-2": ProblemDefinition("CSP201812-2", cases_201812_2, solve_201812_2),
    "CSP201903-2": ProblemDefinition("CSP201903-2", cases_201903_2, solve_201903_2),
    "CSP201909-2": ProblemDefinition("CSP201909-2", cases_201909_2, solve_201909_2),
    "CSP201912-2": ProblemDefinition("CSP201912-2", cases_201912_2, solve_201912_2),
    "CSP202006-2": ProblemDefinition("CSP202006-2", cases_202006_2, solve_202006_2),
}
