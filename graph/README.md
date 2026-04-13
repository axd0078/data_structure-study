# 图 (Graph)

## 模块简介

`graph` 目录同时实现了邻接矩阵和邻接表两种图存储结构，并附带 BFS、DFS、Floyd 与 Dijkstra 最短路示例，适合对照理解不同表示方式的差异。

## 文件结构

| 文件 | 说明 |
|------|------|
| `matrix.h` / `matrix_impl.h` | 邻接矩阵定义与基础操作 |
| `linkList.h` / `linkList_impl.h` | 邻接表定义与基础操作 |
| `BFS.cpp` | 广度优先搜索 |
| `DFS.cpp` | 深度优先搜索 |
| `dijkstra.cpp` | Dijkstra 单源最短路 |
| `floyd.cpp` | Floyd 多源最短路 |
| `test_graph.c` | 图结构基础操作测试 |

## 关键接口

### 邻接矩阵 `matrix_impl.h`

代表性接口包括：

```c
void CreateEmptyGraph_M(MGraph* G);
void CreateGraph_M(MGraph* G, int isDirected);
int InsertVertex_M(MGraph* G, VertexType x);
int AddEdge_M(MGraph* G, VertexType x, VertexType y);
int AddEdge_M_V(MGraph* G, VertexType x, VertexType y, EdgeType v);
int RemoveEdge_M(MGraph* G, VertexType x, VertexType y);
void PrintGraph_M(MGraph G);
```

### 邻接表 `linkList_impl.h`

代表性接口包括：

```c
void CreateEmptyGraph_L(LGraph* G);
void CreateGraph_L(LGraph* G, int isDirected);
int InsertVertex_L(LGraph* G, VertexType x);
int AddEdge_L(LGraph* G, VertexType x, VertexType y);
int RemoveEdge_L(LGraph* G, VertexType x, VertexType y);
void PrintGraph_L(LGraph G);
```

## 核心内容

- 邻接矩阵适合稠密图，便于直接访问边权。
- 邻接表适合稀疏图，更节省空间，便于遍历出边。
- `BFS.cpp` 和 `DFS.cpp` 演示图遍历。
- `dijkstra.cpp` 演示基于邻接矩阵的单源最短路径算法。
- `floyd.cpp` 演示基于动态规划的多源最短路径算法。

## 运行方式

```bash
g++ -std=c++11 BFS.cpp -o test && ./test
g++ -std=c++11 DFS.cpp -o test && ./test
g++ -std=c++11 dijkstra.cpp -o test && ./test
g++ -std=c++11 floyd.cpp -o test && ./test
gcc test_graph.c -o test && ./test
```

## 注意事项

- 邻接矩阵版本支持带权边；邻接表基础版本默认不保存边权。
- `isDirected` 用于区分有向图和无向图，不同实现会据此决定是否双向添加边。
- BFS / DFS / Dijkstra / Floyd 属于独立示例文件，与基础存储结构实现是并列关系。
