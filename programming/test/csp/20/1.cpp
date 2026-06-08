#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,X,Y;
    cin >> n >> X >> Y;
    vector<pair<int,int>> ans;
    int num = 1;
    while(num<=n){
        int x,y;
        cin >> x >> y;
        int distance = pow(X-x,2) + pow(Y-y,2);
        ans.push_back({num,distance});
        sort(ans.begin(),ans.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        if(ans.size() > 3){
            ans.pop_back();
        }
        num++;
    }
    for(int i=0;i<3;i++){
        cout << ans[i].first << endl;
    }
    return 0;
}
