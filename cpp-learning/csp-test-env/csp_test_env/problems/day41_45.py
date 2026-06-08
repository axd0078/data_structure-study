from __future__ import annotations

from . import ProblemDefinition


def _lines(values: list[str] | list[int]) -> str:
    return "\n".join(map(str, values)) + "\n"


def cases_201612_3() -> list[str]:
    def build(
        permissions: list[str],
        roles: list[tuple[str, list[str]]],
        users: list[tuple[str, list[str]]],
        queries: list[tuple[str, str]],
    ) -> str:
        lines = [str(len(permissions)), *permissions, str(len(roles))]
        lines.extend(f"{name} {len(perms)}" + ("" if not perms else " " + " ".join(perms)) for name, perms in roles)
        lines.append(str(len(users)))
        lines.extend(f"{name} {len(role_names)}" + ("" if not role_names else " " + " ".join(role_names)) for name, role_names in users)
        lines.append(str(len(queries)))
        lines.extend(f"{name} {permission}" for name, permission in queries)
        return _lines(lines)

    big_permissions = [f"perm{i}" for i in range(20)] + [f"level{i}:9" for i in range(20)]
    big_roles = [(f"role{i}", [f"perm{i % 20}", f"level{i % 20}:{i % 10}"]) for i in range(30)]
    big_users = [(f"user{i}", [f"role{i % 30}", f"role{(i + 7) % 30}"]) for i in range(50)]
    big_queries = [(f"user{i % 50}", f"level{i % 20}" if i % 2 == 0 else f"perm{i % 20}") for i in range(200)]
    return [
        build(["read", "write", "disk:5"], [("admin", ["read", "write", "disk:5"])], [("alice", ["admin"])], [("alice", "read"), ("alice", "disk"), ("alice", "disk:3")]),
        build(["read", "write"], [("guest", ["read"])], [("bob", ["guest"])], [("bob", "write"), ("bob", "read")]),
        build(["file:3", "net:2"], [("a", ["file:1"]), ("b", ["file:3", "net:2"])], [("u", ["a", "b"])], [("u", "file"), ("u", "file:2"), ("u", "net:3")]),
        build(["x", "y:4"], [("empty", []), ("r", ["y:2"])], [("nobody", []), ("tom", ["empty", "r"])], [("tom", "x"), ("tom", "y"), ("nobody", "y:0")]),
        build(["p:9"], [("low", ["p:2"]), ("mid", ["p:5"]), ("high", ["p:9"])], [("sam", ["low", "mid"])], [("sam", "p"), ("sam", "p:6"), ("sam", "p:5")]),
        build(["a", "b", "c:7"], [("r1", ["a", "c:1"]), ("r2", ["b", "c:4"])], [("u1", ["r1"]), ("u2", ["r2"]), ("u3", ["r1", "r2"])], [("u3", "a"), ("u3", "b"), ("u3", "c")]),
        build(["alpha", "beta:1"], [("ra", ["alpha"]), ("rb", ["beta:1"])], [("mix", ["ra", "rb"])], [("mix", "beta:1"), ("mix", "beta"), ("mix", "gamma")]),
        build([f"p{i}" for i in range(8)], [(f"r{i}", [f"p{i}", f"p{(i + 1) % 8}"]) for i in range(8)], [("u", [f"r{i}" for i in range(8)])], [("u", f"p{i}") for i in range(8)]),
        build(["db:4", "api", "cache:2"], [("dev", ["api", "cache:1"]), ("ops", ["db:4", "cache:2"])], [("li", ["dev"]), ("chen", ["ops"]), ("all", ["dev", "ops"])], [("all", "db"), ("li", "cache:2"), ("chen", "api")]),
        build(big_permissions, big_roles, big_users, big_queries),
    ]


def cases_201703_3() -> list[str]:
    big = []
    for i in range(40):
        big.append(f"# Section {i}")
        big.append("")
        big.append(f"* item _{i}_")
        big.append(f"* [link{i}](http://example.com/{i})")
        big.append("")
        big.append(f"paragraph {i} with _em_ and [go](target{i}).")
        big.append("")
    return [
        "# Title\n\nhello world\n",
        "plain text\ncontinues here\n\n# H2\n",
        "* apple\n* banana\n* cherry\n",
        "A _small_ paragraph with [one](url).\n",
        "# A\n\n* _x_\n* [y](z)\n\nnormal\n",
        "This is [a _mixed_ link](dest) and _em [inside](url)_.\n",
        "## Sub Title\n\n#Not heading\n\n* list item\ntext paragraph\n",
        "first paragraph\n\nsecond paragraph line1\nsecond paragraph line2\n\n### third\n",
        "* [a](x)\n* _b_\n\ntext _one_ [two](three)\n",
        "\n".join(big).rstrip() + "\n",
    ]


def cases_201709_3() -> list[str]:
    def build(json_lines: list[str], queries: list[str]) -> str:
        return _lines([f"{len(json_lines)} {len(queries)}", *json_lines, *queries])

    big_pairs = ",".join(f'"k{i}":{{"v":"{i}","next":{{"x":"{i * i}"}}}}' for i in range(60))
    return [
        build(['{"name":"alice","city":"nanjing"}'], ["name", "city", "none"]),
        build(['{"a":{"b":"c"},"x":"y"}'], ["a", "a.b", "x", "a.c"]),
        build(['{"path":"C:\\\\tmp","quote":"say \\"hi\\""}'], ["path", "quote"]),
        build(['{', '"root":{', '"left":"L",', '"right":{"deep":"D"}', '}', '}'], ["root", "root.right", "root.right.deep"]),
        build(['{"a":{"b":{"c":{"d":"end"}}}}'], ["a.b.c.d", "a.b", "a.b.x"]),
        build(['{"empty":{},"s":"text"}'], ["empty", "empty.any", "s"]),
        build(['{"A":"upper","a":"lower","mix":{"Key":"Value"}}'], ["A", "a", "mix.Key", "mix.key"]),
        build(['{"url":"http://a.b/c","dot":{"name":"ok"}}'], ["url", "dot.name"]),
        build(['{"outer":{"inner":{"value":"123","escaped":"x\\\\y"}},"plain":"p"}'], ["outer.inner.escaped", "plain", "outer.inner"]),
        build(["{" + big_pairs + "}"], [f"k{i}.next.x" if i % 3 == 0 else f"k{i}.v" for i in range(60)] + ["missing"]),
    ]


def cases_201712_3() -> list[str]:
    def build(start: str, finish: str, rules: list[str]) -> str:
        return _lines([f"{len(rules)} {start} {finish}", *rules])

    many_rules = [f"{i % 60} {i % 24} 1 Jan * job{i}" for i in range(100)]
    return [
        build("201801010000", "201801020000", ["0 0 * * * midnight"]),
        build("201801010000", "201801072359", ["30 8 * * Mon wake", "0 12 * * * noon"]),
        build("201802010000", "201802282359", ["0 0 1,14,28 Feb * mark"]),
        build("201803010000", "201803312359", ["5-7 10 * Mar Thu range"]),
        build("201804010000", "201804302359", ["0,30 9-10 * Apr * half"]),
        build("201805010000", "201806302359", ["15 6 1 May,Jun * firstday"]),
        build("201807010000", "201807152359", ["0 0 * * Sun sunday", "0 0 8-10 Jul * days"]),
        build("201812300000", "201901022359", ["59 23 * * * night", "0 0 1 Jan * newyear"]),
        build("201901010000", "201912312359", ["0 0 1 * Tue monthstart", "45 18 * Dec * december"]),
        build("201801010000", "202512312359", many_rules),
    ]


def cases_201803_3() -> list[str]:
    def build(rules: list[tuple[str, str]], urls: list[str]) -> str:
        lines = [f"{len(rules)} {len(urls)}"]
        lines.extend(f"{pattern} {name}" for pattern, name in rules)
        lines.extend(urls)
        return _lines(lines)

    big_rules = [(f"/api/v{i}/<int>/item/<str>", f"r{i}") for i in range(60)]
    big_urls = [f"/api/v{i % 60}/{i:04d}/item/name{i}" for i in range(120)]
    return [
        build([("/user/<int>", "user")], ["/user/001", "/user/a"]),
        build([("/article/<str>", "article"), ("/article/list", "list")], ["/article/list", "/article/abc"]),
        build([("/file/<path>", "file")], ["/file/a/b/c", "/file/"]),
        build([("/a/<int>/b/<str>", "mix")], ["/a/0007/b/xy", "/a/7/b/"]),
        build([("/static", "s"), ("/static/", "slash")], ["/static", "/static/"]),
        build([("/x/<str>", "x"), ("/x/<int>", "xi")], ["/x/123", "/x/abc"]),
        build([("/root/<path>", "root"), ("/root/<str>", "child")], ["/root/a", "/root/a/b"]),
        build([("/p/<int>/<int>", "pair"), ("/p/<str>/<str>", "words")], ["/p/01/002", "/p/a/b"]),
        build([("/download/<path>", "dl"), ("/download/<int>", "id")], ["/download/0009", "/download/a/b/c"]),
        build(big_rules, big_urls),
    ]


def cases_201809_3() -> list[str]:
    def build(document: list[str], queries: list[str]) -> str:
        return _lines([f"{len(document)} {len(queries)}", *document, *queries])

    big_doc = ["html #root"]
    for i in range(40):
        big_doc.append("..section")
        big_doc.append(f"....div #d{i}")
        big_doc.append("......span")
    big_queries = ["div", "section div", "#d17", "html section span", "span"]
    return [
        build(["html", "..body", "....div #main"], ["html", "body", "#main"]),
        build(["HTML #root", "..Div #box", "....span"], ["html div", "HTML Div", "div span"]),
        build(["a #x", "..b #y", "....c #z"], ["a c", "#x #z", "b #z"]),
        build(["div", "..div #inner", "..p"], ["div", "div div", "p"]),
        build(["ul", "..li #a", "..li #b", "....span"], ["ul li", "li span", "#b span"]),
        build(["page", "..header #h", "..main", "....article #a", "......p"], ["page p", "main article", "#h p"]),
        build(["a", "..b", "....c", "..c"], ["a c", "b c", "a b c"]),
        build(["Root #R", "..Child #C", "....Leaf #L"], ["root #C", "#R leaf", "#C #L"]),
        build(["x", "..y", "....z #last", "..z #side"], ["x z", "y z", "#side"]),
        build(big_doc, big_queries),
    ]


def cases_201812_3() -> list[str]:
    def build(prefixes: list[str]) -> str:
        return _lines([len(prefixes), *prefixes])

    big = [f"10.{i // 256}.{i % 256}.0/24" for i in range(512)]
    return [
        build(["192.168.1.1", "192.168.1.0/24"]),
        build(["10.0.0.0/9", "10.128.0.0/9"]),
        build(["1.2/16", "1.2.3/24", "1.2.3.4/32"]),
        build(["0.0.0.0/1", "128.0.0.0/1"]),
        build(["172.16.0.0/16", "172.17.0.0/16", "172.18.0.0/16"]),
        build(["192.0.2.0/25", "192.0.2.128/25", "198.51.100.1"]),
        build(["8.8.8.8", "8.8.4.4", "8.8.0.0/16"]),
        build(["100.64.0.0/10", "100.64.0.0/11", "100.96.0.0/11"]),
        build(["203.0.113.0/24", "203.0.114.0/24", "203.0.112.0/23"]),
        build(big),
    ]


def _hex32(value: int) -> str:
    return f"{value & 0xFFFFFFFF:08X}"


def _raid_case(n: int, s: int, present: list[int], logical_blocks: list[int], queries: list[int]) -> str:
    data_per_row = (n - 1) * s
    rows = max(1, (len(logical_blocks) + data_per_row - 1) // data_per_row)
    disks = [[0 for _ in range(rows * s)] for _ in range(n)]
    padded = list(logical_blocks) + [0] * (rows * data_per_row - len(logical_blocks))
    index = 0
    for row in range(rows):
        parity = n - 1 - row % n
        for data_col in range(n - 1):
            disk = data_col if data_col < parity else data_col + 1
            for offset in range(s):
                disks[disk][row * s + offset] = padded[index]
                index += 1
        for offset in range(s):
            value = 0
            for disk in range(n):
                if disk != parity:
                    value ^= disks[disk][row * s + offset]
            disks[parity][row * s + offset] = value

    lines = [f"{n} {s} {len(present)}"]
    for disk in present:
        lines.append(f"{disk} {''.join(_hex32(value) for value in disks[disk])}")
    lines.append(str(len(queries)))
    lines.extend(str(query) for query in queries)
    return _lines(lines)


def cases_201903_3() -> list[str]:
    return [
        _raid_case(3, 1, [0, 1, 2], [1, 2, 3, 4], [0, 1, 2, 3, 4]),
        _raid_case(3, 1, [0, 2], [10, 20, 30, 40, 50, 60], [0, 1, 2, 3, 4, 5]),
        _raid_case(4, 2, [0, 1, 2, 3], [i * 17 + 5 for i in range(18)], list(range(18))),
        _raid_case(4, 2, [0, 1, 3], [i + 100 for i in range(24)], [0, 5, 6, 11, 18, 23, 24]),
        _raid_case(5, 1, [1, 2, 3, 4], [i * i for i in range(20)], [0, 3, 4, 9, 15, 19]),
        _raid_case(5, 3, [0, 2, 3, 4], [0xABCDEF00 + i for i in range(60)], [0, 1, 17, 18, 35, 59, 60]),
        _raid_case(6, 2, [0, 1, 2, 4, 5], [i * 1234567 for i in range(80)], [0, 7, 18, 39, 79, 80]),
        _raid_case(6, 4, [0, 2, 3, 4, 5], [0x1000 + i * 31 for i in range(120)], [0, 20, 47, 88, 119, 120]),
        _raid_case(7, 2, [0, 1, 2, 3, 4, 5, 6], [i ^ (i << 8) for i in range(150)], [0, 23, 64, 149, 150]),
        _raid_case(8, 8, [0, 1, 2, 3, 5, 6, 7], [0xCAFE0000 + i * 97 for i in range(2000)], [0, 99, 255, 700, 1234, 1999, 2000]),
    ]


def cases_201909_3() -> list[str]:
    def build(m: int, n: int, p: int, q: int, rows: list[list[str]]) -> str:
        return _lines([f"{m} {n} {p} {q}", *(" ".join(row) for row in rows)])

    big_rows = []
    for i in range(20):
        row = []
        for j in range(20):
            row.append(f"#{(i * 13 + j * 7) % 256:02x}{(i * 5 + j * 11) % 256:02x}{(i * 17 + j * 3) % 256:02x}")
        big_rows.append(row)
    return [
        build(1, 1, 1, 1, [["#000000"]]),
        build(2, 1, 1, 1, [["#ffffff", "#000000"]]),
        build(2, 2, 2, 2, [["#000", "#fff"], ["#fff", "#000"]]),
        build(4, 2, 2, 1, [["#123456", "#123456", "#654321", "#654321"], ["#111111", "#222222", "#333333", "#444444"]]),
        build(3, 3, 1, 3, [["#f00", "#0f0", "#00f"], ["#f00", "#0f0", "#00f"], ["#000", "#000", "#000"]]),
        build(4, 4, 2, 2, [[f"#{i}{j}{(i + j) % 10}" for j in range(4)] for i in range(4)]),
        build(6, 2, 3, 1, [["#000000", "#111111", "#222222", "#333333", "#444444", "#555555"], ["#666666", "#777777", "#888888", "#999999", "#aaaaaa", "#bbbbbb"]]),
        build(4, 6, 1, 2, [[f"#{(i * 4 + j) % 16:x}" for j in range(4)] for i in range(6)]),
        build(8, 8, 2, 2, [[f"#{(i * 31 + j * 17) % 256:02X}00{(i * 7 + j * 9) % 256:02X}" for j in range(8)] for i in range(8)]),
        build(20, 20, 2, 2, big_rows),
    ]


def cases_201912_3() -> list[str]:
    equations = [
        ["H2+O2=H2O", "2H2+O2=2H2O"],
        ["CO2+H2O=H2CO3", "C6H12O6=6C+6H2O"],
        ["Ca(OH)2+CO2=CaCO3+H2O", "NaCl+AgNO3=AgCl+NaNO3"],
        ["Fe2O3+3CO=2Fe+3CO2", "Fe+O2=Fe2O3"],
        ["2Na+2H2O=2NaOH+H2", "Na+H2O=NaOH+H2"],
        ["Al2(SO4)3+3BaCl2=3BaSO4+2AlCl3", "K4(ON(SO3)2)2=K4O2N2S4O12"],
        ["CH4+2O2=CO2+2H2O", "C2H6+O2=CO2+H2O"],
        ["3Mg(OH)2+2H3PO4=Mg3(PO4)2+6H2O", "Mg(OH)2+H3PO4=MgPO4+H2O"],
        ["(NH4)2SO4+2NaOH=Na2SO4+2NH3+2H2O", "NH4Cl+NaOH=NaCl+NH3+H2O"],
        [f"{i}H2+O2={i}H2O" if i % 2 == 0 else f"{i}CO2+{i}H2O={i}H2CO3" for i in range(1, 101)],
    ]
    return [_lines([len(case), *case]) for case in equations]


REGISTRY: dict[str, ProblemDefinition] = {
    "CSP201612-3": ProblemDefinition("CSP201612-3", cases_201612_3),
    "CSP201703-3": ProblemDefinition("CSP201703-3", cases_201703_3),
    "CSP201709-3": ProblemDefinition("CSP201709-3", cases_201709_3),
    "CSP201712-3": ProblemDefinition("CSP201712-3", cases_201712_3),
    "CSP201803-3": ProblemDefinition("CSP201803-3", cases_201803_3),
    "CSP201809-3": ProblemDefinition("CSP201809-3", cases_201809_3),
    "CSP201812-3": ProblemDefinition("CSP201812-3", cases_201812_3),
    "CSP201903-3": ProblemDefinition("CSP201903-3", cases_201903_3),
    "CSP201909-3": ProblemDefinition("CSP201909-3", cases_201909_3),
    "CSP201912-3": ProblemDefinition("CSP201912-3", cases_201912_3),
}
