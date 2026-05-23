#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    long long total = 0;
    int bestIndex = 1;
    long long bestRemoved = -1;

    for (int i = 1; i <= n; ++i) {
        long long current;
        cin >> current;

        long long removed = 0;
        for (int j = 0; j < m; ++j) {
            long long delta;
            cin >> delta;
            current += delta;
            removed -= delta;
        }

        total += current;
        if (removed > bestRemoved) {
            bestRemoved = removed;
            bestIndex = i;
        }
    }

    cout << total << ' ' << bestIndex << ' ' << bestRemoved << '\n';
    return 0;
}
