#include <bits/stdc++.h>
using namespace std;

bool should_leave(long long number, int k) {
    return number % k == 0 || number % 10 == k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> children(n);
    iota(children.begin(), children.end(), 1);

    int pos = 0;
    long long number = 1;
    while ((int)children.size() > 1) {
        if (should_leave(number, k)) {
            children.erase(children.begin() + pos);
            if (pos == (int)children.size()) pos = 0;
        } else {
            pos = (pos + 1) % children.size();
        }
        ++number;
    }

    cout << children[0] << '\n';

    return 0;
}
