#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int pre = 1001;
    int cur;
    int ans = 0;
    for(int i=0;i<n;i++){
        cin >> cur;
        if(pre!=cur) ans++;
        pre = cur;
    }
    cout << ans << endl;
}