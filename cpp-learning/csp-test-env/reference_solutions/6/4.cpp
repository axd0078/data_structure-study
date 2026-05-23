#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        ++degree[u];
        ++degree[v];
    }

    int odd = 0;
    for (int i = 1; i <= n; ++i) {
        odd += degree[i] % 2;
    }
    if (!(odd == 0 || (odd == 2 && degree[1] % 2 == 1))) {
        cout << "-1\n";
        return 0;
    }

    vector<int> seen(n + 1, 0);
    queue<int> q;
    q.push(1);
    seen[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!seen[v]) {
                seen[v] = 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (degree[i] && !seen[i]) {
            cout << "-1\n";
            return 0;
        }
    }

    vector<int> path;
    function<void(int)> dfs = [&](int u) {
        while (!adj[u].empty()) {
            int v = *adj[u].begin();
            adj[u].erase(v);
            adj[v].erase(u);
            dfs(v);
        }
        path.push_back(u);
    };
    dfs(1);
    if ((int)path.size() != m + 1) {
        cout << "-1\n";
        return 0;
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < (int)path.size(); ++i) {
        if (i) cout << ' ';
        cout << path[i];
    }
    cout << '\n';
    return 0;
}
