#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int temp = n;
    int max = INT_MIN;
    int min = INT_MAX;
    int a,b,num1,num2;
    if(n%2==1){
        a = n/2+1;
        b = 0;
    }
    else{
        a = n/2;
        b = n/2+1;
    }
    int i = 0;
    while(temp--){
        i++;
        int num;
        cin >> num;
        if(num > max){
            max = num;
        }
        if(num < min){
            min = num;
        }
        if(i==a){
            num1 = num;
        }
        if(i==b){
            num2 = num;
        }
    }
    cout << max << " ";
    int ans;
    if(n%2==1){
        cout << num1 << " ";
    }
    else{
        ans = num1+num2;
        if((num1+num2)%2!=0)
            cout << fixed << setprecision(1) << ans/2.0 << " ";
        else
            cout << ans/2 << " ";
    }
    cout << min << endl;
    return 0;
}
