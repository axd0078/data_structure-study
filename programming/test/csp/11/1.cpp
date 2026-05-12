#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int num5 = N / 50;
    N -= num5*50;
    int num3 = N / 30;
    N -= num3*30;
    int ans = num5*7+num3*4+N/10;
    cout << ans << endl;
    return 0;
}
