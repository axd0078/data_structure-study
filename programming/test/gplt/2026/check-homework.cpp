#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,T;
    cin >> n >> T;
    vector<int> h(n+1);
    for(int i=1;i<=n;i++){
        cin >> h[i];
    }
    vector<int> current;
    vector<int> left;
    vector<int> right;

    for(int i=n;i>=1;i--){
        current.push_back(i);
    }

    long long leftSum = 0;

    while(!current.empty() || !left.empty()){
        if(current.empty()){
            T = leftSum / left.size();
            current = left; //把左边的复制到当前
            left.clear();   //清空left里面的内容
            leftSum = 0;
        }
        int id = current.back();
        current.pop_back();
        if(h[id] > T){
            left.push_back(id);
            leftSum += h[id];
        }
        else{
            right.push_back(id);
        }
    }
    for(int i=0;i<right.size();i++){
        if(i>0) cout << " " << right[i];
        else cout << right[i];
    }
    cout << endl;
    return 0;
}