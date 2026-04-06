#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n < 2) {
            return n;
        }

        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = (dp[j] + 1) > dp[i] ? (dp[j] + 1) : dp[i];
                }
            }
        }

        int maxLen = dp[0];
        for (int i = 1; i < n; i++) {
            maxLen = maxLen > dp[i] ? maxLen : dp[i];
        }
        return maxLen;
    }

    int lengthOfLISBinary(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n < 2) {
            return n;
        }

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int end = 0;//dp数组下标

        for (int i = 1; i < n; i++) {
            if (nums[i] > dp[end]) {
                end++;
                dp[end] = nums[i];
            } else {
                int left = 0;
                int right = end;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (dp[mid] < nums[i]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }//与常规二分查找不同，这里要去找最右边的目标值 如果目标值就是mid，这里做right = mid + 1 就会被错过
                }
                dp[left] = nums[i]; //从右往左二分，去找第一个大于等于nums[i]的数来被nums[i]替换
            }
        }

        return end + 1;//下标变成长度
    }
};

int main() {
    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    cout << solution.lengthOfLISBinary(nums) << endl;
    return 0;
}
