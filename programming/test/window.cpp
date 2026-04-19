#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int id;
    int x1,y1,x2,y2;
}Window;

bool contains(const Window& w,int x,int y){
    return x>=w.x1 && x<=w.x2 && y<=w.y2 && y>=w.y1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<Window> windows;

    for(int i=0;i<n;i++){
        Window w;
        w.id = i+1;
        cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
        windows.push_back(w);
    }
    for(int i = 0;i<m;i++){
        int x,y;
        cin >> x >> y;
        int pos = -1;

        for(int j = n-1;j>=0;j--){
            if(contains(windows[j],x,y)){
                pos = j;
                break;
            }
        }//找到对应窗口

        if(pos==-1)
            cout << "IGNORED" <<endl;
        else{
            cout << windows[pos].id <<endl;
            Window clicked = windows[pos];
            windows.erase(windows.begin() + pos);
            windows.push_back(clicked);
        }
    }
    return 0;
}