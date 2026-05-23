#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, limit;
    cin >> n >> m >> limit;
    vector<int> counts(limit);
    for (int i = 0; i < n * m; ++i) {
        int value;
        cin >> value;
        ++counts[value];
    }
    for (int i = 0; i < limit; ++i) {
        if (i) {
            cout << ' ';
        }
        cout << counts[i];
    }
    cout << '\n';
    return 0;
}
