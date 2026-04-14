#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;


unordered_map<string,int> mp;
int tot = 0;//当前有多少个管理节点

int getId(string s){
    if(mp.count(s)) return mp[s];
    mp[s] = ++tot;
    return tot;
}//返回管理节点的编号

bool isNumber(string s){
    for(char c: s){
        if(!isdigit(c)) return false;
    }
    return true;
}//判断到底是节点还是老人

int query(int x,int n,vector<int>& belong,vector<int>& parent){
    int ans = 0;
    for(int i = 0;i<= n ;i++){
        int p = belong[i];  //老人的父节点往上遍历
        while(p != 0){
            if(p==x){
                ans++;
                break;
            }//发现这个老人属于这个节点
            p = parent[p];
        }
    }
    return ans;
}//搜索节点x管了多少老人

int main(){
    int N,M;
    cin >> N >> M;

    vector<int> parent(200000,0);
    vector<int> belong(N+1,0);

    for(int i=0;i<M;i++){
        string a,b;
        cin >> a >> b;

        int pb = getId(b);

        if(isNumber(a)){
            int id = stoi(a);
            belong[id] = pb;
        }//如果是老人
        else{
            int pa = getId(a);
            parent[pa] = pb;
        }
    }//输入阶段

    while(true){
        char op;
        cin >> op;
        bool first = true;
        if(op == 'E') break;
        else if(op == 'Q'){
            if(!first) cout << '\n';
            string a;
            cin >> a;
            int x = getId(a);
            cout << query(x,N,belong,parent);
        }//查询
        else if(op == 'T'){
            int x;
            string s;
            cin >> x >> s;
            belong[x] = getId(s);
        }//切换关系
    }

    return 0;
}