#include <bits/stdc++.h>
using namespace std;

double after_tax(int salary){
    int taxable = max(0,salary - 3500);
    double tax = 0;
    if (taxable <= 1500) tax = taxable * 0.03;
    else if (taxable <= 4500) tax = taxable * 0.10 - 105;
    else if (taxable <= 9000) tax = taxable * 0.20 - 555;
    else if (taxable <= 35000) tax = taxable * 0.25 - 1005;
    else if (taxable <= 55000) tax = taxable * 0.30 - 2755;
    else if (taxable <= 80000) tax = taxable * 0.35 - 5505;
    else tax = taxable * 0.45 - 13505;
    return tax;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int l = 1,r = 1000000;
    int mid;
    while(l<r){
        mid = (l+r)/2;
        int gain = mid - after_tax(mid);
        if(gain + 1e-9 > n)
            r = mid;
        else if(gain < n)
            l = mid + 1; 
    }
    cout << l << endl;
    return 0;
}
