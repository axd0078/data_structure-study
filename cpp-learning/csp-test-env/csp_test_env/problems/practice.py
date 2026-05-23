from __future__ import annotations

from collections import deque
from dataclasses import dataclass

from . import ProblemDefinition


def _lines(values: list[str]) -> str:
    return "\n".join(values) + "\n"


def cases_202403_1() -> list[str]:
    return [
        "1 1\n1 1\n",
        "2 3\n3 1 2 3\n2 2 2\n",
        "3 4\n4 1 1 2 3\n3 2 4 4\n1 3\n",
        "4 5\n5 1 2 3 4 5\n4 1 1 1 1\n3 5 5 2\n2 3 4\n",
        "2 6\n6 1 2 3 4 5 6\n6 6 5 4 3 2 1\n",
        "5 3\n1 1\n1 2\n1 3\n3 1 2 3\n2 2 3\n",
        "3 7\n7 1 2 3 4 5 6 7\n4 2 2 2 2\n5 7 7 1 1 1\n",
        "4 4\n6 1 2 1 2 1 2\n2 3 4\n4 4 4 4 4\n3 1 3 4\n",
        "2 2\n5 1 1 1 1 1\n5 2 2 2 2 2\n",
        "6 5\n2 1 5\n3 2 2 5\n4 3 4 5 5\n1 4\n2 1 2\n3 3 3 3\n",
    ]


def solve_202403_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m = nums[:2]
    total = [0] * (m + 1)
    doc_count = [0] * (m + 1)
    offset = 2
    for _ in range(n):
        length = nums[offset]
        offset += 1
        seen = set()
        for value in nums[offset : offset + length]:
            total[value] += 1
            seen.add(value)
        offset += length
        for value in seen:
            doc_count[value] += 1
    return "".join(f"{doc_count[i]} {total[i]}\n" for i in range(1, m + 1))


def cases_202412_2() -> list[str]:
    return [
        "1\n5 5\n0\n",
        "3\n5 5 5 5\n0 100 0\n",
        "3\n9 4 6 2\n9 4 6\n",
        "4\n1 2 3 4 5\n5 4 3 2\n",
        "5\n0 0 0 0 0 0\n0 0 0 0 0\n",
        "6\n10 1 10 1 10 1 10\n1 10 1 10 1 10\n",
        "2\n100 0 100\n50 50\n",
        "7\n3 1 4 1 5 9 2 6\n5 3 5 8 9 7 9\n",
        "8\n1 1 1 1 1 1 1 1 1\n0 1 0 1 0 1 0 1\n",
        "10\n9 8 7 6 5 4 3 2 1 0 9\n1 2 3 4 5 6 7 8 9 10\n",
    ]


def solve_202412_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    a = nums[1 : n + 2]
    b = [0] + nums[n + 2 : n + 2 + n]
    s = [0] * (n + 1)
    s[0] = a[0]
    for i in range(1, n + 1):
        s[i] = s[i - 1] + a[i] - b[i]
    pre = [0] * (n + 1)
    suf = [0] * (n + 1)
    pre[0] = s[0]
    for i in range(1, n + 1):
        pre[i] = max(pre[i - 1], s[i])
    suf[n] = s[n]
    for i in range(n - 1, -1, -1):
        suf[i] = max(suf[i + 1], s[i])
    out = [str(max(pre[i - 1], suf[i] + b[i])) for i in range(1, n + 1)]
    return " ".join(out) + "\n"


def cases_202412_4() -> list[str]:
    return [
        "1\n0\n1\n",
        "2\n0 0\n1 1\n",
        "5\n0 1 2 3 0\n3 4 4 10 15\n",
        "10\n0 1 1 1 1 3 1 0 3 0\n2 4 5 4 1 4 1 3 5 3\n",
        "6\n0 1 1 2 1 0\n1 1 1 1 1 1\n",
        "8\n0 0 1 1 2 2 3 0\n2 2 2 2 2 2 2 2\n",
        "7\n0 1 0 2 1 3 0\n3 1 4 1 5 9 2\n",
        "9\n0 0 0 0 0 0 0 0 0\n1 1 1 1 1 1 1 1 1\n",
        "12\n0 1 1 2 1 2 3 1 2 4 5 0\n2 3 1 5 2 6 1 4 3 2 1 10\n",
        "15\n0 1 2 1 4 2 3 6 2 1 5 4 3 2 0\n4 1 5 1 2 6 5 3 5 8 9 7 9 3 2\n",
    ]


def solve_202412_4(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n = nums[0]
    a = [0] + nums[1 : 1 + n]
    k = [0] + nums[1 + n : 1 + 2 * n]
    if n == 1:
        return "0\n"
    dist = [-1] * (n + 1)
    parent = list(range(n + 2))

    def find(x: int) -> int:
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x

    def remove(x: int) -> None:
        parent[x] = find(x + 1)

    q = deque([1])
    dist[1] = 0
    while q:
        cur = q.popleft()
        right = min(n, cur + k[cur])
        landing = find(cur + 1)
        while landing <= right:
            nxt = landing - a[landing]
            remove(landing)
            if dist[nxt] == -1:
                dist[nxt] = dist[cur] + 1
                if nxt == n:
                    return f"{dist[nxt]}\n"
                q.append(nxt)
            landing = find(landing)
    return f"{dist[n]}\n"


def cases_202506_2() -> list[str]:
    return [
        "1 1\n1 1\n",
        "4 1\n1 1\n",
        "4 2\n1 1\n",
        "5 3\n3 3\n",
        "8 2\n4 4\n",
        "8 4\n1 8\n",
        "10 5\n5 5\n",
        "12 3\n6 6\n",
        "20 6\n10 10\n",
        "30 10\n15 15\n",
    ]


def solve_202506_2(input_text: str) -> str:
    n, k, x, y = map(int, input_text.split())
    moves = ((2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2))
    seen = [[False] * (n + 1) for _ in range(n + 1)]
    seen[x][y] = True
    q = deque([(x, y, 0)])
    ans = 1
    while q:
        cx, cy, step = q.popleft()
        if step == k:
            continue
        for dx, dy in moves:
            nx, ny = cx + dx, cy + dy
            if 1 <= nx <= n and 1 <= ny <= n and not seen[nx][ny]:
                seen[nx][ny] = True
                ans += 1
                q.append((nx, ny, step + 1))
    return f"{ans}\n"


_HASH_MULT = 47055833459


def _code_value(ch: str) -> int:
    if ch == " ":
        return 0
    if ch.isdigit():
        return ord(ch) - ord("0") + 1
    if "A" <= ch <= "Z":
        return ord(ch) - ord("A") + 11
    if ch == "_":
        return 37
    raise ValueError(ch)


def _value_code(v: int) -> str:
    if v == 0:
        return " "
    if 1 <= v <= 10:
        return chr(ord("0") + v - 1)
    if 11 <= v <= 36:
        return chr(ord("A") + v - 11)
    return "_"


def _normal_value(code: str) -> int:
    code = code.ljust(11)
    value = 0
    for ch in code:
        value = value * 38 + _code_value(ch)
    return value


def _decode_normal(value: int) -> str:
    chars = []
    for _ in range(11):
        chars.append(_value_code(value % 38))
        value //= 38
    return "".join(reversed(chars)).rstrip()


def _short_typical(code: str) -> int:
    code = code.rjust(6)
    c1 = _code_value(code[0])
    c2 = (ord(code[1]) - ord("0")) if code[1].isdigit() else (ord(code[1]) - ord("A") + 10)
    c3 = ord(code[2]) - ord("0")
    c4 = ord(code[3]) - ord("A")
    c5 = ord(code[4]) - ord("A")
    c6 = ord(code[5]) - ord("A")
    return (((((c1 * 36 + c2) * 10 + c3) * 26 + c4) * 26 + c5) * 26 + c6)


def _hash_code(code: str, bits: int) -> int:
    product = (_normal_value(code) * _HASH_MULT) & ((1 << 64) - 1)
    return (product >> (64 - bits)) & ((1 << bits) - 1)


def _bits(value: int, length: int) -> str:
    return format(value, f"0{length}b")


def _simple_message(receiver_code: str | None, sender_code: str | None, position: int, receiver_hash: int | None = None, sender_hash: int | None = None) -> str:
    receiver = receiver_hash if receiver_hash is not None else (1 << 25) + _short_typical(receiver_code or "")
    sender = sender_hash if sender_hash is not None else (1 << 25) + _short_typical(sender_code or "")
    return "0" + _bits(receiver, 28) + _bits(sender, 28) + _bits(position, 15)


def _complex_message(full_code: str, other_hash: int, flag: int) -> str:
    return "1" + _bits(_normal_value(full_code), 58) + _bits(other_hash, 12) + str(flag)


def _message_case(messages: list[str]) -> str:
    return str(len(messages)) + "\n" + "\n".join(messages) + "\n"


def cases_202506_3() -> list[str]:
    return [
        _message_case([_simple_message("A0BCD", "B1XYZ", 0)]),
        _message_case([_simple_message("A0BCD", "B1XYZ", 123)]),
        _message_case([_complex_message("ABCD200_4", 970, 0)]),
        _message_case([_simple_message("A0BCD", "B1XYZ", 0), _simple_message(None, "C2DEF", 8, receiver_hash=_hash_code("A0BCD", 25))]),
        _message_case([_complex_message("HELLO_1", 123, 1), _complex_message("WORLD_2", _hash_code("HELLO_1", 12), 0)]),
        _message_case([_complex_message("ALPHA", 999, 0), _simple_message(None, None, 7, receiver_hash=_hash_code("ALPHA", 25), sender_hash=_hash_code("BETA", 25))]),
        _message_case([_simple_message("Z9ABC", "Y8DEF", 321), _complex_message("LONG_CODE_1", _hash_code("Z9ABC", 12), 1)]),
        _message_case([_complex_message("CODE123", 1, 0), _complex_message("CODE456", _hash_code("CODE123", 12), 1), _simple_message(None, None, 0, receiver_hash=_hash_code("CODE456", 25), sender_hash=_hash_code("CODE123", 25))]),
        _message_case([_simple_message("M5AAA", "N6BBB", 32400), _simple_message("P7CCC", "Q8DDD", 1)]),
        _message_case([_complex_message("ABCD200_3", 948, 0), _complex_message("PY4XMCHJZTN", 970, 1), _complex_message("ABCD200_5", _hash_code("ABCD200_3", 12), 0)]),
    ]


def _decode_typical(value: int) -> str:
    x = value - (1 << 25)
    c6 = x % 26
    x //= 26
    c5 = x % 26
    x //= 26
    c4 = x % 26
    x //= 26
    c3 = x % 10
    x //= 10
    c2 = x % 36
    x //= 36
    c1 = x
    out = ""
    if c1:
        out += _value_code(c1)
    out += chr(ord("0") + c2) if c2 < 10 else chr(ord("A") + c2 - 10)
    out += chr(ord("0") + c3)
    out += chr(ord("A") + c4) + chr(ord("A") + c5) + chr(ord("A") + c6)
    return out


def solve_202506_3(input_text: str) -> str:
    tokens = input_text.split()
    n = int(tokens[0])
    hash12: dict[int, str] = {}
    hash25: dict[int, str] = {}

    def add(code: str) -> None:
        hash12[_hash_code(code, 12)] = code
        hash25[_hash_code(code, 25)] = code

    def decode_simple(value: int) -> str:
        if value >= (1 << 25):
            return _decode_typical(value)
        if value in hash25:
            return "#" + hash25[value]
        return "###"

    out: list[str] = []
    for msg in tokens[1 : 1 + n]:
        if msg[0] == "0":
            rv = int(msg[1:29], 2)
            sv = int(msg[29:57], 2)
            pos = int(msg[57:72], 2)
            receiver = decode_simple(rv)
            sender = decode_simple(sv)
            out.append(f"{receiver} {sender}" + (f" {pos}" if pos else ""))
            if rv >= (1 << 25):
                add(receiver)
            if sv >= (1 << 25):
                add(sender)
        else:
            full = _decode_normal(int(msg[1:59], 2))
            hv = int(msg[59:71], 2)
            flag = int(msg[71])
            other = "#" + hash12[hv] if hv in hash12 else "###"
            out.append(f"{other} {full}" if flag == 0 else f"{full} {other}")
            add(full)
    return _lines(out)


_WATERMARK_PATTERN = ["111111111", "100100101", "100111110", "100001100", "111111100"]


def _watermark_case(rows: int, cols: int, placements: list[tuple[int, int, int, int]]) -> str:
    grid = [[0 for _ in range(cols)] for _ in range(rows)]
    for top, left, low, high in placements:
        for i in range(5):
            for j in range(9):
                grid[top + i][left + j] = high if _WATERMARK_PATTERN[i][j] == "1" else low
    return f"{rows} {cols}\n" + "\n".join(" ".join(map(str, row)) for row in grid) + "\n"


def cases_202509_2() -> list[str]:
    return [
        _watermark_case(5, 9, [(0, 0, 0, 3)]),
        _watermark_case(6, 12, [(1, 2, 1, 6)]),
        _watermark_case(7, 14, [(0, 4, 2, 9)]),
        _watermark_case(8, 15, [(2, 1, 3, 10)]),
        _watermark_case(9, 16, [(0, 0, 4, 12), (4, 7, 1, 5)]),
        _watermark_case(10, 18, [(1, 3, 0, 8), (5, 8, 6, 14)]),
        _watermark_case(11, 20, [(0, 6, 5, 11), (6, 0, 2, 7)]),
        _watermark_case(12, 21, [(3, 5, 8, 15)]),
        _watermark_case(13, 22, [(0, 0, 1, 4), (4, 6, 5, 12), (8, 12, 9, 18)]),
        _watermark_case(14, 24, [(2, 2, 0, 10), (7, 10, 11, 20)]),
    ]


def solve_202509_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, limit = nums[:2]
    values = [nums[2 + i * limit : 2 + (i + 1) * limit] for i in range(n)]
    ok = set()
    for i in range(n - 4):
        for j in range(limit - 8):
            max_black = -1
            min_white = limit
            for x in range(5):
                for y in range(9):
                    if _WATERMARK_PATTERN[x][y] == "1":
                        min_white = min(min_white, values[i + x][j + y])
                    else:
                        max_black = max(max_black, values[i + x][j + y])
            for k in range(max_black + 1, min_white + 1):
                if 0 <= k < limit:
                    ok.add(k)
    return "".join(f"{x}\n" for x in sorted(ok))


def cases_202512_1() -> list[str]:
    return [
        "3 1\n1 2 3\n3 1 2 3\n3 1 2 3\n",
        "4 2\n1 2 3 4\n2 1 2\n2 3 4\n2 1 2\n2 4 3\n",
        "5 3\n1 1 2 2 3\n3 1 2 3\n2 4 5\n1 1\n3 1 2 3\n2 5 4\n1 2\n",
        "6 2\n5 7 5 7 9 9\n3 1 3 5\n3 2 4 6\n3 1 5 3\n3 2 4 6\n",
        "3 2\n10 20 30\n1 1\n2 2 3\n1 2\n2 2 3\n",
        "4 1\n1 2 4 8\n4 1 2 3 4\n4 4 3 2 1\n",
        "5 2\n3 3 3 3 3\n2 1 2\n2 3 4\n2 2 1\n2 3 4\n",
        "5 1\n1 2 3 4 5\n3 1 3 5\n3 5 3 1\n",
        "8 2\n1 2 3 4 5 6 7 8\n4 1 2 3 4\n4 5 6 7 8\n4 1 2 4 3\n4 5 6 7 8\n",
        "6 3\n1 3 5 7 9 11\n2 1 6\n2 2 5\n2 3 4\n2 6 1\n2 5 2\n2 4 3\n",
    ]


def solve_202512_1(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m = nums[:2]
    values = nums[2 : 2 + n]
    offset = 2 + n
    standards: list[tuple[list[int], int]] = []
    for _ in range(m):
        size = nums[offset]
        offset += 1
        indices = nums[offset : offset + size]
        offset += size
        x = 0
        for idx in indices:
            x ^= values[idx - 1]
        standards.append((indices, x))
    out: list[str] = []
    for i in range(m):
        size = nums[offset]
        offset += 1
        indices = nums[offset : offset + size]
        offset += size
        x = 0
        for idx in indices:
            x ^= values[idx - 1]
        out.append("correct" if (standards[i][0] == indices) == (standards[i][1] == x) else "wrong")
    return _lines(out)


def _transform_g(x: int, k: int) -> int:
    def f(v: int) -> int:
        return ((v * v + k * k) & 7) ^ k

    b = x >> 6
    q = (x >> 3) & 7
    r = x & 7
    c = q ^ f(b)
    a = r ^ f(c)
    return (a << 6) | (b << 3) | c


def cases_202512_2() -> list[str]:
    return [
        "3 1\n0\n0 1 2\n",
        "5 2\n1 2\n0 7 8 63 511\n",
        "4 3\n3 1 4\n1 2 3 4\n",
        "6 4\n0 1 2 3\n10 20 30 40 50 60\n",
        "8 1\n7\n0 64 128 256 511 73 146 292\n",
        "2 5\n1 1 1 1 1\n123 456\n",
        "10 2\n6 5\n0 1 2 3 4 5 6 7 8 9\n",
        "3 6\n1 2 3 4 5 6\n100 200 300\n",
        "7 3\n7 0 7\n11 22 33 44 55 66 77\n",
        "5 4\n2 4 6 0\n15 31 63 127 255\n",
    ]


def solve_202512_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m = nums[:2]
    keys = nums[2 : 2 + m]
    arr = nums[2 + m : 2 + m + n]
    pre = []
    for value in range(512):
        x = value
        for key in reversed(keys):
            x = _transform_g(x, key)
        pre.append(x)
    return " ".join(str(pre[x]) for x in arr) + "\n"


def cases_202512_3() -> list[str]:
    return [
        "2\nab\ncd\n1\n0\n",
        "3\nabc\ndef\nghi\n7\n1 1 1 1 3 90 0\n",
        "3\nabc\ndef\nghi\n7\n1 1 1 1 3 180 0\n",
        "4\nabcd\nefgh\nijkl\nmnop\n7\n1 2 2 3 1 4 1\n",
        "4\nabcd\nefgh\nijkl\nmnop\n7\n1 2 1 2 3 4 -1\n",
        "5\nabcde\nfghij\nklmno\npqrst\nuvwxy\n13\n2 1 1 1 3 90 0 2 2 4 2 5 -1\n",
        "5\n?????\n?a??c\n?????\n?b??d\n?????\n1\n0\n",
        "3\nabc\ndef\nghi\n13\n2 1 1 1 3 90 0 1 1 1 3 90 0\n",
        "6\nabcdef\nghijkl\nmnopqr\nstuvwx\nyzABCD\nEFGHIJ\n7\n1 2 1 5 2 6 1\n",
        "6\nabcdef\nghijkl\nmnopqr\nstuvwx\nyzABCD\nEFGHIJ\n19\n3 1 1 1 3 90 0 2 2 5 2 6 -1 1 3 3 2 180 0\n",
    ]


def solve_202512_3(input_text: str) -> str:
    lines = input_text.splitlines()
    z = int(lines[0])
    grid = [list(line) for line in lines[1 : 1 + z]]
    k_size = int(lines[1 + z])
    data = list(map(int, " ".join(lines[2 + z :]).split()))
    if len(data) != k_size:
        raise ValueError(f"expected {k_size} operation integers, got {len(data)}")
    t = data[0]
    ops = []
    idx = 1
    for _ in range(t):
        ops.append(data[idx : idx + 6])
        idx += 6

    def rotate_square(u: int, v: int, length: int, degree: int) -> None:
        u -= 1
        v -= 1
        times = (degree // 90) % 4
        sub = [row[v : v + length] for row in grid[u : u + length]]
        for _ in range(times):
            sub = [[sub[length - 1 - r][c] for r in range(length)] for c in range(length)]
        for i in range(length):
            for j in range(length):
                grid[u + i][v + j] = sub[i][j]

    def flip(u: int, d: int, l: int, r: int, orient: int) -> None:
        u -= 1
        d -= 1
        l -= 1
        r -= 1
        sub = [row[l : r + 1] for row in grid[u : d + 1]]
        if orient == 1:
            sub.reverse()
        else:
            for row in sub:
                row.reverse()
        for i in range(d - u + 1):
            for j in range(r - l + 1):
                grid[u + i][l + j] = sub[i][j]

    for op, a, b, c, d, e in ops:
        if op == 1:
            rotate_square(a, b, c, d)
        else:
            flip(a, b, c, d, e)
    max_r = max((i for i in range(z) if any(ch != "?" for ch in grid[i])), default=-1) + 1
    max_c = max((j for j in range(z) for i in range(z) if grid[i][j] != "?"), default=-1) + 1
    out = [f"{max_r} {max_c}"]
    out.extend("".join(grid[i][:max_c]) for i in range(max_r))
    return _lines(out)


def cases_202603_2() -> list[str]:
    return [
        "1 0\n1 10 5 5\n",
        "2 5\n0 10 5 5\n1 20 3 4\n",
        "3 10\n0 30 10 15\n0 20 5 6\n1 50 4 8\n",
        "4 6\n1 10 3 5\n1 20 4 7\n0 30 5 6\n0 40 8 16\n",
        "5 12\n0 100 10 50\n1 80 5 30\n0 60 6 18\n1 70 7 28\n0 30 3 12\n",
        "3 1\n0 10 5 5\n0 10 5 100\n1 10 1 9\n",
        "6 20\n0 30 10 10\n0 30 10 20\n1 50 5 25\n1 60 6 18\n0 70 7 35\n1 80 8 8\n",
        "2 100\n0 1000 100 1000\n1 1000 100 999\n",
        "4 0\n0 1 2 3\n1 4 5 6\n0 7 8 9\n1 10 11 12\n",
        "7 15\n0 20 5 10\n0 20 4 7\n0 20 6 12\n1 20 5 9\n1 20 3 8\n1 20 8 20\n0 20 2 3\n",
    ]


def solve_202603_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m = nums[:2]
    normal = []
    flex = []
    total = 0
    offset = 2
    for _ in range(n):
        o, t, a, b = nums[offset : offset + 4]
        offset += 4
        total += t
        (flex if o == 0 else normal).append((a, b))
    dp = [0.0] * (m + 1)
    for a, b in normal:
        for j in range(m, a - 1, -1):
            dp[j] = max(dp[j], dp[j - a] + b)
    flex.sort(key=lambda item: item[1] / item[0], reverse=True)

    def greedy(left: int) -> float:
        ans = 0.0
        remain = float(left)
        for a, b in flex:
            take = min(remain, float(a))
            ans += take * b / a
            remain -= take
            if remain <= 0:
                break
        return ans

    best = max(dp[used] + greedy(m - used) for used in range(m + 1))
    return f"{total - best:.6f}\n"


def cases_202603_3() -> list[str]:
    return [
        "1 3\nnew 1 5\nsend 1\ndelete 1 1\n",
        "2 5\nnew 1 3\nnew 2 2\nsend 1\nsend 2\nsend 1\n",
        "1 6\nnew 1 2\nsend 1\nsend 1\nsend 1\ndelete 1 1\nnew 1 3\n",
        "2 8\nnew 1 5\nnew 1 2\nsend 1\ndelete 1 1\nnew 2 4\nsend 1\nsend 2\nnew 1 1\n",
        "3 10\nnew 1 10\nnew 2 5\nnew 3 3\nsend 1\nsend 2\ndelete 1 1\nnew 2 4\nsend 2\ndelete 2 1\nnew 3 2\n",
        "1 7\nnew 1 1\nnew 1 1\nnew 1 1\nsend 1\ndelete 1 2\nnew 1 2\nsend 1\n",
        "2 9\nnew 1 4\nnew 2 4\ndelete 1 1\nnew 2 2\nsend 2\ndelete 2 1\nnew 1 3\nsend 1\nsend 2\n",
        "3 6\nnew 1 100\nsend 1\nsend 1\nsend 1\ndelete 1 1\nnew 2 50\n",
        "2 7\nnew 1 5\nnew 1 5\ndelete 1 1\ndelete 1 1\nnew 2 8\nsend 2\nnew 1 1\n",
        "4 10\nnew 1 2\nnew 2 3\nnew 3 4\nnew 4 5\nsend 1\nsend 2\nsend 3\nsend 4\ndelete 3 1\nnew 1 4\n",
    ]


def solve_202603_3(input_text: str) -> str:
    tokens = input_text.split()
    n, q = int(tokens[0]), int(tokens[1])
    idx = 2
    free: list[tuple[int, int]] = [(0, 10**18)]
    proc: list[list[list[int]]] = [[] for _ in range(n + 1)]
    out: list[str] = []

    def add_free(l: int, r: int) -> None:
        free.append((l, r))
        free.sort()
        merged: list[tuple[int, int]] = []
        for a, b in free:
            if not merged or merged[-1][1] + 1 < a:
                merged.append((a, b))
            else:
                merged[-1] = (merged[-1][0], max(merged[-1][1], b))
        free[:] = merged

    def alloc(length: int) -> int:
        best = min((seg for seg in free if seg[1] - seg[0] + 1 >= length), key=lambda seg: (seg[1] - seg[0] + 1, seg[0]))
        free.remove(best)
        l, r = best
        if l + length <= r:
            add_free(l + length, r)
        return l

    for _ in range(q):
        op = tokens[idx]
        idx += 1
        if op == "new":
            p, length = int(tokens[idx]), int(tokens[idx + 1])
            idx += 2
            start = alloc(length)
            proc[p].append([start, start + length - 1, start])
            out.append(str(start))
        elif op == "delete":
            p, i = int(tokens[idx]), int(tokens[idx + 1])
            idx += 2
            l, r, _ = proc[p].pop(i - 1)
            add_free(l, r)
        else:
            p = int(tokens[idx])
            idx += 1
            total = 0
            for item in proc[p]:
                total += item[2]
                item[2] += 1
                if item[2] > item[1]:
                    item[2] = item[0]
            out.append(str(total))
    return _lines(out)


def _xor_case(n: int, m: int, k: int, arr: list[int], ops: list[str]) -> str:
    return f"{n} {m} {k}\n" + " ".join(map(str, arr)) + "\n" + "\n".join(ops) + "\n"


def cases_202603_4() -> list[str]:
    arr10 = [(i * 1234567 + 987654321) % (10**12) for i in range(1, 2001)]
    ops10 = []
    for i in range(1, 1001):
        if i % 3 == 0:
            l = (i * 17) % 2000 + 1
            r = min(2000, l + 150)
            ops10.append(f"1 {l} {r} {(i * 987654321) % (10**12)}")
        else:
            l = (i * 31) % 2000 + 1
            r = min(2000, l + 300)
            ops10.append(f"2 {l} {r}")
    return [
        _xor_case(1, 1, 11, [0], ["2 1 1"]),
        _xor_case(3, 4, 11, [1, 2, 3], ["2 1 3", "1 2 3 5", "2 1 3", "2 2 2"]),
        _xor_case(5, 4, 11, [13, 17, 14, 19, 15], ["1 1 3 9", "2 1 2", "1 3 5 6", "2 4 5"]),
        _xor_case(6, 6, 13, [0, 13, 26, 39, 52, 65], ["2 1 6", "1 1 6 13", "2 1 6", "1 2 5 26", "2 2 5", "2 3 3"]),
        _xor_case(8, 7, 101, [100, 101, 102, 999, 10000, 12345, 54321, 0], ["2 1 8", "1 3 7 100", "2 1 4", "1 1 8 202", "2 5 8", "1 4 4 303", "2 4 4"]),
        _xor_case(10, 10, 99991, [i * 99991 for i in range(10)], ["2 1 10", "1 1 10 99991", "2 1 10", "1 3 8 199982", "2 3 8", "1 5 5 299973", "2 1 5", "1 1 1 399964", "2 1 1", "2 10 10"]),
        _xor_case(20, 12, 97, [(i * i + 17) % 100000 for i in range(20)], ["2 1 20", "1 1 10 123", "2 1 10", "1 11 20 456", "2 10 20", "1 5 15 789", "2 1 20", "2 7 7", "1 1 20 1000", "2 3 18", "1 9 9 333", "2 9 9"]),
        _xor_case(100, 30, 1009, [(i * 31337) % 10**9 for i in range(100)], [f"{'1' if i % 4 == 0 else '2'} {max(1, (i * 7) % 100)} {min(100, max(1, (i * 7) % 100) + 20)}" + (f" {(i * 1000003) % 10**9}" if i % 4 == 0 else "") for i in range(1, 31)]),
        _xor_case(500, 200, 1000003, [(i * 1000000007) % 10**12 for i in range(500)], [f"1 {i % 500 + 1} {min(500, i % 500 + 50)} {(i * 998244353) % 10**12}" if i % 5 == 0 else f"2 {i % 500 + 1} {min(500, i % 500 + 80)}" for i in range(1, 201)]),
        _xor_case(2000, 1000, 99991, arr10, ops10),
    ]


def _tree_path(n: int, graph: list[list[tuple[int, int]]], s: int, t: int) -> list[tuple[int, int]]:
    parent = [0] * (n + 1)
    parent_edge = [0] * (n + 1)
    q = deque([s])
    parent[s] = -1
    while q:
        u = q.popleft()
        if u == t:
            break
        for v, edge_id in graph[u]:
            if parent[v] == 0:
                parent[v] = u
                parent_edge[v] = edge_id
                q.append(v)
    rev = []
    cur = t
    while cur != s:
        rev.append((parent_edge[cur], cur))
        cur = parent[cur]
    rev.reverse()
    return rev


def _travel_case(n: int, x: int, edges: list[tuple[int, int]], stations: list[int], plans: list[tuple[int, int]], events: list[tuple[int, int, int] | tuple[int]]) -> str:
    graph: list[list[tuple[int, int]]] = [[] for _ in range(n + 1)]
    edge_map: dict[tuple[int, int], int] = {}
    for idx, (u, v) in enumerate(edges, start=1):
        graph[u].append((v, idx))
        graph[v].append((u, idx))
        edge_map[(min(u, v), max(u, v))] = idx
    station_set = set(stations)
    paths = [_tree_path(n, graph, s, t) for s, t in plans]
    repaired = [False] * (len(edges) + 1)
    lastans = 0
    encoded_events: list[str] = []

    def feasible(path: list[tuple[int, int]]) -> bool:
        bad = 0
        for edge_id, next_node in path:
            if not repaired[edge_id]:
                bad += 1
                if bad >= 2:
                    return False
            if next_node in station_set:
                bad = 0
        return True

    for event in events:
        if event[0] == 2:
            ans = sum(1 for path in paths if feasible(path))
            encoded_events.append("2")
            lastans = ans
        else:
            _, u, v = event
            up = u ^ (x * lastans)
            vp = v ^ (x * lastans)
            encoded_events.append(f"1 {up} {vp}")
            repaired[edge_map[(min(u, v), max(u, v))]] = True
    out = [f"{n} {x}"]
    out.extend(f"{u} {v}" for u, v in edges)
    out.append(str(len(stations)))
    out.append(" ".join(map(str, stations)))
    out.append(str(len(plans)))
    out.extend(f"{s} {t}" for s, t in plans)
    out.append(str(len(encoded_events)))
    out.extend(encoded_events)
    return "\n".join(out) + "\n"


def cases_202603_5() -> list[str]:
    path_edges = [(i, i + 1) for i in range(1, 501)]
    path_plans = [(1, 501), (1, 250), (250, 501), (100, 400), (10, 20)] * 100
    path_events: list[tuple[int, int, int] | tuple[int]] = []
    for i in range(1, 501):
        if i % 5 == 0:
            path_events.append((2,))
        path_events.append((1, i, i + 1))
    path_events.append((2,))
    return [
        _travel_case(2, 0, [(1, 2)], [1], [(1, 2)], [(2,), (1, 1, 2), (2,)]),
        _travel_case(3, 0, [(1, 2), (2, 3)], [1], [(1, 3), (2, 3)], [(2,), (1, 1, 2), (2,), (1, 2, 3), (2,)]),
        _travel_case(5, 0, [(1, 2), (3, 4), (1, 5), (2, 3)], [4, 3, 1, 2, 5], [(5, 2), (2, 5), (1, 3)], [(2,), (1, 2, 3), (1, 1, 5), (1, 1, 2), (1, 3, 4), (2,), (2,)]),
        _travel_case(5, 0, [(1, 2), (2, 3), (3, 4), (4, 5)], [3], [(1, 5), (1, 3), (3, 5), (2, 4)], [(2,), (1, 1, 2), (2,), (1, 2, 3), (2,), (1, 4, 5), (2,)]),
        _travel_case(6, 1, [(1, 2), (2, 3), (2, 4), (4, 5), (4, 6)], [2, 5], [(1, 6), (3, 5), (1, 3), (5, 6)], [(2,), (1, 1, 2), (2,), (1, 2, 4), (2,)]),
        _travel_case(10, 0, [(i, i + 1) for i in range(1, 10)], [1, 5, 10], [(1, 10), (2, 9), (5, 10), (3, 4)], [(2,), (1, 1, 2), (1, 2, 3), (2,), (1, 5, 6), (2,), (1, 9, 10), (2,)]),
        _travel_case(20, 0, [(i, i + 1) for i in range(1, 20)], [1, 10, 20], [(1, 20), (1, 10), (10, 20), (3, 17), (5, 6)] * 5, [(2,)] + [(1, i, i + 1) for i in range(1, 20, 3)] + [(2,)]),
        _travel_case(50, 0, [(i, i + 1) for i in range(1, 50)], [1, 25, 50], [(i, 51 - i) for i in range(1, 25)], [(2,)] + [(1, i, i + 1) for i in range(1, 50, 2)] + [(2,)]),
        _travel_case(100, 0, [(i, i + 1) for i in range(1, 100)], [1, 40, 80, 100], [(i, min(100, i + 50)) for i in range(1, 80)], [(2,)] + [(1, i, i + 1) for i in range(1, 100, 4)] + [(2,)]),
        _travel_case(501, 0, path_edges, [1, 125, 250, 375, 501], path_plans, path_events),
    ]


REGISTRY: dict[str, ProblemDefinition] = {
    "CSP202403-1": ProblemDefinition("CSP202403-1", cases_202403_1, solve_202403_1),
    "CSP202412-2": ProblemDefinition("CSP202412-2", cases_202412_2, solve_202412_2),
    "CSP202412-4": ProblemDefinition("CSP202412-4", cases_202412_4, solve_202412_4),
    "CSP202506-2": ProblemDefinition("CSP202506-2", cases_202506_2, solve_202506_2),
    "CSP202506-3": ProblemDefinition("CSP202506-3", cases_202506_3, solve_202506_3),
    "CSP202509-2": ProblemDefinition("CSP202509-2", cases_202509_2, solve_202509_2),
    "CSP202512-1": ProblemDefinition("CSP202512-1", cases_202512_1, solve_202512_1),
    "CSP202512-2": ProblemDefinition("CSP202512-2", cases_202512_2, solve_202512_2),
    "CSP202512-3": ProblemDefinition("CSP202512-3", cases_202512_3, solve_202512_3),
    "CSP202603-2": ProblemDefinition("CSP202603-2", cases_202603_2, solve_202603_2),
    "CSP202603-3": ProblemDefinition("CSP202603-3", cases_202603_3, solve_202603_3),
    "CSP202603-4": ProblemDefinition("CSP202603-4", cases_202603_4),
    "CSP202603-5": ProblemDefinition("CSP202603-5", cases_202603_5),
}
