#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        long long n;
        int k;
        cin >> n >> k;

        long long answer = 1;
        for (long long p = 2; p * p <= n; p += (p == 2 ? 1 : 2)) {
            int count = 0;
            while (n % p == 0) {
                n /= p;
                ++count;
            }
            if (count >= k) {
                while (count--) {
                    answer *= p;
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
