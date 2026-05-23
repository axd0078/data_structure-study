#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long limit;
    cin >> n >> limit;

    long long previous = 0;
    long long ans = 0;
    for (int index = 1; index <= n; ++index) {
        long long current;
        cin >> current;
        ans += 1LL * (index - 1) * (current - previous);
        previous = current;
    }
    ans += 1LL * n * (limit - previous);

    cout << ans << '\n';
    return 0;
}
