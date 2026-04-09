#include "matrix_impl.h"
#include "linkList_impl.h"
#include "../queue/link.h"
#include <limits.h>

void BFSTraverse(MGraph* G);
void BFSTraverse(LGraph* G);
void listBFS(LGraph* G,linkQueue q,int i);
void matrixBFS(MGraph* G,linkQueue q,int i);
void visit(MGraph* G,int i);
void visit(LGraph* G,int i);

bool visited[MaxVertexNum];

void visit(MGraph* G,int i){
    printf("%c",G->vex[i]);
}
void visit(LGraph* G,int i){
    printf("%c",G->vertices[i].data);
}

void BFSTraverse(MGraph* G){        //矩阵BFS
    for(int i=0;i<G->vexNum;i++){
        visited[i] = false;
    }
    linkQueue q;
    if(initQueue(&q)==false) return;
    for(int i=0;i<G->vexNum;i++){
        if(!visited[i])
            matrixBFS(G,q,i);
    }
}

void listBFS(LGraph* G,linkQueue q,int i){
    visit(G,i);
    visited[i] = true;      //标记被访问
    pushQueue(q,i);         //入栈
    int v;
    while(!isEmptyQueue(q)){
        popQueue(q,&v);     //出栈
        for(ArcNode* w = G->vertices[v].firstArc; w != NULL; w = w->nextArc){   //遍历这个结点的边表
            if(!visited[w->adjvex]){            //发现未被访问的点
                visit(G,w->adjvex);             //访问
                visited[w->adjvex] = true;      //标记访问
                pushQueue(q,w->adjvex);         //入队列
            }
        }
    }
}

void matrixBFS(MGraph* G,linkQueue q,int i){
    visit(G,i);
    visited[i] = true;
    pushQueue(q,i);
    int v;
    while(!isEmptyQueue(q)){
        popQueue(q,&v);                 //出闸元素是起点
        for(int w = 0;w<G->vexNum;w++){
            if(!visited[w] && G->edge[v][w]==1){    //如果起点v到w点存在路径，那么就可以加入
                visit(G,w);
                visited[w] = true;
                pushQueue(q,w);
            }
        }
    }
}

void BFSTraverse(LGraph* G){
    for(int i=0;i<G->vexNum;i++){
        visited[i] = false;             //初始化
    }                       
    linkQueue q;
    if(initQueue(&q)==false) return;    //初始化队列，在里面初始化会导致这条语句重复执行多次    
    for(int i=0;i<G->vexNum;i++){       //对每个点查看访问情况，没被访问，开始BFS
        if(!visited[i])
            listBFS(G,q,i);                 //开始BFS
    }
}

void BFSMinDistance(LGraph* G, int u,int distance[]){
    for(int i = 0;i<G->vexNum;i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    linkQueue q;
    if(initQueue(&q)==false) return;
    pushQueue(q,u);
    distance[u] = 0;
    visited[u] = true;     //初始化
    int v;
    while(!isEmptyQueue(q)){
        popQueue(q,&v);
        for(ArcNode* w = G->vertices[v].firstArc;w;w = w->nextArc){
            if(!visited[w->adjvex]){
                distance[w->adjvex] = distance[v] + 1;
                visit(G,w->adjvex);
                visited[w->adjvex] = true;
                pushQueue(q,w->adjvex);

            }
        }
    }
}

/*============== 测试案例 ==============*/

int main() {
    printf("============== 测试 BFS 遍历 ============\n\n");

    // ========== 测试1: 邻接矩阵 BFS ==========
    printf("--- 测试1: 邻接矩阵 BFS 遍历 ---\n");
    MGraph MG;
    CreateGraph_M(&MG, 0);  // 无向图

    // 构建图: A-B-C-D-E, A-C
    //     A
    //    / \
    //   B---C
    //   |   |
    //   D---E
    InsertVertex_M(&MG, 'A');
    InsertVertex_M(&MG, 'B');
    InsertVertex_M(&MG, 'C');
    InsertVertex_M(&MG, 'D');
    InsertVertex_M(&MG, 'E');

    AddEdge_M(&MG, 'A', 'B');
    AddEdge_M(&MG, 'A', 'C');
    AddEdge_M(&MG, 'B', 'D');
    AddEdge_M(&MG, 'C', 'E');
    AddEdge_M(&MG, 'D', 'E');

    PrintGraph_M(MG);
    printf("\nBFS遍历结果: ");
    BFSTraverse(&MG);
    printf("\n\n");

    // ========== 测试2: 邻接表 BFS ==========
    printf("--- 测试2: 邻接表 BFS 遍历 ---\n");
    LGraph LG;
    CreateGraph_L(&LG, 0);  // 无向图

    InsertVertex_L(&LG, 'A');
    InsertVertex_L(&LG, 'B');
    InsertVertex_L(&LG, 'C');
    InsertVertex_L(&LG, 'D');
    InsertVertex_L(&LG, 'E');

    AddEdge_L(&LG, 'A', 'B');
    AddEdge_L(&LG, 'A', 'C');
    AddEdge_L(&LG, 'B', 'D');
    AddEdge_L(&LG, 'C', 'E');
    AddEdge_L(&LG, 'D', 'E');

    PrintGraph_L(LG);
    printf("\nBFS遍历结果: ");
    BFSTraverse(&LG);
    printf("\n\n");

    // ========== 测试3: 非连通图 BFS ==========
    printf("--- 测试3: 非连通图 BFS 遍历 ---\n");
    MGraph MG2;
    CreateGraph_M(&MG2, 0);

    // 构建非连通图: 两个独立部分
    // A-B-C  和  D-E
    InsertVertex_M(&MG2, 'A');
    InsertVertex_M(&MG2, 'B');
    InsertVertex_M(&MG2, 'C');
    InsertVertex_M(&MG2, 'D');
    InsertVertex_M(&MG2, 'E');

    AddEdge_M(&MG2, 'A', 'B');
    AddEdge_M(&MG2, 'B', 'C');
    AddEdge_M(&MG2, 'D', 'E');

    PrintGraph_M(MG2);
    printf("\nBFS遍历结果(非连通图): ");
    BFSTraverse(&MG2);
    printf("\n\n");

    // ========== 测试4: BFS 求最短距离 ==========
    printf("--- 测试4: BFS 求最短距离 ---\n");
    LGraph LG2;
    CreateGraph_L(&LG2, 0);

    // 构建图:
    //     A
    //    /|\
    //   B C D
    //    \|/
    //     E
    InsertVertex_L(&LG2, 'A');
    InsertVertex_L(&LG2, 'B');
    InsertVertex_L(&LG2, 'C');
    InsertVertex_L(&LG2, 'D');
    InsertVertex_L(&LG2, 'E');

    AddEdge_L(&LG2, 'A', 'B');
    AddEdge_L(&LG2, 'A', 'C');
    AddEdge_L(&LG2, 'A', 'D');
    AddEdge_L(&LG2, 'B', 'E');
    AddEdge_L(&LG2, 'C', 'E');
    AddEdge_L(&LG2, 'D', 'E');

    PrintGraph_L(LG2);

    int distance[MaxVertexNum];
    int startIdx = 0;  // 从顶点 A 开始
    printf("\n从顶点 A 开始 BFS 求最短距离:\n");
    printf("访问顺序: ");
    BFSMinDistance(&LG2, startIdx, distance);
    printf("\n\n各顶点到 A 的最短距离:\n");
    for (int i = 0; i < LG2.vexNum; i++) {
        printf("  %c -> %c: %d\n", LG2.vertices[startIdx].data, LG2.vertices[i].data, distance[i]);
    }

    // ========== 测试5: 有向图 BFS ==========
    printf("\n--- 测试5: 有向图 BFS 遍历 ---\n");
    LGraph LG_directed;
    CreateGraph_L(&LG_directed, 1);  // 有向图

    // 构建有向图:
    // A -> B -> D
    // A -> C -> D
    InsertVertex_L(&LG_directed, 'A');
    InsertVertex_L(&LG_directed, 'B');
    InsertVertex_L(&LG_directed, 'C');
    InsertVertex_L(&LG_directed, 'D');

    AddEdge_L(&LG_directed, 'A', 'B');
    AddEdge_L(&LG_directed, 'A', 'C');
    AddEdge_L(&LG_directed, 'B', 'D');
    AddEdge_L(&LG_directed, 'C', 'D');

    PrintGraph_L(LG_directed);
    printf("\nBFS遍历结果(有向图): ");
    BFSTraverse(&LG_directed);
    printf("\n\n");

    printf("============== 测试完成 ============\n");
    return 0;
}
