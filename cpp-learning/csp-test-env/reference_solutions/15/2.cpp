#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long r, y, g;
    int n;
    cin >> r >> y >> g >> n;
    long long cycle = r + y + g;
    long long total = 0;

    auto wait_time = [&](int kind, long long remain, long long elapsed) {
        long long start;
        if (kind == 1) {
            start = r - remain;
        } else if (kind == 2) {
            start = r + g + (y - remain);
        } else {
            start = r + (g - remain);
        }

        long long cur = (start + elapsed) % cycle;
        if (cur < r) return r - cur;
        if (cur < r + g) return 0LL;
        return cycle - cur;
    };

    for (int i = 0; i < n; ++i) {
        int k;
        long long t;
        cin >> k >> t;
        if (k == 0) {
            total += t;
        } else {
            total += wait_time(k, t, total);
        }
    }

    cout << total << '\n';

    return 0;
}
