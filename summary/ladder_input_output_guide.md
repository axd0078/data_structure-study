# 天梯赛常用输入输出函数总结

天梯赛做题时，输入输出的核心不是背函数，而是先判断数据形态：是单个数、一行多个数、一整行字符串、固定格式、读到 EOF，还是大量数据。选对接收方式，可以减少很多格式错误和超时问题。

## 总体选择表

| 数据形态 | C | C++ | Python |
|------|------|------|------|
| 一个整数 | `scanf("%d", &x)` | `cin >> x` | `int(input())` |
| 多个整数 | `scanf("%d%d", &a, &b)` | `cin >> a >> b` | `map(int, input().split())` |
| 一行整数数组 | 循环 `scanf` | 循环 `cin` 或 `stringstream` | `list(map(int, input().split()))` |
| 很多整数 | 循环 `scanf` | 关同步后循环 `cin` | `sys.stdin.buffer.read().split()` |
| 不含空格字符串 | `scanf("%s", s)` | `cin >> s` | `input().strip()` |
| 含空格整行 | `fgets(s, n, stdin)` | `getline(cin, s)` | `input()` |
| 单个字符 | `scanf(" %c", &ch)` | `cin >> ch` | `input().strip()[0]` |
| 读到 EOF | `while (scanf(...) != EOF)` | `while (cin >> x)` | `for line in sys.stdin` |
| 固定格式 | `scanf("%d:%d", &h, &m)` | 读字符串后解析 | `split` 或切片 |
| 保留小数 | `printf("%.2f", x)` | `fixed << setprecision(2)` | `print(f"{x:.2f}")` |

## C 语言

### 普通数字

```c
int n;
long long x;
double d;

scanf("%d", &n);
scanf("%lld", &x);
scanf("%lf", &d);
```

适合：编号、数量、分数、权值等普通数字。

### 一行多个数据

```c
int a, b, c;
scanf("%d%d%d", &a, &b, &c);
```

`scanf` 会自动跳过空格、换行和制表符，所以不要求这些数必须在同一行。

### 不含空格字符串

```c
char s[1000];
scanf("%s", s);
```

适合：姓名不含空格、编号、单词、命令字符串。

如果字符串可能包含空格，不能用 `%s`。

### 单个字符

```c
char op;
scanf(" %c", &op);
```

`%c` 前面的空格用于跳过前面遗留的换行符。读操作命令时很常用，例如 `T`、`Q`、`E`。

### 一整行字符串

```c
char line[1000];
fgets(line, 1000, stdin);
```

适合：句子、带空格姓名、整行命令。

如果前面刚用过 `scanf`，要处理遗留换行：

```c
getchar();
fgets(line, 1000, stdin);
```

### 读到 EOF

```c
int x;
while (scanf("%d", &x) != EOF) {
    // process x
}
```

适合：题目没有给数据组数，只说“输入到文件结束”。

### 固定格式输入

```c
int h, m, s;
scanf("%d:%d:%d", &h, &m, &s);
```

适合：`HH:MM:SS`、`a:b`、`编号:距离` 这类格式。

### 常用输出

```c
printf("%d\n", ans);
printf("%lld\n", sum);
printf("%.2f\n", avg);
```

## C++

### 加速模板

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

天梯赛用 C++ 时建议写在 `main` 开头。加速后不要再混用 `scanf/printf` 和 `cin/cout`。

### 普通输入

```cpp
int n;
long long x;
double d;
string s;

cin >> n;
cin >> x;
cin >> d;
cin >> s;
```

`cin >> s` 只能读不含空格的字符串。

### 一行多个数

```cpp
int a, b, c;
cin >> a >> b >> c;
```

适合绝大多数普通数字输入。

### 一整行字符串

```cpp
string line;
getline(cin, line);
```

如果前面用了 `cin >> n`，再用 `getline`，要先清理换行：

```cpp
cin.ignore(numeric_limits<streamsize>::max(), '\n');
getline(cin, line);
```

### 每行个数不固定

```cpp
string line;
getline(cin, line);

stringstream ss(line);
int x;
while (ss >> x) {
    // process x
}
```

适合：题目说“一行给出若干整数”，但没有固定数量。

### 读到 EOF

```cpp
int x;
while (cin >> x) {
    // process x
}
```

如果每行是一组复杂数据，可以改成：

```cpp
string line;
while (getline(cin, line)) {
    // process line
}
```

### 固定格式字符串

```cpp
string t;
cin >> t; // 例如 12:30:45

int h = stoi(t.substr(0, 2));
int m = stoi(t.substr(3, 2));
int s = stoi(t.substr(6, 2));
```

也可以用字符变量接收分隔符：

```cpp
int h, m, s;
char c1, c2;
cin >> h >> c1 >> m >> c2 >> s;
```

### 常用输出

```cpp
cout << ans << '\n';
cout << fixed << setprecision(2) << avg << '\n';
```

大量输出时，优先用 `'\n'`，少用 `endl`，因为 `endl` 会刷新缓冲区。

## Python

### 普通输入

```python
n = int(input())
s = input().strip()
```

适合：单个整数、单个字符串。

### 一行多个整数

```python
a, b, c = map(int, input().split())
```

### 一行整数数组

```python
arr = list(map(int, input().split()))
```

### 固定 N 行

```python
n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
```

适合：第一行给数量，后面每行一组数据。

### 读到 EOF

```python
import sys

for line in sys.stdin:
    line = line.strip()
    if not line:
        continue
    # process line
```

适合：输入组数未知。

### 大量数字输入

```python
import sys

data = sys.stdin.buffer.read().split()
nums = list(map(int, data))
```

适合：全是数字、数据量大、对速度要求高。

如果输入里包含普通字符串，可以用：

```python
import sys

data = sys.stdin.read().split()
```

### 固定格式

```python
h, m, s = map(int, input().split(':'))
```

或者用切片：

```python
t = input().strip()  # 12:30:45
h = int(t[0:2])
m = int(t[3:5])
s = int(t[6:8])
```

### 常用输出

```python
print(ans)
print(f"{avg:.2f}")
print(*arr)
```

大量输出时：

```python
out = []
out.append(str(ans))
print('\n'.join(out))
```

## 题面信号与接收方式

| 题面描述 | 推荐处理 |
|------|------|
| “第一行给出 N，随后 N 行” | 先读 `N`，循环 `N` 次 |
| “每行若干整数，直到文件结束” | EOF 读法 |
| “一行给出若干整数” | C++ 用 `stringstream`，Python 用 `split` |
| “姓名/句子可能包含空格” | 整行读取 |
| “HH:MM:SS” | 按 `:` 切分，或字符串切片 |
| “编号:距离” | C 可格式化读，C++/Python 读字符串后解析 |
| “字符矩阵” | C++ 用 `string row`，Python 用 `input().strip()` |
| “操作命令 T x S / Q S / E” | 先读操作字符，再按类型读取剩余参数 |
| “大量整数” | C 用 `scanf`，C++ 关同步，Python 用 `buffer.read` |

## 常见坑

1. **`cin >> x` 后接 `getline`**：必须先 `ignore` 掉换行。
2. **C 读字符时漏空格**：`scanf("%c", &ch)` 可能读到换行，常写成 `scanf(" %c", &ch)`。
3. **含空格字符串不能用普通单词读法**：C 的 `%s`、C++ 的 `cin >> s` 都会在空格处停止。
4. **Python 大数据别一直 `input()`**：数据量大时用 `sys.stdin.readline` 或 `sys.stdin.buffer.read`。
5. **输出格式要精确**：保留几位小数、行末换行、空格分隔都要按题目要求来。
6. **固定格式不要硬猜**：先观察分隔符，能用格式化读取就格式化，不能就读成字符串再解析。

## 记忆口诀

- 普通数字：直接读。
- 一整行：`fgets` / `getline` / `input`。
- 格式特殊：先读字符串，再切分。
- 数据很多：用快读思路。
- 不知道多少组：读到 EOF。
- 字符命令：先读操作，再分支处理。
