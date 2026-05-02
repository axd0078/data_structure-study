#include <bits/stdc++.h>
using namespace std;
int a,b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n >> a >> b;
    int ans = 0;
    while(n--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int width = max(0,min(x2,a) - max(x1,0));
        int height = max(0,min(y2,b) - max(y1,0));
        ans += width * height;
    }
    cout << ans << endl;
    return 0;
}
