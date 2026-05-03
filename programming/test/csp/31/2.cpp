#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
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
    }//采用前缀和 最大程度减少后续计算误差

    cout << fixed << setprecision(6);
    while (m--) {
        int left, right;
        double x, y;
        cin >> left >> right >> x >> y;
        double s = scale[right] / scale[left - 1];
        double theta = angle[right] - angle[left - 1];
        x *= s;
        y *= s;
        double nx = x * cos(theta) - y * sin(theta);
        double ny = x * sin(theta) + y * cos(theta);
        cout << nx << ' ' << ny << '\n';
    }
    return 0;
}
