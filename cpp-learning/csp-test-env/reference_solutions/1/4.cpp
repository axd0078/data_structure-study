#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    int64 r;
    cin >> n >> m >> k >> r;
    vector<pair<int64, int64>> p(n + m);
    for (auto& point : p) {
        cin >> point.first >> point.second;
    }

    auto can_connect = [&](int a, int b) {
        int64 dx = p[a].first - p[b].first;
        int64 dy = p[a].second - p[b].second;
        return dx * dx + dy * dy <= r * r;
    };

    const int INF = 1e9;
    vector<vector<int>> dist(n + m, vector<int>(k + 1, INF));
    queue<pair<int, int>> q;
    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto [cur, used] = q.front();
        q.pop();
        for (int nxt = 0; nxt < n + m; ++nxt) {
            if (nxt == cur || !can_connect(cur, nxt)) {
                continue;
            }
            int next_used = used + (nxt >= n);
            if (next_used > k) {
                continue;
            }
            if (dist[nxt][next_used] > dist[cur][used] + 1) {
                dist[nxt][next_used] = dist[cur][used] + 1;
                q.push({nxt, next_used});
            }
        }
    }

    int hops = *min_element(dist[1].begin(), dist[1].end());
    cout << hops - 1 << '\n';
    return 0;
}

