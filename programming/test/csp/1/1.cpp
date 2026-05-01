#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_set<int> nums;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        nums.insert(x);
    }
    int ans = 0;
    for(int num:nums){
        if(num>0 && nums.count(-num))
            ans ++;
    }
    cout << ans << endl;
    return 0;
}
//这题用查找的方式更好
//双指针也可以做
//set使用insert方法插入元素