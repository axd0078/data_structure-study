#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<pair<int, int>> points;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points.insert({x, y});
    }

    vector<int> ans(5, 0);
    int dx4[4] = {1, -1, 0, 0};
    int dy4[4] = {0, 0, 1, -1};
    int dxc[4] = {1, 1, -1, -1};
    int dyc[4] = {1, -1, 1, -1};

    for (auto [x, y] : points) {
        bool ok = true;
        for (int i = 0; i < 4; ++i) {
            ok &= points.count({x + dx4[i], y + dy4[i]});
        }
        if (!ok) continue;

        int score = 0;
        for (int i = 0; i < 4; ++i) {
            score += points.count({x + dxc[i], y + dyc[i]});
        }
        ++ans[score];
    }

    for (int value : ans) {
        cout << value << '\n';
    }

    return 0;
}
