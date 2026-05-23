#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> erase(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m;) {
            int k = j;
            while (k < m && a[i][k] == a[i][j]) ++k;
            if (k - j >= 3) {
                for (int t = j; t < k; ++t) erase[i][t] = 1;
            }
            j = k;
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n;) {
            int k = i;
            while (k < n && a[k][j] == a[i][j]) ++k;
            if (k - i >= 3) {
                for (int t = i; t < k; ++t) erase[t][j] = 1;
            }
            i = k;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j) cout << ' ';
            cout << (erase[i][j] ? 0 : a[i][j]);
        }
        cout << '\n';
    }
    return 0;
}
