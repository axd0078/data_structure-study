#include <bits/stdc++.h>
using namespace std;

int transform_value(int x, int key) {
    auto f = [&](int value) {
        return ((value * value + key * key) & 7) ^ key;
    };

    int b = x >> 6;
    int q = (x >> 3) & 7;
    int r = x & 7;
    int c = q ^ f(b);
    int a = r ^ f(c);
    return (a << 6) | (b << 3) | c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> keys(m);
    for (int i = 0; i < m; ++i) {
        cin >> keys[i];
    }

    vector<int> decoded(512);
    for (int value = 0; value < 512; ++value) {
        int x = value;
        for (int i = m - 1; i >= 0; --i) {
            x = transform_value(x, keys[i]);
        }
        decoded[value] = x;
    }

    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        if (i) {
            cout << ' ';
        }
        cout << decoded[value];
    }
    cout << '\n';
    return 0;
}
