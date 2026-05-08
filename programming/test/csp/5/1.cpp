#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int pre;
    int x;
    int n;
    cin >> n;
    cin >> x;
    pre = x;
    n--;
    int ans = 0;
    while(n--){
        cin >> x;
        if(pre!=x) ans++;
        pre = x;
    }
    cout << ans+1 << endl;
    return 0;
}
