# Day 6：前缀和、差分与区间贡献

## 今日目标

新题优先练区间贡献和二维统计，旧题用于巩固公式。

## 学习内容

- 看到区间和、区域平均、批量影响，先想前缀和/差分。
- 半开区间 `[l,r)` 能减少边界错误。
- 二维前缀和必须先画公式。

## 主练真题（第 21-41 次为主）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第22次 T2 邻域均值](../csp-certification-problems/22-%E7%AC%AC22%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-112-%E9%82%BB%E5%9F%9F%E5%9D%87%E5%80%BC.md) | 邻域均值：二维前缀和。 |
| 2 | [第24次 T1 序列查询](../csp-certification-problems/24-%E7%AC%AC24%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/01-121-%E5%BA%8F%E5%88%97%E6%9F%A5%E8%AF%A2.md) | 序列查询：分段贡献。 |
| 3 | [第24次 T2 序列查询新解](../csp-certification-problems/24-%E7%AC%AC24%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-122-%E5%BA%8F%E5%88%97%E6%9F%A5%E8%AF%A2%E6%96%B0%E8%A7%A3.md) | 序列查询新解：优化分段贡献。 |
| 4 | [第28次 T2 训练计划](../csp-certification-problems/28-%E7%AC%AC28%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-142-%E8%AE%AD%E7%BB%83%E8%AE%A1%E5%88%92.md) | 训练计划：依赖时间区间。 |

## 主练题解

### 1. 第22次 T2 邻域均值

**题意抓手**

对每个像素 `(i,j)`，看它周围横纵距离不超过 `r` 的矩形邻域。邻域平均值 `<= t`，这个像素就算较暗区域。

**解法**

直接枚举邻域会到 `O(n^2 r^2)`，`n` 最大 600、`r` 最大 100，不稳。用二维前缀和把任意矩形和降到 `O(1)`。

设前缀和 `s[i+1][j+1]` 表示原矩阵左上角到 `(i,j)` 的元素和。对像素 `(i,j)`：

- `x1=max(0,i-r)`，`x2=min(n-1,i+r)`
- `y1=max(0,j-r)`，`y2=min(n-1,j+r)`
- 矩形和用前缀和公式求。
- 不要真的除法求平均，判断 `sum <= t * area`，避免浮点误差。

**易错点**

- 前缀和建议开成 `(n+1)*(n+1)`，查询时右下角要用 `x2+1,y2+1`。
- 边界像素的邻域会被裁剪，面积不是固定 `(2r+1)^2`。
- 灰度总和最大约 `600*600*255`，用 `long long` 更稳。

**复杂度**

时间 `O(n^2)`，空间 `O(n^2)`。

**参考代码**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, L, r, t;
    cin >> n >> L >> r >> t;

    vector<vector<long long>> s(n + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            long long x;
            cin >> x;
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x1 = max(0, i - r);
            int x2 = min(n - 1, i + r);
            int y1 = max(0, j - r);
            int y2 = min(n - 1, j + r);

            long long sum = s[x2 + 1][y2 + 1] - s[x1][y2 + 1] - s[x2 + 1][y1] + s[x1][y1];
            long long area = 1LL * (x2 - x1 + 1) * (y2 - y1 + 1);
            if (sum <= 1LL * t * area) {
                ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
```

### 2. 第24次 T1 序列查询

**题意抓手**

给定递增序列 `A0=0 < A1 < ... < An < N`。对每个 `x`，`f(x)` 是不大于 `x` 的最大 `A` 的下标。要求 `x=0..N-1` 的 `f(x)` 之和。

**解法**

`f(x)` 在区间 `[A[i], A[i+1])` 内恒等于 `i`。补一个哨兵 `A[n+1]=N`，直接累加每段贡献：

```text
ans += i * (A[i+1] - A[i])
```

**易错点**

- 输入不包含 `A0`，要手动补 `0`。
- 最后一段是 `[A[n], N)`，所以要补 `A[n+1]=N`。
- `N` 可到 `1e7`，答案用 `long long`。

**复杂度**

时间 `O(n)`，空间 `O(n)`。

**参考代码**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long N;
    cin >> n >> N;

    vector<long long> a(n + 2);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = N;

    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += 1LL * i * (a[i + 1] - a[i]);
    }

    cout << ans << '\n';
    return 0;
}
```

### 3. 第24次 T2 序列查询新解

**题意抓手**

这一题还是有 `f(x)`，但新增估计函数 `g(x)=floor(x/r)`，其中 `r=floor(N/(n+1))`。要求：

```text
sum |g(x)-f(x)|, x=0..N-1
```

**解法**

`f(x)` 在 `[A[i], A[i+1])` 内不变，`g(x)` 在 `[k*r, (k+1)*r)` 内不变。把这两类边界合并扫描即可。

对每个 `f` 分段 `[A[i], A[i+1])`：

1. 当前左端点为 `left`。
2. `g = left / r`。
3. 当前 `g` 的右边界是 `(g+1)*r`。
4. 本次小段右端点是 `min(A[i+1], (g+1)*r)`。
5. 小段贡献是 `(end-left) * abs(g-i)`。

由于 `r>=1`，`g` 的分段数量大约也是 `O(n)`，整体可以通过。

**易错点**

- `N` 可到 `1e9`，不能枚举每个 `x`。
- `g(x)` 可能大于 `n`，不要把它限制在 `0..n`。
- 所有贡献都用 `long long`。

**复杂度**

时间 `O(n + N/r)`，实际为 `O(n)` 级别；空间 `O(n)`。

**参考代码**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long N;
    cin >> n >> N;

    vector<long long> a(n + 2);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = N;

    long long r = N / (n + 1);
    long long ans = 0;

    for (int i = 0; i <= n; i++) {
        long long left = a[i];
        long long right = a[i + 1];
        while (left < right) {
            long long g = left / r;
            long long end = min(right, (g + 1) * r);
            ans += (end - left) * llabs(g - i);
            left = end;
        }
    }

    cout << ans << '\n';
    return 0;
}
```

### 4. 第28次 T2 训练计划

**题意抓手**

每个科目最多依赖一个编号更小的科目。先求每个科目最早哪天能开始；如果全部能在 `n` 天内完成，再求每个科目最晚哪天开始。

**解法**

最早开始时间正向算，因为依赖科目编号一定更小：

```text
early[i] = 1                         // 无依赖
early[i] = early[p[i]] + t[p[i]]     // 有依赖
```

如果存在 `early[i] + t[i] - 1 > n`，说明无法完成全部训练，只输出最早开始时间。

若可以完成，再求最晚开始时间：

1. 每个科目默认最晚开始为 `n - t[i] + 1`。
2. 倒序扫描科目 `i`。
3. 如果 `i` 依赖父科目 `p`，那么 `p` 必须在 `i` 最晚开始前完成：

```text
late[p] = min(late[p], late[i] - t[p])
```

倒序的原因是子科目编号更大，先处理子科目才能把限制传回父科目。

**易错点**

- 最早结束日是 `early[i] + t[i] - 1`。
- 如果无法完成，不要输出第二行。
- 最晚开始不是拓扑排序复杂题，编号已经保证依赖方向从小到大。

**复杂度**

时间 `O(m)`，空间 `O(m)`。

**参考代码**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> p(m + 1), t(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> t[i];
    }

    vector<int> early(m + 1);
    bool ok = true;
    for (int i = 1; i <= m; i++) {
        if (p[i] == 0) {
            early[i] = 1;
        } else {
            early[i] = early[p[i]] + t[p[i]];
        }
        if (early[i] + t[i] - 1 > n) {
            ok = false;
        }
    }

    for (int i = 1; i <= m; i++) {
        if (i > 1) cout << ' ';
        cout << early[i];
    }
    cout << '\n';

    if (!ok) {
        return 0;
    }

    vector<int> late(m + 1);
    for (int i = 1; i <= m; i++) {
        late[i] = n - t[i] + 1;
    }

    for (int i = m; i >= 1; i--) {
        if (p[i] != 0) {
            late[p[i]] = min(late[p[i]], late[i] - t[p[i]]);
        }
    }

    for (int i = 1; i <= m; i++) {
        if (i > 1) cout << ' ';
        cout << late[i];
    }
    cout << '\n';

    return 0;
}
```

## 回顾真题（第 1-20 次补基础）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第02次 T2 画图](../csp-certification-problems/02-%E7%AC%AC02%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-012-%E7%94%BB%E5%9B%BE.md) | 画图：二维覆盖。 |
| 2 | [第14次 T2 买菜](../csp-certification-problems/14-%E7%AC%AC14%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-072-%E4%B9%B0%E8%8F%9C.md) | 买菜：区间交集。 |

## 验收标准

- 能独立复述题意和数据范围。
- 能说明使用的数据结构或算法为什么合适。
- 主练至少完成前三题，回顾题至少完成一题。

## 复盘记录

- 用时：
- 错因：
- 下次改进：
