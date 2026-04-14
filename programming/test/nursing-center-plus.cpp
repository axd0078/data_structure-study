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

void addChain(int u,int val,vector<int>& parent,vector<int>& cnt){
    while(u!=0){
        cnt[u]+=val;
        u = parent[u]; 
    }
}//cnt -- 记录这个管理节点有多少个老人
//+1 说明老人多一个 -1 说明老人转移了

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);//加速输入输出
    int N,M;
    cin >> N >> M;

    vector<int> belong(N+1,0);
    vector<int> parent(200000,0);
    vector<int> cnt(200000,0);

    for(int i=0;i<M;i++){
        string a,b;
        cin >> a >> b;
        int pb = getId(b);
        if(isNumber(a)){
            belong[stoi(a)] = pb;
        }
        else{
            int pa = getId(a);
            parent[pa] = pb;
        }
    }

    for(int i=1;i<=N;i++){
        addChain(belong[i],+1,parent,cnt);
    }//计算

    bool first = true;
    while(true){
        char op;
        cin >> op;
        if(op == 'E') break;
        else if(op == 'Q'){
            if(!first) cout << "\n";
            string s;
            cin >> s;
            int id = getId(s);
            cout << cnt[id];
            first = false;
        }
        else if(op == 'T'){
            int x;
            string s;
            cin >> x >> s;
            //移除关系链
            addChain(belong[x],-1,parent,cnt);
            int newNode = getId(s);
            //更改从属关系
            belong[x] = newNode;
            //顺关系链自增
            addChain(belong[x],+1,parent,cnt);
        }
    }
}



/*
看一个量是否值得维护，取决于：

查询它有多频繁
现算它有多贵
修改时维护它贵不贵

*/