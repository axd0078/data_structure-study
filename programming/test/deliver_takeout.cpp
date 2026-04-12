#include <iostream>
#include <vector>
using namespace std;

#if 0
class Solution{
public:
    int getDistance(vector<int>& tree,vector<bool>& visited,int place){
        int distance = 0;
        while(!visited[place]){
            visited[place] = true;
            place = tree[place];
            distance++;
        }
        return distance;
    }/*计算从place到第一个已被访问节点的距离*/
    int getDepth(vector<int>& tree,vector<int>& depth,int place){
        if(depth[place]!=-1){
            return depth[place];
        }//已经知道深度 直接返回
        vector<int> path;
        int cur = place;
        while(depth[cur]==-1){
            path.push_back(cur);
            cur = tree[cur];
        }//一直找找到知道深度的节点
        int d = depth[cur];
        int d = depth[cur];
        for(int i=(int)path.size()-1;i>=0;i--){
            depth[path[i]] = ++d;
        }//path 的末尾是第一个已知深度节点 cur 的子节点；所以要从 path 末尾往前填，深度才会一层一层递增。
        return depth[place];
        return depth[place];
    }
};
#endif

class Solution {
public:
    int getDistance(vector<int>& tree, vector<bool>& visited, int place) {
        int distance = 0;
        while (!visited[place]) {
            visited[place] = true;
            place = tree[place];
            distance++;
        }
        return distance;
    }

    int getDepth(vector<int>& tree, vector<int>& depth, int place) {
        if (depth[place] != -1) {
            return depth[place];
        }

        vector<int> path;
        int cur = place;
        while (depth[cur] == -1) {
            path.push_back(cur);
            cur = tree[cur];
        }

        int d = depth[cur];
        for (int i = static_cast<int>(path.size()) - 1; i >= 0; i--) {
            depth[path[i]] = ++d;
        }
        return depth[place];
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> tree(n+1,0);
    vector<int> depth(n+1,-1);
    vector<bool> visited(n+1,false);
    int root = -1;
    for(int i=1;i<=n;i++){
        cin >> tree[i];
        if(tree[i]==-1){
            root = i;
        }
    }
    visited[root] = true;
    depth[root] = 0;

    int place;
    long long distance = 0;
    int maxDepth = 0;
    Solution s;
    for(int i=0;i<m;i++){
        cin >> place;
        distance += s.getDistance(tree,visited,place);
        int curDepth = s.getDepth(tree,depth,place);//place所在的深度
        if(curDepth>maxDepth){
            maxDepth = curDepth;
        }/*负责处理“最后不用回外卖站”的优惠应该给谁 送完结束的节点一定是深度最大的节点*/
        if(i==m-1)
            cout << 2*distance-maxDepth;
        else
            cout << 2*distance-maxDepth << endl;
        //距离所有需要走到的边都走一来一回 - 最后停留那条路径少走一次
    }
}
