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

    for (int col = m - 1; col >= 0; --col) {
        for (int row = 0; row < n; ++row) {
            if (row != 0) {
                cout << ' ';
            }
            cout << a[row][col];
        }
        cout << '\n';
    }
    return 0;
}
