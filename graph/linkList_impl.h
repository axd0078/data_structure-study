#ifndef LINKLIST_IMPL_H
#define LINKLIST_IMPL_H

#include "linkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*============== 辅助函数 ==============*/

// 获取顶点x在图中的位置，若不存在返回-1
int LocateVex_L(LGraph G, VertexType x) {
    for (int i = 0; i < G.vexNum; i++) {
        if (G.vertices[i].data == x) {
            return i;
        }
    }
    return -1;
}

// 查找边表结点
ArcNode* FindArc_L(LGraph G, int i, int j) {
    ArcNode* p = G.vertices[i].firstArc;
    while (p != NULL) {
        if (p->adjvex == j) {
            return p;
        }
        p = p->nextArc;
    }
    return NULL;
}

/*============== 基本操作实现 ==============*/

// 1. Adjacent(G, x, y)：判断图 G 中是否存在边 <x, y> 或 (x, y)
int Adjacent_L(LGraph G, VertexType x, VertexType y) {
    int i = LocateVex_L(G, x);
    int j = LocateVex_L(G, y);
    if (i == -1 || j == -1) {
        return 0;  // 顶点不存在
    }
    return FindArc_L(G, i, j) != NULL;
}

// 2. Neighbors(G, x)：列出图 G 中与顶点 x 邻接的所有边
void Neighbors_L(LGraph G, VertexType x) {
    int i = LocateVex_L(G, x);
    if (i == -1) {
        printf("顶点 %c 不存在\n", x);
        return;
    }
    printf("与顶点 %c 邻接的边: ", x);
    ArcNode* p = G.vertices[i].firstArc;
    int count = 0;
    // 出边
    while (p != NULL) {
        if (G.isDirected) {
            printf("<%c, %c> ", x, G.vertices[p->adjvex].data);
        } else {
            printf("(%c, %c) ", x, G.vertices[p->adjvex].data);
        }
        count++;
        p = p->nextArc;
    }
    // 有向图还需要显示入边
    if (G.isDirected) {
        for (int j = 0; j < G.vexNum; j++) {
            if (j == i) continue;
            ArcNode* q = G.vertices[j].firstArc;
            while (q != NULL) {
                if (q->adjvex == i) {
                    printf("<%c, %c> ", G.vertices[j].data, x);
                    count++;
                }
                q = q->nextArc;
            }
        }
    }
    if (count == 0) {
        printf("无");
    }
    printf("\n");
}

// 3. InsertVertex(G, x)：在图 G 中插入顶点 x
int InsertVertex_L(LGraph* G, VertexType x) {
    if (G->vexNum >= MaxVertexNum) {
        printf("图已满，无法插入顶点\n");
        return 0;
    }
    // 检查顶点是否已存在
    if (LocateVex_L(*G, x) != -1) {
        printf("顶点 %c 已存在\n", x);
        return 0;
    }
    G->vertices[G->vexNum].data = x;
    G->vertices[G->vexNum].firstArc = NULL;
    G->vexNum++;
    return 1;
}

// 4. DeleteVertex(G, x)：从图 G 中删除顶点 x 及其相关的所有边
int DeleteVertex_L(LGraph* G, VertexType x) {
    int i = LocateVex_L(*G, x);
    if (i == -1) {
        printf("顶点 %c 不存在\n", x);
        return 0;
    }

    // 删除顶点i的所有出边并统计数量
    ArcNode* p = G->vertices[i].firstArc;
    int outCount = 0;
    while (p != NULL) {
        ArcNode* temp = p;
        p = p->nextArc;
        free(temp);
        outCount++;
    }
    G->vertices[i].firstArc = NULL;

    // 删除所有指向顶点i的边（入边）
    int inCount = 0;
    for (int j = 0; j < G->vexNum; j++) {
        if (j == i) continue;
        ArcNode* q = G->vertices[j].firstArc;
        ArcNode* pre = NULL;
        while (q != NULL) {
            if (q->adjvex == i) {
                if (pre == NULL) {
                    G->vertices[j].firstArc = q->nextArc;
                } else {
                    pre->nextArc = q->nextArc;
                }
                ArcNode* temp = q;
                q = q->nextArc;
                free(temp);
                inCount++;
            } else {
                pre = q;
                q = q->nextArc;
            }
        }
    }

    // 更新边数
    if (G->isDirected) {
        G->arcNum -= outCount + inCount;
    } else {
        G->arcNum -= outCount;  // 无向图每条边只算一次
    }

    // 将最后一位顶点移到位置i
    int last = G->vexNum - 1;
    if (last != i) {
        // 更新所有指向last的边，改为指向i
        for (int j = 0; j < G->vexNum; j++) {
            if (j == last) continue;
            ArcNode* q = G->vertices[j].firstArc;
            while (q != NULL) {
                if (q->adjvex == last) {
                    q->adjvex = i;
                }
                q = q->nextArc;
            }
        }
        G->vertices[i] = G->vertices[last];
    }

    G->vexNum--;
    return 1;
}

// 5. AddEdge(G, x, y)：添加边 (x, y) 或 <x, y>
int AddEdge_L(LGraph* G, VertexType x, VertexType y) {
    int i = LocateVex_L(*G, x);
    int j = LocateVex_L(*G, y);
    if (i == -1 || j == -1) {
        printf("顶点不存在，无法添加边\n");
        return 0;
    }
    // 检查边是否已存在
    if (FindArc_L(*G, i, j) != NULL) {
        printf("边已存在\n");
        return 0;
    }
    // 头插法插入新边
    ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
    p->adjvex = j;
    p->nextArc = G->vertices[i].firstArc;
    G->vertices[i].firstArc = p;
    G->arcNum++;

    // 无向图需要双向添加
    if (!G->isDirected) {
        ArcNode* q = (ArcNode*)malloc(sizeof(ArcNode));
        q->adjvex = i;
        q->nextArc = G->vertices[j].firstArc;
        G->vertices[j].firstArc = q;
    }

    return 1;
}

// 6. RemoveEdge(G, x, y)：删除边 (x, y) 或 <x, y>
int RemoveEdge_L(LGraph* G, VertexType x, VertexType y) {
    int i = LocateVex_L(*G, x);
    int j = LocateVex_L(*G, y);
    if (i == -1 || j == -1) {
        printf("顶点不存在\n");
        return 0;
    }

    // 删除 x->y 的边
    ArcNode* p = G->vertices[i].firstArc;
    ArcNode* pre = NULL;
    while (p != NULL) {
        if (p->adjvex == j) {
            if (pre == NULL) {
                G->vertices[i].firstArc = p->nextArc;
            } else {
                pre->nextArc = p->nextArc;
            }
            free(p);
            G->arcNum--;
            break;
        }
        pre = p;
        p = p->nextArc;
    }

    // 无向图还需要删除 y->x 的边
    if (!G->isDirected) {
        ArcNode* q = G->vertices[j].firstArc;
        pre = NULL;
        while (q != NULL) {
            if (q->adjvex == i) {
                if (pre == NULL) {
                    G->vertices[j].firstArc = q->nextArc;
                } else {
                    pre->nextArc = q->nextArc;
                }
                free(q);
                break;
            }
            pre = q;
            q = q->nextArc;
        }
    }

    return 1;
}

// 7. FirstNeighbor(G, x)：返回顶点 x 的第一个邻接点
int FirstNeighbor_L(LGraph G, VertexType x) {
    int i = LocateVex_L(G, x);
    if (i == -1) {
        return -1;  // 顶点不存在
    }
    if (G.vertices[i].firstArc != NULL) {
        return G.vertices[i].firstArc->adjvex;
    }
    return -1;  // 没有邻接点
}

// 8. NextNeighbor(G, x, y)：返回除 y 外顶点 x 的下一个邻接点
int NextNeighbor_L(LGraph G, VertexType x, VertexType y) {
    int i = LocateVex_L(G, x);
    int j = LocateVex_L(G, y);
    if (i == -1 || j == -1) {
        return -1;  // 顶点不存在
    }
    ArcNode* p = G.vertices[i].firstArc;
    while (p != NULL) {
        if (p->adjvex == j && p->nextArc != NULL) {
            return p->nextArc->adjvex;
        }
        p = p->nextArc;
    }
    return -1;  // 没有下一个邻接点
}

// 9. Get_edge_value(G, x, y)：获取边 (x, y) 或 <x, y> 的权值
// 注意：邻接表默认无权值，返回1表示存在边
int Get_edge_value_L(LGraph G, VertexType x, VertexType y) {
    int i = LocateVex_L(G, x);
    int j = LocateVex_L(G, y);
    if (i == -1 || j == -1) {
        printf("顶点不存在\n");
        return 0;
    }
    if (FindArc_L(G, i, j) == NULL) {
        printf("边 (%c, %c) 不存在\n", x, y);
        return 0;
    }
    // 邻接表不带权值，默认返回1
    return 1;
}

// 10. Set_edge_value(G, x, y, v)：设置边 (x, y) 或 <x, y> 的权值为 v
// 注意：基础邻接表不带权值，此函数仅检查边是否存在
int Set_edge_value_L(LGraph* G, VertexType x, VertexType y, int v) {
    int i = LocateVex_L(*G, x);
    int j = LocateVex_L(*G, y);
    if (i == -1 || j == -1) {
        printf("顶点不存在\n");
        return 0;
    }
    if (FindArc_L(*G, i, j) == NULL) {
        printf("边 (%c, %c) 不存在\n", x, y);
        return 0;
    }
    // 邻接表基础版本不支持权值，参数v被忽略
    printf("邻接表基础版本不支持权值设置\n");
    return 1;
}

/*============== 辅助操作 ==============*/

// 创建空图（默认无向图）
void CreateEmptyGraph_L(LGraph* G) {
    G->vexNum = 0;
    G->arcNum = 0;
    G->isDirected = 0;  // 默认无向图
    for (int i = 0; i < MaxVertexNum; i++) {
        G->vertices[i].data = 0;
        G->vertices[i].firstArc = NULL;
    }
}

// 创建空图（指定是否有向）
void CreateGraph_L(LGraph* G, int isDirected) {
    G->vexNum = 0;
    G->arcNum = 0;
    G->isDirected = isDirected;
    for (int i = 0; i < MaxVertexNum; i++) {
        G->vertices[i].data = 0;
        G->vertices[i].firstArc = NULL;
    }
}

// 打印图
void PrintGraph_L(LGraph G) {
    printf("===== 邻接表 =====\n");
    printf("类型: %s\n", G.isDirected ? "有向图" : "无向图");
    printf("顶点数: %d, 边数: %d\n", G.vexNum, G.arcNum);
    printf("顶点: ");
    for (int i = 0; i < G.vexNum; i++) {
        printf("%c ", G.vertices[i].data);
    }
    printf("\n\n邻接表:\n");
    for (int i = 0; i < G.vexNum; i++) {
        printf("%c -> ", G.vertices[i].data);
        ArcNode* p = G.vertices[i].firstArc;
        while (p != NULL) {
            printf("%c ", G.vertices[p->adjvex].data);
            p = p->nextArc;
        }
        printf("\n");
    }
}

#endif
