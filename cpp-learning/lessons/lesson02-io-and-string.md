# 第 2 课：输入输出与字符串处理

## 本课目标

掌握做题里最常见的输入输出方式，尤其是：

- 数字读入
- 单词读入
- 整行字符串读入
- 字符分类和大小写转换

## 快速输入输出

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

这两行常写在 `main` 开头，作用是让 `cin/cout` 更快。

注意：写了之后不要再混用 `scanf/printf`。

## string 基础

```cpp
string s;
cin >> s;
cout << s.size() << endl;
```

`cin >> s` 只能读到空格前。

如果题目要读整行，就用：

```cpp
string line;
getline(cin, line);
```

如果前面刚用过 `cin >> n`，要先处理缓冲区里的换行：

```cpp
cin.ignore();
getline(cin, line);
```

## 遍历字符串

```cpp
for (char ch : s) {
    cout << ch << endl;
}
```

或者：

```cpp
for (int i = 0; i < (int)s.size(); i++) {
    cout << s[i] << endl;
}
```

## 字符分类函数

```cpp
#include <cctype>
```

常用函数：

- `isdigit(ch)`
- `isalpha(ch)`
- `tolower(ch)`
- `toupper(ch)`

## 本课练习

### 练习 1：输出字符串长度

输入一个不含空格的单词，输出它的长度。

### 练习 2：统计数字字符

输入一行字符串，统计其中数字字符的个数。

### 练习 3：大小写归一

输入一行字符串，把其中所有英文字母转成小写后输出，其他字符保持不变。

## 长题面训练方向

这一课的长题面训练重点不是算法，而是输入。

如果题目里同时出现：

- 整数
- 单词
- 整行描述

一定要先把“每一行怎么读”写清楚，再动手写逻辑。

