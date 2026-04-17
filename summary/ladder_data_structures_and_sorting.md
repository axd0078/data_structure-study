# 天梯赛常用数据结构、方法与排序写法

本文整理 C/C++ 刷题中常用的数据结构、常用方法和排序函数写法。比赛时先根据题面对象选结构，再考虑算法。

## 选择速查表

| 需求 | 推荐结构 |
|------|----------|
| 连续存一组数 | C 数组、`vector` |
| 存二维表、网格 | 二维数组、`vector<vector<int>>`、`vector<string>` |
| 存名字到编号 | `map`、`unordered_map` |
| 判断元素是否出现 | `set`、`unordered_set`、布尔数组 |
| 后进先出 | `stack` |
| 先进先出 | `queue` |
| 两端进出 | `deque` |
| 每次取最大或最小 | `priority_queue` |
| 图的边很多但点不太多 | 邻接表 |
| 任意两点距离、点数小 | 邻接矩阵 |
| 子树区间统计 | DFS 序 + 树状数组 |

## C 常用结构

### 一维数组

```c
int a[100005];
int n;
scanf("%d", &n);
for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
}
```

常用操作：

- 访问：`a[i]`
- 初始化为 0：全局数组默认 0，局部数组可用 `memset(a, 0, sizeof(a))`
- 求和：循环累加，数据大时用 `long long`

### 二维数组

```c
int g[105][105];
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        scanf("%d", &g[i][j]);
    }
}
```

常见用途：矩阵、地图、邻接矩阵、DP 表。

### 字符数组

```c
char s[1005];
scanf("%s", s);       // 不含空格
fgets(s, 1005, stdin); // 整行
```

常用函数：

- `strlen(s)`：长度
- `strcmp(a, b)`：比较
- `strcpy(a, b)`：复制
- `strcspn(s, "\n")`：找换行位置，常用于删除行尾换行

### 结构体数组

```c
typedef struct {
    int id;
    int score;
} Student;

Student stu[1005];
```

适用场景：一个对象有多个属性，如学生、区间、边、时间段。

### 链表节点

```c
typedef struct Node {
    int val;
    struct Node* next;
} Node;
```

常用操作：

- 新建：`Node* p = (Node*)malloc(sizeof(Node));`
- 连接：`p->next = head; head = p;`
- 释放：遍历链表逐个 `free`

## C++ 顺序容器

### `vector`

```cpp
vector<int> a;
a.push_back(10);
a.push_back(20);
cout << a[0] << '\n';
```

常用方法：

- `push_back(x)`：尾部加入
- `pop_back()`：删除最后一个
- `size()`：元素个数
- `empty()`：是否为空
- `clear()`：清空
- `resize(n)`：调整大小
- `assign(n, x)`：重置为 `n` 个 `x`
- `front()` / `back()`：首尾元素
- `begin()` / `end()`：迭代器，常配合排序和查找

二维写法：

```cpp
vector<vector<int>> g(n, vector<int>(m, 0));
vector<string> grid(n);
```

### `string`

```cpp
string s;
cin >> s;          // 不含空格
getline(cin, s);   // 整行
```

常用方法：

- `size()` / `length()`：长度
- `s[i]`：访问字符
- `substr(pos, len)`：截取子串
- `find(t)`：查找子串，找不到返回 `string::npos`
- `push_back(c)`：尾部加字符
- `erase(pos, len)`：删除
- `stoi(s)` / `stoll(s)`：字符串转整数
- `to_string(x)`：数字转字符串

### `pair`

```cpp
pair<int, int> p = {3, 5};
cout << p.first << ' ' << p.second << '\n';
```

常见用途：坐标、边、键值对、堆元素。

`pair` 默认先比较 `first`，再比较 `second`。

### `struct`

```cpp
struct Student {
    string name;
    int score;
    int id;
};
```

适合字段有明确含义的对象，比 `vector<int>{a,b,c}` 更清晰。

## C++ 适配器

### `stack`

后进先出。

```cpp
stack<int> st;
st.push(1);
st.push(2);
cout << st.top() << '\n';
st.pop();
```

常用方法：

- `push(x)`：入栈
- `pop()`：弹出栈顶，不返回值
- `top()`：查看栈顶
- `empty()`：是否为空
- `size()`：元素个数

适用场景：括号匹配、表达式计算、模拟盒子、DFS 手写栈。

### `queue`

先进先出。

```cpp
queue<int> q;
q.push(1);
q.push(2);
cout << q.front() << '\n';
q.pop();
```

常用方法：

- `push(x)`：入队
- `pop()`：出队
- `front()`：队首
- `back()`：队尾
- `empty()` / `size()`

适用场景：BFS、排队模拟。

### `deque`

双端队列。

```cpp
deque<int> dq;
dq.push_front(1);
dq.push_back(2);
dq.pop_front();
dq.pop_back();
```

常用方法：

- `push_front(x)` / `push_back(x)`
- `pop_front()` / `pop_back()`
- `front()` / `back()`
- `empty()` / `size()`

适用场景：两端操作、单调队列。

### `priority_queue`

默认大根堆。

```cpp
priority_queue<int> big;
big.push(3);
big.push(1);
cout << big.top() << '\n'; // 3
```

小根堆：

```cpp
priority_queue<int, vector<int>, greater<int>> small;
small.push(3);
small.push(1);
cout << small.top() << '\n'; // 1
```

常用方法：

- `push(x)`：加入
- `pop()`：删除堆顶
- `top()`：堆顶
- `empty()` / `size()`

适用场景：每次取最大/最小、Dijkstra、会议室最早结束时间。

## C++ 关联容器

### `set`

有序去重集合，底层按值排序。

```cpp
set<int> s;
s.insert(3);
s.insert(1);
if (s.count(3)) {
    cout << "found\n";
}
```

常用方法：

- `insert(x)`：插入
- `erase(x)`：删除
- `find(x)`：返回迭代器
- `count(x)`：是否存在，结果为 0 或 1
- `lower_bound(x)`：第一个 `>= x`
- `upper_bound(x)`：第一个 `> x`
- `begin()` / `rbegin()`：最小值 / 最大值位置

### `map`

有序键值表。

```cpp
map<string, int> mp;
mp["Tom"] = 90;
cout << mp["Tom"] << '\n';
```

常用方法：

- `mp[key]`：访问或创建
- `insert({key, value})`
- `find(key)`：查找
- `count(key)`：是否存在
- `erase(key)`：删除
- `size()` / `empty()`

注意：`mp[key]` 在 key 不存在时会自动插入默认值。如果只是判断是否存在，用 `find` 或 `count`。

### `unordered_set`

无序去重集合，平均 `O(1)` 查找。

```cpp
unordered_set<string> st;
st.insert("abc");
if (st.count("abc")) {
    cout << "yes\n";
}
```

适用场景：只关心是否出现，不需要有序遍历。

### `unordered_map`

无序键值表，平均 `O(1)` 查找。

```cpp
unordered_map<string, int> id;
if (!id.count(name)) {
    id[name] = ++tot;
}
```

适用场景：名字映射编号、计数、快速查找。

常见坑：哈希表不保证顺序，输出需要排序时不能直接遍历。

### `bitset`

固定长度二进制集合。

```cpp
bitset<1000> b;
b.set(3);
b.reset(3);
cout << b.count() << '\n';
```

常用方法：

- `set(pos)`：置 1
- `reset(pos)`：置 0
- `test(pos)`：判断
- `count()`：1 的数量
- `any()` / `none()`：是否存在 1 / 是否全 0

## 图的常用存法

### 邻接矩阵

```cpp
const int INF = 1000000000;
vector<vector<int>> g(n, vector<int>(n, INF));
for (int i = 0; i < n; i++) g[i][i] = 0;
g[u][v] = w;
```

适用场景：点数小、需要快速判断两点是否相连、Floyd。

### 邻接表

```cpp
vector<vector<int>> g(n + 1);
g[u].push_back(v);
g[v].push_back(u);
```

带权图：

```cpp
vector<vector<pair<int,int>>> g(n + 1);
g[u].push_back({v, w});
```

适用场景：边较少、DFS/BFS、Dijkstra。

### 边数组

```cpp
struct Edge {
    int u, v, w;
};
vector<Edge> edges;
edges.push_back({u, v, w});
```

适用场景：Kruskal、按边排序、批量处理边。

## C 排序函数写法

### `qsort` 排普通整数数组

```c
#include <stdlib.h>

int cmpIntAsc(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int a[100];
qsort(a, n, sizeof(int), cmpIntAsc);
```

降序：

```c
int cmpIntDesc(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    if (x > y) return -1;
    if (x < y) return 1;
    return 0;
}
```

注意：不要直接 `return x - y`，极端数据可能溢出。

### `qsort` 排结构体数组

```c
typedef struct {
    int l, r;
} Interval;

int cmpInterval(const void* a, const void* b) {
    const Interval* x = (const Interval*)a;
    const Interval* y = (const Interval*)b;
    if (x->l != y->l) return x->l < y->l ? -1 : 1;
    if (x->r != y->r) return x->r < y->r ? -1 : 1;
    return 0;
}

Interval seg[1000];
qsort(seg, n, sizeof(Interval), cmpInterval);
```

## C++ 排序函数写法

### 普通数组排序

```cpp
int a[100];
sort(a, a + n);                 // 升序
sort(a, a + n, greater<int>()); // 降序
```

### `vector<int>` 排序

```cpp
vector<int> a(n);
sort(a.begin(), a.end());                 // 升序
sort(a.begin(), a.end(), greater<int>()); // 降序
```

自定义 lambda：

```cpp
sort(a.begin(), a.end(), [](int x, int y) {
    return x > y;
});
```

### `vector<pair<int,int>>` 排序

默认排序：先按 `first` 升序，再按 `second` 升序。

```cpp
vector<pair<int,int>> a;
sort(a.begin(), a.end());
```

自定义：先按第一维升序，第一维相同按第二维降序。

```cpp
sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
    if (x.first != y.first) return x.first < y.first;
    return x.second > y.second;
});
```

### `struct` 排序

```cpp
struct Student {
    string name;
    int score;
    int id;
};

vector<Student> stu;
sort(stu.begin(), stu.end(), [](const Student& a, const Student& b) {
    if (a.score != b.score) return a.score > b.score;
    return a.id < b.id;
});
```

规则：分数高的在前，分数相同编号小的在前。

### `vector<vector<int>>` 排序

区间按右端点升序：

```cpp
vector<vector<int>> intervals(n, vector<int>(2));
sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
    if (a[1] != b[1]) return a[1] < b[1];
    return a[0] < b[0];
});
```

二维信封：第一维升序，第一维相同第二维降序。

```cpp
sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
    if (a[0] != b[0]) return a[0] < b[0];
    return a[1] > b[1];
});
```

### `stable_sort`

稳定排序会保留相等元素的原相对顺序。

```cpp
stable_sort(a.begin(), a.end(), [](const Student& x, const Student& y) {
    return x.score > y.score;
});
```

适用场景：题目要求“分数相同保持原输入顺序”。

## 查找和边界函数

### `lower_bound` 和 `upper_bound`

要求区间已经升序排序。

```cpp
vector<int> a = {1, 2, 2, 4};
auto it1 = lower_bound(a.begin(), a.end(), 2); // 第一个 >= 2
auto it2 = upper_bound(a.begin(), a.end(), 2); // 第一个 > 2
int pos1 = it1 - a.begin();
int pos2 = it2 - a.begin();
```

常见用途：

- LIS 中找第一个 `>= x` 的位置
- 区间 DP 中找最后一个不冲突区间
- 统计有序数组中某个值出现次数：`upper_bound - lower_bound`

## 比较函数规则

C++ `sort` 的比较函数必须表示“谁应该排在前面”。

正确写法：

```cpp
return a.score > b.score;
```

错误倾向：

```cpp
return a.score >= b.score; // 不要这样写
```

原因：相等时必须返回 `false`，否则排序规则不严格，可能导致结果异常。

## 复盘清单

- 数据是否需要保持有序：需要就考虑 `sort`、`set`、`map`。
- 是否需要快速判断存在：考虑布尔数组、`unordered_set`、`unordered_map`。
- 是否频繁取最小或最大：考虑堆。
- 是否要处理子树：考虑 DFS 序。
- 排序比较函数相等时是否返回了 `false`。
- C 的 `qsort` 比较函数是否避免了整数溢出。
