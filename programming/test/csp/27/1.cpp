#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    vector<int> c(n+1);
    c[0] = 1;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        c[i] = c[i-1] * a[i];
    }
    int temp = 0;
    int ans;
    for(int i=1;i<=n;i++){
        ans = (m%c[i] - temp)/c[i-1];
        temp = c[i-1] * ans;
        cout << ans << (i==n?"":" ");
    }
    cout << endl;
    return 0;
}
