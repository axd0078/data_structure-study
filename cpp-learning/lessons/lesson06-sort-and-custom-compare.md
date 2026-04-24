# 第 6 课：sort、比较器与多关键字排序

## 本课目标

掌握 C++ 排序，能对数字、字符串、结构体按题目要求排序。

## 基础排序

```cpp
sort(a.begin(), a.end());
```

默认升序。降序可以写：

```cpp
sort(a.begin(), a.end(), greater<int>());
```

## 自定义比较函数

```cpp
bool cmp(int a, int b) {
    return a > b;
}

sort(v.begin(), v.end(), cmp);
```

比较函数返回 `true` 表示 `a` 应该排在 `b` 前面。

## lambda 写法

```cpp
sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;
});
```

## 结构体排序

```cpp
struct Student {
    string name;
    int score;
};

sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
    if (a.score != b.score) return a.score > b.score;
    return a.name < b.name;
});
```

## 易错点

- 不要写 `return a >= b;`
- 相等时比较器应返回 `false`
- 多关键字排序要先比较第一关键字，不相等就直接返回

## 本课练习

### 练习 1：整数降序

输入 `n` 和 `n` 个整数，按从大到小输出。

### 练习 2：学生成绩排序

输入 `n` 个学生姓名和分数，按分数从高到低排序；分数相同按姓名字典序升序。

### 练习 3：区间排序

输入 `n` 个区间 `[l, r]`，按左端点升序排序；左端点相同按右端点升序排序。

## 长题面训练方向

这一课要重点练“规则翻译”：

题面如果写成：

- 先按 A 排
- 如果 A 相同按 B 排
- 如果 B 还相同按 C 排

你要先把它翻译成自然语言顺序，再写比较器，不要边想边写。

