#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> value(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> value[i];
    }

    vector<vector<int>> standard_indices(m);
    vector<int> standard_xor(m, 0);
    for (int i = 0; i < m; ++i) {
        int len;
        cin >> len;
        standard_indices[i].resize(len);
        for (int j = 0; j < len; ++j) {
            cin >> standard_indices[i][j];
            standard_xor[i] ^= value[standard_indices[i][j]];
        }
    }

    for (int i = 0; i < m; ++i) {
        int len;
        cin >> len;
        vector<int> current(len);
        int current_xor = 0;
        for (int j = 0; j < len; ++j) {
            cin >> current[j];
            current_xor ^= value[current[j]];
        }

        bool same_indices = (current == standard_indices[i]);
        bool same_xor = (current_xor == standard_xor[i]);
        cout << (same_indices == same_xor ? "correct" : "wrong") << '\n';
    }
    return 0;
}
