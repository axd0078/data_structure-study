#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        long long radix;
        cin >> radix;
        if (i) {
            cout << ' ';
        }
        cout << m % radix;
        m /= radix;
    }
    cout << '\n';
    return 0;
}
