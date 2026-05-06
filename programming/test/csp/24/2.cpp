#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,N;
    cin >> n >> N;
    vector<long long> a(n+2);
    a[0] = 0;
    a[n+1] = N;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    long long r = N / (n+1);
    long long ans = 0;
    for(int i=0;i<=n;i++){
        long long left = a[i];
        long long right = a[i+1];
        while(left<right){
            long long g = left / r;
            long long end = min(right,(g+1)*r);
            /*g 的值在下一次变成 g+1 的位置是 (g+1) * r。
            但 g 的变化点可能超出当前区间，所以取 min(right, (g+1)*r)。
            这样 [left, end) 内 g 值恒为 g。*/
            ans+=(end - left) * llabs(g-i);
            left = end;
        }
    }
    /*vector<int> diff(N,0);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        diff[x]++;
    }
    int r = N / (n+1);
    int ans = 0;
    int f = 0;
    for(int i=0;i<N;i++){
        int g = i / r;
        f += diff[i];
        ans += abs(g-f);
    }N 可到 1e9，不能枚举每个 x 差分数组不行*/
    cout << ans << endl;
    return 0;
}
