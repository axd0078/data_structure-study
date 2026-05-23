#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> reward(m + 1, 0);
    for (int i = 1; i <= m; ++i) {
        cin >> reward[i];
    }

    vector<long long> dp(n + 1, 0);
    for (int apples = 1; apples <= n; ++apples) {
        long long best = 0;
        for (int take = 1; take <= min(m, apples); ++take) {
            best = max(best, dp[apples - take] + reward[take]);
        }
        dp[apples] = best;
    }

    cout << dp[n] << '\n';
    return 0;
}
