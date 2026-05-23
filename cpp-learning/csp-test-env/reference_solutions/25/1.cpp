#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<char> initialized(n + 1, 0);
    int warnings = 0;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        if (y != 0 && !initialized[y]) {
            ++warnings;
        }
        initialized[x] = 1;
    }
    cout << warnings << '\n';
    return 0;
}
