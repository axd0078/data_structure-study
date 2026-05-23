#include <bits/stdc++.h>
using namespace std;
struct interval{
    int left;
    int right;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<interval> intervals;
    for(int i=0;i<n;i++){
        interval e;
        cin >> e.left >> e.right;
        intervals.push_back(e);
    }
    sort(intervals.begin(),intervals.end(),[](const interval &a,const interval &b){
        if(a.left==b.left)
            return a.right < b.right;
        else
            return a.left < b.left;
    });
    for(int i=0;i<n;i++){
        cout << intervals[i].left << " " << intervals[i].right << endl;
    }
    return 0;
}