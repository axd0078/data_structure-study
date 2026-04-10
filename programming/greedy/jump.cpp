#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return true;
        }

        int maxReached = 0;  // 目前能够到达的最远下标。
        for (int i = 0; i < len - 1; i++) {
            if (i > maxReached) {
                return false;
            }
            maxReached = max(maxReached, i + nums[i]);
            if (maxReached >= len - 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution s;
    cout << s.canJump(nums) << endl;
    return 0;
}

