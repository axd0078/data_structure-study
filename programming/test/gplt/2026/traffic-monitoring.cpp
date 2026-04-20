#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> traffic;
    int max = 0,min = INT_MAX,sum = 0;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        traffic.push_back(x);
        if(max < x) max = x;
        if(min > x) min = x;
        sum += x;
    }
    int ave = sum / n;
    cout << max << " " <<  min  << " " << ave << endl;
    int first = 0;
    for(int i=0;i<n;i++){
        if(traffic[i] > ave*2){
            if(first == 0){
                first = 1;
                cout << i + 1;
            }
            else
                cout << " " << i+1;
        }
    }
    if(first==0) cout << "Normal";
    cout << endl;
    return 0;
}