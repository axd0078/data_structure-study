#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i=0;i<n;i++){
        int a;
        int num_0 = 0,num_1 = 0;
        cin >> a;
        while(a>0){
            if(a%2==0){
                num_0++;
            }
            else{
                num_1++;
            }
            a/=2;
        }
        if(num_0==num_1) ans++;
    }
    cout << ans << endl;
    return 0;
}