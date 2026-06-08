#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int ans = 0;
    while(n--){
        int w,s;
        cin >> w >> s;
        ans += w*s;
    }
    cout << max(ans,0) << endl;
    return 0;
}
