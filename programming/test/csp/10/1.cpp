#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    int ans = 0;
    int temp = 0;
    for(int i=0;i<n;){
        ans++;
        while(temp < k && i < n){
            int cake;
            cin >> cake;
            temp += cake;
            i++;
        }
        temp = 0;
    }
    cout << ans << '\n';
    return 0;
}
