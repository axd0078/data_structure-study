#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        int current = 0;  // 当前步数能够覆盖到的最远边界。
        int next = 0;     // 再多跳一步时能够到达的最远位置。
        int ans = 0;

        for (int i = 0; i < len - 1; i++) {
            next = max(next, i + nums[i]);
            if (i == current) {
                current = next;
                ans++;
            }
        }
        return ans;
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
    cout << s.jump(nums) << endl;
    return 0;
}

