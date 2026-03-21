# 图 (Graph)

图的邻接矩阵与邻接表实现，以及遍历算法。

## 文件结构

| 文件 | 说明 |
|------|------|
| `matrix.h` | 邻接矩阵定义 |
| `matrix_impl.h` | 邻接矩阵实现 |
| `linkList.h` | 邻接表定义 |
| `linkList_impl.h` | 邻接表实现 |
| `BFS.cpp` | 广度优先搜索 |
| `DFS.cpp` | 深度优先搜索 |
| `floyd.cpp` | Floyd最短路径算法 |
| `test_graph.c` | 测试示例 |

## 存储结构

### 邻接矩阵 (MGraph)

使用二维数组存储边，适合稠密图。

```c
typedef struct {
    VertexType vex[MaxVertexNum];       // 顶点表
    EdgeType edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵
    int vexNum, edgeNum;                // 顶点数、边数
    int isDirected;                     // 0:无向图  1:有向图
} MGraph;
```

### 邻接表 (LGraph)

使用链表存储边，适合稀疏图。

```c
typedef struct ArcNode {    // 边表结点
    int adjvex;             // 邻接顶点
    struct ArcNode* nextArc;
} ArcNode;

typedef struct VNode {      // 顶点表结点
    VertexType data;
    ArcNode* firstArc;
} VNode;

typedef struct {
    AdjList vertices;       // 邻接表
    int vexNum, arcNum;
    int isDirected;
} LGraph;
```

## 核心算法

| 算法 | 文件 | 说明 |
|------|------|------|
| BFS | `BFS.cpp` | 广度优先搜索，使用队列 |
| DFS | `DFS.cpp` | 深度优先搜索，递归/栈实现 |
| Floyd | `floyd.cpp` | 多源最短路径，动态规划 |

## 运行示例

```bash
# BFS 测试
g++ -std=c++11 BFS.cpp -o test && ./test

# DFS 测试
g++ -std=c++11 DFS.cpp -o test && ./test

# Floyd 最短路径
g++ -std=c++11 floyd.cpp -o test && ./test

# 图结构测试
gcc test_graph.c -o test && ./test
```
