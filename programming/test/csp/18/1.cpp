#include <bits/stdc++.h>
using namespace std;

bool shouldSkip(int value){
    if(value%7 == 0)
        return true;
    else{
        while(value > 0){
            if(value%10 == 7)
                return true;
            value /= 10;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> ans(4,0);
    int index = 0;
    while(n>0){
        index ++;
        if(shouldSkip(index)){
            ans[index%4-1] ++;
        }
        else{
            n--;
        }
    }
    for(int i=0;i<4;i++){
        cout << ans[i] << endl;
    }
    return 0;
}
