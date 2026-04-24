#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    double a;
    cin >> n >> a;
    int m = 0;
    for(int i=0;i<n;i++){
        double x,y;
        cin >> x >> y;
        if(x*x + y*y <= a*a) m++;
    }
    double pi = 1.0 * 4*m/n;
    cout << fixed << setprecision(6) << pi << endl;
    return 0;
}