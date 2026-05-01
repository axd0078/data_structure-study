#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> B(n);
    for(int i=0;i<n;i++){
        cin >> B[i];
    }
    int min = B[0],max = B[0];
    for(int i = 1;i<n;i++){
        max += B[i];
        if(B[i] > B[i-1])
            min += B[i];
    }
    cout << max << endl;
    cout << min << endl;
    return 0;
}
