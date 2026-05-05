#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<string,int> map;
    while(n--){
        string state;
        string row;
        for(int i=0;i<8;i++){
            cin >> row;
            state += row;
        }
        cout << ++map[state] << '\n';
    }
    return 0;
}
