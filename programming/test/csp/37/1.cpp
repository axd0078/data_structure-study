#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long b,c,l,r;
    cin >> b >> c >> l >> r;
    long long sum = 0;

    int start = (l%2==0 ? l:l+1);

    for(int x=start;x<=r;x+=2){
        sum += 1LL*x*x +  1LL*b*x + c;
    }
    sum *= 2;
    cout << sum << endl;
    return 0;
}