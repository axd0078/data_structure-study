#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> price(n);
    int total = 0;
    for (int& value : price) {
        cin >> value;
        total += value;
    }

    vector<char> dp(total + 1, 0);
    dp[0] = 1;
    for (int value : price) {
        for (int sum = total - value; sum >= 0; --sum) {
            if (dp[sum]) {
                dp[sum + value] = 1;
            }
        }
    }

    for (int sum = x; sum <= total; ++sum) {
        if (dp[sum]) {
            cout << sum << '\n';
            return 0;
        }
    }

    return 0;
}
