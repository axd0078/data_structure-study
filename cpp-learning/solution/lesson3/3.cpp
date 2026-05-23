#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    int ans = 0;
    for(int i=0;i<m*n;i++){
        int x;
        cin >> x;
        if(x > 0) ans++;
    }
    cout << ans << endl;
    return 0;
}