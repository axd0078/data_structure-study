#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, t;
    cin >> n >> l >> t;
    vector<int> x(n), dir(n, 1);
    for (int i = 0; i < n; ++i) cin >> x[i];

    for (int sec = 0; sec < t; ++sec) {
        for (int i = 0; i < n; ++i) {
            x[i] += dir[i];
            if (x[i] == 0 || x[i] == l) {
                dir[i] = -dir[i];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (x[i] == x[j]) {
                    dir[i] = -dir[i];
                    dir[j] = -dir[j];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << x[i];
    }
    cout << '\n';

    return 0;
}
