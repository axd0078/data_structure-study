#include <bits/stdc++.h>
using namespace std;

void print_line(const vector<int>& values) {
    for (int i = 0; i < (int)values.size(); ++i) {
        if (i) cout << ' ';
        cout << values[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> parent(m), duration(m);
    for (int& value : parent) cin >> value;
    for (int& value : duration) cin >> value;

    vector<int> earliest(m, 1);
    for (int i = 0; i < m; ++i) {
        if (parent[i] != 0) {
            int p = parent[i] - 1;
            earliest[i] = earliest[p] + duration[p];
        }
    }
    print_line(earliest);

    bool feasible = true;
    for (int i = 0; i < m; ++i) {
        if (earliest[i] + duration[i] - 1 > n) {
            feasible = false;
        }
    }
    if (!feasible) {
        return 0;
    }

    vector<int> latest(m);
    for (int i = 0; i < m; ++i) {
        latest[i] = n - duration[i] + 1;
    }
    for (int i = m - 1; i >= 0; --i) {
        if (parent[i] != 0) {
            int p = parent[i] - 1;
            latest[p] = min(latest[p], latest[i] - duration[p]);
        }
    }
    print_line(latest);

    return 0;
}
