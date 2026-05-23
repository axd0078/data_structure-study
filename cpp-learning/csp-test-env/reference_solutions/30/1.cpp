#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    unordered_map<string, int> count;
    for (int step = 0; step < n; ++step) {
        string state;
        state.reserve(64);
        string row;
        for (int i = 0; i < 8; ++i) {
            cin >> row;
            state += row;
        }
        cout << ++count[state] << '\n';
    }
    return 0;
}
