#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int total = 0;
    int centerScore = 0;
    int value;
    while (cin >> value && value != 0) {
        if (value == 1) {
            total += 1;
            centerScore = 0;
        } else {
            centerScore += 2;
            total += centerScore;
        }
    }

    cout << total << '\n';
    return 0;
}
