#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    const int MAX_TIME = 200000;
    vector<int> diff(MAX_TIME + 3, 0);
    for (int i = 0; i < n; ++i) {
        int t, c;
        cin >> t >> c;
        int left = t - c - k + 1;
        int right = t - k;
        if (right < 1) {
            continue;
        }
        left = max(left, 1);
        right = min(right, MAX_TIME);
        if (left <= right) {
            ++diff[left];
            --diff[right + 1];
        }
    }

    for (int i = 1; i <= MAX_TIME; ++i) {
        diff[i] += diff[i - 1];
    }

    while (m--) {
        int q;
        cin >> q;
        cout << diff[q] << '\n';
    }

    return 0;
}
