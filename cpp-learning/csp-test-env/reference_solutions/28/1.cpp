#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double rate;
    cin >> n >> rate;

    double total = 0.0;
    double discount = 1.0;
    for (int i = 0; i <= n; ++i) {
        double value;
        cin >> value;
        total += value / discount;
        discount *= 1.0 + rate;
    }

    cout << fixed << setprecision(6) << total << '\n';
    return 0;
}
