#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            return a[1] < b[1];
        });
        int end = intervals[0][1];
        int maxLen = 1;
        for(int i = 1;i<len;i++){
            if(end <= intervals[i][0]){ //出现了有一个区间不重叠
                maxLen ++;
                end = intervals[i][1];
            }
        }
        return len - maxLen;
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

    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    Solution solution;
    cout << solution.eraseOverlapIntervals(intervals) << endl;
    return 0;
}