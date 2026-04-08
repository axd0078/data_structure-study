#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,5);
        dp[0] = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;pow(j,2)<=i;j++){
                if(i - pow(j,2) >= 0){
                    dp[i] = fmin(dp[i],dp[i-(int)pow(j,2)]+1);
                }
            }
        }
        return dp[n];
    }
};


int main(){
    int n;
    cin >> n ;
    Solution s;
    cout << s.numSquares(n) << endl;
    return 0;
}