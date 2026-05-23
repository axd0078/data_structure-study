#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double r;
    cin >> n >> r;
    int inside = 0;
    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        if (x * x + y * y <= r * r + 1e-12) {
            ++inside;
        }
    }
    cout << fixed << setprecision(6) << 4.0 * inside / n << '\n';
    return 0;
}

