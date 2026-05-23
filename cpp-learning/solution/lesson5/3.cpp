#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    priority_queue<int,vector<int>,greater<int>> pq;
    cin >> n;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        pq.push(num);
    }
    for(int i=0;i<n;i++){
        int num = pq.top();
        if(i==0)
            cout << num;
        else 
            cout << " " << num;
        pq.pop();
    }
    cout << endl;
    return 0;
}