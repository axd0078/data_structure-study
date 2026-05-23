#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long total = 0;
    vector<int> dropped(n, 0);

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        long long current;
        cin >> current;
        for (int j = 1; j < m; ++j) {
            long long value;
            cin >> value;
            if (value <= 0) {
                current += value;
            } else {
                if (value < current) dropped[i] = 1;
                current = value;
            }
        }
        total += current;
    }

    int d = accumulate(dropped.begin(), dropped.end(), 0);
    int e = 0;
    for (int i = 0; i < n; ++i) {
        if (dropped[(i - 1 + n) % n] && dropped[i] && dropped[(i + 1) % n]) {
            ++e;
        }
    }

    cout << total << ' ' << d << ' ' << e << '\n';

    return 0;
}
