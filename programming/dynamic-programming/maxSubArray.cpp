#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = static_cast<int>(nums.size());
        if (len == 0) {
            return 0;
        }

        int pre = nums[0];
        int res = pre;
        for (int i = 1; i < len; i++) {
            pre = max(nums[i], pre + nums[i]);
            res = max(res, pre);
        }
        return res;
        //这里只需要关联到底加不加前一个状态，所以不需要dp数组
    }
};

int main() {
    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    cout << solution.maxSubArray(nums) << endl;
    return 0;
}
