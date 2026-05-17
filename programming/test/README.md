# 编程补充题 (Programming Test)

## 模块简介

`programming/test` 用于存放主 `programming` 模块之外的补充练习题，当前主要分成三类内容：

- 顶层单文件补充题，用于练习字符串、图、栈、树和简单模拟。
- `csp/` 目录，按第 `1` 次到第 `41` 次 CSP 认证届次归档练习入口。
- `gplt/` 目录，按年份归档 GPLT 赛题。

当前 `csp/` 下共有 `65` 个 `.cpp` 文件，其中 `31` 个文件已经补有实现，`34` 个文件仍保留为空 `main` 的练习入口或占位骨架。详细状态见 [csp/README.md](./csp/README.md)。

## 文件结构

| 路径 | 说明 |
|------|------|
| `abbreviation-check.cpp` | 缩写检查 |
| `bestAttract.cpp` | 最佳异性缘筛选 |
| `boss-time.cpp` | 老板空闲时间统计 |
| `chihuoguo.cpp` | 吃火锅文本检索 |
| `csp/` | CSP 赛题按题号归档 |
| `deliver_takeout.cpp` | 外卖配送路径统计 |
| `gplt/` | GPLT 赛题按年份归档 |
| `greedy_multi_round_selection.cpp` | 多轮推荐筛选 |
| `guacaipiao.cpp` | 刮彩票九宫格 |
| `nursing-center.cpp` | 养老院管理统计朴素版 |
| `nursing-center-plus.cpp` | 养老院管理统计维护计数版 |
| `nursing-center-pro.cpp` | 养老院管理统计树状数组版 |
| `qinshidangan.cpp` | 寝室档案二叉编号 |
| `random-fail.cpp` | 随机输赢策略模拟 |
| `safe-cell.cpp` | 安全格子统计 |
| `stack-calculator.cpp` | 堆栈计算器 |
| `stack_sequence_builder.cpp.cpp` | 栈辅助序列构造 |

## 核心内容

### 独立补充题

| 文件 | 题目 | 核心算法 | 复杂度 |
|------|------|----------|--------|
| `abbreviation-check.cpp` | 缩写检查 | 字符串扫描与规则比对 | `O(n)` |
| `bestAttract.cpp` | 最佳异性缘筛选 | Floyd 多源最短路 + 分组最小化最大距离 | `O(n^3)` |
| `boss-time.cpp` | 老板空闲时间统计 | 区间排序 + 空档扫描 | `O(n log n)` |
| `chihuoguo.cpp` | 吃火锅文本检索 | 整行读取 + 子串查找 | `O(L)` |
| `deliver_takeout.cpp` | 外卖配送路径统计 | 树上访问标记 + 深度抵扣 | `O(n + m)` |
| `greedy_multi_round_selection.cpp` | 多轮推荐筛选 | 分数分桶 + 贪心计数 | `O(n + R)` |
| `guacaipiao.cpp` | 刮彩票九宫格 | 缺失数字查找 + 固定规则映射 | `O(1)` |
| `nursing-center.cpp` | 养老院管理统计朴素版 | 祖先链逐个查询 | 查询 `O(Nh)` |
| `nursing-center-plus.cpp` | 养老院管理统计维护计数版 | 祖先链增减计数 | 查询 `O(1)`，转移 `O(h)` |
| `nursing-center-pro.cpp` | 养老院管理统计树状数组版 | DFS 序 + 树状数组 | `O((N + M) log V)` |
| `qinshidangan.cpp` | 寝室档案二叉编号 | 字符路径模拟完全二叉树编号 | `O(MN)` |
| `random-fail.cpp` | 随机输赢策略模拟 | 周期计数 + 石头剪刀布映射 | `O(t)` |
| `safe-cell.cpp` | 安全格子统计 | 行列去重标记 + 容斥统计 | `O(q + n + m)` |
| `stack-calculator.cpp` | 堆栈计算器 | 双栈模拟逆序计算 | `O(n)` |
| `stack_sequence_builder.cpp.cpp` | 栈辅助序列构造 | 栈 + 队列模拟 | `O(n)` |

### `csp/` 赛题归档

`csp/` 当前已经同时包含三种状态的文件：

- 早期 T1 练习入口：`csp/1/1.cpp` 到 `csp/14/1.cpp` 已经补有实现。
- 已实现的进阶题：如 `csp/22/2.cpp`、`csp/31/2.cpp`、`csp/35/2.cpp`、`csp/41/3.cpp` 等，继续保留在原届次目录下。
- 保留为空 `main` 的练习入口：`csp/1/2.cpp`、`csp/2/2.cpp`、`csp/3/2.cpp`、`csp/4/2.cpp`，以及 `csp/15/1.cpp` 到 `csp/41/1.cpp` 中的大部分 T1 文件，方便继续按 `cpp-learning/csp-100days` 自己重做。

代表性的当前实现包括：

| 文件 | 题目 | 核心算法 | 复杂度 |
|------|------|----------|--------|
| `csp/9/1.cpp` | 中间数 | 计数桶 + 小于大于数量平衡 | `O(n + V)` |
| `csp/10/1.cpp` | 分蛋糕 | 顺序分组 + 累计重量结算 | `O(n)` |
| `csp/11/1.cpp` | 打酱油 | 整除取模 + 优惠分组公式 | `O(1)` |
| `csp/12/1.cpp` | 最小差值 | 排序 + 相邻差值扫描 | `O(n log n)` |
| `csp/13/1.cpp` | 跳一跳 | 连续中心计分状态维护 | `O(n)` |
| `csp/14/1.cpp` | 卖菜 | 邻域平均 + 原数组与结果数组分离 | `O(n)` |
| `csp/22/2.cpp` | 邻域均值 | 二维前缀和 + 区域平均比较 | `O(n^2)` |
| `csp/31/2.cpp` | 坐标变换（其二） | 前缀缩放积 + 前缀旋转和 | `O(n + m)` |
| `csp/35/2.cpp` | 字符串变换 | 二进制倍增 + 映射复合 | `O(n + qL log k)` |
| `csp/41/3.cpp` | 消息队列区间分配模拟 | `set` / `map` 维护空闲段 + 循环发送 | `O(q log n)` |

更完整的届次状态、骨架列表和运行示例见 [csp/README.md](./csp/README.md)。

### `gplt/` 赛题归档

当前 `gplt/2026/` 已整理以下练习题：

| 文件 | 题目 | 核心算法 | 复杂度 |
|------|------|----------|--------|
| `gplt/2026/all-things-i-can.cpp` | 已出现未获赞编号筛选 | 布尔标记 + 顺序扫描 | `O(n + U)` |
| `gplt/2026/check-homework.cpp` | 作业检查分流 | 阈值分组 + 多轮筛选 | `O(n × 轮数)` |
| `gplt/2026/string-change.cpp` | 字符串变换操作 | 查找 / 插入 / 区间翻转 | `O(qL)` |
| `gplt/2026/traffic-monitoring.cpp` | 交通流量监控 | 统计最大最小平均值 + 异常筛选 | `O(n)` |

## 关键接口或算法说明

`csp/12/1.cpp` 当前写法是“排序后扫描相邻差值”，不是值域桶写法。代码先把数组排序，再维护当前最小相邻差值；一旦发现重复值，可以直接提前输出 `0`。

`csp/13/1.cpp` 用 `times` 记录连续跳到中心的次数。遇到 `1` 就把连续状态清零，遇到 `2` 时按 `2 * (++times)` 计入本次得分。

`csp/14/1.cpp` 把第一天价格放在 `first` 中，把第二天结果写到 `second` 中，避免边算边覆盖原值导致后续平均数被污染。

`csp/35/2.cpp` 把字符变换视作函数复合，先为每个字符预处理 `2^bit` 次后的结果，再按查询轮数的二进制位逐层跳转。

`csp/41/3.cpp` 维护“按左端点排序”的空闲区间映射和“按长度排序”的空闲区间集合，支持分配、删除合并和循环发送三类操作。

`cpp-learning/csp-100days`、`cpp-learning/csp-test-env/reference_solutions` 与这里的练习入口是两套配合关系：前者可以已经补齐题解或参考代码，后者仍然可能故意保留为空 `main`，用于自己重新实现。

## 运行方式

建议在仓库根目录编译。

```bash
g++ -std=c++11 programming/test/abbreviation-check.cpp -o test && ./test
g++ -std=c++11 programming/test/csp/12/1.cpp -o test && ./test
g++ -std=c++11 programming/test/csp/22/2.cpp -o test && ./test
g++ -std=c++11 programming/test/csp/35/2.cpp -o test && ./test
g++ -std=c++17 programming/test/csp/38/3.cpp -o test && ./test
g++ -std=c++11 programming/test/gplt/2026/string-change.cpp -o test && ./test
```

如果只想检查语法，不想生成可执行文件，可以直接使用：

```bash
g++ -std=c++11 -fsyntax-only programming/test/csp/13/1.cpp
g++ -std=c++11 -fsyntax-only programming/test/csp/14/1.cpp
```

## 注意事项

- `programming/test/csp` 下的很多文件是“练习入口”，文档已经补齐不等于该入口一定已经写完。
- `csp/1/2.cpp`、`csp/2/2.cpp`、`csp/3/2.cpp`、`csp/4/2.cpp` 以及 `csp/15/1.cpp` 之后的大量 T1 文件，当前都保留为空 `main`。
- `csp/38/3.cpp` 需要 `C++17` 编译，其余大多数文件按 `C++11` 即可。
- `random-fail.cpp` 虽然扩展名是 `.cpp`，但使用的是 C 风格输入输出，`gcc` 或 `g++` 都可以编译。
- 本地编译产物默认会被 `.gitignore` 忽略，建议只保留源码和文档。
