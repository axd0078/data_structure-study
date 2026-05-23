#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<double> scale(n + 1, 1.0), angle(n + 1, 0.0);

    for (int i = 1; i <= n; ++i) {
        int type;
        double value;
        cin >> type >> value;
        scale[i] = scale[i - 1];
        angle[i] = angle[i - 1];
        if (type == 1) {
            scale[i] *= value;
        } else {
            angle[i] += value;
        }
    }

    cout << fixed << setprecision(10);
    while (m--) {
        int l, r;
        double x, y;
        cin >> l >> r >> x >> y;
        double s = scale[r] / scale[l - 1];
        double theta = angle[r] - angle[l - 1];
        double nx = s * (x * cos(theta) - y * sin(theta));
        double ny = s * (x * sin(theta) + y * cos(theta));
        cout << nx << ' ' << ny << '\n';
    }

    return 0;
}
