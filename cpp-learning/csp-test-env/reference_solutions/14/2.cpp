#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    for (int i = 0; i < n; ++i) cin >> b[i].first >> b[i].second;

    int i = 0, j = 0, ans = 0;
    while (i < n && j < n) {
        int left = max(a[i].first, b[j].first);
        int right = min(a[i].second, b[j].second);
        if (left < right) ans += right - left;
        if (a[i].second < b[j].second) ++i;
        else ++j;
    }

    cout << ans << '\n';

    return 0;
}
