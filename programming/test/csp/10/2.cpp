#include <bits/stdc++.h>
using namespace std;
int findIndex(vector<int>& pos,int stu){
    int ans = 0;
    for(int i=0;i<pos.size();i++){
        if(pos[i]==stu){
            ans = i;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> pos(n);
    for(int i=0;i<n;i++){
        pos[i] = i+1;
    }
    int times;
    cin >> times;
    while(times--){
        int stu,op;
        cin >> stu >> op;
        int index = findIndex(pos,stu);
        pos.erase(pos.begin() + index);
        pos.insert(pos.begin() + index + op, stu);
    }
    for(int i=0;i<n;i++){
        if(i==n-1) cout << pos[i] << endl;
        else cout << pos[i] << " ";
    }
    return 0;
}
