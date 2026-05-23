#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore();
    string s;
    map<string,int> cnt;
    for(int i = 0;i < n;i++){
        getline(cin,s);
        cnt[s]++;
    }

    for(auto& x:cnt){
        cout << x.first << " " << x.second << endl;
    }
}