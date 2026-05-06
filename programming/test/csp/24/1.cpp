#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,N;
    cin >> n >> N;
    vector<int> a(n+2);
    a[0] = 0,a[n+1] = N;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    long long ans = 0;
    for(int i=0;i<=n;i++){
        ans += 1LL * i * (a[i+1] - a[i]);
        //i是查询的结果 a[i+1] - a[i] 是这个区间的答案都是i
    }
    cout << ans << endl;
    return 0;
}
