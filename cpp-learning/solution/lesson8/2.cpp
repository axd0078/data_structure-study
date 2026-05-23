#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    vector<long long> prefix(n + 1, 0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << endl;
    }
}
