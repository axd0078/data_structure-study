#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, S;
    long long L;
    cin >> n >> L >> S;

    vector<pair<long long, long long>> trees(n);
    set<pair<long long, long long>> has_tree;
    for (auto& [x, y] : trees) {
        cin >> x >> y;
        has_tree.insert({x, y});
    }

    vector<vector<int>> pattern(S + 1, vector<int>(S + 1));
    for (int row = S; row >= 0; --row) {
        for (int col = 0; col <= S; ++col) {
            cin >> pattern[row][col];
        }
    }

    int ans = 0;
    for (auto [x, y] : trees) {
        if (x + S > L || y + S > L) {
            continue;
        }
        bool ok = true;
        for (int i = 0; i <= S && ok; ++i) {
            for (int j = 0; j <= S; ++j) {
                bool tree = has_tree.count({x + i, y + j});
                if (tree != (pattern[i][j] == 1)) {
                    ok = false;
                    break;
                }
            }
        }
        ans += ok;
    }

    cout << ans << '\n';
    return 0;
}
