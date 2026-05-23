#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long a, b;
    cin >> n >> a >> b;

    long long total = 0;
    for (int i = 0; i < n; ++i) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        long long width = max(0LL, min(x2, a) - max(x1, 0LL));
        long long height = max(0LL, min(y2, b) - max(y1, 0LL));
        total += width * height;
    }

    cout << total << '\n';
    return 0;
}
