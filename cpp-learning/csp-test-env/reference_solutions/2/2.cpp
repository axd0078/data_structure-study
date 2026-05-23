#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    bool painted[101][101] = {};
    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; ++x) {
            for (int y = y1; y < y2; ++y) {
                painted[x][y] = true;
            }
        }
    }
    int ans = 0;
    for (int x = 0; x <= 100; ++x) {
        for (int y = 0; y <= 100; ++y) {
            ans += painted[x][y];
        }
    }
    cout << ans << '\n';
    return 0;
}

