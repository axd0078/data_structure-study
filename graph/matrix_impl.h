#ifndef MATRIX_IMPL_H
#define MATRIX_IMPL_H

#include "matrix.h"
#include <stdio.h>
#include <string.h>

/*============== 辅助函数 ==============*/

// 获取顶点x在图中的位置，若不存在返回-1
int LocateVex_M(MGraph G, VertexType x) {
    for (int i = 0; i < G.vexNum; i++) {
        if (G.vex[i] == x) {
            return i;
        }
    }
    return -1;
}

/*============== 基本操作实现 ==============*/

// 1. Adjacent(G, x, y)：判断图 G 中是否存在边 <x, y> 或 (x, y)
int Adjacent_M(MGraph G, VertexType x, VertexType y) {
    int i = LocateVex_M(G, x);
    int j = LocateVex_M(G, y);
    if (i == -1 || j == -1) {
        return 0;  // 顶点不存在
    }
    return G.edge[i][j] != 0;  // 假设0表示不存在边
}

// 2. Neighbors(G, x)：列出图 G 中与顶点 x 邻接的所有边
void Neighbors_M(MGraph G, VertexType x) {
    int i = LocateVex_M(G, x);
    if (i == -1) {
        printf("顶点 %c 不存在\n", x);
        return;
    }
    printf("与顶点 %c 邻接的边: ", x);
    int count = 0;
    // 出边
    for (int j = 0; j < G.vexNum; j++) {
        if (G.edge[i][j] != 0) {
            if (G.isDirected) {
                printf("<%c, %c, 权值=%d> ", x, G.vex[j], G.edge[i][j]);
            } else {
                printf("(%c, %c, 权值=%d) ", x, G.vex[j], G.edge[i][j]);
            }
            count++;
        }
    }
    // 有向图还需要显示入边
    if (G.isDirected) {
        for (int j = 0; j < G.vexNum; j++) {
            if (G.edge[j][i] != 0) {
                printf("<%c, %c, 权值=%d> ", G.vex[j], x, G.edge[j][i]);
                count++;
            }
        }
    }
    if (count == 0) {
        printf("无");
    }
    printf("\n");
}

// 3. InsertVertex(G, x)：在图 G 中插入顶点 x
int InsertVertex_M(MGraph* G, VertexType x) {
    if (G->vexNum >= MaxVertexNum) {
        printf("图已满，无法插入顶点\n");
        return 0;
    }
    // 检查顶点是否已存在
    if (LocateVex_M(*G, x) != -1) {
        printf("顶点 %c 已存在\n", x);
        return 0;
    }
    G->vex[G->vexNum] = x;
    // 初始化新顶点相关的边
    for (int i = 0; i <= G->vexNum; i++) {
        G->edge[G->vexNum][i] = 0;
        G->edge[i][G->vexNum] = 0;
    }
    G->vexNum++;
    return 1;
}

// 4. DeleteVertex(G, x)：从图 G 中删除顶点 x 及其相关的所有边
int DeleteVertex_M(MGraph* G, VertexType x) {
    int i = LocateVex_M(*G, x);
    if (i == -1) {
        printf("顶点 %c 不存在\n", x);
        return 0;
    }
    // 删除与x相关的所有边
    if (G->isDirected) {
        // 有向图：分别统计出边和入边
        for (int j = 0; j < G->vexNum; j++) {
            if (G->edge[i][j] != 0) {  // 出边
                G->edge[i][j] = 0;
                G->edgeNum--;
            }
            if (G->edge[j][i] != 0) {  // 入边
                G->edge[j][i] = 0;
                G->edgeNum--;
            }
        }
    } else {
        // 无向图：对称矩阵，只统计一次
        for (int j = 0; j < G->vexNum; j++) {
            if (G->edge[i][j] != 0) {
                G->edge[i][j] = 0;
                G->edge[j][i] = 0;
                G->edgeNum--;
            }
        }
    }
    // 将最后一位顶点移到位置i
    for (int j = 0; j < G->vexNum; j++) {
        G->edge[j][i] = G->edge[j][G->vexNum - 1];
    }
    for (int j = 0; j < G->vexNum; j++) {
        G->edge[i][j] = G->edge[G->vexNum - 1][j];
    }
    // 删除顶点
    for (int j = i; j < G->vexNum - 1; j++) {
        G->vex[j] = G->vex[j + 1];
    }
    G->vexNum--;
    return 1;
}

// 5. AddEdge(G, x, y)：添加边 (x, y) 或 <x, y>
// 带权重的版本声明
int AddEdge_M_V(MGraph* G, VertexType x, VertexType y, EdgeType v);

int AddEdge_M(MGraph* G, VertexType x, VertexType y) {
    return AddEdge_M_V(G, x, y, 1);  // 默认权值为1
}

int AddEdge_M_V(MGraph* G, VertexType x, VertexType y, EdgeType v) {
    int i = LocateVex_M(*G, x);
    int j = LocateVex_M(*G, y);
    if (i == -1 || j == -1) {
        printf("顶点不存在，无法添加边\n");
        return 0;
    }
    if (G->edge[i][j] == 0) {  // 边不存在才添加
        G->edge[i][j] = v;
        if (!G->isDirected) {  // 无向图需要双向赋值
            G->edge[j][i] = v;
        }
        G->edgeNum++;
    }
    return 1;
}

// 6. RemoveEdge(G, x, y)：删除边 (x, y) 或 <x, y>
int RemoveEdge_M(MGraph* G, VertexType x, VertexType y) {
    int i = LocateVex_M(*G, x);
    int j = LocateVex_M(*G, y);
    if (i == -1 || j == -1) {
        printf("顶点不存在\n");
        return 0;
    }
    if (G->edge[i][j] != 0) {
        G->edge[i][j] = 0;
        if (!G->isDirected) {  // 无向图需要双向删除
            G->edge[j][i] = 0;
        }
        G->edgeNum--;
        return 1;
    }
    return 0;  // 边不存在
}

// 7. FirstNeighbor(G, x)：返回顶点 x 的第一个邻接点
int FirstNeighbor_M(MGraph G, VertexType x) {
    int i = LocateVex_M(G, x);
    if (i == -1) {
        return -1;  // 顶点不存在
    }
    for (int j = 0; j < G.vexNum; j++) {
        if (G.edge[i][j] != 0) {
            return j;
        }
    }
    return -1;  // 没有邻接点
}

// 8. NextNeighbor(G, x, y)：返回除 y 外顶点 x 的下一个邻接点
int NextNeighbor_M(MGraph G, VertexType x, VertexType y) {
    int i = LocateVex_M(G, x);
    int j = LocateVex_M(G, y);
    if (i == -1 || j == -1) {
        return -1;  // 顶点不存在
    }
    for (int k = j + 1; k < G.vexNum; k++) {
        if (G.edge[i][k] != 0) {
            return k;
        }
    }
    return -1;  // 没有下一个邻接点
}

// 9. Get_edge_value(G, x, y)：获取边 (x, y) 或 <x, y> 的权值
int Get_edge_value_M(MGraph G, VertexType x, VertexType y, EdgeType* v) {
    int i = LocateVex_M(G, x);
    int j = LocateVex_M(G, y);
    if (i == -1 || j == -1) {
        printf("顶点不存在\n");
        return 0;
    }
    if (G.edge[i][j] == 0) {
        printf("边 (%c, %c) 不存在\n", x, y);
        return 0;
    }
    *v = G.edge[i][j];
    return 1;
}

// 10. Set_edge_value(G, x, y, v)：设置边 (x, y) 或 <x, y> 的权值为 v
int Set_edge_value_M(MGraph* G, VertexType x, VertexType y, EdgeType v) {
    int i = LocateVex_M(*G, x);
    int j = LocateVex_M(*G, y);
    if (i == -1 || j == -1) {
        printf("顶点不存在\n");
        return 0;
    }
    G->edge[i][j] = v;
    if (!G->isDirected) {  // 无向图需要双向设置
        G->edge[j][i] = v;
    }
    return 1;
}

/*============== 辅助操作 ==============*/

// 创建空图（默认无向图）
void CreateEmptyGraph_M(MGraph* G) {
    G->vexNum = 0;
    G->edgeNum = 0;
    G->isDirected = 0;  // 默认无向图
    memset(G->vex, 0, sizeof(G->vex));
    memset(G->edge, 0, sizeof(G->edge));
}

// 创建空图（指定是否有向）
void CreateGraph_M(MGraph* G, int isDirected) {
    G->vexNum = 0;
    G->edgeNum = 0;
    G->isDirected = isDirected;
    memset(G->vex, 0, sizeof(G->vex));
    memset(G->edge, 0, sizeof(G->edge));
}

// 打印图
void PrintGraph_M(MGraph G) {
    printf("===== 邻接矩阵 =====\n");
    printf("类型: %s\n", G.isDirected ? "有向图" : "无向图");
    printf("顶点数: %d, 边数: %d\n", G.vexNum, G.edgeNum);
    printf("顶点: ");
    for (int i = 0; i < G.vexNum; i++) {
        printf("%c ", G.vex[i]);
    }
    printf("\n\n邻接矩阵:\n    ");
    for (int i = 0; i < G.vexNum; i++) {
        printf("%c  ", G.vex[i]);
    }
    printf("\n");
    for (int i = 0; i < G.vexNum; i++) {
        printf("%c  ", G.vex[i]);
        for (int j = 0; j < G.vexNum; j++) {
            printf("%d  ", G.edge[i][j]);
        }
        printf("\n");
    }
}

#endif
