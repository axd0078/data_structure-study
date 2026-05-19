#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r,y,g;
    cin >> r >> y >> g;
    int n;
    cin >> n;
    int time = 0;
    while(n--){
        int k , t;
        cin >> k >> t;
        if(k==0){
            time += t;
        }
        else if(k==1){
            time += t;
        }
        else if(k==2){
            time += (t + r);
        }
        else if(k==3){
            continue;
        }
    }
    cout << time << endl;
    return 0;
}
