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
    int num = 0;
    for(int x:nums){
        if(x > 0 && nums.count(-x)){
            num++;
        }
    }
    cout << num << endl;
    return 0;
}
//这题用查找的方式更好
//双指针也可以做
//set使用insert方法插入元素