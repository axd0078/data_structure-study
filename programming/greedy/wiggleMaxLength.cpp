#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        int prev = 0;
        int curr;
        int ans = 1;
        
        for(int i = 1;i<len;i++){
            curr = nums[i] - nums[i-1];
            //if(curr*prev <= 0){ 差值curr为0时这里会出现判断错误
            if((curr>0 && prev<=0) || (curr<0 && prev>=0)){
                ans ++;
                prev = curr;
            }
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
    cout << s.wiggleMaxLength(nums) << endl;

    return 0;
}