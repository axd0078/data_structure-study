#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    sort(nums.begin(),nums.end());
    int ans = 0;
    for(int i=0;i<n-1;i++){
        if(nums[i] + 1==nums[i+1])
            ans++;
    }
    cout << ans << endl;
    return 0;
}
