#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> q(n);
    iota(q.begin(), q.end(), 1);

    while (m--) {
        int id, delta;
        cin >> id >> delta;
        int pos = find(q.begin(), q.end(), id) - q.begin();
        q.erase(q.begin() + pos);
        q.insert(q.begin() + pos + delta, id);
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << q[i];
    }
    cout << '\n';

    return 0;
}
