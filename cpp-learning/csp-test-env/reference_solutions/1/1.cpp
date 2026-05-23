#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    unordered_set<int> seen;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        seen.insert(x);
    }

    int ans = 0;
    for (int x : seen) {
        if (x > 0 && seen.count(-x)) {
            ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}

