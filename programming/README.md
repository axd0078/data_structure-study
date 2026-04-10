# 综合编程题 (Programming)

## 模块简介

`programming` 目录现在按算法思想重新分组，便于按专题刷题和回顾。当前覆盖双指针、二分、动态规划、图搜索、贪心、字符串索引、数学与模拟等方向，大多数文件都包含独立的 `main`，可以单文件编译运行。

## 文件结构

| 目录 | 说明 |
|------|------|
| `double-pointer-and-greedy/` | 双指针、排序与贪心相关题目 |
| `binary-search/` | 二分查找、二分答案、二分优化题目 |
| `dynamic-programming/` | 动态规划题目 |
| `graph-search/` | 图搜索、最短路、DFS 网格题 |
| `greedy/` | 贪心与区间调度类题目 |
| `string-index/` | 字符串索引与检索优化题 |
| `math-and-simulation/` | 数学筛法、矩阵模拟等题目 |
| `test/` | 补充练习题与单独 README |
| `README.md` | 当前目录总览 |

## 分类总览

### 双指针与贪心 `double-pointer-and-greedy/`

| 文件 | 题目 | 核心算法 | 复杂度 |
|------|------|----------|--------|
| `a+b+c=0.cpp` | 三数之和 | 排序 + 双指针 | `O(n^2)` |
| `merge.cpp` | 区间合并 | 排序 + 贪心合并 | `O(n log n)` |
| `meeting.cpp` | 会议室数量 | 排序 + 双指针 | `O(n log n)` |
| `rain.cpp` | 盛最多水的容器 | 双指针 | `O(n)` |
| `rain-plus.cpp` | 接雨水 | 双指针 + 左右最大值维护 | `O(n)` |

### 二分 `binary-search/`

| 文件 | 题目 | 核心算法 | 复杂度 |
|------|------|----------|--------|
| `find-mid.cpp` | 两个有序数组的中位数 | 二分查找 | `O(log(min(m,n)))` |
| `lis-binary.cpp` | 最长递增子序列 | `tails` + 二分 | `O(n log n)` |
| `minEatingSpeed.cpp` | 爱吃香蕉的珂珂 | 二分答案 | `O(n log M)` |
| `shipWithDays.cpp` | 在 D 天内送达包裹的能力 | 二分答案 | `O(n log S)` |

### 动态规划 `dynamic-programming/`

| 文件 | 题目 | 核心算法 | 复杂度 |
|------|------|----------|--------|
| `coinChange.cpp` | 零钱兑换 | 完全背包动态规划 | `O(amount × 硬币种类数)` |
| `lis.cpp` | 最长递增子序列 | 动态规划 / 二分优化对照实现 | `O(n^2)` 或 `O(n log n)` |
| `eraseOverlapIntervals.cpp` | 无重叠区间 | 区间调度 + 前缀 DP / 二分 | `O(n log n)` |
| `lcis.cpp` | 最长连续递增子序列 | 线性动态规划 | `O(n)` |
| `maxSubArray.cpp` | 最大子数组和 | Kadane 动态规划 | `O(n)` |
| `maxEnvelopes.cpp` | 俄罗斯套娃信封问题 | 排序 + LIS 优化 | `O(n log n)` |
| `numSquare.cpp` | 完全平方数 | 动态规划 | `O(n√n)` |

### 图搜索与最短路 `graph-search/`

| 文件 | 题目 | 核心算法 | 复杂度 |
|------|------|----------|--------|
| `dijkstra.cpp` | 最短路径 | Dijkstra（邻接矩阵版） | `O(n^2)` |
| `numOfLand.cpp` | 岛屿数量 | DFS 淹没岛屿 | `O(mn)` |
| `numOfLand2.cpp` | 封闭岛屿数量 | 先淹边界再 DFS 统计 | `O(mn)` |
| `sizeOfLand.cpp` | 封闭岛屿总面积 | DFS 统计面积 | `O(mn)` |
| `sonOfLand.cpp` | 子岛屿数量 | 双网格 DFS | `O(mn)` |
| `numOfDiffLand.cpp` | 不同岛屿数量 | DFS + 相对坐标判重 | `O(mn)` |

### 贪心 `greedy/`

| 文件 | 题目 | 核心算法 | 复杂度 |
|------|------|----------|--------|
| `arrayPairSum.cpp` | 数组拆分 | 排序 + 贪心配对 | `O(n log n)` |
| `candy.cpp` | 分发糖果 | 双向趋势计数贪心 | `O(n)` |
| `eraseOverlapIntervals.cpp` | 无重叠区间 | 按右端点排序 + 区间贪心 | `O(n log n)` |
| `findMinArrowShots.cpp` | 用最少数量的箭引爆气球 | 按右端点排序 + 贪心选点 | `O(n log n)` |
| `increasingDigits.cpp` | 单调递增的数字 | 从右向左回退修正 + 贪心填 9 | `O(d)` |
| `jump.cpp` | 跳跃游戏 | 贪心维护最远可达位置 | `O(n)` |
| `jump2.cpp` | 跳跃游戏 II | 分层贪心 / 区间扩展 | `O(n)` |
| `maxProfit.cpp` | 买卖股票的最佳时机 II | 贪心累加上升段 | `O(n)` |
| `maxSubArray.cpp` | 最大子数组和 | 贪心维护当前贡献和 | `O(n)` |
| `meeting.cpp` | 会议室数量 | 排序 + 小根堆 | `O(n log n)` |
| `wiggleMaxLength.cpp` | 摆动序列 | 贪心记录趋势变化 | `O(n)` |

### 字符串索引 `string-index/`

| 文件 | 题目 | 核心算法 | 复杂度 |
|------|------|----------|--------|
| `countMatchingSubsequences.cpp` | 匹配子序列数量 | 倒排索引 + `upper_bound` | `O(|s| + 单词总长度 × log |s|)` |

### 数学与模拟 `math-and-simulation/`

| 文件 | 题目 | 核心算法 | 复杂度 |
|------|------|----------|--------|
| `countPrimes.cpp` | 计数质数 | 埃氏筛 | `O(n log log n)` |
| `set-matrix-zeroes.cpp` | 矩阵置零 | 标记数组 | `O(mn)` |

额外补充题见 [test/README.md](./test/README.md)。

## 运行方式

```bash
g++ -std=c++11 double-pointer-and-greedy/rain.cpp -o test && ./test
g++ -std=c++11 binary-search/minEatingSpeed.cpp -o test && ./test
g++ -std=c++11 dynamic-programming/coinChange.cpp -o test && ./test
g++ -std=c++11 dynamic-programming/lis.cpp -o test && ./test
g++ -std=c++11 dynamic-programming/eraseOverlapIntervals.cpp -o test && ./test
g++ -std=c++11 dynamic-programming/lcis.cpp -o test && ./test
g++ -std=c++11 dynamic-programming/maxSubArray.cpp -o test && ./test
g++ -std=c++11 dynamic-programming/maxEnvelopes.cpp -o test && ./test
g++ -std=c++11 dynamic-programming/numSquare.cpp -o test && ./test
g++ -std=c++11 graph-search/numOfDiffLand.cpp -o test && ./test
g++ -std=c++11 greedy/arrayPairSum.cpp -o test && ./test
g++ -std=c++11 greedy/candy.cpp -o test && ./test
g++ -std=c++11 greedy/eraseOverlapIntervals.cpp -o test && ./test
g++ -std=c++11 greedy/findMinArrowShots.cpp -o test && ./test
g++ -std=c++11 greedy/increasingDigits.cpp -o test && ./test
g++ -std=c++11 greedy/jump.cpp -o test && ./test
g++ -std=c++11 greedy/jump2.cpp -o test && ./test
g++ -std=c++11 greedy/maxProfit.cpp -o test && ./test
g++ -std=c++11 greedy/maxSubArray.cpp -o test && ./test
g++ -std=c++11 greedy/meeting.cpp -o test && ./test
g++ -std=c++11 greedy/wiggleMaxLength.cpp -o test && ./test
g++ -std=c++11 string-index/countMatchingSubsequences.cpp -o test && ./test
g++ -std=c++11 math-and-simulation/countPrimes.cpp -o test && ./test
```

## 注意事项

- 每个题目的输入格式都由对应文件中的 `main` 决定，运行前建议先阅读源码。
- `rain.cpp` 和 `rain-plus.cpp` 都属于双指针题，但关注点不同：
  - `rain.cpp` 求的是两条边围成的最大容量
- `rain-plus.cpp` 求的是柱状图能够接住的雨水总量
- `minEatingSpeed.cpp` 和 `shipWithDays.cpp` 都属于“二分答案”题型，核心是对可行性进行单调性判断。
- `coinChange.cpp` 和 `numSquare.cpp` 都是典型完全背包 / 一维动态规划题，适合对比状态转移写法。
- `lis.cpp` 同时保留了朴素动态规划和二分优化两个版本，适合对照学习。
- `eraseOverlapIntervals.cpp` 目标是删最少区间，本质上等价于“保留最多个互不重叠区间”。
- `lcis.cpp` 更适合用来理解“连续递增”和“普通 LIS”在状态转移上的区别。
- `maxEnvelopes.cpp` 先按宽度排序，再在高度维度上做 LIS，是二维问题降维的典型例子。
- `arrayPairSum.cpp`、`findMinArrowShots.cpp`、`maxProfit.cpp` 都体现了“局部最优推动全局最优”的贪心思路。
- `candy.cpp` 属于带回看修正的贪心题，比普通区间贪心更适合练状态维护。
- `findMinArrowShots.cpp` 和无重叠区间题都属于典型区间贪心，核心是优先按右端点排序。
- `increasingDigits.cpp` 适合理解“局部违背单调时，向前借位并把后缀全部置 9”的数位贪心。
- `jump.cpp` 和 `jump2.cpp` 是一组很适合对照练习的题：前者判断能否到达，后者求最少跳跃次数。
- `maxSubArray.cpp`、`eraseOverlapIntervals.cpp` 和 `meeting.cpp` 现在都保留了不同思路版本，适合横向对比同题多解。
- `wiggleMaxLength.cpp` 适合用来体会“只保留趋势转折点”这一类贪心判断。
- 岛屿类题目集中在 `graph-search/` 目录，方便统一复习 DFS 网格搜索。
