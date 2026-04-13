#include <stdio.h>
#define MAXSIZE 500
typedef struct{
    int matrix[MAXSIZE][MAXSIZE];
    char sex[MAXSIZE];//F:female  M:male
    int size;
}Graph;

int main(){
    Graph g;
    const int INF = 1000000000;


    scanf("%d",&g.size);
    for (int i = 0; i < g.size; i++) {
        for (int j = 0; j < g.size; j++) {
            g.matrix[i][j] = (i == j ? 0 : INF);
        }
    }//图的初始化!!!

    
    for(int i=0;i<g.size;i++){
        char sex;
        int size;
        scanf(" %c %d",&sex,&size);
        g.sex[i] = sex;
        for(int j=0;j<size;j++){
            int point,weight;
            scanf("%d:%d",&point,&weight);
            g.matrix[i][point-1] = weight;
        }
    }//输入图
    for(int k = 0;k<g.size;k++){
        for(int i=0;i<g.size;i++){
            for(int j=0;j<g.size;j++){
                if (g.matrix[i][k] == INF || g.matrix[k][j] == INF) {
                    continue;
                }
                if(g.matrix[i][k] + g.matrix[k][j] < g.matrix[i][j]){
                    g.matrix[i][j] = g.matrix[i][k] + g.matrix[k][j];
                }
            }
        }
    }//执行floyd
    int max[g.size];
    int bestF = INF;
    int bestM = INF;
    for(int i=0;i<g.size;i++){
        max[i] = 0;
        for(int j=0;j<g.size;j++){
            if(g.sex[i]==g.sex[j]) continue;
            if(g.matrix[j][i] > max[i]) max[i] = g.matrix[j][i];
        }
    }//计算异性缘 这是j对于i而谈缘分 人 i 在异性 j 眼中的距离感
    for(int i=0;i<g.size;i++){
        if (g.sex[i] == 'F' && max[i] < bestF) {
            bestF = max[i];
        }
        if (g.sex[i] == 'M' && max[i] < bestM) {
            bestM = max[i];
        }
    }
    int first = 1;
    for (int i = 0; i < g.size; i++) {
        if (g.sex[i] == 'F' && max[i] == bestF) {
            if (!first) {
                printf(" ");
            }
            printf("%d", i + 1);
            first = 0;
        }
    }

    printf("\n");

    first = 1;
    for (int i = 0; i < g.size; i++) {
        if (g.sex[i] == 'M' && max[i] == bestM) {
            if (!first) {
                printf(" ");
            }
            printf("%d", i + 1);
            first = 0;
        }
    }

    return 0;
}