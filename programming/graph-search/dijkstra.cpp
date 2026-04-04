#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MaxVertexNum 500
#define INF 0x3f3f3f3f  // 定义无穷大

typedef struct {
    int vexNum,edgeNum;
    int edge[MaxVertexNum][MaxVertexNum];
}Graph;

void dijkstra(Graph* G,int start,int* distance){
    int visited[MaxVertexNum] = {0};   //标记已经找到最短路径的集合

    //初始化
    for(int i=0;i<G->vexNum;i++){
        distance[i] = G->edge[start][i];
    }
    distance[start] = 0;
    visited[start] = 1;

    //需要n-1次更新
    for(int i=1;i<G->vexNum;i++){
        //从未标记集合中找到距离最短的点
        int minDist = INF,u = -1;
        for (int j = 0; j < G->vexNum; j++) {
            if (!visited[j] && distance[j] < minDist) {
                minDist = distance[j];
                u = j;
            }
        }
        if(u==-1) break;
        visited[u] = 1;     //加入集合
        for(int v = 0;v<G->vexNum;v++){
            if(!visited[v] && G->edge[u][v]!=INF){//这里强调的是不可达
                if(distance[v] > distance[u] + G->edge[u][v]){
                    distance[v] = distance[u] + G->edge[u][v];
                }
            }
        }

    }

}

int main(){
    Graph G;
    // 正确初始化：对角线为0，其他为INF
    for(int i=0;i<MaxVertexNum;i++){
        for(int j=0;j<MaxVertexNum;j++){
            G.edge[i][j] = (i==j) ? 0 : INF;
        }
    }
    scanf("%d %d",&(G.vexNum),&(G.edgeNum));
    for(int i=0;i<G.edgeNum;i++){
        int x,y,num;
        scanf("%d %d %d",&x,&y,&num);
        G.edge[-x][--y] = num;
    }
    int* distance = (int*)malloc(G.vexNum * sizeof(int));
    dijkstra(&G,0,distance);
    int dis = distance[G.vexNum-1] == INF ? -1:distance[G.vexNum-1];
    printf("%d",dis);
    free(distance);  // 释放内存
    return 0;
}