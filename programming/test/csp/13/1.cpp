#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x,times=0;
    int ans = 0;
    cin >> x;
    while(x!=0){
        if(x==1){
            ans++;
            times = 0;
        }
        if(x==2)
            ans += 2*(++times);
        if(x==0)
            break;
        cin >> x;
    }
    cout << ans << '\n';
    return 0;
}
