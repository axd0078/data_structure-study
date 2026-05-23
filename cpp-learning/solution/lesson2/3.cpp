#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin,s);
    for(char& ch:s){    //这里的参数应该是引用才可以
        if(isalpha(ch)){
            ch = tolower(ch);
        }
    }
    cout << s << endl;
}