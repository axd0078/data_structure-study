#include "matrix_impl.h"
#include "../linkList/head.h"
#include <stdlib.h>
#include <stdio.h>

void print(MGraph G, int* path[],int i,int j){
    linkList list;
    initLinkList(&list);
    insertListByPos(list,1,G.vex[j]);
    while(1){
        j = path[i][j];
        insertListByPos(list,1,G.vex[j]);
        if(i==j){
            LNode* p = list->next;
            while(p->next!=NULL){
                printf("%c-> ",p->data);
                p = p->next;
            }
            printf("%c",p->data);
            break;
        }
    }
    destroyList(&list);
}

void floyd(MGraph G,int* path[],int* distance[]){
    // 完全使用你的初始化代码 - 内存由main分配，这里只负责初始化和计算
    for(int j = 0; j < G.vexNum; j++){
            distance[0][j] = G.edge[0][j];
    }//初始化路径数组
    for(int i = 1; i < G.vexNum; i++){
        path[i] = path[i-1] + G.vexNum;     //用path[]把path[0]创造的空间分割
        distance[i] = distance[i-1] + G.vexNum;     //同上
        for(int j = 0; j < G.vexNum; j++){
            path[i][j] = i;
            distance[i][j] = G.edge[i][j];
        }//初始化路径数组
    }
    
    // Floyd算法核心 - 在 distance 上操作
    for(int k = 0; k < G.vexNum; k++){
        for(int i = 0; i < G.vexNum; i++){
            for(int j = 0; j < G.vexNum; j++){
                // 跳过无效路径（0表示无直接边）
                if(distance[i][k] == 0 || distance[k][j] == 0) continue;
                int newDist = distance[i][k] + distance[k][j];
                if(distance[i][j] == 0 || newDist < distance[i][j]){
                    distance[i][j] = newDist;
                    path[i][j] = path[k][j];
                }
            }
        }
    }
}

// ========== 测试程序 ==========
int main() {
    MGraph G;
    CreateGraph_M(&G, 0);  // 创建无向图
    
    // 添加顶点 A, B, C, D
    InsertVertex_M(&G, 'A');
    InsertVertex_M(&G, 'B');
    InsertVertex_M(&G, 'C');
    InsertVertex_M(&G, 'D');
    
    // 添加边 (带权值)
    AddEdge_M_V(&G, 'A', 'B', 5);
    AddEdge_M_V(&G, 'A', 'C', 10);
    AddEdge_M_V(&G, 'B', 'C', 3);
    AddEdge_M_V(&G, 'B', 'D', 8);
    AddEdge_M_V(&G, 'C', 'D', 2);
    
    printf("===== 原始图 =====\n");
    PrintGraph_M(G);
    
    // 分配 path 和 distance 数组（完全由main分配内存）
    int** path = (int**)malloc(sizeof(int*) * G.vexNum);
    path[0] = (int*)calloc(G.vexNum * G.vexNum, sizeof(int));
    for(int i = 1; i < G.vexNum; i++) {
        path[i] = path[0] + i * G.vexNum;
    }
    
    int** distance = (int**)malloc(sizeof(int*) * G.vexNum);
    distance[0] = (int*)calloc(G.vexNum * G.vexNum, sizeof(int));
    for(int i = 1; i < G.vexNum; i++) {
        distance[i] = distance[0] + i * G.vexNum;
    }
    
    // 运行 Floyd 算法
    floyd(G, path, distance);
    
    printf("\n===== 最短距离矩阵 =====\n");
    printf("    A   B   C   D\n");
    for(int i = 0; i < G.vexNum; i++) {
        printf("%c   ", G.vex[i]);
        for(int j = 0; j < G.vexNum; j++) {
            printf("%-4d", distance[i][j]);
        }
        printf("\n");
    }
    
    printf("\n===== 路径打印测试 =====\n");
    printf("A 到 D 的路径: ");
    print(G, path, 0, 3);
    printf("\n");
    
    printf("B 到 D 的路径: ");
    print(G, path, 1, 3);
    printf("\n");
    
    printf("\n===== 验证原图未被修改 =====\n");
    PrintGraph_M(G);
    
    // 释放内存
    free(path[0]);
    free(path);
    free(distance[0]);
    free(distance);
    
    return 0;
}