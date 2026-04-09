#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;

class Solution{
public:
    int minMeetingRooms(vector<vector<int>>& intervals){
        int len = intervals.size();
        if(len < 2){
            return len;
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        priority_queue<int,vector<int>,greater<int>> minHeap;
        //存的元素类型 底层用什么存放 比较规则(greater小根堆 less大根堆)
        int ans = 0;
        for(const auto& interval : intervals){
            while(!minHeap.empty() && interval[0] >= minHeap.top())
                minHeap.pop();
            //弹出已经结束的会议
            minHeap.push(interval[1]);
            //把当前会议加入
            ans = fmax(ans,minHeap.size());
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> intervals(n,vector<int>(2,0));//这里相当于初始化，不是初始化为值而是初始化为容器
    for(int i=0;i<n;i++){
        cin >> intervals[i][0] >> intervals[i][1];
    }
    Solution s;
    cout << s.minMeetingRooms(intervals) << endl;
    return 0;
}