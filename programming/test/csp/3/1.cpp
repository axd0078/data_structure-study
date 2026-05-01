#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> cnt(n+1,0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        cnt[x]++;
        if(i==0)
            cout << cnt[x];
        else cout << " " << cnt[x];
    }
    cout << endl;
}