#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    queue<int> q;
    cin >> n;
    for(int i=0;i<n;i++){
        string op;
        int num;
        cin >> op;
        if(op=="IN"){
            cin >> num;
            q.push(num);
        }
        else if(op=="OUT"){
            if(!q.empty()){
                cout << q.front() << endl;
                q.pop();
            }
            else{
                cout << "empty" << endl;
            }
        }
    }
    return 0;
}