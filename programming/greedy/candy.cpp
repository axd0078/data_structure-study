#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 1;
        int len = ratings.size();
        int pre = 1;//给上一个多少糖
        int inc = 1,dec = 0;    //最近的递增序列长度和递减长度
        for(int i = 1;i<len;i++){
            if(ratings[i]>=ratings[i-1]){
                dec = 0;
                pre = ratings[i] == ratings[i-1] ? 1 : pre + 1;
                //如果出现相等，直接给一颗糖
                ans += pre;
                //inc = ratings[i] == ratings[i-1] ? 1 : inc + 1;
                //inc + 1 可能是在旧峰顶基础上继续加，直接把旧状态带进来了。所以在这里inc + 1不可取
                inc = pre;
                //严格递增序列的长度
            }
            else{
                dec++;
                if(dec == inc){
                    dec ++;
                }//如果出现了递增跟递减一样长，说明峰值需要+1
                ans += dec;
                pre = 1;
            }
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> ratings(n);
    for(int i=0;i<n;i++){
        cin >> ratings[i];
    }
    Solution s;
    cout << s.candy(ratings) << endl;
    return 0;
}