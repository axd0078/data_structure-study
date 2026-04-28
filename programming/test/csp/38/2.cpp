#include <bits/stdc++.h>
using namespace std;
struct Pos{
    int x;
    int y;
    int k;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    queue<Pos> q;
    vector<vector<bool>> visited(n+1,vector<bool>(n+1,false));
    Pos begin;
    cin >> begin.x >> begin.y;
    visited[begin.x][begin.y] = true;
    begin.k = 0;
    q.push(begin);
    int ans = 1;
    while(!q.empty()){
        Pos cur = q.front();
        if(cur.k >= k){
            q.pop();
            continue;
        }
        if(cur.x-2>=1 && cur.y+1<=n && !visited[cur.x-2][cur.y+1]){
            visited[cur.x-2][cur.y+1] = true;
            ans++;
            q.push({cur.x-2,cur.y+1,cur.k+1});
        }
        if(cur.x+2<=n && cur.y+1<=n && !visited[cur.x+2][cur.y+1]){
            visited[cur.x+2][cur.y+1] = true;
            ans++;
            q.push({cur.x+2,cur.y+1,cur.k+1});
        }
        if(cur.x-2>=1 && cur.y-1>=1 && !visited[cur.x-2][cur.y-1]){
            visited[cur.x-2][cur.y-1] = true;
            ans++;
            q.push({cur.x-2,cur.y-1,cur.k+1});
        }
        if(cur.x+2<=n && cur.y-1>=1 && !visited[cur.x+2][cur.y-1]){
            visited[cur.x+2][cur.y-1] = true;
            ans++;
            q.push({cur.x+2,cur.y-1,cur.k+1});
        }
        if(cur.x-1>=1 && cur.y+2<=n && !visited[cur.x-1][cur.y+2]){
            visited[cur.x-1][cur.y+2] = true;
            ans++;
            q.push({cur.x-1,cur.y+2,cur.k+1});
        }
        if(cur.x+1<=n && cur.y+2<=n && !visited[cur.x+1][cur.y+2]){
            visited[cur.x+1][cur.y+2] = true;
            ans++;
            q.push({cur.x+1,cur.y+2,cur.k+1});
        }
        if(cur.x-1>=1 && cur.y-2>=1 && !visited[cur.x-1][cur.y-2]){
            visited[cur.x-1][cur.y-2] = true;
            ans++;
            q.push({cur.x-1,cur.y-2,cur.k+1});
        }
        if(cur.x+1<=n && cur.y-2>=1 && !visited[cur.x+1][cur.y-2]){
            visited[cur.x+1][cur.y-2] = true;
            ans++;
            q.push({cur.x+1,cur.y-2,cur.k+1});
        }
        q.pop();
    }
    cout << ans << endl;
    return 0;
}