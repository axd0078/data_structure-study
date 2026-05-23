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
        auto it = lower_bound(nums.begin(),nums.end(),x);
        if(it!=nums.end()){
            int pos = it - nums.begin();
            cout << pos + 1 << endl;
        }
        else cout << "-1" << endl;
    }
}