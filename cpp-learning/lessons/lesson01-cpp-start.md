# 第 1 课：从 C 过渡到 C++

## 本课目标

你已经有 C 语言基础，这一课只处理最小迁移成本：会写 C++ 单文件程序、会用 `cin` / `cout`、知道 `bool`、`const` 和基本输出格式。

## 最小程序结构

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    return 0;
}
```

做题时常用 `#include <bits/stdc++.h>`，它会包含大部分常用标准库。正式工程里不推荐这样写，但单文件练习足够方便。

## 输入输出

```cpp
int a, b;
cin >> a >> b;
cout << a + b << '\n';
```

和 C 的 `scanf/printf` 相比，`cin/cout` 更直观，但大量输入时建议加：

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

## bool 与 const

`bool` 表示真假：

```cpp
bool pass = score >= 60;
```

`const` 表示常量：

```cpp
const double PI = 3.1415926;
```

不要把不会改变的值写成普通变量，这样更容易读懂代码意图。

## 本课练习

### 练习 1：两个整数求和

输入两个整数 `a`、`b`，输出它们的和。

测试输入：

```text
3 5
```

测试输出：

```text
8
```

### 练习 2：及格判断

输入一个整数分数 `score`。如果 `score >= 60`，输出 `pass`，否则输出 `fail`。

测试输入：

```text
59
```

测试输出：

```text
fail
```

### 练习 3：圆面积

输入半径 `r`，输出圆面积，结果保留两位小数。圆周率使用 `3.1415926`。

测试输入：

```text
2
```

测试输出：

```text
12.57
```

## 复盘点

- `cin >>` 会自动跳过空白字符。
- 输出小数要用 `fixed << setprecision(...)`。
- 判断题先写清楚条件，再写输出，不要把逻辑塞进复杂表达式。
