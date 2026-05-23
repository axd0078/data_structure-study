#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(),nums.end(),[](const int &a,const int &b){
        return a > b;
    });
    for(int i=0;i<n;i++){
        if(i==0) cout << nums[i];
        else cout << " " << nums[i];
    }   
    cout << endl;
}