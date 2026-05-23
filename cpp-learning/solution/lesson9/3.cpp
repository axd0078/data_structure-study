#include <bits/stdc++.h>
using namespace std;

int getTime(vector<int> &a,int v){
    int time = 0;
    for(int i=0;i<a.size();i++){
        time += (a[i] + v - 1) / v;
    }
    return time;
}

int minV(vector<int>& a,int h){
    int len = 0;
    for(int i = 0; i < a.size(); i++){
        len = max(len,a[i]);
    }
    vector<int> time(len,0);
    for(int i=0;i<len;i++){
        time[i] = getTime(a,i+1);
    }
    auto it = upper_bound(time.begin(),time.end(),h,greater<int>());
    //找第一个小于等于 h
    return it-time.begin() + 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,h;
    cin >> n >> h;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << minV(a,h) << endl;

}
