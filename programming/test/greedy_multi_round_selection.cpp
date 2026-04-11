#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,k,s;
    cin >> n >> k >> s;
    vector<vector<int>> grade(n,vector<int>(2));
    vector<int> nums(290-175+1,0);//记录分数段人数
    for(int i=0;i<n;i++){
        cin >> grade[i][0] >> grade[i][1];
        if(grade[i][0] >= 175)
            nums[grade[i][0]-175]++;
    }
    sort(grade.begin(),grade.end(),[](const vector<int>& a,const vector<int>& b){
        if(a[0]==b[0]){
            return a[1] < b[1];
        }
        return a[0] < b[0];
    });
    int ans = 0;
    for(int j=0;j<n;j++){
        if(grade[j][0] < 175)
            continue;
        if(grade[j][0] >= 175 && grade[j][1] >= s){//不需要占批次名额
            nums[grade[j][0]-175]--;
            ans++;
        }
    }
    for(int i=175;i<=290;i++){
        ans += nums[i-175] < k ? nums[i-175] : k;
    }
    cout << ans;
    return 0;
}

/*
给定整数 n k s
n 表示学生人数
k 表示企业接受的推荐批次
s 表示该企业的 PAT 面试分数线

接下来 n 行
每行包含两个整数
第一个是学生的天梯赛分数（最高 290）
第二个是 PAT 分数（最高 100）

筛选规则如下
只考虑天梯赛分数不小于 175 的学生
学生按天梯赛分数从小到大排序 如果相同则按 PAT 分数从小到大排序

企业进行 k 轮筛选
每一轮从头到尾遍历学生

每一轮中
对于每一个新的天梯赛分数段 可以选一个学生
如果该分数段中还有其他学生 且 PAT 分数不小于 s 也可以被选

每个学生最多只能被选一次

输出最终被选中的学生总人数

*/