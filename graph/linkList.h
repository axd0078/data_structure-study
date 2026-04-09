#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#define MaxVertexNum 100

typedef char VertexType;

typedef struct ArcNode{         //边表结点
    int adjvex;                 //顶点
    struct ArcNode* nextArc;    //下一条弧指针
}ArcNode;
typedef struct VNode{           //顶点
    VertexType data;            //数据
    ArcNode* firstArc;          //第一条依附于顶点的弧
}VNode,AdjList[MaxVertexNum];
typedef struct{
    AdjList vertices;
    int vexNum,arcNum;
    int isDirected;             // 0:无向图  1:有向图
}LGraph;

#endif
