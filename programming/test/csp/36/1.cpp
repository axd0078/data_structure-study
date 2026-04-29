#include <bits/stdc++.h>
using namespace std;
int n;
bool inGraph(int x,int y){
    return (x<=n&&x>=1) && (y<=n&&y>=1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> n >> k;
    while(k--){
        int x,y;
        cin >> x >> y;
        string ops;
        cin.ignore();
        cin >> ops;
        for(char op:ops){
            if(op=='f'){
                if(inGraph(x,y+1)){
                    y++;
                }
            }
            else if(op=='b'){
                if(inGraph(x,y-1)){
                    y--;
                }
            }
            else if(op=='l'){
                if(inGraph(x-1,y)){
                    x--;
                }
            }
            else if(op=='r'){
                if(inGraph(x+1,y)){
                    x++;
                }
            }
        }
        cout << x << " " << y << endl;
    }
}