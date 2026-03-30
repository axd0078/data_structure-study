#include <vector>
#include <iostream>
#include <set>
using namespace std;

class Solution{
    
    // 四个方向 右上左下
    vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};

    int m,n;    //网格的行数列数，共享

    set<vector<vector<int>>> s;     //存储岛屿形状的集合,具有自动去重功能

public:
    int numDistinctIslands(vector<vector<int>>& grid){

        if(grid.empty() || grid[0].empty()) return 0;

        m = grid.size(),n = grid[0].size();     //获取行数  列数

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    vector<vector<int>> path;    //记录当前岛屿的形状，path 要记录相对坐标，不能直接记录绝对坐标
                    grid[i][j] = 0;     //标记为已访问
                    dfs(grid,i,j,i,j,path);   //从(i,j)出发进行DFS，记录路径
                    s.insert(path);     //将当前岛屿的形状加入集合
                }
            }
        }

        return s.size();    //集合中不同岛屿形状的数量即为答案

    }

    void dfs(vector<vector<int>>& grid, int x0,int y0,int x,int y,vector<vector<int>>& path){
        // 记录当前位置相对于起点的偏移量
        // 这样形状相同但位置不同的岛屿会产生相同的路径

        path.push_back({x-x0,y-y0});    //添加到末尾

        int k,nx,ny;    //方向索引 nx/ny: 下一个位置坐标

        for(k=0; k<4; k++){
            nx = x + dir[k][0];
            ny = y + dir[k][1];

            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]){
                grid[nx][ny] = 0;
                dfs(grid,x0,y0,nx,ny,path);
            }
        }
    }

};

int main(){
    int m,n;
    cin >> m >> n;

    vector<vector<int>> grid(m,vector<int>(n));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }

    Solution s;
    cout<< s.numDistinctIslands(grid) <<endl;

    return 0;
}