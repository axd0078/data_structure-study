#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, t;
    int xl, yd, xr, yu;
    cin >> n >> k >> t >> xl >> yd >> xr >> yu;

    int passed = 0;
    int stayed = 0;
    for (int i = 0; i < n; ++i) {
        int best = 0;
        int current = 0;
        for (int j = 0; j < t; ++j) {
            int x, y;
            cin >> x >> y;
            if (xl <= x && x <= xr && yd <= y && y <= yu) {
                ++current;
                best = max(best, current);
            } else {
                current = 0;
            }
        }
        passed += best > 0;
        stayed += best >= k;
    }

    cout << passed << '\n' << stayed << '\n';
    return 0;
}
