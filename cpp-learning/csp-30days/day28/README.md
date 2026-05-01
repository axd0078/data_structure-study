# Day 28：线段树与树状数组

## ▶ CSP 考情分析

线段树/树状数组是 CSP 第 4-5 题中的高级数据结构。CSP 考查的规律是：**第 4 题可能考线段树的简单应用（区间查询/单点更新），第 5 题可能考线段树的变体（离散化、动态开点、线段树优化 DP）。**

**CSP 线段树/树状数组真题：**
| 真题 | 数据结构 | 考点 |
|------|---------|------|
| 磁盘文件操作(202112-4) | 线段树 | 区间赋值 + 区间恢复 |
| PS无限版(202206-5) | 线段树 | 离散化 + 区间覆盖 |
| 阻击(202306-5) | 线段树 + 树形 DP | 动态 DP |
| 推荐系统(201909-4) | set / 优先队列 | 可用树状数组维护排名 |

**CSP 考线段树的特征信号：** "区间查询"、"区间修改"、"在线操作"（边查边改）。

## ▶ 核心技巧

### 树状数组（Fenwick Tree）— 代码最简

```cpp
// 单点更新 + 前缀查询
int bit[MAXN];
void add(int i, int delta) {
    for (; i <= n; i += i & -i) bit[i] += delta;
}
int sum(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) res += bit[i];
    return res;
}
// 区间 [l, r] 和 = sum(r) - sum(l - 1)
```

### 线段树模板

```cpp
int tree[MAXN * 4];  // 数组开 4 倍

void build(int node, int l, int r) {
    if (l == r) { tree[node] = a[l]; return; }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int l, int r, int pos, int val) {
    if (l == r) { tree[node] = val; return; }
    int mid = (l + r) / 2;
    if (pos <= mid) update(node * 2, l, mid, pos, val);
    else update(node * 2 + 1, mid + 1, r, pos, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[node];
    int mid = (l + r) / 2, res = 0;
    if (ql <= mid) res += query(node * 2, l, mid, ql, qr);
    if (qr > mid) res += query(node * 2 + 1, mid + 1, r, ql, qr);
    return res;
}
```

### 树状数组 vs 线段树

| | 树状数组 | 线段树 |
|------|---------|------|
| 代码量 | 少（~10 行） | 多（~50 行） |
| 功能 | 前缀和/单点更新 | 区间最值/区间修改 |
| CSP 中的使用 | T2-T3 够用 | T4-T5 可能需要 |

---

## ▶ 真题 1：磁盘文件操作

**试题编号：202112-4（第24次认证第4题）**

模拟磁盘操作：写入一段连续数据、删除一段、恢复被删数据。需要支持区间赋值、区间恢复（undo）、区间求和。

**思路：** 线段树维护三个值：当前数据、原始数据、是否被删除。区间操作用懒标记（lazy propagation）。

**CSP 考察点：** 线段树 + 懒标记 + 多状态——CSP 第 4 题的经典压力测试。

---

## ▶ 真题 2：离散化 + 线段树

CSP 中很多线段树题的数据范围很大（10^9），但操作次数较少（10^5），需要先**离散化**坐标再建线段树。

```cpp
// 离散化模板
vector<int> sorted = raw;
sort(sorted.begin(), sorted.end());
sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
int compressed = lower_bound(sorted.begin(), sorted.end(), raw_val) - sorted.begin() + 1;
```

---

## ✅ 今日自检

- [ ] 能写出树状数组（bit）的单点更新和前缀查询
- [ ] 理解线段树的递归建树、查询、更新
- [ ] 理解懒标记（lazy）的作用
- [ ] 了解离散化的使用场景
- [ ] 做一道线段树/树状数组题（磁盘文件操作 or 更简单的）
