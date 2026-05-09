#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int pre,now;
    cin >> pre >> now;
    int max = abs(now-pre);
    n -= 2;
    while(n--){
        pre = now;
        cin >> now;
        if(abs(now-pre) > max)
            max = abs(now-pre);
    }
    cout << max << endl;
    return 0;
}//波动一定是正数
