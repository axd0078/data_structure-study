#include <bits/stdc++.h>
using namespace std;

double after_tax(int salary) {
    int taxable = max(0, salary - 3500);
    double tax = 0;
    if (taxable <= 1500) tax = taxable * 0.03;
    else if (taxable <= 4500) tax = taxable * 0.10 - 105;
    else if (taxable <= 9000) tax = taxable * 0.20 - 555;
    else if (taxable <= 35000) tax = taxable * 0.25 - 1005;
    else if (taxable <= 55000) tax = taxable * 0.30 - 2755;
    else if (taxable <= 80000) tax = taxable * 0.35 - 5505;
    else tax = taxable * 0.45 - 13505;
    return salary - tax;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s;
    cin >> s;

    int left = 0, right = 1000000;
    while (left < right) {
        int mid = (left + right) / 2;
        if (after_tax(mid) + 1e-9 < s) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    cout << left << '\n';

    return 0;
}
