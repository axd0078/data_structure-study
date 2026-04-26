# 第 7 课：pair、map、set 与计数建模

## 本课目标

使用 STL 做统计、去重、映射和二元数据保存。

## pair

`pair` 用来存两个值：

```cpp
pair<string, int> p = {"alice", 90};
```

常见用途：坐标、姓名和成绩、值和下标。

## map

`map` 是有序映射：

```cpp
map<string, int> cnt;
cnt["apple"]++;
```

遍历时会按 key 从小到大。

## set

`set` 自动去重并排序：

```cpp
set<int> s;
s.insert(3);
s.insert(1);
s.insert(3);
```

最终只有 `1` 和 `3`。

## 本课练习

### 练习 1：整数去重排序

输入 `n` 和 `n` 个整数，输出去重后从小到大的结果。

测试输入：

```text
8
5 3 5 -1 3 2 -1 2
```

测试输出：

```text
-1 2 3 5
```

### 练习 2：单词频次

输入 `n` 和 `n` 个单词，按字典序输出每个单词出现次数。单词可能分布在一行或多行，读取时应使用 `cin >> word`。

测试输入：

```text
5
banana apple banana apple carrot
```

测试输出：

```text
apple 2
banana 2
carrot 1
```

### 练习 3：成绩最高记录

输入多条姓名和分数记录，输出分数最高的记录；如果分数相同，输出姓名字典序最小的。

测试输入：

```text
5
Tom 90
Alice 95
Bob 95
Ann 90
Aaron 95
```

测试输出：

```text
Aaron 95
```

## 复盘点

- `map` 适合要按 key 有序输出的统计题。
- 单词统计用 `cin >> word`，不要用 `getline` 读整行。
- `set` 会自动去重，但不会保留输入顺序。
