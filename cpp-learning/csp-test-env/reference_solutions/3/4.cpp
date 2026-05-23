#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    explicit DSU(int n) : parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        parent[a] = b;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a - 1, b - 1});
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    long long ans = 0;
    for (auto [cost, a, b] : edges) {
        if (dsu.unite(a, b)) {
            ans += cost;
        }
    }
    cout << ans << '\n';
    return 0;
}

