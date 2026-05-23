#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }

    int ans = n > 0 ? 1 : 0;
    for (int i = 1; i < n; ++i) {
        ans += (a[i] != a[i - 1]);
    }

    cout << ans << '\n';
    return 0;
}
