#include "matrix_impl.h"
#include "linkList_impl.h"

void visit(MGraph* G,int i);
void visit(LGraph* G,int i);
void DFS(LGraph* G,int i);
void DFS(MGraph* G,int i);

bool visited[MaxVertexNum];

void visit(MGraph* G,int i){
    printf("%c",G->vex[i]);
}
void visit(LGraph* G,int i){
    printf("%c",G->vertices[i].data);
}

void DFS(LGraph* G,int i){
    visit(G,i);
    visited[i] = true;      //访问并标记
    for(ArcNode* w = G->vertices[i].firstArc;w;w = w->nextArc){     //遍历边表
        if(!visited[w->adjvex])    //未被访问（修复：删除分号）
            DFS(G,w->adjvex);       //继续递归
    }
}

void DFS(MGraph* G,int i){
    visit(G,i);
    visited[i] = true;
    for(int w = 0;w<G->vexNum;w++){
        if(!visited[w]&&G->edge[i][w]==1)   //有弧并且未被访问
            DFS(G,w);
    }
}

void DFSTraverse(LGraph* G){
    for(int i = 0;i<G->vexNum;i++)
        visited[i] = false;
    for(int i = 0;i<G->vexNum;i++){
        if(!visited[i])  // 修复：只对未访问的顶点调用DFS
            DFS(G,i);
    }
}

void DFSTraverse(MGraph* G){
    for(int i = 0;i<G->vexNum;i++)
        visited[i] = false;
    for(int i = 0;i<G->vexNum;i++){
        if(!visited[i])
            DFS(G,i);
    }
}

/*============== 测试案例 ==============*/

int main() {
    printf("============== 测试 DFS 遍历 ============\n\n");

    // ========== 测试1: 邻接矩阵 DFS ==========
    printf("--- 测试1: 邻接矩阵 DFS 遍历 ---\n");
    MGraph MG;
    CreateGraph_M(&MG, 0);  // 无向图

    // 构建图:
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
    printf("\nDFS遍历结果: ");
    DFSTraverse(&MG);
    printf("\n\n");

    // ========== 测试2: 邻接表 DFS ==========
    printf("--- 测试2: 邻接表 DFS 遍历 ---\n");
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
    printf("\nDFS遍历结果: ");
    DFSTraverse(&LG);
    printf("\n\n");

    // ========== 测试3: 非连通图 DFS ==========
    printf("--- 测试3: 非连通图 DFS 遍历 ---\n");
    MGraph MG2;
    CreateGraph_M(&MG2, 0);

    // 构建非连通图: 两个独立部分 A-B-C 和 D-E
    InsertVertex_M(&MG2, 'A');
    InsertVertex_M(&MG2, 'B');
    InsertVertex_M(&MG2, 'C');
    InsertVertex_M(&MG2, 'D');
    InsertVertex_M(&MG2, 'E');

    AddEdge_M(&MG2, 'A', 'B');
    AddEdge_M(&MG2, 'B', 'C');
    AddEdge_M(&MG2, 'D', 'E');

    PrintGraph_M(MG2);
    printf("\nDFS遍历结果(非连通图): ");
    DFSTraverse(&MG2);
    printf("\n\n");

    // ========== 测试4: 有向图 DFS ==========
    printf("--- 测试4: 有向图 DFS 遍历 ---\n");
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
    printf("\nDFS遍历结果(有向图): ");
    DFSTraverse(&LG_directed);
    printf("\n\n");

    // ========== 测试5: 单顶点图 ==========
    printf("--- 测试5: 单顶点图 DFS 遍历 ---\n");
    MGraph MG_single;
    CreateGraph_M(&MG_single, 0);
    InsertVertex_M(&MG_single, 'X');
    
    PrintGraph_M(MG_single);
    printf("\nDFS遍历结果(单顶点): ");
    DFSTraverse(&MG_single);
    printf("\n\n");

    printf("============== 测试完成 ============\n");
    return 0;
}
