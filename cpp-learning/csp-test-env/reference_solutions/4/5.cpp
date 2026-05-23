#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int len;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> price(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> price[i];
    }

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        graph[u].push_back({v, len});
        graph[v].push_back({u, len});
    }

    vector<int> parent(n + 1), depth(n + 1), edge_to_parent(n + 1);
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    depth[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const Edge& e : graph[u]) {
            if (e.to == parent[u]) {
                continue;
            }
            parent[e.to] = u;
            depth[e.to] = depth[u] + 1;
            edge_to_parent[e.to] = e.len;
            q.push(e.to);
        }
    }

    auto edge_len = [&](int u, int v) {
        if (parent[u] == v) {
            return edge_to_parent[u];
        }
        return edge_to_parent[v];
    };

    while (m--) {
        int s, t;
        cin >> s >> t;
        int a = s, b = t;
        vector<int> up, down;
        while (depth[a] > depth[b]) {
            up.push_back(a);
            a = parent[a];
        }
        while (depth[b] > depth[a]) {
            down.push_back(b);
            b = parent[b];
        }
        while (a != b) {
            up.push_back(a);
            down.push_back(b);
            a = parent[a];
            b = parent[b];
        }
        up.push_back(a);
        reverse(down.begin(), down.end());
        vector<int> path = up;
        path.insert(path.end(), down.begin(), down.end());

        long long best_price = LLONG_MAX;
        long long answer = 0;
        for (int i = 0; i + 1 < (int)path.size(); ++i) {
            best_price = min(best_price, price[path[i]]);
            answer += best_price * edge_len(path[i], path[i + 1]);
        }
        cout << answer << '\n';
    }

    return 0;
}
