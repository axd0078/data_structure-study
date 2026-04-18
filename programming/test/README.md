# 编程补充题 (Programming Test)

## 模块简介

`programming/test` 目录用于存放补充练习题，和主目录下的综合题目相互补充。

## 文件结构

| 文件 | 说明 |
|------|------|
| `abbreviation-check.cpp` | 缩写检查 |
| `bestAttract.cpp` | 最佳异性缘筛选 |
| `boss-time.cpp` | 老板空闲时间统计 |
| `chihuoguo.cpp` | 吃火锅文本检索 |
| `deliver_takeout.cpp` | 外卖配送路径统计 |
| `greedy_multi_round_selection.cpp` | 多轮推荐筛选 |
| `guacaipiao.cpp` | 刮彩票九宫格 |
| `nursing-center.cpp` | 养老院管理统计朴素版 |
| `nursing-center-plus.cpp` | 养老院管理统计维护计数版 |
| `nursing-center-pro.cpp` | 养老院管理统计树状数组版 |
| `opposite-number.cpp` | 相反数对统计 |
| `qinshidangan.cpp` | 寝室档案二叉编号 |
| `random-fail.cpp` | 随机输赢策略模拟 |
| `safe-cell.cpp` | 安全格子统计 |
| `stack-calculator.cpp` | 堆栈计算器 |
| `stack_sequence_builder.cpp.cpp` | 栈辅助序列构造 |

## 题目列表

| 文件 | 题目 | 核心算法 | 复杂度 |
|------|------|----------|--------|
| `abbreviation-check.cpp` | 缩写检查 | 字符串扫描与规则比对 | `O(n)` |
| `bestAttract.cpp` | 最佳异性缘筛选 | Floyd 多源最短路 + 分组最小化最大距离 | `O(n^3)` |
| `boss-time.cpp` | 老板空闲时间统计 | 区间排序 + 空档扫描 | `O(n log n)` |
| `chihuoguo.cpp` | 吃火锅文本检索 | 整行读取 + 子串查找 | `O(L)` |
| `deliver_takeout.cpp` | 外卖配送路径统计 | 树上访问标记 + 深度抵扣 | `O(n + m)` |
| `greedy_multi_round_selection.cpp` | 多轮推荐筛选 | 分数分桶 + 贪心计数 | `O(n + R)` |
| `guacaipiao.cpp` | 刮彩票九宫格 | 缺失数字查找 + 固定规则映射 | `O(1)` |
| `nursing-center.cpp` | 养老院管理统计朴素版 | 祖先链逐个查询 | 查询 `O(Nh)` |
| `nursing-center-plus.cpp` | 养老院管理统计维护计数版 | 祖先链增减计数 | 查询 `O(1)`，转移 `O(h)` |
| `nursing-center-pro.cpp` | 养老院管理统计树状数组版 | DFS 序 + 树状数组 | `O((N + M) log V)` |
| `opposite-number.cpp` | 相反数对统计 | 哈希集合查找相反数 | `O(n)` |
| `qinshidangan.cpp` | 寝室档案二叉编号 | 字符路径模拟完全二叉树编号 | `O(MN)` |
| `random-fail.cpp` | 随机输赢策略模拟 | 周期计数 + 石头剪刀布映射 | `O(t)` |
| `safe-cell.cpp` | 安全格子统计 | 行列去重标记 + 容斥统计 | `O(q + n + m)` |
| `stack-calculator.cpp` | 堆栈计算器 | 双栈模拟逆序计算 | `O(n)` |
| `stack_sequence_builder.cpp.cpp` | 栈辅助序列构造 | 栈 + 队列模拟 | `O(n)` |

## 核心内容

`abbreviation-check.cpp` 用于判断一个以下划线分隔的字符串与其缩写是否匹配。核心做法是提取首字符以及每个下划线后的字符，再与目标缩写进行比较。

`bestAttract.cpp` 使用 Floyd 计算所有人之间的最短距离，再分别在女性和男性候选中选择对异性最大距离最小的编号集合。

`boss-time.cpp` 将忙碌时间段转换成秒数并按开始时间排序，通过相邻区间之间的空档输出老板的空闲时间。

`chihuoguo.cpp` 按行读取文本直到遇到 `.`，统计出现关键词 `chi1 huo3 guo1` 的总行数和首次出现位置。

`deliver_takeout.cpp` 在树形路径上维护已访问节点和节点深度，每次新增订单只统计新走过的边，并用最深节点抵扣最后一次返程距离。

`greedy_multi_round_selection.cpp` 按天梯赛分数段统计候选人数，并把 PAT 分数达到阈值的学生单独计入，最后按每个分数段最多 `k` 人的规则完成推荐人数统计。

`guacaipiao.cpp` 先补全九宫格中缺失的数字，再按用户选择的行、列或对角线求和并映射到对应奖金。

`nursing-center.cpp`、`nursing-center-plus.cpp` 和 `nursing-center-pro.cpp` 是同一类养老院管理统计题的三版实现，分别对应朴素祖先查询、维护祖先计数和 DFS 序 + 树状数组优化。

`opposite-number.cpp` 使用哈希集合保存输入数字，只统计正数 `x` 是否存在对应的 `-x`，避免重复计算同一组相反数。

`qinshidangan.cpp` 把由 `y` / 非 `y` 字符组成的路径映射到完全二叉树编号，用于快速输出每条路径对应的档案位置。

`random-fail.cpp` 根据给定轮次周期决定何时故意输一局，其余轮次输出能赢当前手势的选择。

`safe-cell.cpp` 用布尔数组记录被攻击过的行和列，再用容斥关系从总格子数中扣除不安全格子，避免重复攻击造成重复扣减。

`stack-calculator.cpp` 将数字栈和运算符栈按输入顺序压栈，每次弹出两个数字和一个运算符执行 `n2 op n1`，遇到除数为 `0` 时按题目格式输出错误并终止。

`stack_sequence_builder.cpp.cpp` 使用队列表示传送带、栈表示辅助盒子，按非递增序列规则构造并输出每一条松枝。

## 运行方式

```bash
g++ -std=c++11 abbreviation-check.cpp -o test && ./test
g++ -std=c++11 bestAttract.cpp -o test && ./test
g++ -std=c++11 boss-time.cpp -o test && ./test
g++ -std=c++11 chihuoguo.cpp -o test && ./test
g++ -std=c++11 deliver_takeout.cpp -o test && ./test
g++ -std=c++11 greedy_multi_round_selection.cpp -o test && ./test
g++ -std=c++11 guacaipiao.cpp -o test && ./test
g++ -std=c++11 nursing-center.cpp -o test && ./test
g++ -std=c++11 nursing-center-plus.cpp -o test && ./test
g++ -std=c++11 nursing-center-pro.cpp -o test && ./test
g++ -std=c++11 opposite-number.cpp -o test && ./test
g++ -std=c++11 qinshidangan.cpp -o test && ./test
gcc random-fail.cpp -o test && ./test
g++ -std=c++11 safe-cell.cpp -o test && ./test
g++ -std=c++11 stack-calculator.cpp -o test && ./test
g++ -std=c++11 stack_sequence_builder.cpp.cpp -o test && ./test
```

## 注意事项

- 每个题目的输入格式都由对应文件中的 `main` 决定，运行前建议先阅读源码。
- `bestAttract.cpp` 的边输入使用 `编号:距离` 形式，结果分两行输出女性和男性候选编号。
- `boss-time.cpp` 按 `HH:MM:SS - HH:MM:SS` 格式读取每个忙碌区间。
- `chihuoguo.cpp` 使用整行读取，适合处理包含空格的句子。
- `deliver_takeout.cpp` 会随着订单逐步输出当前最短配送总路程。
- `guacaipiao.cpp` 的奖金映射由九宫格选择后的和值决定。
- `greedy_multi_round_selection.cpp` 中天梯赛分数段固定按 `175` 到 `290` 统计。
- `nursing-center-pro.cpp` 使用树状数组，下标必须保持从 `1` 开始。
- `opposite-number.cpp` 只遍历集合中的正数，因此一对 `x` 和 `-x` 只会被统计一次。
- `qinshidangan.cpp` 按路径字符逐层更新完全二叉树中的节点编号。
- `random-fail.cpp` 虽然扩展名是 `.cpp`，但使用的是 C 风格输入输出，`gcc` 或 `g++` 都可编译。
- `safe-cell.cpp` 需要注意同一行或同一列被多次攻击时只能计算一次影响。
- `stack-calculator.cpp` 的除法判断分母是先弹出的 `n1`，错误输出中的分子是后弹出的 `n2`。
- `stack_sequence_builder.cpp.cpp` 文件名暂按当前源码保留，编译时请使用完整文件名。
- 如果后续继续扩展补充题，建议保持“一题一文件 + 当前 README 统一索引”的组织方式。
