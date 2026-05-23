#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long r, y, g;
    cin >> r >> y >> g;

    int n;
    cin >> n;

    long long total = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        long long t;
        cin >> k >> t;
        if (k == 0 || k == 1) {
            total += t;
        } else if (k == 2) {
            total += t + r;
        }
    }

    cout << total << '\n';
    return 0;
}
