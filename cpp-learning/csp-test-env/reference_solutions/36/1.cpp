#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    while (k--) {
        int x, y;
        string ops;
        cin >> x >> y >> ops;
        for (char op : ops) {
            int nx = x, ny = y;
            if (op == 'f') {
                ++ny;
            } else if (op == 'b') {
                --ny;
            } else if (op == 'l') {
                --nx;
            } else if (op == 'r') {
                ++nx;
            }
            if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
                x = nx;
                y = ny;
            }
        }
        cout << x << ' ' << y << '\n';
    }
    return 0;
}

