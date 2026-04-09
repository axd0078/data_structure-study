#include <stdio.h>
#include "linkList.h"
#include "linkList_impl.h"
#include "matrix.h"
#include "matrix_impl.h"

int main() {
    setbuf(stdout, NULL);  // 禁用缓冲

    printf("============== 测试邻接矩阵 - 无向图 ============\n");
    MGraph MG_undirected;
    CreateGraph_M(&MG_undirected, 0);  // 无向图

    InsertVertex_M(&MG_undirected, 'A');
    InsertVertex_M(&MG_undirected, 'B');
    InsertVertex_M(&MG_undirected, 'C');
    InsertVertex_M(&MG_undirected, 'D');

    AddEdge_M(&MG_undirected, 'A', 'B');
    AddEdge_M(&MG_undirected, 'A', 'C');
    AddEdge_M(&MG_undirected, 'B', 'D');
    AddEdge_M(&MG_undirected, 'C', 'D');

    PrintGraph_M(MG_undirected);
    printf("\nAdjacent(M, A, B): %d\n", Adjacent_M(MG_undirected, 'A', 'B'));
    printf("Adjacent(M, B, A): %d (无向图应该对称)\n", Adjacent_M(MG_undirected, 'B', 'A'));
    Neighbors_M(MG_undirected, 'A');

    printf("\n============== 测试邻接矩阵 - 有向图 ============\n");
    MGraph MG_directed;
    CreateGraph_M(&MG_directed, 1);  // 有向图

    InsertVertex_M(&MG_directed, 'A');
    InsertVertex_M(&MG_directed, 'B');
    InsertVertex_M(&MG_directed, 'C');
    InsertVertex_M(&MG_directed, 'D');

    AddEdge_M(&MG_directed, 'A', 'B');  // A -> B
    AddEdge_M(&MG_directed, 'A', 'C');  // A -> C
    AddEdge_M(&MG_directed, 'B', 'D');  // B -> D
    AddEdge_M(&MG_directed, 'C', 'D');  // C -> D

    PrintGraph_M(MG_directed);
    printf("\nAdjacent(M, A, B): %d (A->B 存在)\n", Adjacent_M(MG_directed, 'A', 'B'));
    printf("Adjacent(M, B, A): %d (B->A 不存在，有向图不对称)\n", Adjacent_M(MG_directed, 'B', 'A'));
    Neighbors_M(MG_directed, 'A');
    Neighbors_M(MG_directed, 'D');  // D有入边但没有出边

    printf("\n============== 测试邻接表 - 无向图 ============\n");
    LGraph LG_undirected;
    CreateGraph_L(&LG_undirected, 0);  // 无向图

    InsertVertex_L(&LG_undirected, 'A');
    InsertVertex_L(&LG_undirected, 'B');
    InsertVertex_L(&LG_undirected, 'C');
    InsertVertex_L(&LG_undirected, 'D');

    AddEdge_L(&LG_undirected, 'A', 'B');
    AddEdge_L(&LG_undirected, 'A', 'C');
    AddEdge_L(&LG_undirected, 'B', 'D');
    AddEdge_L(&LG_undirected, 'C', 'D');

    PrintGraph_L(LG_undirected);
    printf("\nAdjacent(L, A, B): %d\n", Adjacent_L(LG_undirected, 'A', 'B'));
    printf("Adjacent(L, B, A): %d (无向图应该对称)\n", Adjacent_L(LG_undirected, 'B', 'A'));
    Neighbors_L(LG_undirected, 'A');

    printf("\n============== 测试邻接表 - 有向图 ============\n");
    LGraph LG_directed;
    CreateGraph_L(&LG_directed, 1);  // 有向图

    InsertVertex_L(&LG_directed, 'A');
    InsertVertex_L(&LG_directed, 'B');
    InsertVertex_L(&LG_directed, 'C');
    InsertVertex_L(&LG_directed, 'D');

    AddEdge_L(&LG_directed, 'A', 'B');  // A -> B
    AddEdge_L(&LG_directed, 'A', 'C');  // A -> C
    AddEdge_L(&LG_directed, 'B', 'D');  // B -> D
    AddEdge_L(&LG_directed, 'C', 'D');  // C -> D

    PrintGraph_L(LG_directed);
    printf("\nAdjacent(L, A, B): %d (A->B 存在)\n", Adjacent_L(LG_directed, 'A', 'B'));
    printf("Adjacent(L, B, A): %d (B->A 不存在，有向图不对称)\n", Adjacent_L(LG_directed, 'B', 'A'));
    Neighbors_L(LG_directed, 'A');
    Neighbors_L(LG_directed, 'D');  // D有入边但没有出边

    printf("\n============== 测试删除操作 ============\n");
    printf("--- 有向图删除边 A->B ---\n");
    RemoveEdge_M(&MG_directed, 'A', 'B');
    PrintGraph_M(MG_directed);
    printf("Adjacent(M, A, B): %d\n", Adjacent_M(MG_directed, 'A', 'B'));

    printf("\n--- 有向图删除顶点 C ---\n");
    DeleteVertex_M(&MG_directed, 'C');
    PrintGraph_M(MG_directed);

    printf("\n测试完成！\n");
    return 0;
}
