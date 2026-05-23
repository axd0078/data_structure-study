#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long b, c, l, r;
    cin >> b >> c >> l >> r;

    long long start = (l % 2 == 0 ? l : l + 1);
    if (start > r) {
        cout << 0 << '\n';
        return 0;
    }

    long long count = (r - start) / 2 + 1;
    long long last = start + 2 * (count - 1);
    long long sum_t = count * (count - 1) / 2;
    long long sum_t2 = count * (count - 1) * (2 * count - 1) / 6;
    long long sum_x = count * (start + last) / 2;
    long long sum_x2 = count * start * start + 4 * start * sum_t + 4 * sum_t2;

    cout << 2 * (sum_x2 + b * sum_x + c * count) << '\n';
    return 0;
}
