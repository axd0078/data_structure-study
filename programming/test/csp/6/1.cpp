#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string num;
    cin >> num;
    int ans = 0;
    for(char &ch:num){
        ans += ch - '0';
    }
    cout << ans << endl;
    return 0;
}
