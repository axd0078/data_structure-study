#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        int ans = nums[0];
        for(int num:nums){
            if(sum>=0){
                sum += num;
            }
            else{
                sum = num;
            }
            ans = ans>sum?ans:sum;
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
    cout << s.maxSubArray(nums) << endl;

    return 0;
}