#include <bits/stdc++.h>
using namespace std;

int judge(string &s){
    unordered_map<char,int> map;
    bool d = false;//同一字符
    bool a = false,b = false,c = false;//字母 数字 特殊
    for(char ch :s){
        if(isdigit(ch)){
            b = true;
        }
        else if(isalpha(ch)){
            a = true;
        }
        else
            c = true;
        if(map[ch]==2){
            d = true;
        }
        map[ch]++;
    }
    if(d && a && b && c) return 1;
    if(!d && a && b && c) return 2;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string s;
        cin >> s;
        cout << judge(s) << endl;
    }
    return 0;
}
