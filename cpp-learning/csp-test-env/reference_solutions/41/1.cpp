#include <bits/stdc++.h>
using namespace std;

bool balanced(int x) {
    int zero = 0;
    int one = 0;
    while (x > 0) {
        if (x % 2 == 0) {
            ++zero;
        } else {
            ++one;
        }
        x /= 2;
    }
    return zero == one;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int x;
        cin >> x;
        if (balanced(x)) {
            ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}

