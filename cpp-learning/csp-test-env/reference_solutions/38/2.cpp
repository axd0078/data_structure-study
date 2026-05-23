#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    int sx, sy;
    cin >> n >> k >> sx >> sy;

    vector<pair<int, int>> moves = {
        {1, 2}, {2, 1}, {-1, 2}, {-2, 1},
        {1, -2}, {2, -1}, {-1, -2}, {-2, -1},
    };

    vector<vector<int>> seen(n + 1, vector<int>(n + 1, 0));
    queue<tuple<int, int, int>> q;
    seen[sx][sy] = 1;
    q.push({sx, sy, 0});

    int ans = 1;
    while (!q.empty()) {
        auto [x, y, dist] = q.front();
        q.pop();
        if (dist == k) {
            continue;
        }
        for (auto [dx, dy] : moves) {
            int nx = x + dx;
            int ny = y + dy;
            if (1 <= nx && nx <= n && 1 <= ny && ny <= n && !seen[nx][ny]) {
                seen[nx][ny] = 1;
                ++ans;
                q.push({nx, ny, dist + 1});
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
