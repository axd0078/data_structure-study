# 编程补充题 (Programming Test)

## 模块简介

`programming/test` 目录用于存放补充练习题，和主目录下的综合题目相互补充。

## 文件结构

| 文件 | 说明 |
|------|------|
| `abbreviation-check.cpp` | 缩写检查 |
| `bestAttract.cpp` | 最佳异性缘筛选 |
| `boss-time.cpp` | 老板空闲时间统计 |
| `deliver_takeout.cpp` | 外卖配送路径统计 |
| `greedy_multi_round_selection.cpp` | 多轮推荐筛选 |
| `safeCell.cpp` | 安全格子统计 |
| `stack_sequence_builder.cpp.cpp` | 栈辅助序列构造 |

## 题目列表

| 文件 | 题目 | 核心算法 | 复杂度 |
|------|------|----------|--------|
| `abbreviation-check.cpp` | 缩写检查 | 字符串扫描与规则比对 | `O(n)` |
| `bestAttract.cpp` | 最佳异性缘筛选 | Floyd 多源最短路 + 分组最小化最大距离 | `O(n^3)` |
| `boss-time.cpp` | 老板空闲时间统计 | 区间排序 + 空档扫描 | `O(n log n)` |
| `deliver_takeout.cpp` | 外卖配送路径统计 | 树上访问标记 + 深度抵扣 | `O(n + m)` |
| `greedy_multi_round_selection.cpp` | 多轮推荐筛选 | 分数分桶 + 贪心计数 | `O(n + R)` |
| `safeCell.cpp` | 安全格子统计 | 行列去重标记 + 容斥统计 | `O(q + n + m)` |
| `stack_sequence_builder.cpp.cpp` | 栈辅助序列构造 | 栈 + 队列模拟 | `O(n)` |

## 核心内容

`abbreviation-check.cpp` 用于判断一个以下划线分隔的字符串与其缩写是否匹配。核心做法是提取首字符以及每个下划线后的字符，再与目标缩写进行比较。

`bestAttract.cpp` 使用 Floyd 计算所有人之间的最短距离，再分别在女性和男性候选中选择对异性最大距离最小的编号集合。

`boss-time.cpp` 将忙碌时间段转换成秒数并按开始时间排序，通过相邻区间之间的空档输出老板的空闲时间。

`deliver_takeout.cpp` 在树形路径上维护已访问节点和节点深度，每次新增订单只统计新走过的边，并用最深节点抵扣最后一次返程距离。

`greedy_multi_round_selection.cpp` 按天梯赛分数段统计候选人数，并把 PAT 分数达到阈值的学生单独计入，最后按每个分数段最多 `k` 人的规则完成推荐人数统计。

`safeCell.cpp` 用布尔数组记录被攻击过的行和列，再用容斥关系从总格子数中扣除不安全格子，避免重复攻击造成重复扣减。

`stack_sequence_builder.cpp.cpp` 使用队列表示传送带、栈表示辅助盒子，按非递增序列规则构造并输出每一条松枝。

## 运行方式

```bash
g++ -std=c++11 abbreviation-check.cpp -o test && ./test
g++ -std=c++11 bestAttract.cpp -o test && ./test
g++ -std=c++11 boss-time.cpp -o test && ./test
g++ -std=c++11 deliver_takeout.cpp -o test && ./test
g++ -std=c++11 greedy_multi_round_selection.cpp -o test && ./test
g++ -std=c++11 safeCell.cpp -o test && ./test
g++ -std=c++11 stack_sequence_builder.cpp.cpp -o test && ./test
```

## 注意事项

- 每个题目的输入格式都由对应文件中的 `main` 决定，运行前建议先阅读源码。
- `bestAttract.cpp` 的边输入使用 `编号:距离` 形式，结果分两行输出女性和男性候选编号。
- `boss-time.cpp` 按 `HH:MM:SS - HH:MM:SS` 格式读取每个忙碌区间。
- `deliver_takeout.cpp` 会随着订单逐步输出当前最短配送总路程。
- `greedy_multi_round_selection.cpp` 中天梯赛分数段固定按 `175` 到 `290` 统计。
- `safeCell.cpp` 需要注意同一行或同一列被多次攻击时只能计算一次影响。
- `stack_sequence_builder.cpp.cpp` 文件名暂按当前源码保留，编译时请使用完整文件名。
- 如果后续继续扩展补充题，建议保持“一题一文件 + 当前 README 统一索引”的组织方式。
