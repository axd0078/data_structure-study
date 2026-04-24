# 第 4 课：函数拆分、引用、struct 与记录类题目

## 本课目标

从这一课开始，你要逐步摆脱“所有逻辑都写在 `main` 里”的习惯。

本课重点不是语法本身，而是：

1. 什么时候该拆函数。
2. 什么时候该传引用、什么时候传值。
3. 什么时候该用 `struct` 表达一条记录。

## 函数不是为了形式，而是为了减错

如果一个题目里同时有：

- 读入
- 统计
- 排序
- 输出

那把所有逻辑塞在 `main` 里很容易把变量写乱。

比较实用的拆法：

```cpp
readInput(...)
calcAnswer(...)
printAnswer(...)
```

或者：

```cpp
bool check(...)
int solve(...)
```

## 值传递和引用传递

### 值传递

```cpp
void addOne(int x) {
    x++;
}
```

外面的变量不会改变。

### 引用传递

```cpp
void addOne(int &x) {
    x++;
}
```

这是直接改原变量。

### 常量引用

如果参数比较大，又只读不改，优先写：

```cpp
int sumVector(const vector<int> &a) {
    int sum = 0;
    for (int x : a) sum += x;
    return sum;
}
```

这是刷题里最常见、也最推荐的函数参数写法。

## struct 的作用

当一组数据总是一起出现时，不要拆成多个平行数组，优先考虑 `struct`。

例如学生信息：

```cpp
struct Student {
    string name;
    int score;
    int id;
};
```

这样比下面这种更稳：

```cpp
vector<string> names;
vector<int> scores;
vector<int> ids;
```

因为后者排序时很容易同步错位。

## 记录类题目的常见写法

### 1. 找最优记录

```cpp
Student best = students[0];
for (const Student &s : students) {
    if (s.score > best.score) {
        best = s;
    }
}
```

### 2. 排序后输出

```cpp
sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
    if (a.score != b.score) return a.score > b.score;
    return a.name < b.name;
});
```

## 这课最容易错的地方

- `vector` 传参时忘了加 `const &`，导致不必要复制。
- 用引用传参却不清楚函数会改原变量。
- 结构体题目里相等情况没有写清楚。
- 排序后想保留原输入顺序，却没有额外存编号。

## 本课练习

直接完成下面的练习。这一课开始，题目会更明显地要求你把代码“组织起来”。

