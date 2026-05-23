#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        long long w, score;
        cin >> w >> score;
        sum += w * score;
    }
    cout << max(0LL, sum) << '\n';
    return 0;
}
