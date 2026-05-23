#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0 ; i < n ; i ++ ){
        int num;
        cin >> num;
        s.insert(num);
    }
    int first = 0;
    for(int x : s){
        if(first==0){
            cout << x;
            first = 1;
        }
        else
            cout << " " << x;
    }
    cout << endl;
}