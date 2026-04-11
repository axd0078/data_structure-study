#include<iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main(){
    stack<int> box;
    queue<int> conveyor;
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> tree(k);
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        conveyor.push(num);
    }
    int i = 0;
    while(!conveyor.empty() || !box.empty()){
        if(i==k){
            for(int j=0;j<i;j++){
                if(j==i-1) cout << tree[j] << endl;
                else cout << tree[j] << " ";
            }
            i = 0;
            continue;
        }//满了
        if(box.empty()){
            if(conveyor.empty()) break;
            int num = conveyor.front();
            if(i==0 || (tree[i-1] >= num && i<k)){
                tree[i] = num;
                i++;
                conveyor.pop();
            }//可以插入的条件
            else{
                box.push(num);
                conveyor.pop();
            }//盒子空了还插不进去 需要把传送带的放盒子里面
        }//盒子空了的情况
        else{
            int num = box.top();
            if(i==0 || (tree[i-1] >= num && i<k)){
                tree[i] = num;
                i++;
                box.pop();
            }//能插就出盒子 
            else{
                if(conveyor.empty()){
                    for(int j=0;j<i;j++){
                        if(j==i-1)
                            cout << tree[j] << endl;
                        else
                            cout << tree[j] << " ";
                    }
                    i = 0;
                    continue;
                }//盒子插不进去 传送带也没了(2)
                num = conveyor.front();
                if(tree[i-1] >= num && i<k){
                    tree[i] = num;
                    i++;
                    conveyor.pop();
                }
                else{
                    if((int)box.size()<m){
                        box.push(conveyor.front());
                        conveyor.pop();
                    }
                    else{
                        for(int j=0;j<i;j++){
                            if(j==i-1)
                                cout << tree[j] << endl;
                            else
                                cout << tree[j] << " ";
                        }
                        i = 0;
                    }//(1)
                }
            }//不能插看传送带能不能插 
        }//盒子没空的话 
    }//盒子和传送带都空了就结束
    if(i>0){
        for(int j=0;j<i;j++){
            if(j==i-1)
                cout << tree[j] << endl;
            else
                cout << tree[j] << " ";
        }
    }
    return 0;
}

/*
有一条传送带按顺序给出一批松针（整数序列）

有一个容量为 m 的辅助盒子（栈）

需要构造若干条“松枝”（序列），每条最多长度为 k

构造规则：

当前松枝必须是非递增序列
每次可以选择：
直接使用传送带当前元素
或使用盒子栈顶元素
如果当前元素不能加入松枝：
可以暂存到盒子（如果未满）
如果盒子已满且仍无法加入：
当前松枝结束，输出，并开始新的一条

结束条件：

传送带和盒子都为空

输出：

每一条构造好的松枝



*/
