#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    int max_value = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        max_value = max(max_value, a[i]);
    }

    vector<vector<int>> pos(max_value + 1);
    for (int i = 1; i <= n; ++i) {
        if (a[i] > 0) {
            pos[a[i]].push_back(i);
        }
    }

    vector<int> active(n + 2, 0);
    int segments = 0;
    int answer = 0;
    for (int value = max_value; value >= 1; --value) {
        for (int idx : pos[value]) {
            bool left = active[idx - 1];
            bool right = active[idx + 1];
            if (!left && !right) {
                ++segments;
            } else if (left && right) {
                --segments;
            }
            active[idx] = 1;
        }
        answer = max(answer, segments);
    }

    cout << answer << '\n';
    return 0;
}
