#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x;
    long long y;
    char type;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Point> points(n);
    for (auto &point : points) {
        cin >> point.x >> point.y >> point.type;
    }

    while (m--) {
        long long theta0, theta1, theta2;
        cin >> theta0 >> theta1 >> theta2;

        int signA = 0;
        int signB = 0;
        bool ok = true;
        for (const auto &point : points) {
            long long value = theta0 + theta1 * point.x + theta2 * point.y;
            int sign = value > 0 ? 1 : -1;
            int &stored = point.type == 'A' ? signA : signB;
            if (stored == 0) {
                stored = sign;
            } else if (stored != sign) {
                ok = false;
                break;
            }
        }

        cout << (ok && signA != signB ? "Yes" : "No") << '\n';
    }

    return 0;
}
