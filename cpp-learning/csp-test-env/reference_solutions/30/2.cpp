#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;
    vector<vector<long long>> q(n, vector<long long>(d));
    vector<vector<long long>> k(n, vector<long long>(d));
    vector<vector<long long>> v(n, vector<long long>(d));

    for (auto& row : q) {
        for (auto& value : row) cin >> value;
    }
    for (auto& row : k) {
        for (auto& value : row) cin >> value;
    }
    for (auto& row : v) {
        for (auto& value : row) cin >> value;
    }

    vector<long long> w(n);
    for (auto& value : w) cin >> value;

    vector<vector<long long>> ktv(d, vector<long long>(d, 0));
    for (int row = 0; row < d; ++row) {
        for (int col = 0; col < d; ++col) {
            for (int i = 0; i < n; ++i) {
                ktv[row][col] += k[i][row] * v[i][col];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int col = 0; col < d; ++col) {
            long long value = 0;
            for (int mid = 0; mid < d; ++mid) {
                value += q[i][mid] * ktv[mid][col];
            }
            if (col) cout << ' ';
            cout << value * w[i];
        }
        cout << '\n';
    }

    return 0;
}
