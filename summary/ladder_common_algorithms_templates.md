# 程序设计天梯赛常用算法思想与代码模板

本文按比赛中最常遇到的题型整理。复习时先看题面信号，再套对应的数据结构和模板。

## 基础框架

### C++ 快速输入输出

适用场景：大多数 C++ 题。

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
```

细节：使用这两行后，不要混用 `scanf/printf` 和 `cin/cout`。

## 枚举

适用场景：数据范围小，题目要求找满足条件的组合、位置、方案。

核心思路：把所有可能情况列出来，边枚举边判断，先保证正确，再考虑剪枝。

```cpp
int ans = 0;
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        if (check(i, j)) {
            ans++;
        }
    }
}
cout << ans << '\n';
```

常见坑：先估算复杂度，`n <= 1000` 可以考虑 `O(n^2)`，`n <= 100000` 通常不能双重枚举。

## 模拟

适用场景：题面给出明确规则，如排队、发牌、栈队列过程、日期时间变化。

核心思路：把题目里的实体变成变量或容器，严格按规则更新状态。

```cpp
for (int step = 0; step < m; step++) {
    char op;
    cin >> op;
    if (op == 'A') {
        // update state A
    } else if (op == 'B') {
        // update state B
    }
}
```

常见坑：模拟题最怕顺序错。先写清楚每一步的优先级，再写代码。

## 字符串处理

适用场景：整行文本、关键词检索、格式拆分、缩写、编号解析。

### 整行读取与查找

```cpp
string line;
while (getline(cin, line)) {
    if (line == ".") break;
    if (line.find("target") != string::npos) {
        // found
    }
}
```

### 固定分隔符拆分

```cpp
string s = "12:30:45";
int h = stoi(s.substr(0, 2));
int m = stoi(s.substr(3, 2));
int sec = stoi(s.substr(6, 2));
```

### 一行多个数

```cpp
string line;
getline(cin, line);
stringstream ss(line);
int x;
while (ss >> x) {
    // use x
}
```

常见坑：`cin >> n` 后接 `getline` 时，要先 `cin.ignore(...)` 或使用 `getline(cin >> ws, line)`。

## 双指针

适用场景：有序数组、左右边界收缩、两数/三数和、最大面积、滑动范围。

```cpp
sort(a.begin(), a.end());
int l = 0, r = (int)a.size() - 1;
while (l < r) {
    int sum = a[l] + a[r];
    if (sum == target) {
        // record answer
        l++;
        r--;
    } else if (sum < target) {
        l++;
    } else {
        r--;
    }
}
```

常见坑：需要去重时，找到答案后跳过相同值；移动哪一边必须和单调性对应。

## 二分查找

适用场景：有序数组找位置，或答案具有单调性。

### 找第一个大于等于 target 的位置

```cpp
int lowerBound(vector<int>& a, int target) {
    int l = 0, r = (int)a.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] < target) l = mid + 1;
        else r = mid;
    }
    return l;
}
```

### 二分答案

```cpp
bool check(int x) {
    // x 是否可行
    return true;
}

int l = low, r = high;
while (l < r) {
    int mid = l + (r - l) / 2;
    if (check(mid)) r = mid;
    else l = mid + 1;
}
cout << l << '\n';
```

常见坑：二分答案前必须确认单调性；`check` 只判断可行，不要把最终答案逻辑混进去。

## 贪心

适用场景：最少次数、最多保留、区间选择、覆盖、局部选择可以推出全局最优。

### 区间按右端点选择

```cpp
sort(seg.begin(), seg.end(), [](const auto& a, const auto& b) {
    if (a.r != b.r) return a.r < b.r;
    return a.l < b.l;
});

int cnt = 0;
int lastEnd = INT_MIN;
for (auto& s : seg) {
    if (s.l >= lastEnd) {
        cnt++;
        lastEnd = s.r;
    }
}
```

常见坑：区间调度通常按右端点排序，不是左端点；边界相等是否冲突要按题意确定。

## 动态规划

适用场景：最值、方案数、可行性，且大问题可以由小问题推出。

### 一维 DP

```cpp
vector<int> dp(n, 0);
dp[0] = init;
for (int i = 1; i < n; i++) {
    dp[i] = max(dp[i - 1], value(i));
}
```

### 完全背包最少数量

```cpp
int INF = amount + 1;
vector<int> dp(amount + 1, INF);
dp[0] = 0;
for (int coin : coins) {
    for (int x = coin; x <= amount; x++) {
        dp[x] = min(dp[x], dp[x - coin] + 1);
    }
}
cout << (dp[amount] == INF ? -1 : dp[amount]) << '\n';
```

### LIS 二分优化

```cpp
vector<int> tail;
for (int x : a) {
    auto it = lower_bound(tail.begin(), tail.end(), x);
    if (it == tail.end()) tail.push_back(x);
    else *it = x;
}
cout << tail.size() << '\n';
```

常见坑：先定义清楚 `dp[i]` 的含义，再写转移；完全背包一维优化通常正序，01 背包通常倒序。

## DFS 和 BFS

适用场景：连通块、迷宫、网格搜索、树遍历、可达性。

### 网格 DFS

```cpp
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
vector<string> g;

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (g[x][y] != '1') return;
    g[x][y] = '0';
    for (int k = 0; k < 4; k++) {
        dfs(x + dx[k], y + dy[k]);
    }
}
```

### BFS 最短步数

```cpp
queue<pair<int,int>> q;
vector<vector<int>> dist(n, vector<int>(m, -1));
q.push({sx, sy});
dist[sx][sy] = 0;

while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (dist[nx][ny] != -1 || g[nx][ny] == '#') continue;
        dist[nx][ny] = dist[x][y] + 1;
        q.push({nx, ny});
    }
}
```

常见坑：边界判断必须放在访问数组前；DFS 大数据可能爆栈，可改 BFS。

## Dijkstra 最短路

适用场景：非负边权单源最短路。

```cpp
const long long INF = 4e18;
vector<vector<pair<int,int>>> g(n + 1);
vector<long long> dist(n + 1, INF);
vector<int> vis(n + 1, 0);

priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
dist[s] = 0;
pq.push({0, s});

while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto [v, w] : g[u]) {
        if (dist[v] > d + w) {
            dist[v] = d + w;
            pq.push({dist[v], v});
        }
    }
}
```

常见坑：Dijkstra 不能处理负边权；距离可能很大时用 `long long`。

## Floyd 多源最短路

适用场景：点数较小，要求任意两点最短路。

```cpp
const int INF = 1000000000;
vector<vector<int>> d(n, vector<int>(n, INF));
for (int i = 0; i < n; i++) d[i][i] = 0;

for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][k] == INF || d[k][j] == INF) continue;
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}
```

常见坑：复杂度 `O(n^3)`，只适合点数不大的题；加法前跳过 `INF`。

## 并查集

适用场景：连通性、合并集合、朋友圈、最小生成树 Kruskal。

```cpp
vector<int> fa, sz;

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void unite(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    fa[y] = x;
    sz[x] += sz[y];
}

void init(int n) {
    fa.resize(n + 1);
    sz.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) fa[i] = i;
}
```

常见坑：编号从 0 还是 1 开始要统一；合并前一定先找根。

## 树与 DFS 序

适用场景：子树统计、树上管理关系、把子树查询变成区间查询。

```cpp
vector<vector<int>> tree;
vector<int> in, out;
int timer = 0;

void dfs(int u) {
    in[u] = ++timer;
    for (int v : tree[u]) {
        dfs(v);
    }
    out[u] = timer;
}
```

使用方式：节点 `u` 的整棵子树对应 DFS 序区间 `[in[u], out[u]]`。

常见坑：树必须先找到根；如果存在多棵树，要对每个根 DFS。

## 树状数组

适用场景：单点修改、前缀和、区间和查询。

```cpp
vector<int> bit;
int n;

int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    for (; x <= n; x += lowbit(x)) {
        bit[x] += v;
    }
}

int sum(int x) {
    int res = 0;
    for (; x > 0; x -= lowbit(x)) {
        res += bit[x];
    }
    return res;
}

int rangeSum(int l, int r) {
    return sum(r) - sum(l - 1);
}
```

常见坑：树状数组下标必须从 1 开始，`add(0, v)` 会死循环。

## 前缀和与差分

### 一维前缀和

```cpp
vector<long long> pre(n + 1, 0);
for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + a[i];
}
long long ans = pre[r] - pre[l - 1];
```

### 一维差分

```cpp
vector<long long> diff(n + 2, 0);
diff[l] += v;
diff[r + 1] -= v;
for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + diff[i];
}
```

常见坑：前缀和适合多次区间查询，差分适合多次区间修改后统一求结果。

## 素数筛与基础数学

### 埃氏筛

```cpp
vector<int> isPrime(n + 1, 1);
isPrime[0] = isPrime[1] = 0;
for (int i = 2; i * i <= n; i++) {
    if (isPrime[i]) {
        for (int j = i * i; j <= n; j += i) {
            isPrime[j] = 0;
        }
    }
}
```

### 最大公约数和最小公倍数

```cpp
long long g = gcd(a, b);
long long l = a / g * b;
```

常见坑：`lcm` 先除后乘，减少溢出风险；筛法里 `i * i` 可能溢出时用 `long long`。

## 复盘清单

- 题目对象能不能转成数组、区间、图、树、字符串或状态表。
- 查询是否很多，是否需要预处理或维护统计量。
- 排序规则是按左端点、右端点、值大小，还是自定义优先级。
- 如果用了二分，`check` 是否真的单调。
- 如果用了 DFS/BFS，访问标记是否会漏掉或重复。
- 如果用了树状数组、前缀和、下标映射，下标是否从合法位置开始。
