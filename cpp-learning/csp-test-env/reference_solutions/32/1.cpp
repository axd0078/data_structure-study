#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            bool ok = true;
            for (int k = 0; k < m; ++k) {
                if (a[j][k] <= a[i][k]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = j + 1;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

