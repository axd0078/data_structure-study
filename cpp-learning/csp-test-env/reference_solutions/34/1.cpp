#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p, q;
    cin >> n >> m >> p >> q;
    int total = n * m;
    for (int index = 0; index < total; ++index) {
        int value;
        cin >> value;
        if (index % q) {
            cout << ' ';
        }
        cout << value;
        if (index % q == q - 1) {
            cout << '\n';
        }
    }
    return 0;
}
