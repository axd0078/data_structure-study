#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int len = prices.size();
        for(int i = 0;i < len - 1;i++){
            if(prices[i+1]>prices[i])
                res += prices[i+1] - prices[i];
        }
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i=0;i<n;i++){
        cin >> prices[i];
    }
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}