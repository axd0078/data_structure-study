#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(),nums.end());
    int ans = nums[1] - nums[0];
    if(ans==0){
        cout << ans << '\n';
        return 0;
    }
        for(int i=2;i<n;i++){
        int temp = nums[i] - nums[i-1];
        if(temp == 0){
            cout << temp << '\n';
            return 0;
        }
        if(temp<ans) ans = temp;
    }
    cout << ans << '\n';
    return 0;
}
