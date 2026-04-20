#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<bool> appeared(100001,false);
    vector<bool> praised(100001,false);

    for(int i=1;i<=n;i++){
        int a , b;
        cin >> a >> b;
        appeared[a] = true;
        if(b==1){
            praised[a] = true;
        }
    }
    int first = 0;
    for(int i=1;i<=100000;i++){
        if(appeared[i]&&!praised[i]){
            if(first == 0){
                cout << i;
                first = 1;
            }
            else{
                cout << " " << i;;
            }
        }
    }
    if(first==0){
        cout << "NONE" << endl;
    }
    return 0;
}