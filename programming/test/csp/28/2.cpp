#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> p(m + 1), t(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> t[i];
    }

    vector<int> earliest(m + 1);
    bool ok = true;

    for (int i = 1; i <= m; ++i) {
        if (p[i] == 0) {
            earliest[i] = 1;
        } else {
            earliest[i] = earliest[p[i]] + t[p[i]];
        }
        if (earliest[i] + t[i] - 1 > n) {
            ok = false;
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (i > 1) {
            cout << ' ';
        }
        cout << earliest[i];
    }
    cout << '\n';

    if (!ok) {
        return 0;
    }

    vector<int> latest(m + 1);
    for (int i = 1; i <= m; ++i) {
        latest[i] = n - t[i] + 1;
    }

    for (int i = m; i >= 1; --i) {
        if (p[i] != 0) {
            latest[p[i]] = min(latest[p[i]], latest[i] - t[p[i]]);
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (i > 1) {
            cout << ' ';
        }
        cout << latest[i];
    }
    cout << '\n';

    return 0;
}
