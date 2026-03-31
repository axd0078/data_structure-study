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
        }//灏嗗瓧绗︿覆 s 涓殑鍏ㄩ儴鐨勫瓧绗︾殑浣嶇疆鎸夌収瀵瑰簲鐨勫瓧绗﹁繘琛屽瓨鍌?
        //浠ゅ叾涓烘暟缁?index 鍏朵腑 index[c] 瀛樺偍鐨勬槸瀛楃涓?s 涓瓧绗︿负 c 鐨勪粠灏忓埌澶ф帓鍒楃殑浣嶇疆銆?

        int res = words.size();
        for(auto &w: words){    //鑼冨洿 based for
            if(w.size() > s.size()){    //鍗曡瘝姣斿簭鍒楅暱锛屼竴瀹氫笉鏄瓙搴忓垪
                res--;
                continue;
            }
            int p = -1;
            for(char c: w){
                auto& ps = index[c - 'a'];
                auto it = upper_bound(ps.begin(),ps.end(),p);//鎵惧埌绗竴涓弗鏍煎ぇ浜?p 鐨勪綅缃?
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
