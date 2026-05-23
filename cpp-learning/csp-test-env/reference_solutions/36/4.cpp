#include <bits/stdc++.h>
using namespace std;

struct NextSet {
    vector<int> parent;

    explicit NextSet(int n) : parent(n + 2) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void erase(int x) {
        parent[x] = find(x + 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1), k(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;
    NextSet unused(n + 1);
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int right = min(n, cur + k[cur]);
        for (int landing = unused.find(cur + 1); landing <= right; landing = unused.find(landing)) {
            int next_pos = landing - a[landing];
            unused.erase(landing);
            if (dist[next_pos] == -1) {
                dist[next_pos] = dist[cur] + 1;
                q.push(next_pos);
            }
        }
    }

    cout << dist[n] << '\n';
    return 0;
}
