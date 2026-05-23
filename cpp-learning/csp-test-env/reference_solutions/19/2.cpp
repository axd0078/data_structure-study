#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    int a, b;
    cin >> n >> a >> b;
    vector<pair<int, long long>> u(a), v(b);
    for (auto& [idx, value] : u) cin >> idx >> value;
    for (auto& [idx, value] : v) cin >> idx >> value;

    int i = 0, j = 0;
    long long ans = 0;
    while (i < a && j < b) {
        if (u[i].first == v[j].first) {
            ans += u[i].second * v[j].second;
            ++i;
            ++j;
        } else if (u[i].first < v[j].first) {
            ++i;
        } else {
            ++j;
        }
    }

    cout << ans << '\n';

    return 0;
}
