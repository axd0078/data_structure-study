# 数据结构学习代码

一个面向数据结构与算法练习的 C/C++ 学习仓库，按专题拆分为多个目录，覆盖顺序表、链表、栈、队列、排序、字符串、二叉树、并查集、图、查找，以及综合编程题和学习总结。

仓库中的大多数题目都采用“单题单文件”的方式组织，便于独立编译、单独调试和按专题复习。

## 项目特点

- 以 `12` 个学习模块组织内容，结构清晰，便于按专题推进。
- 基础数据结构通常放在头文件中，练习题按独立 `.c` / `.cpp` 文件组织。
- 当前仓库包含约 `114` 个 `.c` / `.cpp` / `.h` 源码文件。
- 大多数示例文件自带 `main`，适合直接单文件编译运行。

## 目录概览

| 模块 | 内容 | 说明 |
|------|------|------|
| [sqList](./sqList) | 顺序表 | 动态顺序表实现，以及删除、去重、旋转、合并等练习 |
| [linkList](./linkList) | 链表 | 带头结点单链表实现，以及反转、相交、判环等题目 |
| [stack](./stack) | 栈 | 顺序栈、链栈，以及表达式求值、括号匹配 |
| [queue](./queue) | 队列 | 顺序队列与链队列的基础实现 |
| [sort](./sort) | 排序 | 插入类、交换类、选择类及其他常见排序实现 |
| [string](./string) | 字符串 | 朴素匹配、KMP、最长公共前缀 |
| [binaryTree](./binaryTree) | 二叉树 | 顺序存储二叉树与线索二叉树 |
| [DSU](./DSU) | 并查集 | 基础并查集、路径压缩、按集合大小合并 |
| [graph](./graph) | 图 | 邻接矩阵、邻接表、BFS、DFS、Floyd |
| [search](./search) | 查找 | 顺序查找与二分查找 |
| [programming](./programming) | 综合题目 | 已按算法思想分组的双指针、二分、图搜索、动态规划、贪心等题目 |
| [summary](./summary) | 学习总结 | 指针安全与编码经验类笔记 |

## 推荐学习路径

1. `sqList` -> `linkList` -> `stack` -> `queue`
2. `sort` -> `string` -> `search`
3. `binaryTree` -> `DSU` -> `graph`
4. `programming` 中的综合题用于巩固算法思维
5. `summary` 可作为刷题或写指针代码时的补充阅读

## 运行方式

这个仓库没有统一构建系统，通常按“单文件编译”使用即可。

### Linux / macOS / Git Bash

```bash
g++ -std=c++11 sqList/delete-min.cpp -o test && ./test
g++ -std=c++11 sort/testExchangeSort.cpp -o test && ./test
g++ -std=c++11 programming/string-index/countMatchingSubsequences.cpp -o test && ./test
gcc graph/test_graph.c -o test && ./test
```

### Windows PowerShell

```powershell
g++ -std=c++11 .\sqList\delete-min.cpp -o test.exe
.\test.exe

g++ -std=c++11 .\sort\testExchangeSort.cpp -o test.exe
.\test.exe
```

## 文档组织

- 各学习模块均提供自己的 `README.md`，用于说明文件结构、关键接口和运行方式。
- `programming/test/README.md` 负责补充练习题的单独索引。
- `summary/README.md` 负责整理非源码类学习笔记。

## 代表性内容

### 基础数据结构

- 顺序表、单链表、顺序栈、链栈、顺序队列、链队列
- 邻接矩阵与邻接表两种图存储结构
- 顺序存储二叉树与中序线索二叉树

### 常见算法

- 直接插入排序、折半插入排序、希尔排序、冒泡排序、快速排序、选择排序、堆排序、归并排序、计数排序
- KMP 模式匹配、表达式求值、括号匹配
- Floyd 多源最短路、Dijkstra 单源最短路
- LIS、LCIS、零钱兑换、完全平方数、最大子数组和、俄罗斯套娃信封、无重叠区间、最少箭引爆气球、分发糖果、股票 II、跳跃游戏、跳跃游戏 II、单调递增的数字、摆动序列、三数之和、区间合并、会议室数量
- 岛屿数量、封闭岛屿、子岛屿、不同岛屿等 DFS 题
- 埃氏筛、匹配子序列数量、多轮筛选、安全格子统计、栈辅助序列构造、堆栈计算器、老板空闲时间、外卖路径统计、最佳异性缘筛选、养老院管理统计、吃火锅文本检索、刮彩票等扩展题

## 注意事项

- 仓库中同时包含 C 和 C++ 文件，编译时请根据扩展名选择 `gcc` 或 `g++`。
- 各题目大多是学习型实现，重点在思路表达与结构练习，不强调工程化封装。
- 部分题目会复用同目录下的头文件，建议在仓库根目录执行编译命令，避免相对路径失效。
- 本地编译产物默认通过 `.gitignore` 忽略，建议不要把生成的 `.exe`、`.out` 提交进仓库。

## License

[MIT](./LICENSE)
