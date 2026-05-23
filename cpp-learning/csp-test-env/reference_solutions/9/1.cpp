#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> counts(1001, 0);
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        ++counts[value];
    }

    int less = 0;
    for (int candidate = 1; candidate <= 1000; ++candidate) {
        if (counts[candidate] == 0) {
            continue;
        }
        int greater = n - less - counts[candidate];
        if (less == greater) {
            cout << candidate << '\n';
            return 0;
        }
        less += counts[candidate];
    }

    cout << -1 << '\n';
    return 0;
}
