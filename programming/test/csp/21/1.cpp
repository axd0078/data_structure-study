#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    long long ans = 0;
    while(n--){
        long long s,w;
        cin >> s >> w;
        ans += s*w;
    }
    ans = 0>ans?0:ans;
    cout << ans << endl;
    return 0;
}
