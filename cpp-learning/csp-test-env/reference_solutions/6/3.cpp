#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, q;
    cin >> m >> n >> q;
    vector<string> canvas(n, string(m, '.'));

    auto row = [&](int y) { return n - 1 - y; };

    while (q--) {
        int op;
        cin >> op;
        if (op == 0) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 == x2) {
                if (y1 > y2) swap(y1, y2);
                for (int y = y1; y <= y2; ++y) {
                    char& cell = canvas[row(y)][x1];
                    cell = (cell == '-' || cell == '+') ? '+' : '|';
                }
            } else {
                if (x1 > x2) swap(x1, x2);
                for (int x = x1; x <= x2; ++x) {
                    char& cell = canvas[row(y1)][x];
                    cell = (cell == '|' || cell == '+') ? '+' : '-';
                }
            }
        } else {
            int x, y;
            char c;
            cin >> x >> y >> c;
            int sr = row(y), sc = x;
            if (canvas[sr][sc] == '-' || canvas[sr][sc] == '|' || canvas[sr][sc] == '+') continue;
            queue<pair<int, int>> que;
            que.push({sr, sc});
            canvas[sr][sc] = c;
            const int dr[4] = {1, -1, 0, 0};
            const int dc[4] = {0, 0, 1, -1};
            while (!que.empty()) {
                auto [r, col] = que.front();
                que.pop();
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d], nc = col + dc[d];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    char ch = canvas[nr][nc];
                    if (ch == '-' || ch == '|' || ch == '+' || ch == c) continue;
                    canvas[nr][nc] = c;
                    que.push({nr, nc});
                }
            }
        }
    }

    for (const string& line : canvas) {
        cout << line << '\n';
    }
    return 0;
}
