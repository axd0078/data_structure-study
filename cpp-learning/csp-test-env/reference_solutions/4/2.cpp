#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> count(1001, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++count[x];
    }

    vector<pair<int, int>> items;
    for (int value = 0; value <= 1000; ++value) {
        if (count[value] > 0) {
            items.push_back({value, count[value]});
        }
    }
    sort(items.begin(), items.end(), [](const auto& lhs, const auto& rhs) {
        if (lhs.second != rhs.second) {
            return lhs.second > rhs.second;
        }
        return lhs.first < rhs.first;
    });

    for (auto [value, times] : items) {
        cout << value << ' ' << times << '\n';
    }
    return 0;
}
