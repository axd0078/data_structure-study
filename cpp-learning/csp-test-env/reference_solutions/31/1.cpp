#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    long long dx = 0;
    long long dy = 0;
    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        dx += x;
        dy += y;
    }

    for (int i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        cout << x + dx << ' ' << y + dy << '\n';
    }
    return 0;
}
