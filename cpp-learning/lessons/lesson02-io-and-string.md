# 第 2 课：输入输出与 string

## 本课目标

掌握 `string` 的读入、长度、逐字符遍历，以及 `getline` 和 `cin >>` 的区别。

## string 基础

```cpp
string s;
cin >> s;
cout << s.size() << '\n';
```

`cin >> s` 只读到空白字符前。如果一整行里可能有空格，要用：

```cpp
getline(cin, s);
```

如果前面刚用过 `cin >> n`，再用 `getline`，要先处理残留换行：

```cpp
cin.ignore();
getline(cin, s);
```

## 字符处理

常用函数在 `<cctype>` 中：

```cpp
isdigit(ch)
isalpha(ch)
tolower(ch)
toupper(ch)
```

做普通英文和数字题时直接用即可。

## 本课练习

### 练习 1：输出字符串长度

输入一个不含空格的字符串，输出它的长度。

测试输入：

```text
csp2026
```

测试输出：

```text
7
```

### 练习 2：统计数字字符

输入一行字符串，统计其中数字字符的个数。

测试输入：

```text
a12b305
```

测试输出：

```text
5
```

### 练习 3：整行转小写

输入一整行字符串，将其中英文字母全部转为小写，其他字符保持不变。

测试输入：

```text
Hello Cpp 2026!
```

测试输出：

```text
hello cpp 2026!
```

## 复盘点

- 单词读入用 `cin >> s`。
- 整行读入用 `getline(cin, s)`。
- 前面如果用了 `cin >>`，后面马上 `getline`，通常要先 `cin.ignore()`。
