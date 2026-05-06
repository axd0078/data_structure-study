#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,l,r,t;
    cin >> n >> l >> r >> t;
    vector<vector<long long>> s(n+1,vector<long long>(n+1,0));
    //s[i][j]表示从左下角到ij的元素和
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            long long x;
            cin >> x;
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + x;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x1 = max(0,i-r);
            int x2 = min(n-1,i+r);
            int y1 = max(0,j-r);
            int y2 = min(n-1,j+r);
            long long sum = s[x2+1][y2+1] - s[x1][y2+1]
                             - s[x2+1][y1] + s[x1][y1];
            long long area = 1LL * (x2-x1+1) * (y2-y1+1);
            if(area*t >= sum){
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}