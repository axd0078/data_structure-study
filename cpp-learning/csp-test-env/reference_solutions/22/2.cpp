#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, L, r, t;
    cin >> n >> L >> r >> t;

    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        int row_sum = 0;
        for (int j = 0; j < n; ++j) {
            int value;
            cin >> value;
            row_sum += value;
            prefix[i + 1][j + 1] = prefix[i][j + 1] + row_sum;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x1 = max(0, i - r);
        int x2 = min(n - 1, i + r);
        for (int j = 0; j < n; ++j) {
            int y1 = max(0, j - r);
            int y2 = min(n - 1, j + r);
            int sum = prefix[x2 + 1][y2 + 1] - prefix[x1][y2 + 1] - prefix[x2 + 1][y1] + prefix[x1][y1];
            int count = (x2 - x1 + 1) * (y2 - y1 + 1);
            if (sum <= t * count) {
                ++ans;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
