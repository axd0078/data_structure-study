#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<n;i++){
        int op;
        cin >> op;
        if(op==1){
            string s1;
            cin >> s1;
            vector<int> ans;
            int start = 0;
            while((int)ans.size() < 3){
                size_t pos = s.find(s1,start);
                if(pos == string::npos){
                    break;
                }
                ans.push_back((int)pos);
                start = (int)pos + 1;
            }
            if(ans.empty()){
                cout << "-1";
            }
            else{
                for(int j=0;j<(int)ans.size();j++){
                    if(j==0) cout << ans[j];
                    else cout << " " << ans[j];
                }
            }
            cout << endl;
        }
        else if(op==2){
            int p;
            cin >> p;
            string s2;
            cin >> s2;
            s.insert(p,s2);
            cout << s <<endl;
        }
        else if(op==3){
            int l,r;
            cin >> l >> r;
            reverse(s.begin() + l,s.begin() + r + 1);
            cout << s << endl;
        }
    }

    /*find 用 pos + 1 防重叠遗漏；
    insert 直接用 string.insert；
    reverse 注意右端点 + 1。
    */
}