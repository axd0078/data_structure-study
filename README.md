# 数据结构学习代码

C/C++ 数据结构练习集合，包含顺序表、链表、栈、队列、字符串、二叉树、并查集、图等数据结构的实现与经典题目。

## 目录

| 模块 | 说明 |
|------|------|
| [sqList](./sqList) | 顺序表 - 动态顺序表实现与 15 道经典题目 |
| [linkList](./linkList) | 链表 - 带头结点单链表实现与 10 道经典题目 |
| [stack](./stack) | 栈 - 顺序栈/链栈实现，表达式求值、括号匹配 |
| [queue](./queue) | 队列 - 顺序队列/链队列实现 |
| [string](./string) | 字符串 - KMP 模式匹配、最长公共前缀 |
| [binaryTree](./binaryTree) | 二叉树 - 顺序存储、线索二叉树 |
| [DSU](./DSU) | 并查集 - 基础实现与路径压缩优化 |
| [graph](./graph) | 图 - 邻接矩阵/邻接表实现，BFS/DFS 遍历 |

## 快速开始

每个 `.cpp` 文件独立可运行，单文件编译即可：

```bash
# 编译运行示例
g++ -std=c++11 sqList/delete-min.cpp -o test && ./test
g++ -std=c++11 linkList/reverse-list.cpp -o test && ./test
```

## 代码特点

- 每个题目独立成文件，内含 `main` 测试入口
- 注释详细，强调指针操作与算法思路
- 复用公共头文件，避免重复代码

## License

[MIT](LICENSE)
