#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,t;
    cin >> n >> m >> t;
    vector<int> matrix(m*n);
    for(int i=0;i<n*m;i++){
        cin >> matrix[i];
    }
    while(t--){
        int op,a,b;
        cin >> op >> a >> b;
        if(op==1){
            n = a;
            m = b;
        }
        if(op==2){
            vector<int> temp(m*n);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    temp[j * n + i] = matrix[i * m + j];
                }
            }
            matrix.swap(temp);
            swap(n,m);
        }
        if(op==3){
            cout << matrix[a*m+b] << endl;
        }
    }
    return 0;
}
