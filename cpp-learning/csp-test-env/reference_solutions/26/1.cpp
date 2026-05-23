#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<double> a(n);
    double sum = 0.0;
    for (double &value : a) {
        cin >> value;
        sum += value;
    }

    double mean = sum / n;
    double variance = 0.0;
    for (double value : a) {
        double diff = value - mean;
        variance += diff * diff;
    }
    variance /= n;
    double denominator = sqrt(variance);

    cout << fixed << setprecision(12);
    for (double value : a) {
        cout << (value - mean) / denominator << '\n';
    }
    return 0;
}
