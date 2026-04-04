# 综合编程题 (Programming)

## 模块简介

`programming` 目录现在按算法思想重新分组，便于按专题刷题和回顾。当前覆盖双指针、二分、动态规划、图搜索、字符串索引、数学与模拟等方向，大多数文件都包含独立的 `main`，可以单文件编译运行。

## 文件结构

| 目录 | 说明 |
|------|------|
| `double-pointer-and-greedy/` | 双指针、排序与贪心相关题目 |
| `binary-search/` | 二分查找、二分答案、二分优化题目 |
| `dynamic-programming/` | 动态规划题目 |
| `graph-search/` | 图搜索、最短路、DFS 网格题 |
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
| `lis.cpp` | 最长递增子序列 | 动态规划 / 二分优化对照实现 | `O(n^2)` 或 `O(n log n)` |

### 图搜索与最短路 `graph-search/`

| 文件 | 题目 | 核心算法 | 复杂度 |
|------|------|----------|--------|
| `dijkstra.cpp` | 最短路径 | Dijkstra（邻接矩阵版） | `O(n^2)` |
| `numOfLand.cpp` | 岛屿数量 | DFS 淹没岛屿 | `O(mn)` |
| `numOfLand2.cpp` | 封闭岛屿数量 | 先淹边界再 DFS 统计 | `O(mn)` |
| `sizeOfLand.cpp` | 封闭岛屿总面积 | DFS 统计面积 | `O(mn)` |
| `sonOfLand.cpp` | 子岛屿数量 | 双网格 DFS | `O(mn)` |
| `numOfDiffLand.cpp` | 不同岛屿数量 | DFS + 相对坐标判重 | `O(mn)` |

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
g++ -std=c++11 dynamic-programming/lis.cpp -o test && ./test
g++ -std=c++11 graph-search/numOfDiffLand.cpp -o test && ./test
g++ -std=c++11 string-index/countMatchingSubsequences.cpp -o test && ./test
g++ -std=c++11 math-and-simulation/countPrimes.cpp -o test && ./test
```

## 注意事项

- 每个题目的输入格式都由对应文件中的 `main` 决定，运行前建议先阅读源码。
- `rain.cpp` 和 `rain-plus.cpp` 都属于双指针题，但关注点不同：
  - `rain.cpp` 求的是两条边围成的最大容量
  - `rain-plus.cpp` 求的是柱状图能够接住的雨水总量
- `minEatingSpeed.cpp` 和 `shipWithDays.cpp` 都属于“二分答案”题型，核心是对可行性进行单调性判断。
- `lis.cpp` 同时保留了朴素动态规划和二分优化两个版本，适合对照学习。
- 岛屿类题目集中在 `graph-search/` 目录，方便统一复习 DFS 网格搜索。
