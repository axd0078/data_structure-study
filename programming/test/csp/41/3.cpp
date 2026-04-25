#include <bits/stdc++.h>
using namespace std;

const long long INF = (long long)4e18;

struct Segment{
    long long l,r;
    long long len() const{
        return r - l + 1;
    }
};
struct SegmentCmp {
    bool operator()(const Segment &a, const Segment &b) const {
        if (a.len() != b.len()) return a.len() < b.len();
        return a.l < b.l;//长度相同比较左端点
    }
};//给set的排序规则

struct QueueInfo {
    long long l, r;
    long long next;//下一个应该存放的下标
};

map<long long,long long> freeByL;   //用于维护删除操作时有没有区间合并情况
set<Segment,SegmentCmp> freeByLen;  //用于找可用区间

void addFree(long long l,long long r){
    if(l > r) return;
    freeByL[l] = r;
    freeByLen.insert({l,r});
}

void removeFree(long long l,long long r){
    freeByL.erase(l);
    freeByLen.erase({l,r});
}

long long allocateBlock(long long L){//L 需要多长
    auto it = freeByLen.lower_bound({0,L-1});   //这里得二分查找用的是Cmp结构体里面的方法
    Segment seg = *it;
    removeFree(seg.l,seg.r);

    long long begin = seg.l;
    long long end = seg.l + L - 1;

    if(end + 1<=seg.r){
        addFree(end+1,seg.r);
    }//把剩余空间添加到segment
    return begin;
}//new

void releaseBlock(long long l,long long r){
    long long nl = l;
    long long nr = r;
    auto it = freeByL.lower_bound(l);   //找到第一个左端点 >= l 的空闲区间
    if(it != freeByL.begin()){
        auto pre = prev(it);//获取pre前面一个迭代器
        if(pre->second + 1 == l){
            nl = pre->first;
            removeFree(pre->first,pre->second);
        }//说明前端点可以合并
    }
    it = freeByL.lower_bound(l);
    if(it != freeByL.end() && r+1 == it->first){
        nr = it->second;
        removeFree(it->first,it->second);
    }
    addFree(nl,nr);
}//delete

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    vector<vector<QueueInfo>> proc(n+1);
    addFree(0,INF);
    while(q--){
        string op;
        cin >> op;
        if(op=="new"){
            int p;
            long long L;
            cin >> p >> L;
            long long a = allocateBlock(L);
            proc[p].push_back({a,a+L-1,a});
            cout << a << '\n';
        }
        else if(op=="delete"){
            int p;
            int i;
            cin >> p >> i;
            i--;
            QueueInfo que = proc[p][i];
            releaseBlock(que.l,que.r);
            proc[p].erase(proc[p].begin() + i);
        }
        else if(op=="send"){
            int p;
            cin >> p;
            long long sum = 0;
            for(auto &que: proc[p]){
                sum += que.next;
                que.next++;
                if(que.next > que.r)
                    que.next = que.l;
            }
            cout << sum << "\n";
        }
    }
    return 0;
}