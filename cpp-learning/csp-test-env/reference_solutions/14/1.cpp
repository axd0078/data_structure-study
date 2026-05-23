#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int prev, cur;
    cin >> prev >> cur;

    bool printed = false;
    auto printValue = [&](int value) {
        if (printed) {
            cout << ' ';
        }
        cout << value;
        printed = true;
    };

    printValue((prev + cur) / 2);
    for (int i = 3; i <= n; ++i) {
        int next;
        cin >> next;
        printValue((prev + cur + next) / 3);
        prev = cur;
        cur = next;
    }
    printValue((prev + cur) / 2);
    cout << '\n';
    return 0;
}
