#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> a(n+1);
    vector<long long> b(n+1);
    for(int i=0;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }
    vector<long long> S(n + 1);
    S[0] = a[0];
    for (int i = 1; i <= n; i++)
        S[i] = S[i - 1] + a[i] - b[i];

    vector<long long> pre_max(n + 1), suf_max(n + 1);

    pre_max[0] = S[0];
    for (int i = 1; i <= n; i++)
        pre_max[i] = max(pre_max[i - 1], S[i]);
    //前缀最大值

    suf_max[n] = S[n];
    for (int i = n - 1; i >= 0; i--)
        suf_max[i] = max(suf_max[i + 1], S[i]);
    //后缀最大值
    for (int i = 1; i <= n; i++) {
        long long ans = max(pre_max[i - 1], suf_max[i] + b[i]);
        cout << ans << " \n"[i == n];
    }
    return 0;
}
