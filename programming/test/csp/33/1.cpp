#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<int> cnt(m+1);
    unordered_map<int, unordered_set<int>> belong;
    for(int i=1;i<=n;i++){
        int len;
        cin >> len;
        for(int j=0;j<len;j++){
            int s;
            cin >> s;
            belong[s].insert(i);
            cnt[s]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout << belong[i].size() << " " << cnt[i] << endl;
    }
    return 0;
}