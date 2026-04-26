# 第 6 课：sort、比较器与多关键字排序

## 本课目标

掌握 C++ 排序，能对数字、字符串、结构体按题目要求排序。

## 基础排序

升序：

```cpp
sort(a.begin(), a.end());
```

降序：

```cpp
sort(a.begin(), a.end(), greater<int>());
```

## 自定义比较器

```cpp
sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;
});
```

比较器返回 `true` 表示 `a` 应该排在 `b` 前面。

不要写：

```cpp
return a >= b;
```

相等时比较器应返回 `false`，否则排序规则不严格，可能出问题。

## 多关键字排序

```cpp
sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
    if (a.score != b.score) return a.score > b.score;
    return a.name < b.name;
});
```

先比较第一关键字，不相等就直接返回；相等再比较第二关键字。

## 本课练习

### 练习 1：整数降序

输入 `n` 和 `n` 个整数，按从大到小输出。

测试输入：

```text
7
3 -1 3 0 9 9 -5
```

测试输出：

```text
9 9 3 3 0 -1 -5
```

### 练习 2：学生成绩排序

输入 `n` 个学生姓名和分数，按分数从高到低排序；分数相同按姓名字典序升序排序。

测试输入：

```text
5
Bob 90
Alice 95
Tom 90
Ann 90
Zed 95
```

测试输出：

```text
Alice 95
Zed 95
Ann 90
Bob 90
Tom 90
```

### 练习 3：区间排序

输入 `n` 个区间 `[l, r]`，按左端点升序排序；左端点相同按右端点升序排序。

测试输入：

```text
6
3 5
1 9
1 2
-1 4
3 1
-1 0
```

测试输出：

```text
-1 0
-1 4
1 2
1 9
3 1
3 5
```

## 复盘点

- 比较器必须表达“严格排在前面”。
- 多关键字排序要按题目顺序逐层判断。
- 如果需要稳定保留原顺序，可以额外保存输入编号。
