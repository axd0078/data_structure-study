#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long N;
    cin >> n >> N;

    vector<long long> a(n + 2);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[n + 1] = N;

    long long r = N / (n + 1);
    long long x = 0;
    int idx = 0;
    long long ans = 0;
    while (x < N) {
        while (idx + 1 <= n + 1 && a[idx + 1] <= x) {
            ++idx;
        }
        long long f = idx;
        long long g = x / r;
        long long next_x = min({N, a[idx + 1], (g + 1) * r});
        ans += (next_x - x) * llabs(g - f);
        x = next_x;
    }

    cout << ans << '\n';
    return 0;
}
