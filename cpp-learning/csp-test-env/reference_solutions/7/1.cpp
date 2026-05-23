#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int prev;
    cin >> prev;
    if (n <= 2) {
        for (int i = 1; i < n; ++i) {
            int unused;
            cin >> unused;
        }
        cout << 0 << '\n';
        return 0;
    }

    int cur;
    cin >> cur;
    int ans = 0;

    for (int i = 3; i <= n; ++i) {
        int next;
        cin >> next;
        if ((cur > prev && cur > next) || (cur < prev && cur < next)) {
            ++ans;
        }
        prev = cur;
        cur = next;
    }

    cout << ans << '\n';
    return 0;
}
