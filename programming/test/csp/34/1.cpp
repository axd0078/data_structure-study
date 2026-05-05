#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,p,q;
    cin >> n >> m >> p >> q;
    vector<int> a(m*n);
    for(int i=0;i<n*m;i++){
        cin >> a[i];
    }
    int index = 0;
    for(int i=0;i<p;i++){
        for(int j=0;j<q-1;j++){
            cout << a[index++] << " ";
        }
        cout << a[index++] << endl;
    }
    return 0;
}
