#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long targetX, targetY;
    cin >> n >> targetX >> targetY;

    vector<pair<long long, int>> best;
    for (int i = 1; i <= n; ++i) {
        long long x, y;
        cin >> x >> y;
        long long dx = x - targetX;
        long long dy = y - targetY;
        best.push_back({dx * dx + dy * dy, i});
        sort(best.begin(), best.end());
        if (best.size() > 3) {
            best.pop_back();
        }
    }

    for (const auto &[distance, index] : best) {
        (void)distance;
        cout << index << '\n';
    }

    return 0;
}
