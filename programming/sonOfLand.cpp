#include <stdio.h>
#include <stdlib.h>

void dfs(int* grid[],int i,int j,int row,int col){
    if(i<0||j<0||i>=row||j>=col)
        return;
    
    if(grid[i][j]==0)
        return;
    
    grid[i][j] = 0;

    dfs(grid,i-1,j,row,col);
    dfs(grid,i+1,j,row,col);
    dfs(grid,i,j-1,row,col);
    dfs(grid,i,j+1,row,col);
}

int countSubIslands(int* grid1[],int* grid2[],int row,int col){
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            if(grid1[i][j] == 0 && grid2[i][j] == 1){
                dfs(grid2,i,j,row,col);
            }
        }
    }

    int num = 0;
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            if(grid2[i][j] == 1){
                num++;
                dfs(grid2,i,j,row,col);
            }
        }
    }
    return num;
}

int main(){
    int row, col;
    scanf("%d %d", &row, &col);
    
    // 分配 grid1
    int** grid1 = (int**)malloc(row * sizeof(int*));
    for(int i = 0; i < row; i++){
        grid1[i] = (int*)malloc(col * sizeof(int));
        for(int j = 0; j < col; j++){
            scanf("%d", &grid1[i][j]);
        }
    }
    
    // 分配 grid2
    int** grid2 = (int**)malloc(row * sizeof(int*));
    for(int i = 0; i < row; i++){
        grid2[i] = (int*)malloc(col * sizeof(int));
        for(int j = 0; j < col; j++){
            scanf("%d", &grid2[i][j]);
        }
    }
    
    printf("%d\n", countSubIslands(grid1, grid2, row, col));
    
    // 释放内存
    for(int i = 0; i < row; i++){
        free(grid1[i]);
        free(grid2[i]);
    }
    free(grid1);
    free(grid2);
    
    return 0;
}