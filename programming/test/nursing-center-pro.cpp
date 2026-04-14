#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> mp;
int tot = 0;
//字符串编号

vector<vector<int>> tree;
vector<int> parent;
//tree[u] -- u的所有儿子 邻接表的表示树
//parent[u] -- u的父亲是谁

vector<int> in,out;
int timer = 0;
//dfs序得到每个管理结点的
//in[u]：进入时间
//out[u]：离开时间

vector<int> belong;

vector<int> bit;
//树状数组

bool isNumber(const string& s){
    for(char c:s){
        if(!isdigit(c)) return false;
    }
    return true;
}

int getId(const string& s){
    if(mp.count(s)) return mp[s];//查找是否存在
    mp[s] = ++tot;//先加后用才能让返回值对应上
    return tot;
}

void add(int x,int v){
    if(x<=0) return;
    int n = bit.size() - 1;
    while(x<=n){
        bit[x] += v;//把x的贡献加上
        x += x & -x;//跳转到下一个需要维护的位置
    }
}

int sum(int x){
    int res = 0;
    while(x > 0){
        res += bit[x];
        x -= x & -x;
    }
    return res;
}//返回前缀和

int rangeSum(int l,int r){
    return sum(r) - sum(l-1);
}//区间和函数


void dfs(int u){
    in[u] = ++timer;
    for(int v:tree[u]){
        dfs(v);
    }
    out[u] = timer;//这当出现叶子节点后 dfs回溯 会让这整条链上的out值都变成timer
}//子树 = 区间

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //加快输入输出

    int N,M;
    cin >> N >> M;

    int MAXV = N + M + 105;
    tree.assign(MAXV,vector<int>());
    parent.assign(MAXV,0);
    in.assign(MAXV,0);
    out.assign(MAXV, 0);
    belong.assign(N + 1, 0);    //老人的归属 大小一定是N+1
    bit.assign(MAXV + 5, 0);

    for (int i = 0; i < M; i++) {
        string a, b;
        cin >> a >> b;
        int pb = getId(b);  // b 一定是管理结点
        if (isNumber(a)) {
            int oldId = stoi(a);
            belong[oldId] = pb;
        } else {
            int pa = getId(a);
            parent[pa] = pb;
            tree[pb].push_back(pa); //邻接表的表示树
        }
    }
    
    int root = 0;
    for(int i=1;i<=tot;i++){
        if(parent[i] == 0){
            root = i;
            break;
        }
    }//找树根来遍历

    dfs(root);
    //做dfs

    for(int i = 1;i<=N;i++){
        add(in[belong[i]],1);
    }
    //所有老人到树状数组

    bool first = true;

    while (true) {
        char op;
        cin >> op;

        if (op == 'E') break;

        if (op == 'T') {
            int x;
            string s;
            cin >> x >> s;

            int newNode = getId(s);

            add(in[belong[x]], -1);
            belong[x] = newNode;
            add(in[belong[x]], 1);
        }
        else if (op == 'Q') {
            string s;
            cin >> s;

            int node = mp[s];
            int ans = rangeSum(in[node], out[node]);

            if (!first) cout << '\n';
            first = false;

            cout << ans;
        }
    }
    
    return 0;
}