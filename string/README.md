# 字符串 (String)

## 模块简介

`string` 目录整理了串结构与常见字符串算法，重点包括朴素模式匹配、KMP 模式匹配，以及一个独立的最长公共前缀示例。

## 文件结构

| 文件 | 说明 |
|------|------|
| `string.h` | 串结构定义、朴素匹配、KMP 核心接口 |
| `kmp.cpp` | KMP 相关实现示例 |
| `kmp-test.c` | KMP 测试程序 |
| `longest-common-prefix.cpp` | 最长公共前缀 |

## 关键接口

`string.h` 当前提供的核心接口如下：

```c
int Index(SString s, SString t);
void getNext(SString s, int next[]);
void getNextVal(SString s, int nextval[]);
int IndexKmp(SString s, SString t);
```

## 核心内容

- `Index` 使用朴素匹配，适合对照理解模式串移动过程。
- `getNext` 和 `getNextVal` 分别计算 KMP 的 `next` 与改进版 `nextval` 数组。
- `IndexKmp` 使用 `nextval` 完成 KMP 匹配。
- `longest-common-prefix.cpp` 使用字典序极值法求最长公共前缀，只比较字典序最小和最大的字符串。

## 运行方式

```bash
gcc kmp-test.c -o test && ./test
g++ -std=c++11 longest-common-prefix.cpp -o test && ./test
```

## 注意事项

- 当前串结构 `SString` 的字符下标从 `0` 开始，匹配结果返回的也是下标位置。
- `kmp.cpp` 与 `string.h` 的内容存在一定重叠，适合作为对照学习材料。
- 如果只想快速验证 KMP，优先运行 `kmp-test.c` 即可。
