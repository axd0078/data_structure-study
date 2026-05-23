#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    stack<char> st;
    for(char& ch : s){
        if(ch=='(' || ch=='[')
            st.push(ch);
        else{
            auto c = st.top();
            if((c=='('&&ch==')') || (c=='['&&ch==']')){
                st.pop();
                continue;
            }
            else{
                cout << "no" << endl;
                break;
            }
        }
    }
    if(st.empty())
        cout << "yes" << endl;
    return 0;
}