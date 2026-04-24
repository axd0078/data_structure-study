# 第 1 课：C 到 C++ 的最小迁移

## 本课目标

你已经会 C 语言，所以这一课不重新讲变量、判断和循环。本课只解决一件事：

> 如何把你熟悉的 C 写法，平稳地迁到做题常用的 C++ 写法。

## 最小 C++ 程序

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello C++" << endl;
    return 0;
}
```

和 C 的对应关系：

| C | C++ |
|---|-----|
| `#include <stdio.h>` | `#include <iostream>` |
| `printf` | `cout` |
| `scanf` | `cin` |
| `0/1` 表示真假 | `bool`、`true`、`false` |

## cin 和 cout

```cpp
int a, b;
cin >> a >> b;
cout << a + b << endl;
```

`cin` 会自动跳过空格和换行，`cout` 可以连续拼接输出。

做题时通常不要输出提示词，只输出题目要求的结果。

## bool

```cpp
bool ok = true;
if (ok) {
    cout << "yes" << endl;
}
```

`bool` 输出时默认显示成 `1` 或 `0`。

## const

```cpp
const double PI = 3.1415926;
```

常用来表示不会变化的值，比如精度、模数、固定上限。

## 本课练习

### 练习 1：两个整数求和

输入两个整数 `a` 和 `b`，输出它们的和。

### 练习 2：是否及格

输入一个整数成绩 `score`。如果大于等于 `60`，输出 `pass`，否则输出 `fail`。

### 练习 3：圆面积

输入一个半径 `r`，输出圆面积，保留两位小数。

提示：使用 `const double PI = 3.1415926;` 和 `fixed << setprecision(2)`。

## 长题面训练方向

这一课不要求题面特别长，但要求你开始养成一个习惯：

1. 先找输入
2. 再找输出
3. 再看规则

只要一开始就把这三件事抓出来，后面的题面再长，你也不会完全乱。

