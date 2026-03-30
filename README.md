# 数据结构学习代码

一个面向数据结构与算法练习的 C/C++ 学习仓库，按专题拆分为多个子目录，覆盖顺序表、链表、栈、队列、字符串、二叉树、并查集、图、查找，以及若干经典编程题。

仓库中的大多数题目都采用“单题单文件”的方式组织，便于独立编译、单独调试和按专题复习。

## 项目特点

- 按数据结构模块划分目录，学习路径清晰
- 头文件中保留基础数据结构实现，示例题中聚焦典型算法题
- 大部分 `.cpp` / `.c` 文件自带 `main`，可以直接单文件编译运行
- 既包含基础结构定义，也包含面试/考研常见经典题
- 当前仓库共包含约 `68` 个 `.c` / `.cpp` / `.h` 源码文件

## 目录概览

| 模块 | 内容 | 说明 |
|------|------|------|
| [sqList](./sqList) | 顺序表 | 动态顺序表实现，含删除、去重、旋转、合并、中位数等题目 |
| [linkList](./linkList) | 链表 | 带头结点单链表实现，含反转、相交、倒数第 k 个、判环等题目 |
| [stack](./stack) | 栈 | 顺序栈与链栈实现，包含表达式求值、括号匹配 |
| [queue](./queue) | 队列 | 顺序队列与链队列实现 |
| [sort](./sort) | 排序 | 当前包含直接插入排序、折半插入排序、希尔排序 |
| [string](./string) | 字符串 | 串结构、朴素匹配、KMP、最长公共前缀 |
| [binaryTree](./binaryTree) | 二叉树 | 顺序存储二叉树、线索二叉树与遍历相关示例 |
| [DSU](./DSU) | 并查集 | 基础并查集、路径压缩、按规模合并 |
| [graph](./graph) | 图 | 邻接矩阵、邻接表、BFS、DFS、Floyd |
| [search](./search) | 查找 | 顺序查找、哨兵查找、二分查找 |
| [programming](./programming) | 综合题目 | LIS、Dijkstra、区间合并、会议室、岛屿问题等 |
| [summary](./summary) | 学习总结 | 当前包含空指针检查相关笔记 |

## 适合怎么学

推荐按下面的顺序阅读和练习：

1. `sqList` -> `linkList` -> `stack` -> `queue`
2. `sort` -> `string` -> `search`
3. `binaryTree` -> `DSU` -> `graph`
4. `programming` 中的综合题用于巩固算法思维

如果你是复习导向，可以优先看各目录下的 `README.md`，再挑对应题目单独运行。

## 运行方式

这个仓库没有统一的构建系统，通常按“单文件编译”使用即可。

### Linux / macOS / Git Bash

```bash
g++ -std=c++11 sqList/delete-min.cpp -o test && ./test
g++ -std=c++11 linkList/reverse-list.cpp -o test && ./test
g++ -std=c++11 programming/lis-binary.cpp -o test && ./test
gcc graph/test_graph.c -o test && ./test
```

### Windows PowerShell

```powershell
g++ -std=c++11 .\sqList\delete-min.cpp -o test.exe
.\test.exe

g++ -std=c++11 .\programming\dijkstra.cpp -o test.exe
.\test.exe
```

## 代码组织说明

### 1. 基础结构头文件

一些目录会先提供基础数据结构实现，供题目或测试代码复用，例如：

- `sqList/dynamic.h`
- `linkList/head.h`
- `stack/sequence.h`
- `queue/link.h`
- `graph/matrix.h`

### 2. 单题独立源码

大多数题目文件为独立的 `.cpp`，通常包含：

- 题目对应的数据构造
- 核心算法实现
- `main` 测试入口

这种组织方式比较适合学习阶段逐题验证，不依赖统一工程配置。

### 3. 模块内说明文档

大部分子目录已经包含各自的 `README.md`，会补充：

- 文件用途
- 关键接口
- 典型算法说明
- 对应编译示例

## 代表性内容

### 基础数据结构

- 顺序表的插入、删除、扩容与打印
- 单链表的按位插入、删除、尾插建表、销毁
- 顺序栈、链栈、顺序队列、链队列的基本操作
- 插入排序、折半插入排序、希尔排序
- 图的邻接矩阵与邻接表存储结构

### 经典算法题

- KMP 模式匹配
- 表达式求值与括号匹配
- Floyd 多源最短路
- Dijkstra 单源最短路
- 最长递增子序列（LIS）
- 三数之和、区间合并、会议室问题
- 岛屿数量与封闭岛屿相关 DFS 题

## 注意事项

- 仓库中同时包含 C 和 C++ 文件，编译时请根据扩展名选择 `gcc` 或 `g++`
- 各题目大多是学习型实现，重点在思路表达与结构练习，不一定追求工程化封装
- 部分题目会复用同目录下的头文件，编译时请在仓库根目录执行命令，避免相对路径失效

## 后续可继续完善的方向

- 为更多题目补充输入输出样例
- 增加统一的编译脚本或 `Makefile`
- 为每个模块补充复杂度总结
- 增加测试用例与边界情况说明

## License

[MIT](./LICENSE)
