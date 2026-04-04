#include<iostream>
#include<vector>
#include<cstring>
#include <algorithm>
using namespace std;

class Solution{

public:
    int isSubsequence(string s,vector<string>& words){

        vector<vector<int>> index(26);
        for(int i = 0;i<s.size();i++){
            index[s[i] - 'a'].push_back(i);
        }
        // 将字符串 s 中每个字符出现的位置按字符分类保存。
        // 例如 index[c] 中存的是字符 c 在 s 中所有出现下标，且天然有序。

        int res = words.size();
        for(auto &w: words){    // 范围 for
            if(w.size() > s.size()){    // 单词比原串更长，不可能是子序列
                res--;
                continue;
            }
            int p = -1;
            for(char c: w){
                auto& ps = index[c - 'a'];
                auto it = upper_bound(ps.begin(),ps.end(),p);// 找到第一个严格大于 p 的位置
                if(it == ps.end()){
                    --res;
                    break;
                }
                p = *it;
            }

        }
        return res;
    }
};

int main(){
    string s;
    int n;
    cin >> s >> n;

    vector<string> words(n);
    for(int i=0;i<n;i++){
        cin >> words[i];
    }

    Solution sol;
    cout << sol.isSubsequence(s,words) <<endl;
    return 0;
}
