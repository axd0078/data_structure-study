#include <stdio.h>
#include <stdlib.h>

void dfs(char* grid[],int i,int j,int row,int col){
    if(i==row || j==col || i<0 || j<0){
        return;
    }
    if(grid[i][j] == '1'){
        grid[i][j] = '0';
    }
    else{
        return;
    }
    dfs(grid,i-1,j,row,col);
    dfs(grid,i+1,j,row,col);
    dfs(grid,i,j+1,row,col);
    dfs(grid,i,j-1,row,col);
}

int numIsland(char* grid[],int col,int row){
    int res = 0;
    for(int i = 0;i < row; i++){
        for(int j = 0;j < col; j++){
            if(grid[i][j] == '1'){
                res++;
                dfs(grid,i,j,row,col);//出现陆地就要淹没所有相邻陆地
            }
        }
    }
    return res;
}

int main(){
    int row, col;
    scanf("%d %d", &row, &col);
    
    // 分配二维数组
    char** grid = (char**)malloc(row * sizeof(char*));
    for(int i = 0; i < row; i++){
        grid[i] = (char*)malloc((col + 1) * sizeof(char)); // +1 for '\0'
        scanf("%s", grid[i]);
    }
    
    printf("%d\n", numIsland(grid, col, row));
    
    // 释放内存
    for(int i = 0; i < row; i++){
        free(grid[i]);
    }
    free(grid);
    
    return 0;
}

