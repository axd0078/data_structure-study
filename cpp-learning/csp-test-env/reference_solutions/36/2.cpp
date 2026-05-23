#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n + 1), b(n + 1, 0);
    for (long long& value : a) {
        cin >> value;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    vector<long long> need(n + 1);
    long long sum_a = 0;
    long long sum_b = 0;
    for (int j = 0; j <= n; ++j) {
        sum_a += a[j];
        if (j > 0) {
            sum_b += b[j];
        }
        need[j] = sum_a - sum_b;
    }

    vector<long long> prefix_max = need;
    for (int i = 1; i <= n; ++i) {
        prefix_max[i] = max(prefix_max[i], prefix_max[i - 1]);
    }

    vector<long long> suffix_max = need;
    for (int i = n - 1; i >= 0; --i) {
        suffix_max[i] = max(suffix_max[i], suffix_max[i + 1]);
    }

    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        cout << max(prefix_max[i - 1], suffix_max[i] + b[i]);
    }
    cout << '\n';

    return 0;
}
