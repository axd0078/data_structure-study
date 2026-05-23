#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int index = 0;
    for(int i=1;i<n;i++){
        if(a[index] < a[i])
            index = i;
    }
    cout << a[index] << " " << index+1 << endl;
}