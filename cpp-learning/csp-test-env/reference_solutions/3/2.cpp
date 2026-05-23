#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    bool first = true;
    for (int sum = 0; sum <= 2 * n - 2; ++sum) {
        vector<pair<int, int>> cells;
        for (int i = 0; i < n; ++i) {
            int j = sum - i;
            if (0 <= j && j < n) {
                cells.push_back({i, j});
            }
        }
        if (sum % 2 == 0) {
            reverse(cells.begin(), cells.end());
        }
        for (auto [i, j] : cells) {
            if (!first) {
                cout << ' ';
            }
            first = false;
            cout << a[i][j];
        }
    }
    cout << '\n';
    return 0;
}
