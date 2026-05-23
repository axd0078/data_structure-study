#include <bits/stdc++.h>
using namespace std;

bool shouldSkip(int value) {
    if (value % 7 == 0) {
        return true;
    }
    while (value > 0) {
        if (value % 10 == 7) {
            return true;
        }
        value /= 10;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    array<int, 4> skipped{};
    int reported = 0;
    int current = 1;
    while (reported < n) {
        int player = (current - 1) % 4;
        if (shouldSkip(current)) {
            ++skipped[player];
        } else {
            ++reported;
        }
        ++current;
    }

    for (int count : skipped) {
        cout << count << '\n';
    }
    return 0;
}
