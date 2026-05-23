#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int ans = 0;
    getline(cin,s);
    for(char ch :s){
        if(isdigit(ch))
            ans++;
    }
    cout << ans << endl;
    return 0;
}