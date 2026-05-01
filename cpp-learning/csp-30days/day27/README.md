# Day 27：拓扑排序与 DAG 上的 DP

## ▶ CSP 考情分析

拓扑排序在 CSP 中主要出现在两类场景：
1. **依赖关系处理：** 如 高速公路(201509-4) 的强连通分量、区间依赖问题(202209-2)
2. **DAG 上的 DP：** 利用拓扑序做"无后效性"的状态转移

| 真题 | 考点 |
|------|------|
| 高速公路(201509-4) | Tarjan 求 SCC + DAG 缩点 |
| 区间依赖(202209-2) | 拓扑排序 + 最长链 |
| 任务调度(201403-5) | 拓扑序 + DP |
| 拼图(201409-5) | 按列 DP（拓扑序思想） |

## ▶ 核心技巧

### 拓扑排序（Kahn 算法）

```cpp
vector<int> G[MAXN];
int indegree[MAXN];

// 建图时统计入度
for (auto& [u, v] : edges) indegree[v]++;

// 入度为 0 的节点入队
queue<int> q;
for (int i = 1; i <= n; i++)
    if (indegree[i] == 0) q.push(i);

vector<int> order;
while (!q.empty()) {
    int u = q.front(); q.pop();
    order.push_back(u);          // 拓扑序
    for (int v : G[u]) {
        indegree[v]--;
        if (indegree[v] == 0) q.push(v);
    }
}
// 如果 order.size() < n，说明有环
```

### DAG 上的 DP

拓扑排序后，按拓扑序做 DP（保证处理节点 u 时，所有能到达 u 的节点都已处理完）：

```cpp
for (int u : order) {
    for (int v : G[u]) {
        dp[v] = max(dp[v], dp[u] + 1);  // 最长路
    }
}
```

---

## ▶ 真题 1：高速公路（SCC + 缩点）

**试题编号：201509-4（第5次认证第4题）**

n 个城市，m 条有向高速公路。两个城市互相可达 = 一个"便利城市对"。求总共有多少个便利城市对。

**思路：**
1. Tarjan 算法求所有强连通分量（SCC）
2. 每个 SCC 内部节点数 k → 贡献 C(k, 2) 对
3. 所有 SCC 贡献之和 = 答案

**CSP 考察点：** 强连通分量是拓扑排序思想的延伸——SCC 缩点后形成 DAG。

---

## ▶ 真题 2：区间依赖问题

**试题编号：202209-2（第28次认证第2题）**

n 个任务，每个任务依赖一些区间。求所有任务的最小完成时间。

**思路：** 任务之间的依赖构成 DAG（无环）。拓扑排序求出每个任务的最早完成时间（DAG 最长路）。

**CSP 考察点：** "依赖关系" → 有向边 → 拓扑序 → DAG DP。这是 CSP 处理依赖的标准流程。

---

## ▶ Tarjan 求 SCC（进阶参考）

```cpp
int dfn[MAXN], low[MAXN], timer;
bool inStack[MAXN];
stack<int> stk;

void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    stk.push(u); inStack[u] = true;
    for (int v : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {  // u 是 SCC 的根
        while (true) { int v = stk.top(); stk.pop(); /* 属于同一 SCC */ }
    }
}
```

---

## ✅ 今日自检

- [ ] 能写出拓扑排序的入度 + 队列算法
- [ ] 理解 DAG 上 DP 为什么可以按拓扑序
- [ ] 了解 Tarjan 算法的基本流程
- [ ] 做高速公路 or 区间依赖并 AC
