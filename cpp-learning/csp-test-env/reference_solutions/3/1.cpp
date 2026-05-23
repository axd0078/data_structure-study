#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cout << ++cnt[x] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}

