#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long m;
    int k;
    cin >> n >> m >> k;
    vector<pair<int, int>> fields(n);
    int high = k;
    for (auto& [t, c] : fields) {
        cin >> t >> c;
        high = max(high, t);
    }

    int low = k;
    while (low < high) {
        int mid = (low + high) / 2;
        long long cost = 0;
        for (auto [t, c] : fields) {
            if (t > mid) {
                cost += 1LL * (t - mid) * c;
                if (cost > m) {
                    break;
                }
            }
        }
        if (cost <= m) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << '\n';
    return 0;
}
