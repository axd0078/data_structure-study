#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1), k(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    int steps = 0;
    int curRight = 1;//用 steps 次跳跃，最远可以跳到哪里
    int scanLeft = 1;//这一轮还没扫描的第一个位置

    while (curRight < n) {
        int nextRight = curRight;
        for(int i=scanLeft;i<=curRight;i++){
            int p = i - a[i];
            int to = min(n,p+k[p]);
            nextRight = max(nextRight,to);
        }
        if(nextRight==curRight){
            cout << "-1" << '\n';
            return 0;
        }
        steps++;
        scanLeft = curRight + 1;
        curRight = nextRight;
    }

    cout << steps << '\n';

    return 0;
}

