from __future__ import annotations

from math import cos, isqrt, sin

from . import ProblemDefinition


def _join_lines(values: list[int]) -> str:
    return "\n".join(str(value) for value in values) + "\n"


def _lines(values: list[str]) -> str:
    return "\n".join(values) + ("\n" if values else "")


def cases_201403_1() -> list[str]:
    return [
        "1\n0\n",
        "2\n1 -1\n",
        "5\n1 2 3 4 5\n",
        "6\n-1 1 -2 2 -3 4\n",
        "8\n-10 10 0 5 -5 7 -7 11\n",
        "10\n1 -1 2 -2 3 -3 4 -4 5 -5\n",
        "7\n100 -100 50 -51 51 0 -1\n",
        "9\n-8 -7 -6 6 7 8 9 -9 10\n",
        "4\n123456 -123456 654321 -1\n",
        "12\n1 3 5 7 9 -1 -3 -5 -7 -9 11 -11\n",
    ]


def solve_201403_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    values = nums[1 : 1 + n]
    seen = set(values)
    count = sum(1 for value in values if value > 0 and -value in seen)
    return f"{count}\n"


def cases_201403_2() -> list[str]:
    return [
        "1 1\n0 0 10 10\n5 5\n",
        "2 3\n0 0 5 5\n2 2 8 8\n1 1\n3 3\n9 9\n",
        "3 5\n0 0 2 2\n1 1 3 3\n2 2 4 4\n2 2\n0 0\n4 4\n3 3\n5 5\n",
        "2 4\n-5 -5 0 0\n0 0 5 5\n-3 -3\n0 0\n4 4\n6 6\n",
        "4 6\n0 0 10 10\n1 1 9 9\n2 2 8 8\n3 3 7 7\n4 4\n2 2\n0 0\n11 11\n6 6\n1 1\n",
        "3 4\n0 0 1 1\n2 2 3 3\n4 4 5 5\n2 2\n4 4\n1 1\n6 6\n",
        "5 5\n0 0 100 100\n10 10 20 20\n30 30 40 40\n50 50 60 60\n70 70 80 80\n75 75\n55 55\n35 35\n15 15\n90 90\n",
        "2 5\n0 0 10 1\n0 2 10 3\n5 2\n5 0\n5 3\n5 1\n5 4\n",
        "3 3\n1 1 1 1\n1 1 2 2\n2 2 3 3\n1 1\n2 2\n3 3\n",
        "4 4\n-10 -10 -1 -1\n-5 -5 5 5\n0 0 10 10\n20 20 30 30\n-8 -8\n0 0\n25 25\n15 15\n",
    ]


def solve_201403_2(input_text: str) -> str:
    nums = input_text.split()
    n, m = int(nums[0]), int(nums[1])
    offset = 2
    windows: list[tuple[int, int, int, int, int]] = []
    for i in range(n):
        x1, y1, x2, y2 = map(int, nums[offset : offset + 4])
        offset += 4
        windows.append((i + 1, x1, y1, x2, y2))
    out: list[str] = []
    for _ in range(m):
        x, y = map(int, nums[offset : offset + 2])
        offset += 2
        pos = -1
        for i in range(len(windows) - 1, -1, -1):
            _, x1, y1, x2, y2 = windows[i]
            if x1 <= x <= x2 and y1 <= y <= y2:
                pos = i
                break
        if pos == -1:
            out.append("IGNORED")
        else:
            window = windows.pop(pos)
            windows.append(window)
            out.append(str(window[0]))
    return "\n".join(out) + "\n"


def cases_201403_3() -> list[str]:
    return [
        "ab:c:\n3\ntool -a -b x -c y\ntool -b first -b second -a\ntool -c missing -d tail\n",
        "x:y:z\n4\ncmd -x p -y q -z\ncmd -z -x a\ncmd -x -bad\ncmd arg -x p\n",
        "abc\n3\nrun -a -b -c\nrun -a value -b\nrun -d -a\n",
        "a:b:c:d:\n2\nprog -a one -b two -c three -d four\nprog -a one -a two -b bee stop -c see\n",
        "m:nop:q:\n4\nls -m mm -n -o -p -q qq\nls -q qq -p -m last\nls -n -m\nls -o file -p\n",
        "z:\n3\nt -z abc-123\nt -z\nt --z abc\n",
        "ab\n2\ncmd -a -b -a -b\ncmd -a -c -b\n",
        "h:i:j:k\n3\nmake -h one -i two -j three -k\nmake -k -j value -i\nmake -h -- -k\n",
        "r:s:t:u:v:\n2\nx -v vv -u uu -t tt -s ss -r rr\nx -r a -s b -x bad -t c\n",
        "p:q\n3\ncmd -p val -q\ncmd -q -p val\ncmd -p val extra -q\n",
    ]


def solve_201403_3(input_text: str) -> str:
    lines = input_text.splitlines()
    spec = lines[0].strip()
    accepts: dict[str, bool] = {}
    i = 0
    while i < len(spec):
        ch = spec[i]
        has_arg = i + 1 < len(spec) and spec[i + 1] == ":"
        accepts[ch] = has_arg
        i += 2 if has_arg else 1
    n = int(lines[1])
    out: list[str] = []
    for case_id in range(1, n + 1):
        tokens = lines[case_id + 1].split()
        found: dict[str, str | None] = {}
        pos = 1
        while pos < len(tokens):
            token = tokens[pos]
            if len(token) != 2 or token[0] != "-" or token[1] not in accepts:
                break
            option = token[1]
            if accepts[option]:
                if pos + 1 >= len(tokens):
                    break
                found[option] = tokens[pos + 1]
                pos += 2
            else:
                found[option] = None
                pos += 1
        line = f"Case {case_id}:"
        for option in sorted(found):
            line += f" -{option}"
            if found[option] is not None:
                line += f" {found[option]}"
        out.append(line)
    return "\n".join(out) + "\n"


def cases_201403_4() -> list[str]:
    return [
        "2 1 1 5\n0 0\n10 0\n5 0\n",
        "3 2 1 5\n0 0\n12 0\n4 0\n8 0\n6 0\n",
        "4 3 2 3\n0 0\n9 0\n3 0\n6 0\n2 0\n5 0\n8 0\n",
        "5 2 1 4\n0 0\n10 0\n4 0\n7 0\n10 4\n2 0\n6 0\n",
        "3 3 2 10\n0 0\n30 0\n10 0\n5 0\n20 0\n25 0\n",
        "6 3 1 5\n0 0\n15 0\n5 0\n10 0\n15 5\n20 5\n7 0\n12 0\n3 4\n",
        "4 4 2 6\n0 0\n18 0\n6 0\n12 0\n3 0\n9 0\n15 0\n9 5\n",
        "5 5 3 5\n0 0\n20 0\n4 0\n8 0\n12 0\n16 0\n2 0\n6 0\n10 0\n14 0\n18 0\n",
        "3 1 1 100\n0 0\n1 1\n50 50\n1000 1000\n",
        "7 4 2 4\n0 0\n16 0\n4 0\n8 0\n12 0\n16 4\n20 4\n2 0\n6 0\n10 0\n14 0\n",
    ]


def solve_201403_4(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m, k, r = nums[:4]
    points = []
    offset = 4
    for _ in range(n + m):
        points.append((nums[offset], nums[offset + 1]))
        offset += 2

    def connected(i: int, j: int) -> bool:
        dx = points[i][0] - points[j][0]
        dy = points[i][1] - points[j][1]
        return dx * dx + dy * dy <= r * r

    from collections import deque

    inf = 10**9
    dist = [[inf] * (k + 1) for _ in range(n + m)]
    dist[0][0] = 0
    queue = deque([(0, 0)])
    while queue:
        cur, used = queue.popleft()
        for nxt in range(n + m):
            if cur == nxt or not connected(cur, nxt):
                continue
            next_used = used + (1 if nxt >= n else 0)
            if next_used > k:
                continue
            if dist[nxt][next_used] > dist[cur][used] + 1:
                dist[nxt][next_used] = dist[cur][used] + 1
                queue.append((nxt, next_used))
    hops = min(dist[1])
    return f"{hops - 1}\n"


def cases_201403_5() -> list[str]:
    return [
        "1\n5 4 3 2\n",
        "2\n4 4 2 2\n3 3 3 3\n",
        "3\n2 3 4 5\n6 2 6 2\n3 5 2 4\n",
        "4\n1 2 3 4\n4 3 2 1\n5 5 5 5\n2 4 2 4\n",
        "5\n10 1 10 1\n1 10 1 10\n6 6 3 3\n3 3 6 6\n2 2 2 2\n",
        "6\n2 2 2 2\n2 2 2 2\n2 2 2 2\n2 2 2 2\n2 2 2 2\n2 2 2 2\n",
        "4\n8 5 4 3\n7 6 5 4\n6 4 7 3\n5 3 6 2\n",
        "5\n3 7 2 6\n4 6 3 5\n5 5 4 4\n6 4 5 3\n7 3 6 2\n",
        "3\n9 9 1 1\n9 1 9 1\n1 9 1 9\n",
        "7\n1 10 1 10\n2 9 2 9\n3 8 3 8\n4 7 4 7\n5 6 5 6\n6 5 6 5\n7 4 7 4\n",
    ]


def solve_201403_5(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    tasks = []
    offset = 1
    for _ in range(n):
        a, b, c, d = nums[offset : offset + 4]
        offset += 4
        tasks.append((a, c, min(b, d)))

    inf = 10**9
    dp: dict[tuple[int, int, int], int] = {(0, 0, 0): 0}
    for one_cpu, cpu_gpu, both_cpu in tasks:
        next_dp: dict[tuple[int, int, int], int] = {}

        def relax(state: tuple[int, int, int], value: int) -> None:
            if value < next_dp.get(state, inf):
                next_dp[state] = value

        for (cpu1, cpu2, gpu), serial_time in dp.items():
            relax((cpu1, cpu2, gpu), serial_time + both_cpu)
            relax((cpu1 + one_cpu, cpu2, gpu), serial_time)
            relax((cpu1, cpu2 + one_cpu, gpu), serial_time)
            relax((cpu1 + cpu_gpu, cpu2, gpu + cpu_gpu), serial_time)
            relax((cpu1, cpu2 + cpu_gpu, gpu + cpu_gpu), serial_time)
        dp = next_dp
    ans = min(serial + max(cpu1, cpu2, gpu) for (cpu1, cpu2, gpu), serial in dp.items())
    return f"{ans}\n"


def cases_201412_1() -> list[str]:
    return [
        "1\n1\n",
        "5\n1 2 1 3 2\n",
        "8\n1 1 1 1 1 1 1 1\n",
        "10\n1 2 3 4 5 1 2 3 4 5\n",
        "12\n3 3 2 2 1 1 3 2 1 3 2 1\n",
        "6\n6 5 4 3 2 1\n",
        "9\n2 4 2 4 2 4 2 4 2\n",
        "7\n7 7 6 6 7 6 7\n",
        "10\n10 9 10 9 8 8 8 10 9 8\n",
        "15\n1 2 3 1 2 3 1 2 3 1 2 3 1 2 3\n",
    ]


def solve_201412_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    counts: dict[int, int] = {}
    out: list[int] = []
    for value in nums[1 : 1 + n]:
        counts[value] = counts.get(value, 0) + 1
        out.append(counts[value])
    return _join_lines(out).replace("\n", " ").rstrip() + "\n"


def cases_201412_2() -> list[str]:
    return [
        "1\n42\n",
        "2\n1 2\n3 4\n",
        "3\n1 2 3\n4 5 6\n7 8 9\n",
        "4\n1 5 3 9\n3 7 5 6\n9 4 6 4\n7 3 1 3\n",
        "5\n1 2 3 4 5\n6 7 8 9 10\n11 12 13 14 15\n16 17 18 19 20\n21 22 23 24 25\n",
        "3\n9 8 7\n6 5 4\n3 2 1\n",
        "4\n10 20 30 40\n50 60 70 80\n90 100 110 120\n130 140 150 160\n",
        "6\n1 1 1 1 1 1\n2 2 2 2 2 2\n3 3 3 3 3 3\n4 4 4 4 4 4\n5 5 5 5 5 5\n6 6 6 6 6 6\n",
        "2\n1000 999\n998 997\n",
        "7\n1 2 3 4 5 6 7\n8 9 10 11 12 13 14\n15 16 17 18 19 20 21\n22 23 24 25 26 27 28\n29 30 31 32 33 34 35\n36 37 38 39 40 41 42\n43 44 45 46 47 48 49\n",
    ]


def solve_201412_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    matrix = [nums[1 + i * n : 1 + (i + 1) * n] for i in range(n)]
    out: list[int] = []
    for s in range(2 * n - 1):
        cells = [(i, s - i) for i in range(n) if 0 <= s - i < n]
        if s % 2 == 0:
            cells.reverse()
        out.extend(matrix[i][j] for i, j in cells)
    return " ".join(map(str, out)) + "\n"


def cases_201412_3() -> list[str]:
    return [
        "buy 1.00 100\nsell 1.00 50\n",
        "buy 10.00 100\nbuy 9.50 200\nsell 9.00 150\nsell 10.50 100\n",
        "buy 9.25 100\nbuy 8.88 175\nsell 9.00 1000\nbuy 9.00 400\nsell 8.92 400\ncancel 1\nbuy 100.00 50\n",
        "buy 1.00 10\nbuy 2.00 10\nsell 1.50 15\ncancel 2\nsell 0.90 5\n",
        "sell 5.00 100\nbuy 4.00 100\nbuy 6.00 50\ncancel 1\nsell 5.50 60\n",
        "buy 3.10 100\nbuy 3.10 200\nsell 3.10 250\nsell 3.20 50\n",
        "buy 1.01 1\nsell 1.01 1\ncancel 2\nsell 1.00 10\n",
        "buy 99.99 100000000\nsell 99.98 1\nsell 100.00 100000000\n",
        "buy 2.00 100\nsell 1.00 100\ncancel 1\nbuy 1.50 50\n",
        "buy 8.00 30\nsell 7.00 10\nsell 8.00 20\nbuy 7.50 15\ncancel 3\nsell 7.40 50\n",
    ]


def solve_201412_3(input_text: str) -> str:
    records = [line.split() for line in input_text.splitlines() if line.strip()]
    canceled = [False] * len(records)
    for idx, parts in enumerate(records):
        if parts[0] == "cancel":
            target = int(parts[1]) - 1
            if 0 <= target < len(records):
                canceled[target] = True
            canceled[idx] = True
    active = []
    for idx, parts in enumerate(records):
        if canceled[idx] or parts[0] == "cancel":
            continue
        whole, cents = parts[1].split(".")
        price = int(whole) * 100 + int(cents)
        active.append((parts[0], price, int(parts[2])))
    best_price = 0
    best_volume = -1
    for price in sorted({price for _, price, _ in active}):
        buy = sum(amount for side, p, amount in active if side == "buy" and p >= price)
        sell = sum(amount for side, p, amount in active if side == "sell" and p <= price)
        volume = min(buy, sell)
        if volume > best_volume or (volume == best_volume and price > best_price):
            best_price = price
            best_volume = volume
    if best_volume < 0:
        best_volume = 0
    return f"{best_price // 100}.{best_price % 100:02d} {best_volume}\n"


def cases_201412_4() -> list[str]:
    return [
        "2 1\n1 2 5\n",
        "3 3\n1 2 1\n2 3 2\n1 3 5\n",
        "4 4\n1 2 1\n2 3 4\n2 4 2\n3 4 3\n",
        "5 7\n1 2 10\n1 3 5\n2 3 2\n2 4 7\n3 4 3\n3 5 8\n4 5 1\n",
        "6 8\n1 2 3\n1 3 1\n2 3 2\n2 4 4\n3 5 6\n4 5 5\n4 6 7\n5 6 2\n",
        "4 6\n1 2 9\n1 3 8\n1 4 7\n2 3 6\n2 4 5\n3 4 4\n",
        "7 9\n1 2 1\n2 3 1\n3 4 1\n4 5 1\n5 6 1\n6 7 1\n1 7 10\n2 6 8\n3 5 6\n",
        "5 4\n1 2 4\n2 3 4\n3 4 4\n4 5 4\n",
        "8 10\n1 2 5\n1 3 3\n2 4 6\n3 4 2\n4 5 7\n5 6 1\n6 7 9\n7 8 4\n2 8 20\n3 6 8\n",
        "3 2\n1 2 10000\n2 3 9999\n",
    ]


def solve_201412_4(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m = nums[:2]
    edges = []
    offset = 2
    for _ in range(m):
        a, b, c = nums[offset : offset + 3]
        offset += 3
        edges.append((c, a - 1, b - 1))
    parent = list(range(n))

    def find(x: int) -> int:
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x

    total = 0
    for cost, a, b in sorted(edges):
        ra, rb = find(a), find(b)
        if ra != rb:
            parent[ra] = rb
            total += cost
    return f"{total}\n"


def cases_201409_1() -> list[str]:
    return [
        "1\n42\n",
        "2\n1 2\n",
        "3\n1 3 5\n",
        "5\n1 2 3 4 5\n",
        "6\n10 8 9 20 21 22\n",
        "8\n-3 -2 -1 0 1 2 3 4\n",
        "7\n100 99 97 96 95 50 51\n",
        "10\n1 10 2 9 3 8 4 7 5 6\n",
        "6\n-10 10 -9 9 -8 8\n",
        "12\n30 31 33 34 36 37 39 40 42 43 45 46\n",
    ]


def solve_201409_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    values = nums[1 : 1 + n]
    values.sort()
    count = sum(1 for i in range(1, n) if values[i] - values[i - 1] == 1)
    return f"{count}\n"


def cases_201409_2() -> list[str]:
    return [
        "1\n0 0 1 1\n",
        "2\n0 0 2 2\n1 1 3 3\n",
        "3\n0 0 10 10\n2 2 4 4\n5 5 8 8\n",
        "4\n1 1 4 4\n4 4 8 8\n0 0 2 5\n6 1 9 3\n",
        "5\n0 0 100 100\n10 10 20 20\n30 30 40 40\n50 50 60 60\n70 70 80 80\n",
        "3\n0 0 5 1\n0 1 5 2\n0 2 5 3\n",
        "6\n1 1 2 2\n2 2 3 3\n3 3 4 4\n4 4 5 5\n5 5 6 6\n6 6 7 7\n",
        "2\n10 10 20 30\n15 0 25 15\n",
        "4\n0 0 50 50\n25 25 75 75\n50 50 100 100\n0 50 50 100\n",
        "8\n0 0 10 10\n1 1 9 9\n2 2 8 8\n3 3 7 7\n4 4 6 6\n10 10 20 20\n15 15 25 25\n20 20 30 30\n",
    ]


def solve_201409_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    painted = [[False] * 101 for _ in range(101)]
    offset = 1
    for _ in range(n):
        x1, y1, x2, y2 = nums[offset : offset + 4]
        offset += 4
        for x in range(x1, x2):
            for y in range(y1, y2):
                painted[x][y] = True
    return f"{sum(cell for row in painted for cell in row)}\n"


def cases_201409_3() -> list[str]:
    return [
        "Hello\n1\n3\nHelloWorld\nHELLO\nSayHello\n",
        "abc\n0\n4\nABC\nxxabcxx\nabx\nAABBCC\n",
        "Aa\n1\n5\nAa\naa\nAaaA\nbAa\nAA\n",
        "test\n0\n5\ncontest\nTesting\nTES\nthisisatest\nTEstCase\n",
        "Z\n1\n4\nZ\nz\nabcZdef\nabc\n",
        "long\n0\n3\nshort\nLoNgString\nlllonnng\n",
        "Case\n1\n5\ncase\nCase\nMyCaseHere\nCASE\nNoMatch\n",
        "xyZ\n0\n4\nxyz\nXYz\nxYzz\nxy\n",
        "a\n0\n5\nA\nb\nabc\nCBA\nzzz\n",
        "Pattern\n1\n4\nPatternPattern\npattern\nPat\nxPatternx\n",
    ]


def solve_201409_3(input_text: str) -> str:
    lines = input_text.splitlines()
    pattern = lines[0]
    sensitive = int(lines[1]) == 1
    n = int(lines[2])
    query = pattern if sensitive else pattern.lower()
    out: list[str] = []
    for line in lines[3 : 3 + n]:
        target = line if sensitive else line.lower()
        if query in target:
            out.append(line)
    return "\n".join(out) + ("\n" if out else "")


def cases_201409_4() -> list[str]:
    return [
        "3 1 1 0\n1 1\n3 3 2\n",
        "5 1 2 0\n1 1\n5 5 1\n3 3 2\n",
        "5 2 3 1\n1 1\n5 5\n1 5 1\n3 3 2\n5 1 3\n3 2\n",
        "6 1 3 3\n1 1\n6 6 1\n1 6 2\n4 4 3\n2 1\n2 2\n2 3\n",
        "8 2 4 2\n1 1\n8 8\n2 2 5\n7 7 6\n1 8 1\n8 1 1\n4 4\n5 5\n",
        "10 3 5 4\n1 1\n10 10\n5 5\n2 2 1\n9 9 2\n5 8 3\n8 5 4\n3 7 5\n4 4\n4 5\n4 6\n6 6\n",
        "4 1 2 2\n1 4\n4 1 2\n2 2 3\n2 4\n3 4\n",
        "7 2 4 0\n1 7\n7 1\n4 4 10\n1 1 1\n7 7 1\n3 5 2\n",
        "9 1 3 5\n5 5\n1 1 1\n9 9 1\n5 9 2\n5 6\n5 7\n4 7\n6 7\n7 7\n",
        "6 2 3 4\n1 1\n6 6\n2 5 2\n5 2 2\n3 3 5\n2 2\n2 3\n3 2\n4 4\n",
    ]


def solve_201409_4(input_text: str) -> str:
    from collections import deque

    nums = list(map(int, input_text.split()))
    n, m, k, d = nums[:4]
    offset = 4
    stores = []
    for _ in range(m):
        stores.append((nums[offset], nums[offset + 1]))
        offset += 2
    customers = []
    for _ in range(k):
        customers.append((nums[offset], nums[offset + 1], nums[offset + 2]))
        offset += 3
    blocked = [[False] * (n + 1) for _ in range(n + 1)]
    for _ in range(d):
        x, y = nums[offset], nums[offset + 1]
        offset += 2
        blocked[x][y] = True
    dist = [[-1] * (n + 1) for _ in range(n + 1)]
    queue = deque()
    for x, y in stores:
        dist[x][y] = 0
        queue.append((x, y))
    while queue:
        x, y = queue.popleft()
        for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            nx, ny = x + dx, y + dy
            if 1 <= nx <= n and 1 <= ny <= n and not blocked[nx][ny] and dist[nx][ny] == -1:
                dist[nx][ny] = dist[x][y] + 1
                queue.append((nx, ny))
    total = sum(dist[x][y] * demand for x, y, demand in customers)
    return f"{total}\n"


MOD = 1_000_000_007


def _tiling_transitions(width: int) -> list[list[int]]:
    size = 1 << width
    matrix = [[0] * size for _ in range(size)]
    shapes = (
        ((0, 0), (1, 0), (1, 1)),
        ((0, 1), (1, 0), (1, 1)),
        ((0, 0), (0, 1), (1, 0)),
        ((0, 0), (0, 1), (1, 1)),
    )

    def dfs(start_mask: int, cur_mask: int, next_mask: int) -> None:
        first = -1
        for col in range(width):
            if not (cur_mask >> col) & 1:
                first = col
                break
        if first == -1:
            matrix[start_mask][next_mask] = (matrix[start_mask][next_mask] + 1) % MOD
            return
        for shape in shapes:
            for anchor_row, anchor_col in shape:
                base_col = first - anchor_col
                cells = [(row - anchor_row, col + base_col) for row, col in shape]
                ok = True
                new_cur = cur_mask
                new_next = next_mask
                for row, col in cells:
                    if col < 0 or col >= width or row < 0 or row > 1:
                        ok = False
                        break
                    if row == 0:
                        if (new_cur >> col) & 1:
                            ok = False
                            break
                        new_cur |= 1 << col
                    else:
                        if (new_next >> col) & 1:
                            ok = False
                            break
                        new_next |= 1 << col
                if ok:
                    dfs(start_mask, new_cur, new_next)

    for mask in range(size):
        dfs(mask, mask, 0)
    return matrix


def _mat_mul(a: list[list[int]], b: list[list[int]]) -> list[list[int]]:
    n = len(a)
    result = [[0] * n for _ in range(n)]
    for i in range(n):
        for k in range(n):
            if a[i][k] == 0:
                continue
            aik = a[i][k]
            for j in range(n):
                if b[k][j]:
                    result[i][j] = (result[i][j] + aik * b[k][j]) % MOD
    return result


def _tiling_count(rows: int, cols: int) -> int:
    trans = _tiling_transitions(cols)
    size = 1 << cols
    result = [[0] * size for _ in range(size)]
    for i in range(size):
        result[i][i] = 1
    power = trans
    exp = rows
    while exp:
        if exp & 1:
            result = _mat_mul(result, power)
        power = _mat_mul(power, power)
        exp >>= 1
    return result[0][0]


def cases_201409_5() -> list[str]:
    return [
        "1 1\n",
        "2 2\n",
        "2 3\n",
        "3 2\n",
        "3 3\n",
        "4 3\n",
        "5 3\n",
        "4 4\n",
        "10 2\n",
        "12 5\n",
    ]


def solve_201409_5(input_text: str) -> str:
    n, m = map(int, input_text.split())
    if m > n:
        n, m = m, n
    return f"{_tiling_count(n, m)}\n"


def cases_201509_1() -> list[str]:
    return [
        "1\n5\n",
        "5\n1 1 1 1 1\n",
        "5\n1 2 3 4 5\n",
        "6\n1 1 2 2 3 3\n",
        "8\n3 3 3 2 2 1 1 1\n",
        "10\n1 2 2 2 3 3 2 2 1 1\n",
        "7\n100 100 101 101 101 100 99\n",
        "12\n1 1 2 1 1 3 3 3 2 2 2 1\n",
        "9\n5 4 4 4 5 5 6 6 5\n",
        "15\n1 1 1 2 2 3 4 4 4 4 3 3 2 2 1\n",
    ]


def solve_201509_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    values = nums[1 : 1 + n]
    if not values:
        return "0\n"
    segments = 1
    for i in range(1, n):
        if values[i] != values[i - 1]:
            segments += 1
    return f"{segments}\n"


def cases_201604_1() -> list[str]:
    return [
        "1\n5\n",
        "2\n10 20\n",
        "3\n1 3 2\n",
        "3\n3 2 1\n",
        "5\n1 3 2 4 3\n",
        "6\n6 1 5 2 4 3\n",
        "8\n10 20 30 25 15 18 12 9\n",
        "10\n1 4 2 5 3 6 4 7 5 8\n",
        "20\n" + " ".join(str((i * 37) % 10001) for i in range(20)) + "\n",
        "1000\n" + " ".join(str((i * 97) % 10001) for i in range(1000)) + "\n",
    ]


def solve_201604_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    values = nums[1 : 1 + n]
    ans = 0
    for i in range(1, n - 1):
        if (values[i] > values[i - 1] and values[i] > values[i + 1]) or (
            values[i] < values[i - 1] and values[i] < values[i + 1]
        ):
            ans += 1
    return f"{ans}\n"


def cases_201609_1() -> list[str]:
    return [
        "2\n1 1\n",
        "2\n1 10000\n",
        "3\n3 8 2\n",
        "5\n10 10 10 10 10\n",
        "6\n9 1 9 1 9 1\n",
        "8\n100 200 50 50 300 1 2 999\n",
        "10\n1 2 4 8 16 32 64 128 256 512\n",
        "20\n" + " ".join(str((i * i) % 10000 + 1) for i in range(20)) + "\n",
        "100\n" + " ".join(str((i * 37) % 10000 + 1) for i in range(100)) + "\n",
        "1000\n" + " ".join(str((i * 7919) % 10000 + 1) for i in range(1000)) + "\n",
    ]


def solve_201609_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    values = nums[1 : 1 + n]
    ans = 0
    for i in range(1, n):
        ans = max(ans, abs(values[i] - values[i - 1]))
    return f"{ans}\n"


def cases_201612_1() -> list[str]:
    return [
        "1\n42\n",
        "3\n1 2 3\n",
        "5\n1 1 2 3 3\n",
        "4\n1 2 2 3\n",
        "4\n1 2 3 4\n",
        "7\n10 10 20 30 40 40 40\n",
        "8\n5 5 6 7 8 9 9 9\n",
        "9\n1000 1 500 500 2 999 3 998 4\n",
        "20\n1 1 1 2 2 3 3 4 4 5 6 6 7 7 8 8 9 9 10 10\n",
        "1000\n" + " ".join(str((i % 100) + 1) for i in range(1000)) + "\n",
    ]


def solve_201612_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    values = nums[1 : 1 + n]
    counts = [0] * 1001
    for value in values:
        counts[value] += 1

    less = 0
    for candidate in range(1, 1001):
        if counts[candidate] == 0:
            continue
        greater = n - less - counts[candidate]
        if less == greater:
            return f"{candidate}\n"
        less += counts[candidate]
    return "-1\n"


def cases_201703_1() -> list[str]:
    return [
        "1 10\n5\n",
        "1 10\n10\n",
        "3 5\n1 1 1\n",
        "5 3\n1 2 3 1 1\n",
        "6 10\n2 6 5 6 3 5\n",
        "8 9\n9 1 8 2 7 3 6 4\n",
        "10 100\n" + " ".join(["10"] * 10) + "\n",
        "20 50\n" + " ".join(str((i * 17) % 100 + 1) for i in range(20)) + "\n",
        "100 10000\n" + " ".join(["1000"] * 100) + "\n",
        "1000 10000\n" + " ".join(str(i % 1000 + 1) for i in range(1000)) + "\n",
    ]


def solve_201703_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, k = nums[:2]
    weights = nums[2 : 2 + n]
    friends = 0
    current = 0
    for weight in weights:
        current += weight
        if current >= k:
            friends += 1
            current = 0
    if current > 0:
        friends += 1
    return f"{friends}\n"


def cases_201709_1() -> list[str]:
    return [
        "10\n",
        "20\n",
        "30\n",
        "50\n",
        "60\n",
        "70\n",
        "90\n",
        "100\n",
        "290\n",
        "300\n",
    ]


def solve_201709_1(input_text: str) -> str:
    money = int(input_text.strip())
    paid_bottles = money // 10
    answer = paid_bottles // 5 * 7
    paid_bottles %= 5
    answer += paid_bottles // 3 * 4 + paid_bottles % 3
    return f"{answer}\n"


def cases_201712_1() -> list[str]:
    return [
        "2\n1 2\n",
        "2\n7 7\n",
        "5\n1 2 10 20 30\n",
        "5\n10 1 100 10000 5000\n",
        "6\n6 3 9 12 15 18\n",
        "7\n100 50 51 200 300 400 500\n",
        "8\n10000 9999 1 2 3 8000 7000 6000\n",
        "10\n5 5 6 7 8 100 200 300 400 500\n",
        "20\n" + " ".join(str(i * 37 + 11) for i in range(20)) + "\n",
        "1000\n" + " ".join(str(i + 1) for i in range(1000)) + "\n",
    ]


def solve_201712_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    values = nums[1 : 1 + n]
    seen = [False] * 10001
    has_duplicate = False
    for value in values:
        if seen[value]:
            has_duplicate = True
        seen[value] = True

    if has_duplicate:
        return "0\n"

    previous = -1
    answer = 10001
    for value in range(1, 10001):
        if not seen[value]:
            continue
        if previous != -1:
            answer = min(answer, value - previous)
        previous = value
    return f"{answer}\n"


def cases_201803_1() -> list[str]:
    return [
        "0\n",
        "1 0\n",
        "2 0\n",
        "1 2 0\n",
        "2 2 2 0\n",
        "1 2 1 2 2 0\n",
        "2 1 2 2 1 2 0\n",
        "1 1 1 1 1 0\n",
        "2 2 1 2 2 2 1 0\n",
        " ".join(str(2 if i % 3 else 1) for i in range(29)) + " 0\n",
    ]


def solve_201803_1(input_text: str) -> str:
    total = 0
    center_score = 0
    for value in map(int, input_text.split()):
        if value == 0:
            break
        if value == 1:
            total += 1
            center_score = 0
        else:
            center_score += 2
            total += center_score
    return f"{total}\n"


def cases_201809_1() -> list[str]:
    def build(values: list[int]) -> str:
        return f"{len(values)}\n" + " ".join(map(str, values)) + "\n"

    return [
        build([1, 3]),
        build([10, 10, 10]),
        build([1, 100, 1]),
        build([5, 6, 7, 8]),
        build([9, 1, 9, 1, 9]),
        build([10000, 1, 10000, 1, 10000, 1]),
        build([3, 8, 2, 6, 4, 10, 12, 14]),
        build([(i * i) % 100 + 1 for i in range(20)]),
        build([(i * 37) % 10000 + 1 for i in range(100)]),
        build([(i * 7919) % 10000 + 1 for i in range(1000)]),
    ]


def solve_201809_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    values = nums[1 : 1 + n]
    answer = []
    for index in range(n):
        if index == 0:
            answer.append((values[0] + values[1]) // 2)
        elif index == n - 1:
            answer.append((values[n - 2] + values[n - 1]) // 2)
        else:
            answer.append((values[index - 1] + values[index] + values[index + 1]) // 3)
    return " ".join(map(str, answer)) + "\n"


def cases_201812_1() -> list[str]:
    def build(r: int, y: int, g: int, events: list[tuple[int, int]]) -> str:
        return f"{r} {y} {g}\n{len(events)}\n" + "".join(f"{k} {t}\n" for k, t in events)

    return [
        build(30, 3, 30, [(0, 5)]),
        build(30, 3, 30, [(1, 10)]),
        build(30, 3, 30, [(2, 2)]),
        build(30, 3, 30, [(3, 8)]),
        build(10, 5, 10, [(0, 3), (1, 4), (0, 6)]),
        build(20, 4, 15, [(0, 7), (2, 3), (3, 5), (1, 6)]),
        build(100, 20, 80, [(2, 20), (0, 30), (1, 40), (3, 10), (0, 50)]),
        build(7, 3, 5, [(i % 4, (i * 2) % 7 + 1) for i in range(1, 21)]),
        build(1000000, 1000000, 1000000, [(0, 1000000), (1, 999999), (2, 888888), (3, 777777)]),
        build(
            1000000,
            999999,
            888888,
            [
                (0, 1000000) if i % 4 == 0
                else (1, 1000000 - i)
                if i % 4 == 1
                else (2, 999999 - i)
                if i % 4 == 2
                else (3, 888888 - i)
                for i in range(100)
            ],
        ),
    ]


def solve_201812_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    r, y, _g = nums[:3]
    n = nums[3]
    total = 0
    offset = 4
    for _ in range(n):
        k, t = nums[offset], nums[offset + 1]
        offset += 2
        if k == 0 or k == 1:
            total += t
        elif k == 2:
            total += t + r
    return f"{total}\n"


def cases_201903_1() -> list[str]:
    def build(values: list[int]) -> str:
        return f"{len(values)}\n" + " ".join(map(str, values)) + "\n"

    return [
        build([5]),
        build([1, 2]),
        build([2, 2, 2]),
        build([9, 7, 5, 3]),
        build([-5, -2, 0, 3, 8]),
        build([-3, -1, 2, 4]),
        build([10, 8, 8, 4, 1]),
        build([i - 50 for i in range(101)]),
        build([1000 - i for i in range(1000)]),
        build([i * 2 - 100000 for i in range(100000)]),
    ]


def solve_201903_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    values = nums[1 : 1 + n]
    maximum = max(values[0], values[-1])
    minimum = min(values[0], values[-1])
    if n % 2 == 1:
        twice_median = values[n // 2] * 2
    else:
        twice_median = values[n // 2 - 1] + values[n // 2]
    if twice_median % 2 == 0:
        median = str(twice_median // 2)
    else:
        median = f"{twice_median / 2:.1f}"
    return f"{maximum} {median} {minimum}\n"


def cases_201909_1() -> list[str]:
    def build(rows: list[list[int]]) -> str:
        return f"{len(rows)} {len(rows[0]) - 1}\n" + "\n".join(" ".join(map(str, row)) for row in rows) + "\n"

    small_large = [[100, -10, -5], [120, -4, -20], [90, 0, -1]]
    large_rows = []
    for i in range(1000):
        removals = [-1] * 1000
        if i % 10 == 0:
            removals[0] = -5
        large_rows.append([1000000] + removals)

    return [
        build([[10, 0]]),
        build([[10, -1], [20, -2]]),
        build([[30, -5, 0], [40, -3, -4]]),
        build([[50, 0, 0, 0], [60, -1, -2, -3], [70, -5, 0, -1]]),
        build(small_large),
        build([[1000] + [-10] * 10 for _ in range(10)]),
        build([[10000] + [-((i + j) % 20) for j in range(10)] for i in range(100)]),
        build([[100000] + [-(j % 7) for j in range(100)] for _ in range(10)]),
        build([[500000] + [-(j % 5) for j in range(100)] for _ in range(100)]),
        build(large_rows),
    ]


def solve_201909_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m = nums[:2]
    offset = 2
    total = 0
    best_index = 1
    best_removed = -1
    for index in range(1, n + 1):
        current = nums[offset]
        offset += 1
        removed = 0
        for _ in range(m):
            delta = nums[offset]
            offset += 1
            current += delta
            removed -= delta
        total += current
        if removed > best_removed:
            best_removed = removed
            best_index = index
    return f"{total} {best_index} {best_removed}\n"


def _contains_digit_seven(value: int) -> bool:
    return "7" in str(value)


def cases_201912_1() -> list[str]:
    return [f"{value}\n" for value in [1, 2, 7, 8, 19, 30, 50, 100, 200, 666]]


def solve_201912_1(input_text: str) -> str:
    target = int(input_text.strip())
    skipped = [0, 0, 0, 0]
    reported = 0
    current = 1
    while reported < target:
        player = (current - 1) % 4
        if current % 7 == 0 or _contains_digit_seven(current):
            skipped[player] += 1
        else:
            reported += 1
        current += 1
    return "".join(f"{count}\n" for count in skipped)


def cases_202006_1() -> list[str]:
    def build(points: list[tuple[int, int, str]], queries: list[tuple[int, int, int]]) -> str:
        lines = [f"{len(points)} {len(queries)}"]
        lines.extend(f"{x} {y} {kind}" for x, y, kind in points)
        lines.extend(f"{t0} {t1} {t2}" for t0, t1, t2 in queries)
        return "\n".join(lines) + "\n"

    separated = [(-3, 0, "A"), (-2, 2, "A"), (-1, -3, "A"), (2, 0, "B"), (3, 2, "B"), (4, -1, "B")]
    diagonal = [(0, 0, "A"), (1, 0, "A"), (0, 1, "A"), (4, 4, "B"), (5, 4, "B"), (4, 5, "B")]
    mixed = [(-5, -5, "A"), (-4, 3, "B"), (2, -3, "A"), (5, 6, "B"), (3, 4, "B"), (-2, -1, "A")]
    large_points = []
    for i in range(500):
        large_points.append((-10000 + i, i % 97, "A"))
        large_points.append((10000 - i, -(i % 89), "B"))
    large_queries = [(0, 1, 0), (0, -1, 0), (5, 1, 1), (-5, -1, -1), (1, 0, 1)] * 4

    return [
        build([(-1, 0, "A"), (1, 0, "B")], [(0, 1, 0), (0, 0, 1)]),
        build([(0, -1, "A"), (0, 2, "B"), (2, 0, "A")], [(0, 0, 1), (1, 1, 0)]),
        build(separated, [(0, 1, 0), (1, 0, 1), (0, -1, 0)]),
        build(diagonal, [(-3, 1, 1), (-5, 1, 1), (0, 1, -1)]),
        build(mixed, [(0, 1, -1), (2, 1, 0), (-1, 0, 1)]),
        build([(i, i * 2, "A" if i < 0 else "B") for i in range(-10, 11) if i != 0], [(0, 1, 0), (0, -1, 0)]),
        build([(i, 100 - i, "A") for i in range(10)] + [(i + 100, -i, "B") for i in range(10)], [(50, 1, 0), (-20, 0, 1), (0, 1, 1)]),
        build([(i, i % 11, "A") for i in range(-50, 0)] + [(i, i % 13, "B") for i in range(1, 51)], [(0, 1, 0), (7, 1, -3), (-7, -1, 3), (100, 0, 1)]),
        build([(i, i * i % 101, "A" if i < 100 else "B") for i in range(1, 200)], [(100, -1, 0), (-100, 1, 0), (1, 1, 1), (-1, -1, 1)]),
        build(large_points, large_queries),
    ]


def solve_202006_1(input_text: str) -> str:
    lines = input_text.splitlines()
    n, m = map(int, lines[0].split())
    points: list[tuple[int, int, str]] = []
    for line in lines[1 : 1 + n]:
        x, y, kind = line.split()
        points.append((int(x), int(y), kind))

    out = []
    for line in lines[1 + n : 1 + n + m]:
        t0, t1, t2 = map(int, line.split())
        sign_by_kind: dict[str, int] = {}
        ok = True
        for x, y, kind in points:
            value = t0 + t1 * x + t2 * y
            sign = 1 if value > 0 else -1
            if kind in sign_by_kind and sign_by_kind[kind] != sign:
                ok = False
                break
            sign_by_kind[kind] = sign
        if ok and sign_by_kind.get("A") != sign_by_kind.get("B"):
            out.append("Yes")
        else:
            out.append("No")
    return "\n".join(out) + "\n"


def cases_202009_1() -> list[str]:
    def build(target: tuple[int, int], points: list[tuple[int, int]]) -> str:
        lines = [f"{len(points)} {target[0]} {target[1]}"]
        lines.extend(f"{x} {y}" for x, y in points)
        return "\n".join(lines) + "\n"

    return [
        build((0, 0), [(1, 0), (0, 1), (2, 0)]),
        build((5, 5), [(5, 4), (4, 5), (6, 5), (5, 6)]),
        build((-1, -1), [(-2, -1), (-1, -3), (0, 0), (5, 5), (-1, 0)]),
        build((10, -10), [(10, -9), (11, -10), (9, -10), (10, -11), (20, 20)]),
        build((0, 1), [(-2, 1), (2, 1), (0, -1), (0, 3), (3, 4), (-3, 4)]),
        build((1000, -1000), [(999, -999), (1000, -999), (999, -1000), (-1000, 1000), (0, 0)]),
        build((12, 34), [(i, 34 + (i % 5)) for i in range(-20, 30)]),
        build((0, 0), [(i, i * i % 97 - 48) for i in range(-70, 70)]),
        build((500, 500), [((i * 37) % 2001 - 1000, (i * 91) % 2001 - 1000) for i in range(180)]),
        build((-321, 654), [((i * 73) % 2001 - 1000, (i * 41) % 2001 - 1000) for i in range(200)]),
    ]


def solve_202009_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, target_x, target_y = nums[:3]
    best: list[tuple[int, int]] = []
    offset = 3
    for index in range(1, n + 1):
        x, y = nums[offset], nums[offset + 1]
        offset += 2
        distance = (x - target_x) ** 2 + (y - target_y) ** 2
        candidate = (distance, index)
        best.append(candidate)
        best.sort()
        if len(best) > 3:
            best.pop()
    return "".join(f"{index}\n" for _distance, index in best)


def cases_202012_1() -> list[str]:
    def build(entries: list[tuple[int, int]]) -> str:
        return f"{len(entries)}\n" + "".join(f"{w} {score}\n" for w, score in entries)

    large = []
    for i in range(100000):
        if i % 3 == 0:
            large.append((10, 100))
        elif i % 3 == 1:
            large.append((-10, 99))
        else:
            large.append((i % 11 - 5, i % 101))

    return [
        build([(1, 100), (2, 50)]),
        build([(-1, 20), (-2, 30), (0, 100)]),
        build([(10, 10), (-5, 20), (3, 30), (-1, 40)]),
        build([(0, 0), (0, 100), (1, 1), (-1, 1), (10, 0)]),
        build([(10, 100), (10, 99), (-10, 100), (1, 50), (-2, 25), (3, 3)]),
        build([(-10, 100), (-10, 100), (10, 1), (9, 2), (8, 3), (7, 4)]),
        build([(i % 21 - 10, (i * 7) % 101) for i in range(50)]),
        build([(10 if i % 2 == 0 else -9, 100 if i % 5 else 0) for i in range(200)]),
        build([(-10 if i < 400 else 10, i % 101) for i in range(800)]),
        build(large),
    ]


def solve_202012_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    total = 0
    offset = 1
    for _ in range(n):
        w, score = nums[offset], nums[offset + 1]
        offset += 2
        total += w * score
    return f"{max(0, total)}\n"


def cases_202104_1() -> list[str]:
    def build(n: int, m: int, limit: int, values: list[int]) -> str:
        rows = [
            " ".join(str(values[i * m + j]) for j in range(m))
            for i in range(n)
        ]
        return f"{n} {m} {limit}\n" + "\n".join(rows) + "\n"

    return [
        build(1, 1, 4, [2]),
        build(2, 3, 5, [0, 1, 2, 3, 4, 0]),
        build(3, 4, 8, [(i + j) % 8 for i in range(3) for j in range(4)]),
        build(4, 5, 16, [(i * 5 + j) % 16 for i in range(4) for j in range(5)]),
        build(5, 5, 10, [7 for _ in range(25)]),
        build(6, 7, 12, [(i * i + j * 3) % 12 for i in range(6) for j in range(7)]),
        build(10, 10, 4, [(i + 2 * j) % 4 for i in range(10) for j in range(10)]),
        build(12, 9, 20, [(i * 11 + j * 13) % 20 for i in range(12) for j in range(9)]),
        build(16, 16, 256, [i * 16 + j for i in range(16) for j in range(16)]),
        build(500, 500, 256, [(i * 17 + j * 31) % 256 for i in range(500) for j in range(500)]),
    ]


def solve_202104_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m, limit = nums[:3]
    counts = [0] * limit
    for value in nums[3 : 3 + n * m]:
        counts[value] += 1
    return " ".join(map(str, counts)) + "\n"


def cases_202104_2() -> list[str]:
    def build(n: int, limit: int, radius: int, threshold: int, values: list[int]) -> str:
        rows = [
            " ".join(str(values[i * n + j]) for j in range(n))
            for i in range(n)
        ]
        return f"{n} {limit} {radius} {threshold}\n" + "\n".join(rows) + "\n"

    return [
        build(1, 8, 1, 3, [2]),
        build(2, 16, 1, 5, [0, 10, 10, 0]),
        build(3, 20, 1, 8, [i * 3 % 20 for i in range(9)]),
        build(5, 32, 2, 10, [(i + j * 2) % 32 for i in range(5) for j in range(5)]),
        build(6, 64, 1, 20, [5 if (i + j) % 2 else 40 for i in range(6) for j in range(6)]),
        build(10, 128, 3, 50, [(i * i + j * 7) % 128 for i in range(10) for j in range(10)]),
        build(30, 256, 5, 90, [(i * 13 + j * 17) % 256 for i in range(30) for j in range(30)]),
        build(80, 256, 10, 100, [(i * 31 + j * 19) % 256 for i in range(80) for j in range(80)]),
        build(120, 256, 100, 120, [(i + j) % 256 for i in range(120) for j in range(120)]),
        build(600, 256, 100, 100, [(i * 17 + j * 29) % 256 for i in range(600) for j in range(600)]),
    ]


def solve_202104_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, _limit, radius, threshold = nums[:4]
    values = nums[4 : 4 + n * n]
    prefix = [[0] * (n + 1) for _ in range(n + 1)]
    for i in range(n):
        row_sum = 0
        for j in range(n):
            row_sum += values[i * n + j]
            prefix[i + 1][j + 1] = prefix[i][j + 1] + row_sum

    ans = 0
    for i in range(n):
        x1 = max(0, i - radius)
        x2 = min(n - 1, i + radius)
        for j in range(n):
            y1 = max(0, j - radius)
            y2 = min(n - 1, j + radius)
            total = prefix[x2 + 1][y2 + 1] - prefix[x1][y2 + 1] - prefix[x2 + 1][y1] + prefix[x1][y1]
            area = (x2 - x1 + 1) * (y2 - y1 + 1)
            if total <= threshold * area:
                ans += 1
    return f"{ans}\n"


def cases_202109_1() -> list[str]:
    return [
        "1\n0\n",
        "1\n7\n",
        "5\n1 2 3 4 5\n",
        "6\n0 0 1 1 1 2\n",
        "6\n5 5 5 5 5 5\n",
        "8\n0 3 3 4 8 8 8 10\n",
        "10\n2 2 4 4 4 9 9 10 10 10\n",
        "12\n0 0 0 100 100 101 101 101 500 500 999 1000\n",
        "100\n" + " ".join(str((i // 4) * 37) for i in range(100)) + "\n",
        "100\n" + " ".join(str((i + 1) * 1000) for i in range(100)) + "\n",
    ]


def solve_202109_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    values = nums[1 : 1 + n]
    max_sum = sum(values)
    min_sum = 0
    previous = -1
    for value in values:
        if value > previous:
            min_sum += value
        previous = value
    return f"{max_sum}\n{min_sum}\n"


def cases_202112_1() -> list[str]:
    def build(limit: int, values: list[int]) -> str:
        return f"{len(values)} {limit}\n" + " ".join(map(str, values)) + "\n"

    return [
        build(5, [1]),
        build(8, [2, 6]),
        build(12, [1, 4, 9]),
        build(20, [3, 5, 10, 11, 18]),
        build(100, [10, 20, 30, 40, 50]),
        build(1000, [7, 19, 101, 333, 777, 999]),
        build(10000, [i * 37 for i in range(1, 101)]),
        build(100000, [i * 499 for i in range(1, 200)]),
        build(10000000, [i * 40000 + 123 for i in range(1, 200)]),
        build(10000000, [i * 49999 for i in range(1, 201)]),
    ]


def solve_202112_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, limit = nums[:2]
    values = [0] + nums[2 : 2 + n] + [limit]
    ans = 0
    for i in range(n + 1):
        ans += i * (values[i + 1] - values[i])
    return f"{ans}\n"


def cases_202112_2() -> list[str]:
    def build(limit: int, values: list[int]) -> str:
        return f"{len(values)} {limit}\n" + " ".join(map(str, values)) + "\n"

    return [
        build(6, [2]),
        build(11, [1, 4]),
        build(20, [2, 9, 15]),
        build(100, [5, 6, 40, 80]),
        build(1000, [10, 200, 201, 800, 900]),
        build(100000, [i * 997 for i in range(1, 100)]),
        build(10000000, [i * 40000 + (i % 17) for i in range(1, 201)]),
        build(1000000000, [i * 7000000 for i in range(1, 101)]),
        build(1000000000, [i * 3000 + (i % 29) for i in range(1, 10001)]),
        build(1000000000, [i * 9999 for i in range(1, 100001)]),
    ]


def solve_202112_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, limit = nums[:2]
    values = [0] + nums[2 : 2 + n] + [limit]
    unit = limit // (n + 1)
    ans = 0
    for i in range(n + 1):
        left, right = values[i], values[i + 1]
        while left < right:
            g = left // unit
            end = min(right, (g + 1) * unit)
            ans += (end - left) * abs(g - i)
            left = end
    return f"{ans}\n"


def cases_202203_1() -> list[str]:
    def build(n: int, statements: list[tuple[int, int]]) -> str:
        return f"{n} {len(statements)}\n" + "".join(f"{x} {y}\n" for x, y in statements)

    large = []
    n = 100000
    for i in range(1, n + 1):
        if i % 4 == 1:
            large.append((i, 0))
        elif i % 4 == 2:
            large.append((i, i - 1))
        elif i % 4 == 3:
            large.append((i, min(n, i + 10)))
        else:
            large.append((i, i))

    return [
        build(3, [(1, 0)]),
        build(3, [(1, 1), (2, 1), (3, 2)]),
        build(5, [(1, 2), (2, 0), (3, 2), (4, 3), (5, 4)]),
        build(6, [(1, 0), (2, 0), (3, 1), (4, 2), (5, 3), (6, 5)]),
        build(10, [(1, 9), (9, 0), (2, 9), (3, 2), (4, 4), (5, 4)]),
        build(8, [(1, 0), (1, 1), (2, 1), (3, 7), (7, 0), (4, 7), (5, 4), (6, 5)]),
        build(20, [(i, 0 if i % 3 == 0 else max(1, i - 2)) for i in range(1, 21)]),
        build(50, [(i, i + 1 if i < 50 else 1) for i in range(1, 51)]),
        build(1000, [(i, 0 if i <= 500 else i - 500) for i in range(1, 1001)]),
        build(n, large),
    ]


def solve_202203_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, k = nums[:2]
    initialized = [False] * (n + 1)
    ans = 0
    offset = 2
    for _ in range(k):
        x, y = nums[offset], nums[offset + 1]
        offset += 2
        if y != 0 and not initialized[y]:
            ans += 1
        initialized[x] = True
    return f"{ans}\n"


def cases_202206_1() -> list[str]:
    def build(values: list[int]) -> str:
        return f"{len(values)}\n" + " ".join(map(str, values)) + "\n"

    return [
        build([0, 2]),
        build([-1, 0, 1]),
        build([1, 1, 3, 5]),
        build([-5, -5, 0, 5, 10]),
        build([1000, -1000, 500, -500, 0, 250]),
        build([7, -3, 12, 0, 8, -11, 5, 20]),
        build(list(range(1, 11))),
        build([(-1) ** i * (i * 13 % 97) for i in range(1, 13)]),
        build([(i * 29) % 401 - 200 for i in range(100)]),
        build([(i * 37) % 2001 - 1000 for i in range(1000)]),
    ]


def solve_202206_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    values = nums[1 : 1 + n]
    mean = sum(values) / n
    variance = sum((value - mean) ** 2 for value in values) / n
    denominator = variance ** 0.5
    return "".join(f"{(value - mean) / denominator:.12f}\n" for value in values)


def cases_202212_1() -> list[str]:
    def build(rate: str, values: list[int]) -> str:
        return f"{len(values) - 1} {rate}\n" + " ".join(map(str, values)) + "\n"

    return [
        build("0.1", [100, -50]),
        build("0.05", [0, 100, -50, 25]),
        build("0.2", [-1000, 500, 500, 500]),
        build("0.01", [1000] + [-10] * 10),
        build("0.5", [-200, 300, -100, 50, -25]),
        build("0.333", [i * 17 - 200 for i in range(8)]),
        build("0.75", [1000, -1000, 1000, -1000, 1000, -1000]),
        build("0.125", [(-1) ** i * (i * 37 % 1000) for i in range(21)]),
        build("0.02", [500] + [20 if i % 2 else -30 for i in range(1, 41)]),
        build("0.999", [((i * 97) % 2001) - 1000 for i in range(51)]),
    ]


def solve_202212_1(input_text: str) -> str:
    tokens = input_text.split()
    n = int(tokens[0])
    rate = float(tokens[1])
    values = list(map(int, tokens[2 : 2 + n + 1]))
    total = 0.0
    discount = 1.0
    for value in values:
        total += value / discount
        discount *= 1.0 + rate
    return f"{total:.6f}\n"


def cases_202212_2() -> list[str]:
    def build(days: int, parents: list[int], durations: list[int]) -> str:
        return f"{days} {len(parents)}\n" + " ".join(map(str, parents)) + "\n" + " ".join(map(str, durations)) + "\n"

    return [
        build(5, [0], [3]),
        build(10, [0, 0, 0], [1, 5, 10]),
        build(12, [0, 1, 2, 0], [2, 3, 4, 5]),
        build(10, [0, 1, 2, 3], [4, 4, 4, 4]),
        build(20, [0, 1, 1, 2, 2, 3], [3, 4, 5, 2, 6, 1]),
        build(30, [0, 0, 1, 1, 3, 3, 4, 6], [5, 4, 3, 6, 2, 7, 3, 4]),
        build(15, [0, 1, 2, 0, 4, 5, 6], [3, 3, 3, 10, 3, 3, 3]),
        build(365, [0] + [i for i in range(1, 50)], [3] * 50),
        build(100, [0 if i % 5 == 1 else i - 1 for i in range(1, 81)], [(i % 9) + 1 for i in range(1, 81)]),
        build(365, [0 if i == 1 else max(0, i - (i % 7 + 1)) for i in range(1, 101)], [(i * 5) % 30 + 1 for i in range(1, 101)]),
    ]


def solve_202212_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    days, m = nums[:2]
    parents = [0] + nums[2 : 2 + m]
    durations = [0] + nums[2 + m : 2 + 2 * m]
    earliest = [0] * (m + 1)
    ok = True
    for i in range(1, m + 1):
        earliest[i] = 1 if parents[i] == 0 else earliest[parents[i]] + durations[parents[i]]
        if earliest[i] + durations[i] - 1 > days:
            ok = False

    out = [" ".join(map(str, earliest[1:]))]
    if ok:
        latest = [0] + [days - durations[i] + 1 for i in range(1, m + 1)]
        for i in range(m, 0, -1):
            parent = parents[i]
            if parent:
                latest[parent] = min(latest[parent], latest[i] - durations[parent])
        out.append(" ".join(map(str, latest[1:])))
    return _lines(out)


def cases_202209_1() -> list[str]:
    def build(radices: list[int], digits: list[int]) -> str:
        m = 0
        place = 1
        for radix, digit in zip(radices, digits):
            m += place * digit
            place *= radix
        return f"{len(radices)} {m}\n" + " ".join(map(str, radices)) + "\n"

    return [
        build([2], [1]),
        build([3], [0]),
        build([2, 3, 4], [1, 2, 3]),
        build([5, 7, 3, 2], [4, 0, 2, 1]),
        build([10, 10, 10, 10, 10], [9, 8, 7, 6, 5]),
        build([2, 2, 2, 2, 2, 2, 2, 2], [0, 1, 0, 1, 1, 0, 1, 0]),
        build([3, 5, 7, 11, 13], [2, 4, 6, 10, 12]),
        build([4, 4, 4, 4, 4, 4, 4, 4, 4], [3, 0, 1, 2, 3, 1, 0, 2, 1]),
        build([2, 5, 2, 5, 2, 5, 2, 5, 2, 5], [1, 4, 0, 3, 1, 2, 0, 1, 1, 4]),
        build([2] * 20, [i % 2 for i in range(20)]),
    ]


def solve_202209_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m = nums[:2]
    radices = nums[2 : 2 + n]
    digits = []
    for radix in radices:
        digits.append(m % radix)
        m //= radix
    return " ".join(map(str, digits)) + "\n"


def cases_202303_1() -> list[str]:
    def build(a: int, b: int, rectangles: list[tuple[int, int, int, int]]) -> str:
        lines = [f"{len(rectangles)} {a} {b}"]
        lines.extend(f"{x1} {y1} {x2} {y2}" for x1, y1, x2, y2 in rectangles)
        return "\n".join(lines) + "\n"

    grid_rectangles = []
    for i in range(10):
        for j in range(10):
            x1, y1 = i * 10, j * 10
            grid_rectangles.append((x1, y1, x1 + 5, y1 + 5))

    return [
        build(10, 10, [(1, 1, 3, 3)]),
        build(10, 10, [(-5, -5, 5, 5)]),
        build(10, 10, [(12, 12, 20, 20), (-8, 1, -1, 8)]),
        build(8, 6, [(0, 0, 8, 6)]),
        build(10, 10, [(0, 0, 3, 10), (3, 0, 6, 4), (6, 4, 10, 10)]),
        build(20, 15, [(-5, 0, 5, 5), (5, 5, 12, 12), (12, -3, 25, 4)]),
        build(100, 100, [(0, 0, 20, 20), (20, 0, 40, 10), (0, 20, 10, 60), (70, 70, 130, 130)]),
        build(30, 30, [(-10, -10, 0, 10), (0, 10, 10, 20), (10, 20, 40, 40), (20, 0, 30, 5)]),
        build(50, 40, [(i * 5, 0, i * 5 + 3, 10) for i in range(10)]),
        build(100, 100, grid_rectangles),
    ]


def solve_202303_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, a, b = nums[:3]
    offset = 3
    total = 0
    for _ in range(n):
        x1, y1, x2, y2 = nums[offset : offset + 4]
        offset += 4
        width = max(0, min(x2, a) - max(x1, 0))
        height = max(0, min(y2, b) - max(y1, 0))
        total += width * height
    return f"{total}\n"


def cases_202303_2() -> list[str]:
    def build(m: int, k: int, fields: list[tuple[int, int]]) -> str:
        lines = [f"{len(fields)} {m} {k}"]
        lines.extend(f"{t} {c}" for t, c in fields)
        return "\n".join(lines) + "\n"

    large_fields = [
        (100000 - (i % 400), 1 + (i % 17))
        for i in range(20000)
    ]

    return [
        build(1, 3, [(5, 2)]),
        build(100, 2, [(7, 1), (6, 2), (5, 3)]),
        build(8, 2, [(6, 1), (5, 1), (6, 2), (7, 1)]),
        build(20, 5, [(10, 3), (9, 2), (8, 4), (7, 1)]),
        build(1000000000, 1, [(100000, 100000), (99999, 1), (50000, 2)]),
        build(15, 4, [(4, 10), (4, 20), (4, 30)]),
        build(35, 3, [(20, 5), (18, 4), (16, 3), (14, 2), (12, 1)]),
        build(1000, 10, [(100, 9), (90, 8), (80, 7), (70, 6), (60, 5), (50, 4)]),
        build(123456, 100, [(1000 - i * 3, i % 11 + 1) for i in range(100)]),
        build(987654321, 500, large_fields),
    ]


def solve_202303_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m, k = nums[:3]
    fields = []
    offset = 3
    for _ in range(n):
        fields.append((nums[offset], nums[offset + 1]))
        offset += 2

    left, right = k, max(t for t, _ in fields)
    while left < right:
        mid = (left + right) // 2
        cost = sum(max(0, t - mid) * c for t, c in fields)
        if cost <= m:
            right = mid
        else:
            left = mid + 1
    return f"{left}\n"


def cases_202305_1() -> list[str]:
    def board(seed: int) -> list[str]:
        chars = "*kqrbnpKQRBNP"
        rows = []
        for i in range(8):
            row = []
            for j in range(8):
                value = (seed * 17 + i * 7 + j * 11) % 19
                row.append("*" if value >= len(chars) else chars[value])
            rows.append("".join(row))
        return rows

    def build(boards: list[list[str]]) -> str:
        lines = [str(len(boards))]
        for item in boards:
            lines.extend(item)
        return "\n".join(lines) + "\n"

    b1, b2, b3, b4, b5 = [board(i) for i in range(1, 6)]
    many = []
    for i in range(100):
        if i % 10 == 0:
            many.append(b1)
        elif i % 10 == 1:
            many.append(b2)
        elif i % 15 == 0:
            many.append(b3)
        else:
            many.append(board(100 + i))

    return [
        build([b1]),
        build([b1, b1]),
        build([b1, b2, b1, b3]),
        build([b1, b2, b3, b2, b1, b2]),
        build([b4, b5, b4, b5, b4, b5]),
        build([board(i) for i in range(10, 20)]),
        build([b1, b2, b3, b4, b5, b1, b2, b3, b4, b5]),
        build([board(i % 4) for i in range(20)]),
        build([board(i // 3) for i in range(30)]),
        build(many),
    ]


def solve_202305_1(input_text: str) -> str:
    lines = input_text.splitlines()
    n = int(lines[0])
    counts: dict[str, int] = {}
    out: list[str] = []
    cursor = 1
    for _ in range(n):
        state = "\n".join(lines[cursor : cursor + 8])
        cursor += 8
        counts[state] = counts.get(state, 0) + 1
        out.append(str(counts[state]))
    return _lines(out)


def cases_202309_2() -> list[str]:
    def build(ops: list[tuple[int, str]], queries: list[tuple[int, int, int, int]]) -> str:
        lines = [f"{len(ops)} {len(queries)}"]
        lines.extend(f"{op} {value}" for op, value in ops)
        lines.extend(f"{i} {j} {x} {y}" for i, j, x, y in queries)
        return "\n".join(lines) + "\n"

    large_ops = []
    for i in range(1, 3001):
        if i % 3 == 0:
            large_ops.append((2, f"{(i % 628) / 100.0:.2f}"))
        elif i % 2 == 0:
            large_ops.append((1, "0.99"))
        else:
            large_ops.append((1, "1.01"))
    large_queries = [
        (1 + (i * 7) % 2500, 501 + (i * 7) % 2500, (i * 97) % 2000000 - 1000000, (i * 131) % 2000000 - 1000000)
        for i in range(3000)
    ]

    return [
        build([(1, "2.0")], [(1, 1, 3, 4)]),
        build([(2, "1.57079632679")], [(1, 1, 1, 0), (1, 1, 0, 1)]),
        build([(1, "0.5"), (2, "3.1415926535"), (1, "2.0")], [(1, 3, 10, -20), (2, 2, 7, 8)]),
        build([(2, "0.25"), (2, "0.5"), (2, "0.75")], [(1, 2, 100, 0), (2, 3, 0, 100), (1, 3, -5, 12)]),
        build([(1, "1.2"), (1, "0.8"), (2, "2.0"), (1, "1.5")], [(1, 4, 11, 22), (3, 4, -30, 40)]),
        build([(1, "1.001"), (1, "0.999"), (2, "6.0"), (2, "0.1"), (1, "1.0")], [(1, 5, 123456, -654321)]),
        build([(1, "2.0"), (1, "0.5"), (1, "2.0"), (1, "0.5")], [(1, 4, 1, 1), (2, 3, 1000, -1000)]),
        build([(2, f"{i / 10.0:.1f}") for i in range(10)], [(1, 10, 9, 8), (4, 7, -6, 5), (10, 10, 3, -2)]),
        build([(1, "1.1" if i % 2 else "0.9") for i in range(1, 101)], [(1, 100, 100, 200), (25, 75, -300, 400)]),
        build(large_ops, large_queries),
    ]


def solve_202309_2(input_text: str) -> str:
    tokens = input_text.split()
    n, m = int(tokens[0]), int(tokens[1])
    index = 2
    scales = [1.0]
    angles = [0.0]
    for _ in range(n):
        op = int(tokens[index])
        value = float(tokens[index + 1])
        index += 2
        scales.append(scales[-1] * (value if op == 1 else 1.0))
        angles.append(angles[-1] + (value if op == 2 else 0.0))

    out: list[str] = []
    for _ in range(m):
        left, right = int(tokens[index]), int(tokens[index + 1])
        x, y = float(tokens[index + 2]), float(tokens[index + 3])
        index += 4
        scale = scales[right] / scales[left - 1]
        angle = angles[right] - angles[left - 1]
        x *= scale
        y *= scale
        nx = x * cos(angle) - y * sin(angle)
        ny = x * sin(angle) + y * cos(angle)
        out.append(f"{nx:.6f} {ny:.6f}")
    return _lines(out)


def cases_202309_1() -> list[str]:
    def build(ops: list[tuple[int, int]], points: list[tuple[int, int]]) -> str:
        lines = [f"{len(ops)} {len(points)}"]
        lines.extend(f"{dx} {dy}" for dx, dy in ops)
        lines.extend(f"{x} {y}" for x, y in points)
        return "\n".join(lines) + "\n"

    large_ops = [((i * 37) % 200001 - 100000, (i * 53) % 200001 - 100000) for i in range(100)]
    large_points = [((i * 97) % 200001 - 100000, (i * 131) % 200001 - 100000) for i in range(100)]

    return [
        build([(1, 2)], [(3, 4)]),
        build([(10, -5), (-3, 7)], [(0, 0), (1, 1)]),
        build([(0, 0), (0, 0), (0, 0)], [(-5, 5), (100, -100)]),
        build([(100000, -100000)], [(-100000, 100000), (0, 0), (5, -6)]),
        build([(1, 1), (2, 3), (-4, 5), (6, -7)], [(8, 9)]),
        build([(-10, 20), (30, -40), (50, 60)], [(7, 8), (-9, -10), (1000, -1000)]),
        build([(i, -i) for i in range(1, 11)], [(i * 2, i * 3) for i in range(10)]),
        build([((i % 5) - 2, (i % 7) - 3) for i in range(50)], [(i, -i) for i in range(20)]),
        build([(99999, -99999) for _ in range(100)], [(-99999, 99999) for _ in range(50)]),
        build(large_ops, large_points),
    ]


def solve_202309_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m = nums[:2]
    offset = 2
    dx = dy = 0
    for _ in range(n):
        dx += nums[offset]
        dy += nums[offset + 1]
        offset += 2
    out: list[str] = []
    for _ in range(m):
        x, y = nums[offset], nums[offset + 1]
        offset += 2
        out.append(f"{x + dx} {y + dy}")
    return _lines(out)


def cases_202403_2() -> list[str]:
    def word(value: int) -> str:
        letters = []
        value += 1
        while value:
            value, rem = divmod(value, 26)
            letters.append(chr(ord("a") + rem))
        return "w" + "".join(letters)

    def build(first: list[str], second: list[str]) -> str:
        return f"{len(first)} {len(second)}\n" + " ".join(first) + "\n" + " ".join(second) + "\n"

    large_first = [word(i) for i in range(10000)]
    large_second = [word(i).upper() if i % 2 == 0 else word(i + 5000) for i in range(10000)]

    return [
        build(["a"], ["A"]),
        build(["one", "two", "three"], ["four", "five"]),
        build(["The", "tHe", "thE", "Other"], ["the", "THE"]),
        build(["Alpha", "beta", "Gamma", "alpha"], ["BETA", "delta", "gamma"]),
        build(["cat", "dog", "bird", "fish"], ["CAT", "DOG", "lion", "tiger"]),
        build(["aa", "bb", "cc", "dd", "ee"], ["ff", "gg", "hh"]),
        build(["Word", "word", "WORD", "test"], ["TEST", "case", "word"]),
        build([word(i) for i in range(100)], [word(i) for i in range(50, 150)]),
        build([word(i).upper() if i % 3 == 0 else word(i) for i in range(500)], [word(i) for i in range(250, 750)]),
        build(large_first, large_second),
    ]


def solve_202403_2(input_text: str) -> str:
    tokens = input_text.split()
    n, m = int(tokens[0]), int(tokens[1])
    first = {token.lower() for token in tokens[2 : 2 + n]}
    second = {token.lower() for token in tokens[2 + n : 2 + n + m]}
    return f"{len(first & second)}\n{len(first | second)}\n"


def cases_202406_1() -> list[str]:
    def build(n: int, m: int, p: int, q: int, values: list[int]) -> str:
        rows = [" ".join(str(values[i * m + j]) for j in range(m)) for i in range(n)]
        return f"{n} {m} {p} {q}\n" + "\n".join(rows) + "\n"

    return [
        build(1, 1, 1, 1, [7]),
        build(1, 4, 2, 2, [1, 2, 3, 4]),
        build(4, 1, 2, 2, [5, 6, 7, 8]),
        build(2, 5, 5, 2, list(range(10))),
        build(3, 4, 2, 6, [i * 3 - 10 for i in range(12)]),
        build(5, 6, 3, 10, [(-1) ** i * i for i in range(30)]),
        build(10, 10, 4, 25, [(i * 17) % 1001 - 500 for i in range(100)]),
        build(20, 25, 25, 20, [(i * 31) % 2001 - 1000 for i in range(500)]),
        build(50, 20, 100, 10, [(i % 41) - 20 for i in range(1000)]),
        build(100, 100, 1, 10000, [(i * 73) % 2001 - 1000 for i in range(10000)]),
    ]


def solve_202406_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m, p, q = nums[:4]
    values = nums[4 : 4 + n * m]
    out = []
    for i in range(p):
        row = values[i * q : (i + 1) * q]
        out.append(" ".join(map(str, row)))
    return _lines(out)


def cases_202406_2() -> list[str]:
    def build(n: int, m: int, values: list[int], ops: list[tuple[int, int, int]]) -> str:
        rows = [" ".join(str(values[i * m + j]) for j in range(m)) for i in range(n)]
        lines = [f"{n} {m} {len(ops)}"]
        lines.extend(rows)
        lines.extend(f"{op} {a} {b}" for op, a, b in ops)
        return "\n".join(lines) + "\n"

    large_ops: list[tuple[int, int, int]] = []
    rows, cols = 100, 100
    for i in range(1000):
        if i % 20 == 0:
            large_ops.append((2, 0, 0))
            rows, cols = cols, rows
        elif i % 9 == 0:
            large_ops.append((1, 50, 200))
            rows, cols = 50, 200
        elif i % 9 == 1:
            large_ops.append((1, 100, 100))
            rows, cols = 100, 100
        else:
            large_ops.append((3, (i * 7) % rows, (i * 11) % cols))

    return [
        build(1, 1, [9], [(3, 0, 0)]),
        build(2, 3, [1, 2, 3, 4, 5, 6], [(3, 0, 2), (1, 3, 2), (3, 2, 1)]),
        build(2, 3, [1, 2, 3, 4, 5, 6], [(2, 0, 0), (3, 1, 0), (1, 3, 2), (3, 1, 0)]),
        build(3, 4, list(range(12)), [(3, 2, 3), (2, 0, 0), (3, 3, 2), (1, 2, 6), (3, 1, 5)]),
        build(4, 5, [i * 2 - 10 for i in range(20)], [(1, 2, 10), (3, 1, 9), (2, 0, 0), (3, 9, 1)]),
        build(5, 6, [(-1) ** i * i for i in range(30)], [(2, 0, 0), (2, 0, 0), (3, 4, 5), (1, 3, 10), (3, 2, 9)]),
        build(10, 10, [(i * 13) % 101 for i in range(100)], [(3, i, 9 - i) for i in range(10)]),
        build(20, 25, [(i * 17) % 2001 - 1000 for i in range(500)], [(2, 0, 0)] + [(3, i % 25, (i * 3) % 20) for i in range(50)]),
        build(50, 20, [(i % 37) - 18 for i in range(1000)], [(1, 25, 40), (2, 0, 0)] + [(3, i % 40, (i * 5) % 25) for i in range(100)]),
        build(100, 100, [(i * 73) % 2001 - 1000 for i in range(10000)], large_ops),
    ]


def solve_202406_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    rows, cols, t = nums[:3]
    total = rows * cols
    values = nums[3 : 3 + total]
    offset = 3 + total
    out: list[str] = []
    for _ in range(t):
        op, a, b = nums[offset : offset + 3]
        offset += 3
        if op == 1:
            rows, cols = a, b
        elif op == 2:
            reshaped = [0] * total
            for i in range(rows):
                for j in range(cols):
                    reshaped[j * rows + i] = values[i * cols + j]
            values = reshaped
            rows, cols = cols, rows
        else:
            out.append(str(values[a * cols + b]))
    return _lines(out)


def cases_202406_3() -> list[str]:
    def build(items: list[tuple[str, int]], m: int) -> str:
        lines = [f"{len(items)} {m}"]
        lines.extend(f"{word} {freq}" for word, freq in items)
        return "\n".join(lines) + "\n"

    large: list[tuple[str, int]] = []
    seeds = ["alpha", "alpine", "planet", "plane", "panel", "penal", "lean", "lane", "peal", "plea"]
    for i in range(200):
        base = seeds[i % len(seeds)]
        word = base + chr(ord("a") + (i % 7)) + chr(ord("a") + ((i * 3) % 11))
        large.append((word, i % 17 + 1))

    return [
        build([("ab", 5)], 3),
        build([("abc", 4), ("abd", 3)], 6),
        build([("aaaa", 7), ("aaab", 2)], 5),
        build([("map", 5), ("many", 4), ("man", 3)], 8),
        build([("code", 6), ("coder", 5), ("decode", 2)], 10),
        build([("stone", 8), ("tones", 4), ("notes", 3)], 12),
        build([("banana", 9), ("bandana", 5), ("cabana", 2)], 14),
        build([("zebra", 2), ("azure", 7), ("maze", 6), ("raze", 3)], 16),
        build([("loop", 10), ("pool", 9), ("lollipop", 3), ("pilot", 4)], 18),
        build(large, 300),
    ]


def solve_202406_3(input_text: str) -> str:
    tokens = input_text.split()
    n, m = int(tokens[0]), int(tokens[1])
    items: list[tuple[list[str], int]] = []
    letters: set[str] = set()
    offset = 2
    for _ in range(n):
        word = tokens[offset]
        freq = int(tokens[offset + 1])
        offset += 2
        letters.update(word)
        items.append((list(word), freq))

    vocab = sorted(letters)
    while len(vocab) < m:
        counts: dict[tuple[str, str], int] = {}
        for pieces, freq in items:
            for left, right in zip(pieces, pieces[1:]):
                pair = (left, right)
                counts[pair] = counts.get(pair, 0) + freq
        if not counts:
            break

        best = min(
            counts,
            key=lambda pair: (
                -counts[pair],
                len(pair[0]) + len(pair[1]),
                len(pair[0]),
                pair[0] + pair[1],
            ),
        )
        merged = best[0] + best[1]
        vocab.append(merged)

        for index, (pieces, freq) in enumerate(items):
            new_pieces: list[str] = []
            pos = 0
            while pos < len(pieces):
                if pos + 1 < len(pieces) and pieces[pos] == best[0] and pieces[pos + 1] == best[1]:
                    new_pieces.append(merged)
                    pos += 2
                else:
                    new_pieces.append(pieces[pos])
                    pos += 1
            items[index] = (new_pieces, freq)

    return _lines(vocab)


def cases_202409_1() -> list[str]:
    large = []
    patterns = [
        "Aa1#Bb2*",
        "abc#def",
        "abc#123",
        "AA11##",
        "aaaA11#",
        "Zz9*Yy8#",
        "123456#",
        "abcdef1",
        "a1#b2*c3",
        "##**12ab",
    ]
    for i in range(100):
        base = patterns[i % len(patterns)]
        if i % 7 == 0:
            large.append(base + "X")
        elif i % 7 == 1:
            large.append(base.lower().replace("*", "#"))
        else:
            large.append(base)

    def build(values: list[str]) -> str:
        return f"{len(values)}\n" + "\n".join(values) + "\n"

    return [
        build(["abcDEF"]),
        build(["abc123", "abcdef", "123456"]),
        build(["abc#123", "A1#b2*", "aa11##"]),
        build(["aaa111#", "abcdef#", "ABC123*"]),
        build(["Aa1#Bb", "Aa1#Aa", "Z9*z9#"]),
        build(["AAbb11##", "aaaBBB111###", "aA0*bc"]),
        build(["qwerty#", "QWERTY1", "Qw1#Qw1#"]),
        build(["A1#A1#", "A1#B2*C3", "111aaa***"]),
        build(["abc#12", "ABCD#12", "abCD12##", "aaab12#"]),
        build(large),
    ]


def solve_202409_1(input_text: str) -> str:
    tokens = input_text.split()
    n = int(tokens[0])
    out: list[str] = []
    for password in tokens[1 : 1 + n]:
        has_letter = any(ch.isalpha() for ch in password)
        has_digit = any(ch.isdigit() for ch in password)
        has_special = any(ch in "*#" for ch in password)
        if not (has_letter and has_digit and has_special):
            out.append("0")
            continue
        counts: dict[str, int] = {}
        high = True
        for ch in password:
            counts[ch] = counts.get(ch, 0) + 1
            if counts[ch] > 2:
                high = False
        out.append("2" if high else "1")
    return _lines(out)


def cases_202409_2() -> list[str]:
    def build(s: str, rules: list[tuple[str, str]], queries: list[int]) -> str:
        lines = [f"#{s}#", str(len(rules))]
        lines.extend(f"#{src}{dst}#" for src, dst in rules)
        lines.append(str(len(queries)))
        lines.extend(str(value) for value in queries)
        return "\n".join(lines) + "\n"

    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 "
    large_rules = [(alphabet[i], alphabet[(i + 17) % len(alphabet)]) for i in range(len(alphabet))]
    large_s = "".join(alphabet[(i * 11) % len(alphabet)] for i in range(180))

    return [
        build("Ab 9", [("A", "B"), ("b", "c"), (" ", "0")], [0, 1, 2, 5]),
        build("Shift", [("S", "s"), ("s", "S"), ("h", "i"), ("i", "h")], [1, 2, 3, 10]),
        build("A A", [("A", " "), (" ", "A")], [1, 2, 7]),
        build("012345", [("0", "1"), ("1", "2"), ("2", "3"), ("3", "4"), ("4", "5"), ("5", "0")], [1, 6, 100]),
        build("Mix 42", [("M", "N"), ("i", "j"), ("x", "y"), ("4", "5"), ("2", "3")], [3, 8, 999]),
        build("CycleZ", [("C", "D"), ("D", "E"), ("E", "C"), ("Z", "z"), ("z", "Z")], [1, 2, 30]),
        build("space end ", [(" ", "x"), ("x", "y"), ("y", " ")], [1, 2, 3, 20]),
        build("NoRule", [], [0, 1, 123456789]),
        build("LongCase123", [("L", "l"), ("l", "1"), ("1", "L"), ("e", "E"), ("E", "e")], [5, 12, 1000000000]),
        build(large_s, large_rules, [1, 2, 63, 1000000000]),
    ]


def solve_202409_2(input_text: str) -> str:
    lines = input_text.splitlines()
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 "
    index = {ch: pos for pos, ch in enumerate(alphabet)}
    source = lines[0][1:-1]
    n = int(lines[1])

    mapping = list(range(len(alphabet)))
    for i in range(n):
        line = lines[2 + i]
        mapping[index[line[1]]] = index[line[2]]

    up = [mapping]
    for _ in range(31):
        prev = up[-1]
        up.append([prev[prev[i]] for i in range(len(alphabet))])

    q_line = 2 + n
    q = int(lines[q_line])
    out: list[str] = []
    for raw_k in lines[q_line + 1 : q_line + 1 + q]:
        k = int(raw_k)
        chars: list[str] = []
        for ch in source:
            cur = index[ch]
            bit = 0
            value = k
            while value:
                if value & 1:
                    cur = up[bit][cur]
                value >>= 1
                bit += 1
            chars.append(alphabet[cur])
        out.append("#" + "".join(chars) + "#")
    return _lines(out)


def cases_202312_1() -> list[str]:
    return [
        "1 1\n0\n",
        "2 1\n0\n1\n",
        "3 2\n0 0\n1 1\n2 2\n",
        "4 2\n0 0\n-2 -2\n2 3\n1 -1\n",
        "5 3\n0 0 0\n1 1 1\n1 2 3\n-1 -1 -1\n2 2 2\n",
        "6 2\n5 5\n4 6\n6 4\n7 7\n3 3\n8 8\n",
        "7 4\n0 0 0 0\n1 1 1 1\n1 2 1 2\n2 2 2 2\n-1 -1 -1 -1\n3 0 3 0\n4 4 4 4\n",
        "8 3\n10 10 10\n9 9 11\n11 11 11\n8 8 8\n12 12 12\n7 13 7\n13 13 13\n6 6 6\n",
        "10 2\n0 5\n1 6\n2 7\n3 8\n4 9\n5 10\n-1 4\n6 11\n7 12\n8 13\n",
        "12 5\n0 0 0 0 0\n1 1 1 1 1\n2 0 2 0 2\n3 3 3 3 3\n-1 -1 -1 -1 -1\n4 4 4 4 4\n5 1 5 1 5\n6 6 6 6 6\n-2 0 -2 0 -2\n7 7 7 7 7\n8 8 8 8 8\n9 9 9 9 9\n",
    ]


def solve_202312_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m = nums[0], nums[1]
    values = [nums[2 + i * m : 2 + (i + 1) * m] for i in range(n)]
    ans: list[int] = []
    for i in range(n):
        superior = 0
        for j in range(n):
            if i == j:
                continue
            if all(values[j][k] > values[i][k] for k in range(m)):
                superior = j + 1
                break
        ans.append(superior)
    return _join_lines(ans)


def cases_202312_2() -> list[str]:
    return [
        "2\n8 2\n12 2\n",
        "3\n216 3\n97 2\n10000000000 9\n",
        "4\n16 5\n16 4\n81 4\n81 5\n",
        "5\n72 2\n72 3\n72 4\n3600 2\n3600 3\n",
        "3\n99991 2\n99991 3\n99991 10\n",
        "4\n64 2\n64 3\n64 6\n64 7\n",
        "3\n10000000000 2\n9999999967 2\n9999508849 2\n",
        "6\n36 2\n36 3\n36 4\n48 2\n48 3\n48 4\n",
        "5\n1024 2\n1024 5\n1024 10\n59049 5\n59049 11\n",
        "3\n9876543210 2\n1234567890 3\n1000000007 2\n",
    ]


def _simplify_factorization(n: int, k: int) -> int:
    original = n
    result = 1
    p = 2
    while p * p <= n:
        if n % p == 0:
            power = 1
            count = 0
            while n % p == 0:
                n //= p
                power *= p
                count += 1
            if count >= k:
                result *= power
        p += 1 if p == 2 else 2
        if p == 3:
            continue
    if n > 1 and k <= 1:
        result *= n
    return result if original > 1 else 1


def solve_202312_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    q = nums[0]
    out: list[int] = []
    offset = 1
    for _ in range(q):
        n, k = nums[offset], nums[offset + 1]
        offset += 2
        out.append(_simplify_factorization(n, k))
    return _join_lines(out)


def cases_202412_1() -> list[str]:
    return [
        "5 1\n3 3 f\n",
        "5 2\n1 1 bl\n5 5 fr\n",
        "3 3\n2 2 fblr\n1 3 fffrrr\n3 1 bbblll\n",
        "10 2\n5 5 fffffrrrrr\n10 10 bbbbblllll\n",
        "4 4\n1 1 rrrfff\n4 4 lllbbb\n2 3 flbr\n3 2 rbfl\n",
        "6 3\n6 1 fffff\n1 6 bbbbb\n3 3 lrlrffbb\n",
        "2 5\n1 1 f\n1 1 r\n2 2 b\n2 2 l\n1 2 brfl\n",
        "8 2\n4 4 fbrlffrrbbll\n8 1 ffffffffrrrrrrrr\n",
        "9 4\n5 5 lllll\n5 5 rrrrr\n5 5 fffff\n5 5 bbbbb\n",
        "7 3\n1 7 fff\n7 1 bbb\n4 4 fflbrrbb\n",
    ]


def solve_202412_1(input_text: str) -> str:
    parts = input_text.split()
    n, k = int(parts[0]), int(parts[1])
    offset = 2
    out: list[str] = []
    for _ in range(k):
        x, y = int(parts[offset]), int(parts[offset + 1])
        ops = parts[offset + 2]
        offset += 3
        for op in ops:
            nx, ny = x, y
            if op == "f":
                ny += 1
            elif op == "b":
                ny -= 1
            elif op == "l":
                nx -= 1
            elif op == "r":
                nx += 1
            if 1 <= nx <= n and 1 <= ny <= n:
                x, y = nx, ny
        out.append(f"{x} {y}")
    return "\n".join(out) + "\n"


def cases_202503_1() -> list[str]:
    return [
        "0 0 1 1\n",
        "1 0 1 10\n",
        "-1 2 -5 5\n",
        "3 4 2 2\n",
        "5 -7 1 9\n",
        "10 20 -10 -1\n",
        "-3 -4 -8 8\n",
        "100 100 0 20\n",
        "-100 50 -20 20\n",
        "7 11 13 31\n",
    ]


def solve_202503_1(input_text: str) -> str:
    b, c, left, right = map(int, input_text.split())
    start = left if left % 2 == 0 else left + 1
    total = 0
    for x in range(start, right + 1, 2):
        total += x * x + b * x + c
    return f"{2 * total}\n"


def cases_202503_3() -> list[str]:
    def build(lines: list[str]) -> str:
        return str(len(lines)) + "\n" + "\n".join(lines) + "\n"

    large: list[str] = []
    for i in range(1, 101):
        large.append(f"1 s{i} block{i}")
        large.append(f"2 t{i} $s{i} item{i} $t{i - 1}" if i > 1 else "2 t1 $s1 item1")
        if i % 10 == 0:
            large.append(f"3 t{i}")

    return [
        build(["1 a red", "1 b blue", "2 c $a $b", "3 c", "1 a x", "3 c"]),
        build(["2 x $missing aa", "3 x", "1 missing bbb", "3 x"]),
        build(["1 base abc", "2 wrap L $base R", "1 base z", "3 wrap", "1 out $wrap $base", "3 out"]),
        build(["2 a hello", "2 b $a world", "3 b", "1 a q", "3 b"]),
        build(["1 p one", "1 q two", "1 r $p $q three", "3 r", "2 r $p $q", "3 r"]),
        build(["2 chain $a $b", "1 a aa", "1 b bbb", "3 chain", "1 b c", "3 chain"]),
        build(["1 n0 x", "2 n1 $n0 y", "2 n2 $n1 z", "3 n2", "1 n0 long", "3 n2"]),
        build(["1 a alpha", "1 b beta", "2 c $a $b gamma", "2 d $c $c", "3 d", "1 a k", "3 d"]),
        build(["3 none", "1 none abc", "3 none", "2 other $none q", "3 other"]),
        build(large),
    ]


def solve_202503_3(input_text: str) -> str:
    lines = input_text.splitlines()
    q = int(lines[0])
    definitions: dict[str, tuple[bool, int, list[str]]] = {}

    def eval_var(name: str, memo: dict[str, int]) -> int:
        if name in memo:
            return memo[name]
        if name not in definitions:
            memo[name] = 0
            return 0
        direct, length, expr = definitions[name]
        if direct:
            memo[name] = length
            return length
        total = 0
        for token in expr:
            if token.startswith("$"):
                total = (total + eval_var(token[1:], memo)) % MOD
            else:
                total = (total + len(token)) % MOD
        memo[name] = total
        return total

    out: list[str] = []
    for line in lines[1 : q + 1]:
        parts = line.split()
        op = parts[0]
        name = parts[1]
        if op == "1":
            total = 0
            memo: dict[str, int] = {}
            for token in parts[2:]:
                if token.startswith("$"):
                    total = (total + eval_var(token[1:], memo)) % MOD
                else:
                    total = (total + len(token)) % MOD
            definitions[name] = (True, total, [])
        elif op == "2":
            definitions[name] = (False, 0, parts[2:])
        else:
            out.append(str(eval_var(name, {})))
    return _lines(out)


def cases_202506_1() -> list[str]:
    return [
        "1\n0 100 0\n",
        "2\n0 100 50\n0 100 99\n",
        "3\n10 90 10\n10 90 55\n10 90 99\n",
        "4\n1 3 1\n1 3 2\n1 3 3\n1 3 4\n",
        "5\n100 200 100\n100 200 150\n100 200 199\n100 200 200\n100 200 250\n",
        "2\n-50 100 -50\n-50 100 49\n",
        "3\n0 7 1\n0 7 4\n0 7 6\n",
        "3\n5 5 5\n5 5 6\n5 5 9\n",
        "2\n20 30 27\n20 30 35\n",
        "4\n0 9 0\n0 9 3\n0 9 6\n0 9 8\n",
    ]


def solve_202506_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    k = nums[0]
    offset = 1
    out: list[str] = []
    for _ in range(k):
        a, b, n = nums[offset], nums[offset + 1], nums[offset + 2]
        offset += 3
        ans = int(((n - a) / b) * 100)
        out.append(f"{ans // 10 + 1} {ans % 10 + 1}")
    return "\n".join(out) + "\n"


def cases_202509_1() -> list[str]:
    return [
        "1 1\n0 0\n",
        "4 1\n0 0\n1 0\n0 1\n1 1\n",
        "5 2\n0 0\n2 0\n0 2\n1 1\n3 3\n",
        "3 5\n3 4\n5 0\n6 0\n",
        "6 10\n0 0\n10 0\n0 10\n7 7\n8 8\n11 0\n",
        "4 1.5\n1 1\n1.1 1.1\n2 0\n0 0\n",
        "8 3\n0 0\n1 1\n2 2\n3 0\n0 3\n-1 -1\n-3 0\n4 0\n",
        "10 100\n0 0\n100 0\n0 100\n70 70\n80 80\n50 50\n-60 -60\n101 0\n0 -101\n30 -40\n",
        "2 2.5\n1.5 2\n2.5 0\n",
        "7 4\n4 0\n0 4\n2 2\n3 3\n-4 0\n0 -4\n5 0\n",
    ]


def solve_202509_1(input_text: str) -> str:
    tokens = input_text.split()
    n, radius = int(tokens[0]), float(tokens[1])
    offset = 2
    inside = 0
    for _ in range(n):
        x, y = float(tokens[offset]), float(tokens[offset + 1])
        offset += 2
        if x * x + y * y <= radius * radius + 1e-12:
            inside += 1
    return f"{4 * inside / n:.6f}\n"


def cases_202509_3() -> list[str]:
    def build(static: list[tuple[str, str]], limit: int, tree: str, instructions: list[str]) -> str:
        lines = [f"{len(static)} {limit}"]
        lines.extend(f"{key} {value}" for key, value in static)
        lines.append(tree)
        lines.append(str(len(instructions)))
        lines.extend(instructions)
        return "\n".join(lines) + "\n"

    large_static = [(f"K{i}", f"V{i}") for i in range(1, 21)]
    large_instructions: list[str] = []
    for i in range(1, 81):
        if i % 4 == 0:
            large_instructions.append(f"1 {i % 20 + 1}")
        elif i % 4 == 1:
            large_instructions.append(f"2 0 Dyn{i} Val{i}")
        elif i % 4 == 2:
            large_instructions.append(f"3 {i % 20 + 1} Raw{i}")
        else:
            large_instructions.append(f"2 {20 + min(5, (i + 1) // 4)} Copy{i}")

    return [
        build([("Key", "Value")], 1, "01a1b", ["1 1"]),
        build([("A", "B")], 2, "01a1b", ["2 0 C D", "1 2", "3 2 E"]),
        build([("Host", "Root"), ("Path", "Index")], 3, "01a1b", ["3 1 Local", "2 2 Page", "1 3"]),
        build([("A", "B"), ("C", "D")], 2, "01a1b", ["2 0 X Y", "2 0 Z W", "2 0 P Q", "1 3", "1 4"]),
        build([("Plain", "Base")], 2, "01a1b", ["3 0 HHKey HHValue", "2 0 HHName Data", "1 2"]),
        build([("Left", "Right")], 2, "01a1b", ["3 0 H4006 H8006", "2 0 H6004 H4006", "1 2"]),
        build([("S1", "V1"), ("S2", "V2")], 1, "001a1b1c", ["3 0 H1803 H8005", "2 0 H1803 H2006", "1 3"]),
        build([("AA", "BB"), ("CC", "DD"), ("EE", "FF")], 4, "01x1y", ["2 1 One", "2 2 Two", "2 3 Three", "1 4", "1 6"]),
        build([("Alpha", "Beta")], 3, "001m1n1o", ["2 0 H3004 H8005", "3 2 Next", "2 2 Again", "1 2"]),
        build(large_static, 5, "01a1b", large_instructions),
    ]


def solve_202509_3(input_text: str) -> str:
    lines = input_text.splitlines()
    first = lines[0].split()
    s_count, limit = int(first[0]), int(first[1])
    static: list[tuple[str, str]] = []
    for line in lines[1 : 1 + s_count]:
        key, value = line.split()
        static.append((key, value))

    tree_spec = lines[1 + s_count]

    def parse_tree(pos: int):
        if tree_spec[pos] == "1":
            return (tree_spec[pos + 1], None, None), pos + 2
        left, next_pos = parse_tree(pos + 1)
        right, next_pos = parse_tree(next_pos)
        return (None, left, right), next_pos

    root, _ = parse_tree(0)

    def decode(token: str) -> str:
        if not token.startswith("H"):
            return token
        if token.startswith("HH"):
            return token[1:]
        data = bytes.fromhex(token[1:])
        if not data:
            return ""
        padding = data[-1]
        bits: list[int] = []
        for value in data[:-1]:
            for bit in range(7, -1, -1):
                bits.append((value >> bit) & 1)
        if padding:
            bits = bits[:-padding]
        out: list[str] = []
        node = root
        for bit in bits:
            node = node[1] if bit == 0 else node[2]
            if node[0] is not None:
                out.append(node[0])
                node = root
        return "".join(out)

    dynamic: list[tuple[str, str]] = []

    def lookup(idx: int) -> tuple[str, str]:
        if idx <= s_count:
            return static[idx - 1]
        return dynamic[idx - s_count - 1]

    def add_dynamic(item: tuple[str, str]) -> None:
        dynamic.insert(0, item)
        if len(dynamic) > limit:
            dynamic.pop()

    n = int(lines[2 + s_count])
    out: list[str] = []
    for line in lines[3 + s_count : 3 + s_count + n]:
        parts = line.split()
        op = parts[0]
        if op == "1":
            key, value = lookup(int(parts[1]))
        else:
            indexed = op == "2"
            idx = int(parts[1])
            if idx == 0:
                key = decode(parts[2])
                value = decode(parts[3])
            else:
                key, _ = lookup(idx)
                value = decode(parts[2])
            if indexed:
                add_dynamic((key, value))
        out.append(f"{key}: {value}")
    return _lines(out)


def cases_202603_1() -> list[str]:
    return [
        "1\n2\n",
        "5\n1 2 3 4 5\n",
        "8\n6 9 10 12 15 16 31 32\n",
        "10\n0 1 2 3 4 5 6 7 8 9\n",
        "6\n21 42 85 170 341 682\n",
        "7\n7 11 13 14 19 25 28\n",
        "9\n100 101 102 103 104 105 106 107 108\n",
        "4\n255 256 511 512\n",
        "12\n2 4 6 8 10 12 14 16 18 20 22 24\n",
        "15\n1 3 5 7 9 11 13 15 17 19 21 23 25 27 29\n",
    ]


def solve_202603_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    ans = 0
    for value in nums[1 : 1 + n]:
        if value == 0:
            ans += 1
            continue
        zeros = ones = 0
        while value > 0:
            if value % 2:
                ones += 1
            else:
                zeros += 1
            value //= 2
        if zeros == ones:
            ans += 1
    return f"{ans}\n"


REGISTRY: dict[str, ProblemDefinition] = {
    "CSP201403-1": ProblemDefinition("CSP201403-1", cases_201403_1, solve_201403_1),
    "CSP201403-2": ProblemDefinition("CSP201403-2", cases_201403_2, solve_201403_2),
    "CSP201403-3": ProblemDefinition("CSP201403-3", cases_201403_3, solve_201403_3),
    "CSP201403-4": ProblemDefinition("CSP201403-4", cases_201403_4, solve_201403_4),
    "CSP201403-5": ProblemDefinition("CSP201403-5", cases_201403_5, solve_201403_5),
    "CSP201409-1": ProblemDefinition("CSP201409-1", cases_201409_1, solve_201409_1),
    "CSP201409-2": ProblemDefinition("CSP201409-2", cases_201409_2, solve_201409_2),
    "CSP201409-3": ProblemDefinition("CSP201409-3", cases_201409_3, solve_201409_3),
    "CSP201409-4": ProblemDefinition("CSP201409-4", cases_201409_4, solve_201409_4),
    "CSP201409-5": ProblemDefinition("CSP201409-5", cases_201409_5, solve_201409_5),
    "CSP201412-1": ProblemDefinition("CSP201412-1", cases_201412_1, solve_201412_1),
    "CSP201412-2": ProblemDefinition("CSP201412-2", cases_201412_2, solve_201412_2),
    "CSP201412-3": ProblemDefinition("CSP201412-3", cases_201412_3, solve_201412_3),
    "CSP201412-4": ProblemDefinition("CSP201412-4", cases_201412_4, solve_201412_4),
    "CSP201509-1": ProblemDefinition("CSP201509-1", cases_201509_1, solve_201509_1),
    "CSP201604-1": ProblemDefinition("CSP201604-1", cases_201604_1, solve_201604_1),
    "CSP201609-1": ProblemDefinition("CSP201609-1", cases_201609_1, solve_201609_1),
    "CSP201612-1": ProblemDefinition("CSP201612-1", cases_201612_1, solve_201612_1),
    "CSP201703-1": ProblemDefinition("CSP201703-1", cases_201703_1, solve_201703_1),
    "CSP201709-1": ProblemDefinition("CSP201709-1", cases_201709_1, solve_201709_1),
    "CSP201712-1": ProblemDefinition("CSP201712-1", cases_201712_1, solve_201712_1),
    "CSP201803-1": ProblemDefinition("CSP201803-1", cases_201803_1, solve_201803_1),
    "CSP201809-1": ProblemDefinition("CSP201809-1", cases_201809_1, solve_201809_1),
    "CSP201812-1": ProblemDefinition("CSP201812-1", cases_201812_1, solve_201812_1),
    "CSP201903-1": ProblemDefinition("CSP201903-1", cases_201903_1, solve_201903_1),
    "CSP201909-1": ProblemDefinition("CSP201909-1", cases_201909_1, solve_201909_1),
    "CSP201912-1": ProblemDefinition("CSP201912-1", cases_201912_1, solve_201912_1),
    "CSP202006-1": ProblemDefinition("CSP202006-1", cases_202006_1, solve_202006_1),
    "CSP202009-1": ProblemDefinition("CSP202009-1", cases_202009_1, solve_202009_1),
    "CSP202012-1": ProblemDefinition("CSP202012-1", cases_202012_1, solve_202012_1),
    "CSP202104-1": ProblemDefinition("CSP202104-1", cases_202104_1, solve_202104_1),
    "CSP202104-2": ProblemDefinition("CSP202104-2", cases_202104_2, solve_202104_2),
    "CSP202109-1": ProblemDefinition("CSP202109-1", cases_202109_1, solve_202109_1),
    "CSP202112-1": ProblemDefinition("CSP202112-1", cases_202112_1, solve_202112_1),
    "CSP202112-2": ProblemDefinition("CSP202112-2", cases_202112_2, solve_202112_2),
    "CSP202203-1": ProblemDefinition("CSP202203-1", cases_202203_1, solve_202203_1),
    "CSP202206-1": ProblemDefinition("CSP202206-1", cases_202206_1, solve_202206_1),
    "CSP202209-1": ProblemDefinition("CSP202209-1", cases_202209_1, solve_202209_1),
    "CSP202212-1": ProblemDefinition("CSP202212-1", cases_202212_1, solve_202212_1),
    "CSP202212-2": ProblemDefinition("CSP202212-2", cases_202212_2, solve_202212_2),
    "CSP202303-1": ProblemDefinition("CSP202303-1", cases_202303_1, solve_202303_1),
    "CSP202303-2": ProblemDefinition("CSP202303-2", cases_202303_2, solve_202303_2),
    "CSP202305-1": ProblemDefinition("CSP202305-1", cases_202305_1, solve_202305_1),
    "CSP202309-1": ProblemDefinition("CSP202309-1", cases_202309_1, solve_202309_1),
    "CSP202309-2": ProblemDefinition("CSP202309-2", cases_202309_2, solve_202309_2),
    "CSP202312-1": ProblemDefinition("CSP202312-1", cases_202312_1, solve_202312_1),
    "CSP202312-2": ProblemDefinition("CSP202312-2", cases_202312_2, solve_202312_2),
    "CSP202403-2": ProblemDefinition("CSP202403-2", cases_202403_2, solve_202403_2),
    "CSP202406-1": ProblemDefinition("CSP202406-1", cases_202406_1, solve_202406_1),
    "CSP202406-2": ProblemDefinition("CSP202406-2", cases_202406_2, solve_202406_2),
    "CSP202406-3": ProblemDefinition("CSP202406-3", cases_202406_3, solve_202406_3),
    "CSP202409-1": ProblemDefinition("CSP202409-1", cases_202409_1, solve_202409_1),
    "CSP202409-2": ProblemDefinition("CSP202409-2", cases_202409_2, solve_202409_2),
    "CSP202412-1": ProblemDefinition("CSP202412-1", cases_202412_1, solve_202412_1),
    "CSP202503-1": ProblemDefinition("CSP202503-1", cases_202503_1, solve_202503_1),
    "CSP202503-3": ProblemDefinition("CSP202503-3", cases_202503_3, solve_202503_3),
    "CSP202506-1": ProblemDefinition("CSP202506-1", cases_202506_1, solve_202506_1),
    "CSP202509-1": ProblemDefinition("CSP202509-1", cases_202509_1, solve_202509_1),
    "CSP202509-3": ProblemDefinition("CSP202509-3", cases_202509_3, solve_202509_3),
    "CSP202603-1": ProblemDefinition("CSP202603-1", cases_202603_1, solve_202603_1),
}
