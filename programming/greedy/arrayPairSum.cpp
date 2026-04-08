#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](const int a,const int b){
            return a < b;
        });
        int len = nums.size();
        int ans = 0;
        for(int i = 1;i<len;i+=2){
            ans += min(nums[i],nums[i-1]);
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    Solution s;
    cout << s.arrayPairSum(nums) << endl;
    return 0;
}
