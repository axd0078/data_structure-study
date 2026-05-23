#include <bits/stdc++.h>
using namespace std;

pair<int, int> farthest(int start, const vector<vector<int>>& graph) {
    vector<int> dist(graph.size(), -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    int best = start;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (dist[u] > dist[best]) {
            best = u;
        }
        for (int v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return {best, dist[best]};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + m + 1);
    for (int i = 2; i <= n; ++i) {
        int parent;
        cin >> parent;
        graph[parent].push_back(i);
        graph[i].push_back(parent);
    }
    for (int i = 1; i <= m; ++i) {
        int sw;
        cin >> sw;
        int pc = n + i;
        graph[sw].push_back(pc);
        graph[pc].push_back(sw);
    }

    auto [endpoint, _] = farthest(1, graph);
    auto [other, diameter] = farthest(endpoint, graph);
    (void)other;
    cout << diameter << '\n';
    return 0;
}
