#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    const string alphabet = 
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 ";
    map<char,int> id;
    for(int i=0;i<(int)alphabet.size();i++){
        id[alphabet[i]] = i;
    }
    string line;
    getline(cin,line);
    string source = line.substr(1,line.length()-2);
    int n;
    cin >> n;
    getline(cin,line);
    vector<vector<int>> up(32,vector<int>(alphabet.size()));
    iota(up[0].begin(),up[0].end(),0);
    //作用是从起始值开始连续递增填充
    for(int i=0;i<n;i++){
        getline(cin,line);
        up[0][id[line[1]]] = id[line[2]];
    }//up[0][i]表示i经过2^0=1次变化后变成什么
    for(int bit = 1;bit < 32 ;bit++){
        for(int i=0;i<(int)alphabet.size();i++){
            up[bit][i] = up[bit-1][up[bit-1][i]];
        }//递推公式
    }
    int q;
    cin >> q;
    while(q--){
        long long k;
        cin >> k;
        string answer;
        for(char ch:source){
            int cur = id[ch];
            long long value = k;
            for(int bit=0;value;bit++,value >>= 1){
                if(value & 1LL){
                    cur = up[bit][cur];
                }//最后一位是1 就说明要跳
            }
            answer.push_back(alphabet[cur]);
        }
        cout << "#" << answer << "#\n";
    }
    return 0;
}
