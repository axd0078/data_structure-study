#include <bits/stdc++.h>
using namespace std;
struct mission{
    int c,t;
};
vector<mission> missions;
double getNeed(int day){
    auto it = upper_bound(missions.begin(),missions.end(),day,
                [](int value,const mission &a){
                    return value < a.t;
                });//二分查找的自定义
    double ans = 0;
    while(it!=missions.end()){
        ans += 1LL * (*it).c * ((*it).t - day);
        it++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    double m;
    cin >> n >> m >> k;
    missions.assign(n+1, mission{0, 0});
    int high = 0;
    for(int i=1;i<=n;i++){
        cin >> missions[i].t >> missions[i].c;
        if(missions[i].t>high){
            high = missions[i].t;
        }
    }
    sort(missions.begin(),missions.end(),[](const mission &a,const mission &b){
        return a.t < b.t;
    });
    int low = k;
    int ans;
    while(low<=high){
        int mid = low + (high - low)/2;
        double pay = getNeed(mid);
        if(pay>m){
            low = mid + 1;
        }
        else if(pay<m){
            ans = mid;
            high = mid-1;
        }
        else{
            ans = mid;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
//注意某些数据会溢出的地方