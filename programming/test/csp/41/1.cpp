#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int ans = 0;
    while(n--){
        int x;
        cin >> x;
        int num0 = 0,num1 = 0;
        while(x>0){
            int num = x%2;
            if(num==0) num0++;
            else num1++;
            x/=2;
        }
        if(num0==num1) ans++;
    }
    cout << ans << endl;
    return 0;
}
