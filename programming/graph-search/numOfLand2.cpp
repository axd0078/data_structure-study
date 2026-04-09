#include <stdio.h>
#include <stdlib.h>

void dfs(int* grid[],int i,int j,int row,int col){
    if(i==row||j==col||i<0||j<0){
        return;
    }
    if(grid[i][j] == 0){
        return;
    }
    else{
        grid[i][j] = 0;
    }
    dfs(grid,i-1,j,row,col);
    dfs(grid,i+1,j,row,col);
    dfs(grid,i,j+1,row,col);
    dfs(grid,i,j-1,row,col);
}

int closeIsland(int* grid[],int row,int col){
    int res = 0;
    for(int i=0;i<col;i++){
        dfs(grid,0,i,row,col);
        dfs(grid,row-1,i,row,col);
    }
    for(int i=0;i<row;i++){
        dfs(grid,i,col-1,row,col);
        dfs(grid,i,0,row,col);
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j] == 1){
                res++;
                dfs(grid,i,j,row,col);
            }
        }
    }
    return res;
}

int main(){
    int row, col;
    scanf("%d %d", &row, &col);
    
    // 分配二维数组
    int** grid = (int**)malloc(row * sizeof(int*));
    for(int i = 0; i < row; i++){
        grid[i] = (int*)malloc(col * sizeof(int));
        for(int j = 0; j < col; j++){
            scanf("%d", &grid[i][j]);
        }
    }
    
    printf("%d\n", closeIsland(grid, row, col));
    
    // 释放内存
    for(int i = 0; i < row; i++){
        free(grid[i]);
    }
    free(grid);
    
    return 0;
}