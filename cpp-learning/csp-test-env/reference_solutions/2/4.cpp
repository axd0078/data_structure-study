#include <bits/stdc++.h>
using namespace std;

struct Customer {
    int x;
    int y;
    int demand;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, d;
    cin >> n >> m >> k >> d;

    vector<pair<int, int>> stores(m);
    for (auto& store : stores) {
        cin >> store.first >> store.second;
    }

    vector<Customer> customers(k);
    for (auto& customer : customers) {
        cin >> customer.x >> customer.y >> customer.demand;
    }

    vector<vector<int>> blocked(n + 1, vector<int>(n + 1));
    for (int i = 0; i < d; ++i) {
        int x, y;
        cin >> x >> y;
        blocked[x][y] = true;
    }

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, -1));
    queue<pair<int, int>> q;
    for (auto [x, y] : stores) {
        dist[x][y] = 0;
        q.push({x, y});
    }

    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 1 || nx > n || ny < 1 || ny > n) {
                continue;
            }
            if (blocked[nx][ny] || dist[nx][ny] != -1) {
                continue;
            }
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    long long ans = 0;
    for (const auto& customer : customers) {
        ans += 1LL * dist[customer.x][customer.y] * customer.demand;
    }
    cout << ans << '\n';
    return 0;
}

