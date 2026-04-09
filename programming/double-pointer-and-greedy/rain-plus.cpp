#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) {
            return 0;
        }

        int right = height.size()-1;
        int left = 0;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;
        while(right>left){
            leftMax = height[left] > leftMax ? height[left] : leftMax;
            rightMax = height[right] > rightMax ? height[right] : rightMax;
            //维护左右两端的最值
            if(height[left] >= height[right]){
                water += rightMax - height[right];
                right--;
            }//说明右端一定可以蓄水
            else{
                water += leftMax - height[left];
                left++;
            }//说明左端一定可以蓄水

            //优化了蓄水的条件
        }
        return water;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution solution;
    cout << solution.trap(height) << endl;
    return 0;
}
