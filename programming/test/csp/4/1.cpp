#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> matrix[i][j];
        }
    }
    for(int i=m-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(j!=0) cout << " ";
            cout << matrix[j][i];
        }
        cout << '\n';
    }
    return 0;
}
