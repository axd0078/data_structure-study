#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int leftMiddleIndex = (n + 1) / 2;
    const int rightMiddleIndex = (n + 2) / 2;

    long long first = 0;
    long long last = 0;
    long long leftMiddle = 0;
    long long rightMiddle = 0;

    for (int i = 1; i <= n; ++i) {
        long long value;
        cin >> value;
        if (i == 1) {
            first = value;
        }
        if (i == leftMiddleIndex) {
            leftMiddle = value;
        }
        if (i == rightMiddleIndex) {
            rightMiddle = value;
        }
        last = value;
    }

    long long maximum = max(first, last);
    long long minimum = min(first, last);
    long long twiceMedian = leftMiddle + rightMiddle;

    cout << maximum << ' ';
    if (twiceMedian % 2 == 0) {
        cout << twiceMedian / 2;
    } else {
        cout << fixed << setprecision(1) << twiceMedian / 2.0;
    }
    cout << ' ' << minimum << '\n';
    return 0;
}
