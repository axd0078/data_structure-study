# 综合编程题 (Programming)

## 模块简介

`programming` 目录收集了若干独立的算法题实现，覆盖数组与双指针、二分、图搜索、最短路、筛法、字符串索引等常见专题。大多数文件都包含各自的 `main`，可以单独编译运行。

## 文件结构

| 文件 | 说明 |
|------|------|
| 当前目录下的 `.cpp` | 主体题目实现 |
| `test/` | 补充练习题与单独 README |
| `README.md` | 题目总览 |

## 题目列表

| 文件 | 题目 | 核心算法 | 复杂度 |
|------|------|----------|--------|
| `a+b+c=0.cpp` | 三数之和 | 排序 + 双指针 | `O(n^2)` |
| `set-matrix-zeroes.cpp` | 矩阵置零 | 标记数组 | `O(mn)` |
| `find-mid.cpp` | 两个有序数组的中位数 | 二分查找 | `O(log(min(m,n)))` |
| `lis-binary.cpp` | 最长递增子序列 | `tails` + 二分 | `O(n log n)` |
| `dijkstra.cpp` | 最短路径 | Dijkstra（邻接矩阵版） | `O(n^2)` |
| `merge.cpp` | 区间合并 | 排序 + 区间合并 | `O(n log n)` |
| `meeting.cpp` | 会议室数量 | 排序 + 双指针 | `O(n log n)` |
| `countPrimes.cpp` | 计数质数 | 埃氏筛 | `O(n log log n)` |
| `countMatchingSubsequences.cpp` | 匹配子序列数量 | 倒排索引 + `upper_bound` | `O(|s| + 单词总长度 × log |s|)` |
| `numOfLand.cpp` | 岛屿数量 | DFS 淹没岛屿 | `O(mn)` |
| `numOfLand2.cpp` | 封闭岛屿数量 | 先淹边界再 DFS 统计 | `O(mn)` |
| `sizeOfLand.cpp` | 封闭岛屿总面积 | DFS 统计面积 | `O(mn)` |
| `sonOfLand.cpp` | 子岛屿数量 | 双网格 DFS | `O(mn)` |
| `numOfDiffLand.cpp` | 不同岛屿数量 | DFS + 相对坐标判重 | `O(mn)` |

额外补充题见 [test/README.md](./test/README.md)。

## 核心内容

- 数组与双指针：`a+b+c=0.cpp`、`merge.cpp`、`meeting.cpp`
- 二分与序列问题：`find-mid.cpp`、`lis-binary.cpp`
- 图与搜索：`dijkstra.cpp` 以及一组岛屿类 DFS 题
- 其他常见技巧：筛法统计质数、匹配子序列的索引加速、矩阵原地标记

## 运行方式

```bash
g++ -std=c++11 a+b+c=0.cpp -o test && ./test
g++ -std=c++11 countPrimes.cpp -o test && ./test
g++ -std=c++11 countMatchingSubsequences.cpp -o test && ./test
g++ -std=c++11 numOfDiffLand.cpp -o test && ./test
g++ -std=c++11 sonOfLand.cpp -o test && ./test
```

## 注意事项

- 每个题目的输入格式都由对应文件中的 `main` 决定，运行前建议先阅读源码。
- 岛屿类题目的当前命名约定为：
  - `numOfLand.cpp`：岛屿数量
  - `numOfLand2.cpp`：封闭岛屿数量
  - `sizeOfLand.cpp`：封闭岛屿总面积
  - `sonOfLand.cpp`：子岛屿数量
  - `numOfDiffLand.cpp`：不同岛屿形状数量
- `countMatchingSubsequences.cpp` 使用字符串位置索引和二分查找，比逐词暴力匹配更高效。
