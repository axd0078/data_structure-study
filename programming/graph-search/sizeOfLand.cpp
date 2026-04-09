#include <stdio.h>
#include <stdlib.h>

int size = 0;
void dfs(int* grid[],int i,int j,int row,int col,int flag){
    if(i==row||j==col||i<0||j<0){
        return;
    }
    if(grid[i][j] == 0){
        return;
    }
    grid[i][j] = 0;
    if(flag==0){
        dfs(grid,i-1,j,row,col,flag);
        dfs(grid,i+1,j,row,col,flag);
        dfs(grid,i,j+1,row,col,flag);
        dfs(grid,i,j-1,row,col,flag);
    }//处理靠边情况的岛屿不需要加面积
    else{
        size++;
        dfs(grid,i-1,j,row,col,flag);
        dfs(grid,i+1,j,row,col,flag);
        dfs(grid,i,j+1,row,col,flag);
        dfs(grid,i,j-1,row,col,flag);
    }//处理孤立岛屿需要加面积
}

int closeIsland(int* grid[],int row,int col){
    for(int i=0;i<col;i++){
        dfs(grid,0,i,row,col,0);
        dfs(grid,row-1,i,row,col,0);
    }
    for(int i=0;i<row;i++){
        dfs(grid,i,col-1,row,col,0);
        dfs(grid,i,0,row,col,0);
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j] == 1){//判断出是岛屿，计算面积交给dfs
                dfs(grid,i,j,row,col,1);
            }
        }
    }
    return size;
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