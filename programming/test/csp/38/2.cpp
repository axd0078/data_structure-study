#include <bits/stdc++.h>
using namespace std;

int n;
struct pos{
    int x;
    int y;
    int dis;
};

bool judge(int x,int y){
    return x>=1 && x<=n && y<=n && y>=1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> n >> k;
    int x,y;
    cin >> x >> y;
    queue<pos> q;
    vector<pair<int,int>> dir = {
        {1, 2}, {2, 1}, {-1, 2}, {-2, 1},
        {1, -2}, {2, -1}, {-1, -2}, {-2, -1}
    };
    vector<vector<int>> visited(n+1,vector<int>(n+1,0));
    q.push({x,y,0});
    visited[x][y] = 1;
    int ans = 0;
    while(!q.empty()){
        pos p = q.front();
        if(p.dis == k) {
            q.pop();
            continue;
        }
        for(int i=0;i<dir.size();i++){
            if(judge(p.x+dir[i].first,p.y+dir[i].second))
                if(!visited[p.x+dir[i].first][p.y+dir[i].second]){
                    q.push({p.x+dir[i].first,p.y+dir[i].second,p.dis+1});
                    visited[p.x+dir[i].first][p.y+dir[i].second] = 1;
                    ans++;
                }
        }
        q.pop();
    }
    cout << ans+1 << endl;
    return 0;
}
