#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> used(20, vector<int>(5, 0));

    while (n--) {
        int p;
        cin >> p;
        vector<int> ans;

        for (int row = 0; row < 20 && ans.empty(); ++row) {
            for (int start = 0; start + p <= 5; ++start) {
                bool ok = true;
                for (int col = start; col < start + p; ++col) {
                    ok &= !used[row][col];
                }
                if (!ok) continue;
                for (int col = start; col < start + p; ++col) {
                    used[row][col] = 1;
                    ans.push_back(row * 5 + col + 1);
                }
                break;
            }
        }

        if (ans.empty()) {
            for (int row = 0; row < 20 && (int)ans.size() < p; ++row) {
                for (int col = 0; col < 5 && (int)ans.size() < p; ++col) {
                    if (!used[row][col]) {
                        used[row][col] = 1;
                        ans.push_back(row * 5 + col + 1);
                    }
                }
            }
        }

        for (int i = 0; i < (int)ans.size(); ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }

    return 0;
}
