#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> cnt(1001,0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    int less = 0;
    for(int i=1;i<=1000;i++){
        if(cnt[i]==0) continue;
        int greater = n - less - cnt[i];
        if(less == greater){
            cout << i << endl;
            return 0;
        }
        less += cnt[i];
    }
    cout << -1 << endl;
    return 0;
}
