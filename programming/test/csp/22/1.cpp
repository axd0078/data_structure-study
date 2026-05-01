#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,L;
    cin >> n >> m >> L;
    vector<int> cnt(L);
    for(int i=0;i<m*n;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    for(int i=0;i<L;i++){
        cout << cnt[i] << (i==L-1?"":" ");
    }
    cout << endl;
    return 0;
}
