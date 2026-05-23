#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int money;
    cin >> money;
    int n;
    cin >> n;
    int fail = 0;
    while(n--){
        int op,change;
        cin >> op >> change;
        if(op==1){
            money += change;
        }//收入
        else if(op==0){
            if(money-change<0){
                fail++;
                continue;
            }
            money -= change;
        }
    }
    cout << money << " " << fail << endl;
    return 0;
}