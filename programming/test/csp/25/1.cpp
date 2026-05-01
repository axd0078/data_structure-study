#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<bool> isInit(n+1,false);
    isInit[0] = true;
    int ans = 0;
    while (k--){
        int op1,op2;
        cin >> op1 >> op2;
        if(!isInit[op2]){
            ans++;
        }
        isInit[op1] = true;
    }
    cout << ans << endl;
    return 0;
}
