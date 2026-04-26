#include <bits/stdc++.h>
using namespace std;

int Z;
vector<string> g;
int rot = 0;

struct Op{
    int op,a,b,c,d,e;
};

pair<int,int> pos(int x,int y){
    if(rot==0)  return {x,y};
    if(rot==1)  return {Z-y-1,x};
    if(rot==2)  return {Z-x-1,Z-y-1};
    return {y,Z-x-1};
}//坐标映射模拟旋转

char getCell(int x,int y){
    pair<int,int> p = pos(x,y);
    return g[p.first][p.second];
}
void setCell(int x,int y,char ch){
    pair<int,int> p = pos(x,y);
    g[p.first][p.second] = ch;
}

void rotateSquare(int u,int v,int L,int times){
    u--;
    v--;
    vector<string> temp(L,string(L,'?'));
    for(int i=0;i<L;i++){
        for(int j=0;j<L;j++)
            temp[i][j] = getCell(i+u,j+v);
    }
    while(times--){
        vector<string> a(L,string(L,'?'));
        for(int i=0;i<L;i++){
            for(int j=0;j<L;j++)
                a[j][L-1-i] = temp[i][j];   //顺时针旋转90
        
        }
        temp = a;
    }
    for(int i=0;i<L;i++){
        for(int j=0;j<L;j++)
            setCell(i+u,j+v,temp[i][j]);
    }
}

void flipRect(int u,int d,int l,int r,int o){
    u--,d--,l--,r--;
    int h = d-u+1;
    int w = r-l+1;
    vector<string> temp(h, string(w, '?'));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            temp[i][j] = getCell(i+u,j+l);
        }
    }
    if(o==1){
        reverse(temp.begin(),temp.end());
    }
    else if(o==-1){
        for(int i=0;i<h;i++){
            reverse(temp[i].begin(),temp[i].end());
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            setCell(i+u,j+l,temp[i][j]);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Z;
    g.resize(Z);
    for (int i = 0; i < Z; i++) {
        cin >> g[i];
    }
    int K_size;
    cin >> K_size;
    vector<int> K(K_size);
    for(int i=0;i<K_size;i++){
        cin >> K[i];
    }
    int t = K[0];
    vector<Op> ops;
    int idx = 1;
    for (int i = 0; i < t; i++) {
        Op cur;
        cur.op = K[idx++];
        cur.a = K[idx++];
        cur.b = K[idx++];
        cur.c = K[idx++];
        cur.d = K[idx++];
        cur.e = K[idx++];
        ops.push_back(cur);
    }
    for(int i=t-1;i>=0;i--){
        Op cur = ops[i];
        if(cur.op == 1){
            int u = cur.a;
            int v = cur.b;
            int L = cur.c;
            int d = cur.d;
            int r = cur.e;
            rot = (rot + r) % 4;
            int times = (4-d/90) % 4;
            rotateSquare(u,v,L,times);
        }
        else{
            int u = cur.a;
            int d = cur.b;
            int l = cur.c;
            int r = cur.d;
            int o = cur.e;
            flipRect(u, d, l, r, o);
        }
    }
    int n = 0,m = 0;
    for (int i = 0; i < Z; i++) {
        for (int j = 0; j < Z; j++) {
            if (getCell(i, j) != '?') {
                n = max(n, i + 1);
                m = max(m, j + 1);
            }
        }
    }

    cout << n << " " << m << '\n';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << getCell(i, j);
        }
        cout << '\n';
    }

    return 0;
}
