#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    float grade = 0;
    for(int i=0;i<n;i++){
        float change;
        cin >> change;
        grade += change;
    }
    cout << grade << endl;
}