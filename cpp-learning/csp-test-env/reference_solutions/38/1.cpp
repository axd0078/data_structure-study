#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    while (k--) {
        int mu, sigma, value;
        cin >> mu >> sigma >> value;
        int percent = (value - mu) * 100 / sigma;
        cout << percent / 10 + 1 << ' ' << percent % 10 + 1 << '\n';
    }
    return 0;
}
