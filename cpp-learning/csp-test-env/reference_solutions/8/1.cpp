#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int prev;
    cin >> prev;
    int ans = 0;

    for (int i = 1; i < n; ++i) {
        int cur;
        cin >> cur;
        ans = max(ans, abs(cur - prev));
        prev = cur;
    }

    cout << ans << '\n';
    return 0;
}
