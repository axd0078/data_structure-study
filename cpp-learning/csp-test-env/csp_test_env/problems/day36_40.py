from __future__ import annotations

from collections import deque

from . import ProblemDefinition


def _lines(values: list[str] | list[int]) -> str:
    return "\n".join(map(str, values)) + "\n"


def _f3(x: int, k: int) -> int:
    return ((x * x + k * k) & 7) ^ k


def _forward_transform(x: int, k: int) -> int:
    a = x >> 6
    b = (x >> 3) & 7
    c = x & 7
    return (b << 6) | ((c ^ _f3(b, k)) << 3) | (a ^ _f3(c, k))


def _inverse_transform(x: int, k: int) -> int:
    b = x >> 6
    middle = (x >> 3) & 7
    low = x & 7
    c = middle ^ _f3(b, k)
    a = low ^ _f3(c, k)
    return (a << 6) | (b << 3) | c


def cases_202512_2() -> list[str]:
    def build(keys: list[int], original: list[int]) -> str:
        mapping = []
        for value in range(512):
            cur = value
            for key in keys:
                cur = _forward_transform(cur, key)
            mapping.append(cur)
        transformed = [mapping[value] for value in original]
        return (
            f"{len(original)} {len(keys)}\n"
            + " ".join(map(str, keys))
            + "\n"
            + " ".join(map(str, transformed))
            + "\n"
        )

    return [
        build([0], [0, 1, 7, 64, 511]),
        build([1, 7, 2], [(i * 37 + 5) % 512 for i in range(20)]),
        build([3, 5], [100, 102, 255, 510]),
        build([i % 8 for i in range(16)], list(range(64))),
        build([(i * 3 + 1) % 8 for i in range(31)], [(i * i + 17) % 512 for i in range(200)]),
        build([(i * 5 + 2) % 8 for i in range(100)], [(i * 19 + 23) % 512 for i in range(1000)]),
        build([7] * 333, [(i * 43 + 9) % 512 for i in range(3000)]),
        build([(i * 7 + 4) % 8 for i in range(600)], [(i * 71 + 3) % 512 for i in range(10000)]),
        build([(i * 11 + 6) % 8 for i in range(1000)], [(i * 97 + 41) % 512 for i in range(100000)]),
        build([(i * 5 + 3) % 8 for i in range(1000)], [(i * 37 + 11) % 512 for i in range(500000)]),
    ]


def solve_202512_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m = nums[:2]
    keys = nums[2 : 2 + m]
    values = nums[2 + m : 2 + m + n]
    decoded = [0] * 512
    for value in range(512):
        cur = value
        for key in reversed(keys):
            cur = _inverse_transform(cur, key)
        decoded[value] = cur
    return " ".join(str(decoded[value]) for value in values) + "\n"


def cases_202603_2() -> list[str]:
    def build(m: int, tasks: list[tuple[int, int, int, int]]) -> str:
        lines = [f"{len(tasks)} {m}"]
        lines.extend(f"{kind} {time} {coffee} {saved}" for kind, time, coffee, saved in tasks)
        return "\n".join(lines) + "\n"

    max_tasks = []
    for i in range(200):
        coffee = i * 7 % 100 + 1
        saved = i * 37 % 5000 + 1
        time = saved + (i * 53 % 4999) + 2
        kind = 1 if i % 4 == 0 else 0
        max_tasks.append((kind, time, coffee, saved))

    return [
        build(1, [(0, 10, 2, 4)]),
        build(6, [(1, 100, 3, 20), (1, 90, 4, 35), (0, 50, 5, 10)]),
        build(10, [(0, 20, 3, 9), (0, 30, 7, 10), (0, 40, 8, 20)]),
        build(12, [(1, 200, 8, 100), (1, 150, 5, 70), (1, 120, 6, 65)]),
        build(25, [(0, 60, 10, 13), (1, 500, 20, 260), (0, 90, 6, 18), (1, 300, 11, 120)]),
        build(100, [(0, 1000, i % 20 + 1, i * 17 % 200 + 1) for i in range(1, 21)]),
        build(250, [(1 if i % 3 == 0 else 0, 300 + i * 9, i % 50 + 1, i * 31 % 250 + 1) for i in range(1, 61)]),
        build(500, [(1 if i % 5 == 0 else 0, 1000 + i * 13, i % 80 + 1, i * 97 % 700 + 1) for i in range(1, 120)]),
        build(1000, [(1, 8000 + i, i % 100 + 1, i * 53 % 3000 + 1) for i in range(1, 201)]),
        build(1000, max_tasks),
    ]


def solve_202603_2(input_text: str) -> str:
    nums = list(map(int, input_text.split()))
    n, m = nums[:2]
    offset = 2
    total = 0.0
    normal: list[tuple[int, float]] = []
    flexible: list[tuple[int, float]] = []
    for _ in range(n):
        kind, time, coffee, saved = nums[offset : offset + 4]
        offset += 4
        total += time
        if kind == 0:
            flexible.append((coffee, float(saved)))
        else:
            normal.append((coffee, float(saved)))

    dp = [0.0] * (m + 1)
    for coffee, saved in normal:
        for used in range(m, coffee - 1, -1):
            dp[used] = max(dp[used], dp[used - coffee] + saved)

    flexible.sort(key=lambda item: item[1] / item[0], reverse=True)
    flexible_saved = [0.0] * (m + 1)
    capacity = 0
    saved_sum = 0.0
    for coffee, saved in flexible:
        for _ in range(coffee):
            if capacity == m:
                break
            capacity += 1
            saved_sum += saved / coffee
            flexible_saved[capacity] = saved_sum
        if capacity == m:
            break
    for i in range(capacity + 1, m + 1):
        flexible_saved[i] = saved_sum

    best = max(dp[used] + flexible_saved[m - used] for used in range(m + 1))
    return f"{total - best:.6f}\n"


def cases_201403_3() -> list[str]:
    def build(spec: str, commands: list[str]) -> str:
        return spec + "\n" + str(len(commands)) + "\n" + "\n".join(commands) + "\n"

    many = []
    for i in range(20):
        many.append(f"tool -a -b val{i} -c -d {i}-x rest")
    return [
        build("a", ["run -a"]),
        build("ab:c", ["cmd -a -b value -c tail", "cmd -b last -b newer -a"]),
        build("x:y:z", ["p -x -y arg -z zz", "p -x", "p -y -x -z ok"]),
        build("mn:o", ["app -m -q -n abc", "app -n 123 -m -o"]),
        build("a:b:c:", ["t -a first -b second -a final", "t -c -a -b data"]),
        build("abcdef", ["x -f -e -d -c -b -a", "x -a -a -a"]),
        build("q:w:e:r:t:y:", ["bin -q 1 -w 2 -e 3 -r 4 -t 5 -y 6"]),
        build("a:b", ["p -a -strange -b", "p -b -a"]),
        build("az:m:n", ["ls -z -a value -m mid -n bad", "ls -n value -z -m final"]),
        build("ab:cd:", many),
    ]


def solve_201403_3(input_text: str) -> str:
    lines = input_text.splitlines()
    spec = lines[0]
    accepts: dict[str, bool] = {}
    i = 0
    while i < len(spec):
        has_arg = i + 1 < len(spec) and spec[i + 1] == ":"
        accepts[spec[i]] = has_arg
        i += 2 if has_arg else 1

    n = int(lines[1])
    out = []
    for case_id in range(1, n + 1):
        tokens = lines[1 + case_id].split()
        used: dict[str, str | None] = {}
        pos = 1
        while pos < len(tokens):
            cur = tokens[pos]
            if len(cur) != 2 or cur[0] != "-" or cur[1] not in accepts:
                break
            option = cur[1]
            if accepts[option]:
                if pos + 1 >= len(tokens):
                    break
                used[option] = tokens[pos + 1]
                pos += 2
            else:
                used[option] = None
                pos += 1
        row = [f"Case {case_id}:"]
        for option in sorted(used):
            row.append(f"-{option}")
            if accepts[option]:
                row.append(str(used[option]))
        out.append(" ".join(row) if len(row) > 1 else row[0])
    return "\n".join(out) + "\n"


def cases_201409_3() -> list[str]:
    def build(pattern: str, sensitive: int, lines: list[str]) -> str:
        return f"{pattern}\n{sensitive}\n{len(lines)}\n" + "\n".join(lines) + "\n"

    return [
        build("abc", 1, ["abc", "abC", "zabcx"]),
        build("abc", 0, ["ABC", "aBcD", "zzz"]),
        build("A", 1, ["a", "A", "AaAa"]),
        build("Needle", 0, ["haystack", "NEEDLE", "NeedLess", "needleIn"]),
        build("zz", 1, ["z", "zz", "zzz", "azZ"]),
        build("Case", 0, ["cASE", "showcase", "CAST", "casecase"]),
        build("LongPattern", 1, ["LongPattern", "longpattern", "PrefixLongPatternSuffix"]),
        build("xYz", 0, [f"line{i}xyzline" if i % 3 == 0 else f"line{i}" for i in range(50)]),
        build("AbCd", 1, ["AbCd" if i % 10 == 0 else "abcd" for i in range(100)]),
        build("Token", 0, [("x" * (i % 30)) + ("TOKEN" if i % 7 == 0 else "other") for i in range(100)]),
    ]


def solve_201409_3(input_text: str) -> str:
    lines = input_text.splitlines()
    pattern = lines[0]
    sensitive = int(lines[1])
    n = int(lines[2])
    query = pattern if sensitive else pattern.lower()
    out = []
    for line in lines[3 : 3 + n]:
        target = line if sensitive else line.lower()
        if query in target:
            out.append(line)
    return "\n".join(out) + ("\n" if out else "")


def _price(cents: int) -> str:
    return f"{cents // 100}.{cents % 100:02d}"


def cases_201412_3() -> list[str]:
    def build(records: list[str]) -> str:
        return "\n".join(records) + "\n"

    max_records = []
    for i in range(1, 2501):
        max_records.append(f"buy {_price(50000 + i % 3000)} {i * 17 % 100000000 + 1}")
        max_records.append(f"sell {_price(48000 + i % 3500)} {i * 31 % 100000000 + 1}")

    return [
        build(["buy 10.00 100", "sell 9.50 80"]),
        build(["buy 8.00 100", "sell 7.90 60", "cancel 1", "buy 8.10 30"]),
        build(["buy 1.01 1", "sell 1.01 1", "buy 1.02 3"]),
        build(["buy 20.00 1000", "buy 19.99 300", "sell 19.50 700", "sell 20.00 100"]),
        build(["buy 5.00 100", "sell 6.00 100", "buy 6.00 10", "sell 5.00 5"]),
        build([f"buy {_price(1000 + i)} {100 + i}" for i in range(50)] + [f"sell {_price(1000 + i)} {200 + i}" for i in range(50)]),
        build([f"buy {_price(3000 + i * 3)} {i * 1000}" for i in range(1, 200)] + [f"sell {_price(2500 + i * 4)} {i * 700}" for i in range(1, 200)]),
        build([f"buy {_price(1000000)} 100000000", "sell 9999.99 99999999", "buy 9999.98 88888888", "sell 9999.97 77777777"]),
        build([f"buy {_price(10000 + i % 100)} {i}" if i % 3 else f"sell {_price(9950 + i % 100)} {i * 2}" for i in range(1, 1000)]),
        build(max_records),
    ]


def _parse_price(text: str) -> int:
    whole, cents = text.split(".")
    return int(whole) * 100 + int(cents)


def solve_201412_3(input_text: str) -> str:
    records = [line.split() for line in input_text.splitlines() if line.strip()]
    canceled = [False] * len(records)
    for i, record in enumerate(records):
        if record[0] == "cancel":
            canceled[int(record[1]) - 1] = True
            canceled[i] = True

    buy: dict[int, int] = {}
    sell: dict[int, int] = {}
    prices = set()
    for i, record in enumerate(records):
        if canceled[i] or record[0] == "cancel":
            continue
        price = _parse_price(record[1])
        amount = int(record[2])
        prices.add(price)
        if record[0] == "buy":
            buy[price] = buy.get(price, 0) + amount
        else:
            sell[price] = sell.get(price, 0) + amount

    buy_ge: dict[int, int] = {}
    total_buy = 0
    for price in sorted(prices, reverse=True):
        total_buy += buy.get(price, 0)
        buy_ge[price] = total_buy

    best_price = 0
    best_volume = 0
    total_sell = 0
    for price in sorted(prices):
        total_sell += sell.get(price, 0)
        volume = min(buy_ge[price], total_sell)
        if volume > best_volume or (volume == best_volume and price > best_price):
            best_volume = volume
            best_price = price
    return f"{best_price // 100}.{best_price % 100:02d} {best_volume}\n"


def cases_201503_3() -> list[str]:
    return [
        "1 1 1 1850 1852\n",
        "2 5 1 1900 1904\n",
        "2 5 7 1999 2001\n",
        "5 2 7 2016 2020\n",
        "11 4 4 2020 2026\n",
        "12 5 7 2000 2005\n",
        "3 3 2 1850 2050\n",
        "6 1 6 1949 1955\n",
        "9 5 1 2030 2050\n",
        "12 4 5 1850 2050\n",
    ]


def solve_201503_3(input_text: str) -> str:
    month, nth, weekday, y1, y2 = map(int, input_text.split())

    def leap(year: int) -> bool:
        return year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)

    def days_in_month(year: int, mon: int) -> int:
        days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        if mon == 2 and leap(year):
            return 29
        return days[mon]

    def weekday_first(year: int, mon: int) -> int:
        days = 0
        for y in range(1850, year):
            days += 366 if leap(y) else 365
        for mm in range(1, mon):
            days += days_in_month(year, mm)
        return (1 + days) % 7 + 1

    out = []
    for year in range(y1, y2 + 1):
        first = weekday_first(year, month)
        day = 1 + (weekday - first + 7) % 7 + (nth - 1) * 7
        if day > days_in_month(year, month):
            out.append("none")
        else:
            out.append(f"{year:04d}/{month:02d}/{day:02d}")
    return "\n".join(out) + "\n"


def cases_201509_3() -> list[str]:
    def build(template: list[str], variables: dict[str, str]) -> str:
        lines = [f"{len(template)} {len(variables)}"]
        lines.extend(template)
        lines.extend(f'{name} "{value}"' for name, value in variables.items())
        return "\n".join(lines) + "\n"

    big_template = [f"row{i}: {{ {{ v{i % 20} }} }}/{{ {{ missing{i % 5} }} }}" for i in range(100)]
    big_template = [row.replace("{ {", "{{").replace("} }", "}}") for row in big_template]
    big_vars = {f"v{i}": f"value-{i}" for i in range(100)}

    return [
        build(["hello {{ name }}"], {"name": "CSP"}),
        build(["{{ a }}{{ b }}{{ c }}"], {"a": "1", "c": "3"}),
        build(["plain text", "missing={{ none }}"], {"x": "unused"}),
        build(["{{ Name }} {{ name }}"], {"Name": "Upper", "name": "lower"}),
        build(["{{ x }}"], {"x": "{{ y }}", "y": "not recursive"}),
        build(["path={{ root }}/{{ file }}"], {"root": "/tmp/data", "file": "a-b_c.txt"}),
        build(["spaces: {{ value }}."], {"value": " leading and trailing "}),
        build([f"line{i} {{ {{ v{i} }} }}" .replace("{ {", "{{").replace("} }", "}}") for i in range(20)], {f"v{i}": str(i * i) for i in range(20)}),
        build(["A{{ a }}B{{ b }}C{{ c }}D" for _ in range(80)], {"a": "x", "b": "y", "c": "z"}),
        build(big_template, big_vars),
    ]


def solve_201509_3(input_text: str) -> str:
    lines = input_text.splitlines()
    m, n = map(int, lines[0].split())
    template = lines[1 : 1 + m]
    variables = {}
    for line in lines[1 + m : 1 + m + n]:
        name, rest = line.split(" ", 1)
        first = rest.find('"')
        last = rest.rfind('"')
        variables[name] = rest[first + 1 : last]

    out = []
    for row in template:
        rendered = []
        pos = 0
        while pos < len(row):
            if row.startswith("{{ ", pos):
                end = row.find(" }}", pos)
                name = row[pos + 3 : end]
                rendered.append(variables.get(name, ""))
                pos = end + 3
            else:
                rendered.append(row[pos])
                pos += 1
        out.append("".join(rendered))
    return "\n".join(out) + "\n"


def cases_201512_3() -> list[str]:
    def build(width: int, height: int, ops: list[str]) -> str:
        return f"{width} {height} {len(ops)}\n" + "\n".join(ops) + ("\n" if ops else "")

    max_ops = []
    for i in range(50):
        max_ops.append(f"1 {(i * 3) % 100} {(i * 7) % 100} {chr(ord('A') + i % 26)}")
    for i in range(25):
        max_ops.append(f"0 0 {(i * 4) % 100} 99 {(i * 4) % 100}")
        max_ops.append(f"0 {(i * 4 + 2) % 100} 0 {(i * 4 + 2) % 100} 99")

    return [
        build(2, 2, []),
        build(5, 5, ["0 0 2 4 2", "0 2 0 2 4"]),
        build(6, 4, ["1 0 0 A", "1 5 3 B"]),
        build(6, 4, ["1 0 0 A", "0 2 0 2 3", "1 0 0 B", "1 3 0 C"]),
        build(8, 6, ["0 1 1 6 1", "0 6 1 6 4", "0 1 4 6 4", "0 1 1 1 4", "1 2 2 X"]),
        build(10, 8, ["1 0 0 C", "1 1 0 C", "1 2 0 D", "1 0 0 E"]),
        build(20, 10, [f"0 0 {i} 19 {i}" for i in range(0, 10, 2)] + ["1 1 1 Z", "1 1 3 Y", "1 1 5 X"]),
        build(30, 30, [f"0 {i} 0 {i} 29" for i in range(0, 30, 3)] + [f"1 {(i * 6 + 1) % 30} {(i * 7 + 1) % 30} M" for i in range(10)]),
        build(50, 50, [f"1 {(i * 11) % 50} {(i * 17) % 50} {chr(65 + i % 26)}" for i in range(60)]),
        build(100, 100, max_ops),
    ]


def solve_201512_3(input_text: str) -> str:
    tokens = input_text.splitlines()
    width, height, q = map(int, tokens[0].split())
    canvas = [["."] * width for _ in range(height)]

    def row(y: int) -> int:
        return height - 1 - y

    def is_line(ch: str) -> bool:
        return ch in "-|+"

    for line in tokens[1 : 1 + q]:
        parts = line.split()
        if parts[0] == "0":
            x1, y1, x2, y2 = map(int, parts[1:])
            if x1 == x2:
                if y1 > y2:
                    y1, y2 = y2, y1
                for y in range(y1, y2 + 1):
                    r = row(y)
                    canvas[r][x1] = "+" if canvas[r][x1] in "-+" else "|"
            else:
                if x1 > x2:
                    x1, x2 = x2, x1
                r = row(y1)
                for x in range(x1, x2 + 1):
                    canvas[r][x] = "+" if canvas[r][x] in "|+" else "-"
        else:
            x, y, ch = int(parts[1]), int(parts[2]), parts[3]
            sr, sc = row(y), x
            if is_line(canvas[sr][sc]):
                continue
            seen = [[False] * width for _ in range(height)]
            que: deque[tuple[int, int]] = deque([(sr, sc)])
            seen[sr][sc] = True
            canvas[sr][sc] = ch
            while que:
                r, c = que.popleft()
                for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                    nr, nc = r + dr, c + dc
                    if not (0 <= nr < height and 0 <= nc < width):
                        continue
                    if seen[nr][nc] or is_line(canvas[nr][nc]):
                        continue
                    seen[nr][nc] = True
                    canvas[nr][nc] = ch
                    que.append((nr, nc))
    return "\n".join("".join(row) for row in canvas) + "\n"


def cases_201604_3() -> list[str]:
    def build(current: str, paths: list[str]) -> str:
        return f"{len(paths)}\n{current}\n" + "\n".join(paths) + "\n"

    long_part = "a" * 90
    long_paths = ["/" + "/".join([long_part, "..", f"dir{i}", ".", "file"]) for i in range(10)]
    return [
        build("/", ["", ".", "..", "a/b"]),
        build("/a/b", ["c", "../d", "/x/y", "////"]),
        build("/root", ["./a/./b", "a//b///c", "../../x"]),
        build("/d2/d3", ["../d4/f1", "/d1/./f1", "/d1///f1"]),
        build("/abc", ["a.b/../c-d/_e", "/../x", "x/../../.."]),
        build("/one/two/three", ["../../four", "", "./././"]),
        build("/r", ["/a/b/c/" for _ in range(10)]),
        build("/cur/dir", [f"../x{i}/./y{i}/.." for i in range(10)]),
        build("/base", ["/" + "/".join(f"d{j}" for j in range(i)) for i in range(1, 11)]),
        build("/root/base", long_paths),
    ]


def solve_201604_3(input_text: str) -> str:
    lines = input_text.splitlines()
    p = int(lines[0])
    current = lines[1]
    paths = lines[2 : 2 + p]
    while len(paths) < p:
        paths.append("")

    def normalize(path: str) -> str:
        stack = []
        if not path.startswith("/"):
            stack = [part for part in current.split("/") if part]
        for part in path.split("/"):
            if part == "" or part == ".":
                continue
            if part == "..":
                if stack:
                    stack.pop()
            else:
                stack.append(part)
        return "/" + "/".join(stack) if stack else "/"

    return "\n".join(normalize(path) for path in paths) + "\n"


def cases_201609_3() -> list[str]:
    def build(ops: list[str]) -> str:
        return str(len(ops)) + "\n" + "\n".join(ops) + ("\n" if ops else "")

    max_ops = ["end" for _ in range(1000)]
    return [
        build([]),
        build(["summon 1 1 5"]),
        build(["summon 1 30 1", "attack 1 0"]),
        build(["summon 1 1 1", "end", "summon 1 30 1", "attack 1 0"]),
        build(["summon 1 3 4", "summon 2 2 3", "end", "summon 1 4 5", "attack 1 1"]),
        build(["summon 1 2 2", "summon 1 3 1", "end", "summon 1 1 10", "attack 1 2", "end", "attack 1 1"]),
        build(["summon 1 1 10" for _ in range(7)]),
        build(["summon 1 5 5", "end", "summon 1 4 4", "summon 2 3 3", "attack 1 1", "end", "attack 1 1"]),
        build(["summon 1 1 20", "end", "summon 1 1 20", "end"] + ["attack 1 1", "end"] * 5),
        build(max_ops),
    ]


def solve_201609_3(input_text: str) -> str:
    lines = input_text.splitlines()
    n = int(lines[0])
    heroes = [30, 30]
    boards: list[list[list[int]]] = [[], []]
    current = 0

    for line in lines[1 : 1 + n]:
        parts = line.split()
        if parts[0] == "summon":
            pos, attack, health = map(int, parts[1:])
            boards[current].insert(pos - 1, [attack, health])
        elif parts[0] == "attack":
            attacker, defender = map(int, parts[1:])
            atk = boards[current][attacker - 1]
            if defender == 0:
                heroes[current ^ 1] -= atk[0]
            else:
                enemy = boards[current ^ 1][defender - 1]
                atk[1] -= enemy[0]
                enemy[1] -= atk[0]
                if enemy[1] <= 0:
                    boards[current ^ 1].pop(defender - 1)
                if atk[1] <= 0:
                    boards[current].pop(attacker - 1)
        else:
            current ^= 1

    result = 1 if heroes[1] <= 0 else -1 if heroes[0] <= 0 else 0
    out = [str(result), str(heroes[0])]
    out.append(" ".join([str(len(boards[0]))] + [str(card[1]) for card in boards[0]]))
    out.append(str(heroes[1]))
    out.append(" ".join([str(len(boards[1]))] + [str(card[1]) for card in boards[1]]))
    return "\n".join(out) + "\n"


REGISTRY: dict[str, ProblemDefinition] = {
    "CSP202512-2": ProblemDefinition("CSP202512-2", cases_202512_2, solve_202512_2),
    "CSP202603-2": ProblemDefinition("CSP202603-2", cases_202603_2, solve_202603_2),
    "CSP201403-3": ProblemDefinition("CSP201403-3", cases_201403_3, solve_201403_3),
    "CSP201409-3": ProblemDefinition("CSP201409-3", cases_201409_3, solve_201409_3),
    "CSP201412-3": ProblemDefinition("CSP201412-3", cases_201412_3, solve_201412_3),
    "CSP201503-3": ProblemDefinition("CSP201503-3", cases_201503_3, solve_201503_3),
    "CSP201509-3": ProblemDefinition("CSP201509-3", cases_201509_3, solve_201509_3),
    "CSP201512-3": ProblemDefinition("CSP201512-3", cases_201512_3, solve_201512_3),
    "CSP201604-3": ProblemDefinition("CSP201604-3", cases_201604_3, solve_201604_3),
    "CSP201609-3": ProblemDefinition("CSP201609-3", cases_201609_3, solve_201609_3),
}
