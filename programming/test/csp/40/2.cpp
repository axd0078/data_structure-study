#include <bits/stdc++.h>
using namespace std;

int f(int x,int k){
    return ((x*x+k*k)&7) ^ k;
}

int g(int x,int k){
    int b = x >> 6;
    int q = (x >> 3) & 7;
    int r = x & 7;

    int c = q ^ f(b,k);
    int a = r ^ f(c,k);

    return (a << 6) | (b << 3) | c; 

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<int> k;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        k.push_back(x);
    }
    vector<int> ans(512,0);
    for(int i=0;i<512;i++){
        ans[i] = i;
        for(int j=m-1;j>=0;j--){
            ans[i] = g(ans[i],k[j]);
        }
    }
    int first = 1;
    while(n--){
        int num;
        cin >> num;
        num = ans[num];
        if(first==1){
            cout << num;
            first = 0;
        }
        else
            cout << " " << num;
    }
    cout << '\n';
    return 0;
}