#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    while(k--){
        int a,b,n;
        cin >> a >> b >> n;
        float p = (1.0*n - a) / b;
        p*=100;
        int ans = (int)p;
        int row = ans/10;
        int col = ans%10;
        cout << row + 1 << " " << col + 1 << endl; 
    }
    return 0;
}