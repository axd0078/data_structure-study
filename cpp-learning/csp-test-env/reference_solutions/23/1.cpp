#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long max_sum = 0;
    long long min_sum = 0;
    int previous = -1;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        max_sum += value;
        if (value > previous) {
            min_sum += value;
        }
        previous = value;
    }
    cout << max_sum << '\n' << min_sum << '\n';
    return 0;
}
