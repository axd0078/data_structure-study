#ifndef MATRIX_H
#define MATRIX_H

#define MaxVertexNum 100

typedef char VertexType;
typedef int EdgeType;

typedef struct{
    VertexType vex[MaxVertexNum];
    EdgeType edge[MaxVertexNum][MaxVertexNum];
    int vexNum,edgeNum;
    int isDirected;             // 0:无向图  1:有向图
}MGraph;

#endif
