#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) {
            return 0;
        }

        int i = 0;
        int j = static_cast<int>(height.size()) - 1;
        int maxWater = 0;

        while (i < j) {
            int water = (height[j] < height[i] ? height[j] : height[i]) * (j - i);
            if (water > maxWater) {
                maxWater = water;
            }

            if (height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxWater;
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
    cout << solution.maxArea(height) << endl;
    return 0;
}
