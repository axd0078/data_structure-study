#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    vector<pair<int, int>> a(m);
    int correct = 0;
    for (auto& [y, result] : a) {
        cin >> y >> result;
        correct += result;
    }

    sort(a.begin(), a.end());

    int best = -1;
    int answer = a[0].first;
    for (int i = 0; i < m;) {
        int y = a[i].first;
        if (correct >= best) {
            best = correct;
            answer = y;
        }

        int zeros = 0;
        int ones = 0;
        while (i < m && a[i].first == y) {
            if (a[i].second == 0) ++zeros;
            else ++ones;
            ++i;
        }
        correct += zeros - ones;
    }

    cout << answer << '\n';
    return 0;
}
