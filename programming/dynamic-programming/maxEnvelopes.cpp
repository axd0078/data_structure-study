#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>& a,const vector<int>& b){
            if(a[0]==b[0]){
                return a[1] > b[1];
            }//第一维相等，第二维降序，保持相同宽度但是长度不同的一定不会放进去
            
            else{
                return a[0] < b[0];
            }
        });//排完以后，后面只对第二维做 LIS 就行

        int len = envelopes.size();
        vector<int> dp(len,0);
        int end = 0;
        dp[0] = 0;//这里存元素在envelops里面的index
        for(int i=1;i<len;i++){
            if(envelopes[i][1]>envelopes[dp[end]][1]){
                dp[++end] = i;
            }
            else{
                int left = 0;
                int right = end;
                while(left < right){
                    int mid = left + (right - left)/2;
                    if(envelopes[i][1]>envelopes[dp[mid]][1]){
                        left = mid + 1;
                    }
                    else{
                        right = mid;
                    }
                }//要去找从右往左第一个大于等于envelops[i]的元素
                dp[left] = i;
            }

        }
        return end + 1;
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

    vector<vector<int>> envelopes(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> envelopes[i][0] >> envelopes[i][1];
    }

    Solution solution;
    cout << solution.maxEnvelopes(envelopes) << endl;
    return 0;
}
