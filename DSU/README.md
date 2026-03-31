# 并查集 (Disjoint Set Union)

## 模块简介

`DSU` 目录提供并查集的基础实现与优化实现，用于管理元素所属集合，适合学习连通性判断、集合合并与路径压缩。

## 文件结构

| 文件 | 说明 |
|------|------|
| `dsu.h` | 并查集实现 |
| `test_dsu.cpp` | 测试示例 |

## 关键接口

```c
void init(int s[]);
int find(int s[], int x);
void unionSet(int s[], int root1, int root2);
int findPro(int s[], int x);
void unionPro(int s[], int root1, int root2);
```

## 核心内容

- `find` / `unionSet` 对应基础版并查集。
- `findPro` 使用路径压缩优化查找过程。
- `unionPro` 根据集合规模合并两棵树，减小树高。

## 存储规则

- 根节点位置存储负数，绝对值表示集合大小。
- 非根节点位置存储其父节点下标。
- 当前实现默认数组容量由 `SIZE` 宏控制，值为 `100`。

## 运行方式

```bash
g++ -std=c++11 test_dsu.cpp -o test && ./test
```

## 注意事项

- `unionSet` 和 `unionPro` 需要传入两个集合的根节点，调用前通常先执行 `find` 或 `findPro`。
- 当前优化策略更准确地说是“按集合大小合并”，而不是严格意义上的按秩合并。
