#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n;
    cin >> m >> n;
    vector<int> nums;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }
    while(n--){
        int x;
        cin >> x;
        auto begin = lower_bound(nums.begin(),nums.end(),x);
        auto end = upper_bound(nums.begin(),nums.end(),x);
        if(begin==end) cout << "0" << endl;
        else cout << end - begin << endl;
    }
}