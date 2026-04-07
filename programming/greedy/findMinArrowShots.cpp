#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const vector<int>& a,const vector<int>& b){
            return a[1] < b[1];
        });//鎸夌収鍙宠竟鐣屾帓搴忥紝濡傛灉绠殑浣嶇疆瓒呰繃浜嗗彸杈圭晫锛岄偅涔堜竴瀹氬皠涓嶅埌浜?

        int pos = points[0][1];
        int ans = 1;

        for(const vector<int>& balloon:points){
            if(balloon[0]>pos){//鍒ゅ畾鏉′欢:宸﹁竟鐣岃秴杩噋os
                pos = balloon[1];
                ans++;
            }
        }
        return ans;
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

    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    Solution solution;
    cout << solution.findMinArrowShots(points) << endl;
    return 0;
}
