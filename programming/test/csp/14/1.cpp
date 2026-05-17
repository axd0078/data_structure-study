#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> first(n),second(n);
    for(int i=0;i<n;i++) cin >> first[i];
    second[0] = (first[0] + first[1]) / 2;
    second[n-1] = (first[n-2] + first[n-1]) / 2;
    for(int i=1;i<n-1;i++){
        second[i] = first[i] + first[i+1] + first[i-1];
        second[i] /= 3;
    }
    for(int i=0;i<n;i++){
        if(i!=0) cout << " ";
        cout << second[i];
    }
    cout << '\n';
    return 0;
}
