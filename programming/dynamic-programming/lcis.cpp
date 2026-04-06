#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        int pre = 1;
        int res = pre;
        for(int i=1;i<len;i++){
            if(nums[i]>nums[i-1]){
                pre = pre + 1;
                res = max(pre,res);
            }
            else{
                pre = 1;
                res = max(pre,res);
            }
        }
        return res;
    }
};

int main() {
    int n;
    if (!(cin >> n) || n < 0) {
        return 0;
    }

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    cout << solution.findLengthOfLCIS(nums) << endl;
    return 0;
}
