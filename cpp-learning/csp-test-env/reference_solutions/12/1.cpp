#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> seen(10001, false);
    bool hasDuplicate = false;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        if (seen[value]) {
            hasDuplicate = true;
        }
        seen[value] = true;
    }

    if (hasDuplicate) {
        cout << 0 << '\n';
        return 0;
    }

    int previous = -1;
    int answer = 10001;
    for (int value = 1; value <= 10000; ++value) {
        if (!seen[value]) {
            continue;
        }
        if (previous != -1) {
            answer = min(answer, value - previous);
        }
        previous = value;
    }

    cout << answer << '\n';
    return 0;
}
