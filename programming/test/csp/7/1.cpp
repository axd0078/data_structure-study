#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if(n<=2){
        cout << "0" << endl;
        return 0;
    }
    int pre,now,next;
    cin >> pre >> now >> next;
    n -= 3;
    int ans = 0;
    if((pre>=now && now >=next) || (pre<=now && now<= next));
    else ans++;
    while(n--){
        int x;
        cin >> x;
        pre = now;
        now = next;
        next = x;
        if((pre>=now && now >=next) || (pre<=now && now<= next));
        else ans++;
    }
    cout << ans << endl;
    return 0;
}
