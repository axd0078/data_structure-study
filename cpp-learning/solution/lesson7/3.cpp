#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore();
    vector<pair<string,int>> info;
    for(int i=0;i<n;i++){
        pair<string,int> x;
        cin >> x.first >> x.second;
        info.push_back(x);
    }
    sort(info.begin(),info.end(),[](const pair<string,int> &a,const pair<string,int> &b){
        if(a.second==b.second)
            return a.first < b.first;
        return a.second > b.second;
    });
    cout << info[0].first << " " << info[0].second << endl;
    return 0;
}