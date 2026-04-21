#include<bits/stdc++.h>
using namespace std;

struct Task{
    int o;
    int t;
    int a;
    int b;
};

vector<double> getNormalReduce(vector<Task>& normal,int coffee){
    vector<double> dp(coffee+1,0);//咖啡选择的最优解
    for(const Task &task:normal){
        for(int j=coffee;j>=task.a;j--){
            dp[j] = max(dp[j],dp[j-task.a] + task.b);
        }
    }
    return dp;
}

double getFlexReduce(vector<Task> flex,int coffee){
    sort(flex.begin(), flex.end(), [](const Task &x, const Task &y) {
        return 1.0 * x.b / x.a > 1.0 * y.b / y.a;
    });
    double reduce = 0;
    double left = coffee;
    for (const Task &task : flex) {
        if (left <= 0) {
            break;
        }

        double take = min(left, (double)task.a);
        reduce += take * task.b / task.a;
        left -= take;
    }
    return reduce;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<Task> flex;
    vector<Task> normal;
    long long time = 0;

    for (int i = 0; i < n; i++) {
        Task task;
        cin >> task.o >> task.t >> task.a >> task.b;

        time += task.t;
        if (task.o == 0) {
            flex.push_back(task);
        } else {
            normal.push_back(task);
        }
    }

    vector<double> dp = getNormalReduce(normal,m);

    double maxReduce = 0;
    for(int used = 0;used<=m;used++){
        maxReduce = max(maxReduce,dp[used] + getFlexReduce(flex,m-used));
    }
    //给不同类型的任务分配不同的咖啡数量

    cout << fixed << setprecision(6)<<time - maxReduce <<endl;
    return 0;

}