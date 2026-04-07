#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            return a[0] < b[0];
        });
        int len = intervals.size(); 
        vector<int> dp(len,1);
        for(int i=1;i<len;i++){
            for(int j = 0;j<i;j++){
                if(intervals[j][1] <= intervals[i][0]){
                    dp[i] = max(dp[i],dp[j] + 1);
                }// 如果 intervals[j][1] <= intervals[i][0]，说明 j 区间可以接在 i 前面，不重叠
                // 这样就可以尝试用 dp[j] + 1 来更新 dp[i]
            }
        }
        return len - *max_element(dp.begin(),dp.end());
    }// 这里时间复杂度是 O(n^2)，不够好
    */
    // 优化一下
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int len = intervals.size(); 
        vector<int> dp(len+1,0);
        // dp[i] 表示前 i 个区间里，最多能选多少个互不重叠区间
        // 这里是按前缀长度定义的，所以长度要开 len + 1
        vector<int> ends(len);
        for (int i = 0; i < len; i++) {
            ends[i] = intervals[i][1];
        }
        for(int i=1;i<=len;i++){
            int start = intervals[i-1][0];
            
            // 在区间 [0, i-2] 里，找第一个满足 end > start 的位置
            int j = upper_bound(ends.begin(),ends.begin() + (i - 1),start) - ends.begin();
            // 比较对象是 ends 数组
            // j 也表示前面有多少个区间满足 end <= start
            // 但在这 j 个区间里，最多只能选 dp[j] 个互不重叠区间
            // upper_bound(...) 返回的是迭代器，减去 begin() 后才变成下标
            dp[i] = max(dp[i-1],dp[j] + 1);
            
        }
        return len - dp[len];
    }
    

};// 题目要求等价于：选出最多数量的不重叠区间，然后用总数减掉它

int main() {
    int n;
    if (!(cin >> n) || n < 0) {
        return 0;
    }

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    Solution solution;
    cout << solution.eraseOverlapIntervals(intervals) << endl;
    return 0;
}