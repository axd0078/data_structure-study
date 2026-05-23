#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int friends = 0;
    int current = 0;
    for (int i = 0; i < n; ++i) {
        int weight;
        cin >> weight;
        current += weight;
        if (current >= k) {
            ++friends;
            current = 0;
        }
    }

    if (current > 0) {
        ++friends;
    }

    cout << friends << '\n';
    return 0;
}
