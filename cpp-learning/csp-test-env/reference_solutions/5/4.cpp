#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> dfn(n + 1), low(n + 1), in_stack(n + 1), st;
    int timer = 0;
    long long answer = 0;

    function<void(int)> dfs = [&](int u) {
        dfn[u] = low[u] = ++timer;
        st.push_back(u);
        in_stack[u] = 1;
        for (int v : graph[u]) {
            if (!dfn[v]) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (in_stack[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (low[u] == dfn[u]) {
            long long size = 0;
            while (true) {
                int x = st.back();
                st.pop_back();
                in_stack[x] = 0;
                ++size;
                if (x == u) {
                    break;
                }
            }
            answer += size * (size - 1) / 2;
        }
    };

    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            dfs(i);
        }
    }
    cout << answer << '\n';
    return 0;
}
