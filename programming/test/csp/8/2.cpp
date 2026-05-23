#include <bits/stdc++.h>
using namespace std;

int fullSeat(vector<bool> &seat){
    int res = 0;
    for(int i=0;i<5;i++){
        if(seat[i]) res++;
    }
    return res;    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<bool>> seat(20,vector<bool>(5,false));
    while(n--){
        int need;
        cin >> need;
        int ok = false;
        for(int i=0;i<=19;i++){
            int full = fullSeat(seat[i]);
            if(5-full >= need){
                int begin = full+1;
                while(need--){
                    seat[i][begin-1] = true;
                    if(need==0) cout << i*5 + begin << endl;
                    else cout << i*5 + begin << " ";
                    begin++;
                }
                ok = true;
                break;
            }
        }
        if(ok) continue;
        else{
            for(int i=0;i<=19 && need>0;i++){
                int full = fullSeat(seat[i]);
                for(int begin=full;begin<5 && need>0;begin++){
                    seat[i][begin] = true;
                    need--;
                    if(need==0) cout << i*5 + begin+1 << endl;
                    else cout << i*5 + begin+1 << " ";
                }
            }
        }
    }
    return 0;
}
