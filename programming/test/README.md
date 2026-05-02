# 编程补充题 (Programming Test)

## 模块简介

`programming/test` 目录用于存放补充练习题，和主目录下的综合题目相互补充。当前目录既保留单文件补充题，也包含按题号 / 年份归档的 CSP、GPLT 赛题。

## 文件结构

| 文件 | 说明 |
|------|------|
| `abbreviation-check.cpp` | 缩写检查 |
| `bestAttract.cpp` | 最佳异性缘筛选 |
| `boss-time.cpp` | 老板空闲时间统计 |
| `chihuoguo.cpp` | 吃火锅文本检索 |
| `csp/` | CSP 赛题按题号归档 |
| `deliver_takeout.cpp` | 外卖配送路径统计 |
| `gplt/` | GPLT 赛题练习按年份归档 |
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

## 题目列表

| 文件 | 题目 | 核心算法 | 复杂度 |
|------|------|----------|--------|
| `abbreviation-check.cpp` | 缩写检查 | 字符串扫描与规则比对 | `O(n)` |
| `bestAttract.cpp` | 最佳异性缘筛选 | Floyd 多源最短路 + 分组最小化最大距离 | `O(n^3)` |
| `boss-time.cpp` | 老板空闲时间统计 | 区间排序 + 空档扫描 | `O(n log n)` |
| `chihuoguo.cpp` | 吃火锅文本检索 | 整行读取 + 子串查找 | `O(L)` |
| `csp/1/1.cpp` | 相反数对统计 | 哈希集合查找相反数 | `O(n)` |
| `csp/1/2.cpp` | 窗口点击模拟 | 逆序查找顶层窗口 + 点击后置顶 | `O(nm)` |
| `csp/3/1.cpp` | 门禁系统计数输出 | 频次数组 + 即时输出 | `O(n)` |
| `csp/5/1.cpp` | 报数变化段计数 | 顺序扫描 + 相邻值比较 | `O(n)` |
| `csp/9/1.cpp` | 第 9 次 T1 题目骨架 | 当前仅保留输入输出模板 | `-` |
| `csp/21/1.cpp` | 安全指数加权求和 | 线性累加 + 与零取大 | `O(n)` |
| `csp/22/1.cpp` | 灰度直方图统计 | 频次数组统计 | `O(nm + L)` |
| `csp/23/1.cpp` | 数组推导上下界计算 | 顺序扫描 + 贪心累加 | `O(n)` |
| `csp/25/1.cpp` | 未初始化告警统计 | 状态标记 + 条件计数 | `O(k)` |
| `csp/27/1.cpp` | 混合进制位展开 | 累乘权重 + 逐位还原 | `O(n)` |
| `csp/29/1.cpp` | 矩形覆盖面积裁剪统计 | 区间裁剪 + 面积累加 | `O(n)` |
| `csp/33/1.cpp` | 编号归属与出现次数统计 | `unordered_map` + `unordered_set` 计数 | `O(元素总数)` |
| `csp/36/1.cpp` | 边界内指令移动 | 网格模拟 + 越界判断 | `O(操作串总长)` |
| `csp/36/2.cpp` | 前后缀最大值推导 | 前缀和 + 前后缀最大值 | `O(n)` |
| `csp/36/4.cpp` | 分层区间推进最少步数 | 类 BFS 分层扩展 + 贪心更新最远右端点 | `O(n)` |
| `csp/37/1.cpp` | 偶数点二次函数求和 | 枚举偶数点 + 直接代入 | `O((r-l)/2)` |
| `csp/38/1.cpp` | 百分比网格定位 | 直接公式映射 + 整数拆位 | `O(k)` |
| `csp/38/2.cpp` | 马步可达格子统计 | BFS 按步数扩展 + 去重访问 | `O(n^2)` |
| `csp/38/3.cpp` | 72 位短消息解码 | 位段拆分 + 进制逆解码 + 历史哈希表 | `O(n)` |
| `csp/39/1.cpp` | 蒙特卡洛估算圆周率 | 圆内点统计 | `O(n)` |
| `csp/39/2.cpp` | 阈值模板检测 | 固定模板扫描 + 差分标记 | `O(n^2 + L)` |
| `csp/40/1.cpp` | 集合异或校验 | 子集异或摘要 + 顺序比对 | `O(元素总数)` |
| `csp/40/2.cpp` | 9 位分组三段映射变换 | 预计算 512 状态 + 逆序应用变换参数 | `O(512m + n)` |
| `csp/40/3.cpp` | 字符矩阵旋转与翻转恢复 | 全局旋转映射 + 局部逆操作模拟 | `O(tZ^2)` |
| `csp/41/1.cpp` | 二进制平衡数统计 | 二进制位计数 | `O(n log V)` |
| `csp/41/2.cpp` | 咖啡时间优化 | 0/1 背包 + 分数贪心 | `O(m×普通任务数 + m×灵活任务数 log 灵活任务数)` |
| `csp/41/3.cpp` | 消息队列区间分配模拟 | `set` / `map` 维护空闲段 + 循环发送 | `O(q log n)` |
| `deliver_takeout.cpp` | 外卖配送路径统计 | 树上访问标记 + 深度抵扣 | `O(n + m)` |
| `gplt/2026/all-things-i-can.cpp` | 已出现未获赞编号筛选 | 布尔标记 + 顺序扫描 | `O(n + U)` |
| `gplt/2026/check-homework.cpp` | 作业检查分流 | 阈值分组 + 多轮筛选 | `O(n × 轮数)` |
| `gplt/2026/string-change.cpp` | 字符串变换操作 | 查找 / 插入 / 区间翻转 | `O(qL)` |
| `gplt/2026/traffic-monitoring.cpp` | 交通流量监控 | 统计最大最小平均值 + 异常筛选 | `O(n)` |
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

## 核心内容

`abbreviation-check.cpp` 用于判断一个以下划线分隔的字符串与其缩写是否匹配。核心做法是提取首字符以及每个下划线后的字符，再与目标缩写进行比较。

`bestAttract.cpp` 使用 Floyd 计算所有人之间的最短距离，再分别在女性和男性候选中选择对异性最大距离最小的编号集合。

`boss-time.cpp` 将忙碌时间段转换成秒数并按开始时间排序，通过相邻区间之间的空档输出老板的空闲时间。

`chihuoguo.cpp` 按行读取文本直到遇到 `.`，统计出现关键词 `chi1 huo3 guo1` 的总行数和首次出现位置。

`csp/` 目录按题号整理 CSP 赛题，当前包含相反数统计、窗口置顶、门禁系统、报数变化段计数、安全指数、灰度直方图、数组推导、未初始化告警、混合进制位展开、矩形覆盖面积裁剪统计、编号归属统计、边界内指令移动、前后缀最大值推导、分层区间推进最少步数、偶数点函数求和、百分比网格定位、马步可达格子统计、72 位短消息解码、蒙特卡洛估算圆周率、阈值模板检测、9 位分组三段映射变换、字符矩阵旋转与翻转恢复、集合异或校验、二进制平衡数统计、咖啡时间优化和消息队列区间分配模拟等题，详见 [csp/README.md](./csp/README.md)。

`csp/3/1.cpp` 读入刷卡序列后即时输出当前编号已经出现的次数，重点是边统计边输出，同时控制好首项与后续项之间的空格格式。

`csp/5/1.cpp` 顺序扫描整段报数记录，只要当前值和前一个值不同就把变化段数量加一，适合复盘“只看相邻状态变化”的线性统计题。

`csp/21/1.cpp` 直接累加每组安全得分与权重的乘积，最后再与 `0` 比较取较大值，属于线性求和题。

`csp/22/1.cpp` 把整张灰度图按值落到 `0..L-1` 的计数桶中，最后顺序输出直方图。

`csp/23/1.cpp` 顺序读取推导数组时同时维护可取上界和下界，当前实现直接给出总和上界与满足单调关系的最小累加值。

`csp/25/1.cpp` 通过布尔数组记录变量是否已经初始化，每次使用未初始化变量时累计告警次数。

`csp/27/1.cpp` 先构造各位权值的累乘数组，再从低位到高位依次还原每一位的取值，属于典型的混合进制展开题。

`csp/29/1.cpp` 把每个矩形和目标大矩形做裁剪，得到有效宽高后累加交面积，关键是把越界部分用 `max/min` 截掉。

`csp/33/1.cpp` 用 `unordered_map<int, unordered_set<int>>` 记录每个编号出现在哪些集合中，同时用计数数组统计总出现次数，最终输出“不同归属数 + 总出现次数”。

`csp/36/1.cpp` 在 `n x n` 网格内按 `f / b / l / r` 指令逐步移动，越界时保持原位置，属于直接模拟题。

`csp/36/2.cpp` 先构造前缀和数组，再分别维护前缀最大值和后缀最大值，对每个位置独立计算答案，适合复盘“前后缀拆分贡献”的写法。

`csp/36/4.cpp` 用“当前步数能覆盖到的最远右端点”做分层推进，每一层扫描新加入的位置并更新下一层最远可达范围，求最少步数或判定无解。

`csp/38/1.cpp` 先把输入值在线性区间中的相对位置换算为百分比，再映射到 `10 x 10` 网格中的行列编号，属于直接公式推导题。

`csp/38/2.cpp` 以起点为第一层做 BFS，每扩展一步就尝试 8 个马步方向，并用 `visited` 去重，最终统计不超过 `k` 步能到达的不同格子数。

`csp/38/3.cpp` 把 72 位消息按字段拆成接收方、发送方、位置和校验摘要，再结合 38 进制 / 混合进制逆解码与历史哈希表恢复短消息中的代码串。

`csp/40/2.cpp` 把每个 9 位状态拆成三段，围绕给定参数序列做逆序映射，并预先计算 `0..511` 所有状态的最终结果，之后直接查表输出。

`csp/40/3.cpp` 先把所有操作读入，再按逆序执行局部旋转和翻转恢复，同时用全局旋转状态统一映射当前坐标，最后截取非 `?` 区域输出。

`csp/41/3.cpp` 维护一组可分配的连续空闲区间，支持按长度分配新段、删除后与相邻空闲段合并，以及按进程中的多个循环队列依次发送并更新下一个位置。

`deliver_takeout.cpp` 在树形路径上维护已访问节点和节点深度，每次新增订单只统计新走过的边，并用最深节点抵扣最后一次返程距离。

`gplt/` 目录按年份整理 GPLT 练习题，当前 `2026/` 下包含编号筛选、作业分流、字符串操作和交通监控等模拟题，详见 [gplt/README.md](./gplt/README.md)。

`greedy_multi_round_selection.cpp` 按天梯赛分数段统计候选人数，并把 PAT 分数达到阈值的学生单独计入，最后按每个分数段最多 `k` 人的规则完成推荐人数统计。

`guacaipiao.cpp` 先补全九宫格中缺失的数字，再按用户选择的行、列或对角线求和并映射到对应奖金。

`nursing-center.cpp`、`nursing-center-plus.cpp` 和 `nursing-center-pro.cpp` 是同一类养老院管理统计题的三版实现，分别对应朴素祖先查询、维护祖先计数和 DFS 序 + 树状数组优化。

`qinshidangan.cpp` 把由 `y` / 非 `y` 字符组成的路径映射到完全二叉树编号，用于快速输出每条路径对应的档案位置。

`random-fail.cpp` 根据给定轮次周期决定何时故意输一局，其余轮次输出能赢当前手势的选择。

`safe-cell.cpp` 用布尔数组记录被攻击过的行和列，再用容斥关系从总格子数中扣除不安全格子，避免重复攻击造成重复扣减。

`stack-calculator.cpp` 将数字栈和运算符栈按输入顺序压栈，每次弹出两个数字和一个运算符执行 `n2 op n1`，遇到除数为 `0` 时按题目格式输出错误并终止。

`stack_sequence_builder.cpp.cpp` 使用队列表示传送带、栈表示辅助盒子，按非递增序列规则构造并输出每一条松枝。

## 运行方式

```bash
g++ -std=c++11 abbreviation-check.cpp -o test && ./test
g++ -std=c++11 bestAttract.cpp -o test && ./test
g++ -std=c++11 boss-time.cpp -o test && ./test
g++ -std=c++11 chihuoguo.cpp -o test && ./test
g++ -std=c++11 csp/1/1.cpp -o test && ./test
g++ -std=c++11 csp/1/2.cpp -o test && ./test
g++ -std=c++11 csp/3/1.cpp -o test && ./test
g++ -std=c++11 csp/21/1.cpp -o test && ./test
g++ -std=c++11 csp/22/1.cpp -o test && ./test
g++ -std=c++11 csp/23/1.cpp -o test && ./test
g++ -std=c++11 csp/25/1.cpp -o test && ./test
g++ -std=c++11 csp/36/1.cpp -o test && ./test
g++ -std=c++11 csp/36/4.cpp -o test && ./test
g++ -std=c++11 csp/37/1.cpp -o test && ./test
g++ -std=c++11 csp/38/1.cpp -o test && ./test
g++ -std=c++11 csp/38/2.cpp -o test && ./test
g++ -std=c++17 csp/38/3.cpp -o test && ./test
g++ -std=c++11 csp/39/1.cpp -o test && ./test
g++ -std=c++11 csp/39/2.cpp -o test && ./test
g++ -std=c++11 csp/40/1.cpp -o test && ./test
g++ -std=c++11 csp/40/2.cpp -o test && ./test
g++ -std=c++11 csp/40/3.cpp -o test && ./test
g++ -std=c++11 csp/41/1.cpp -o test && ./test
g++ -std=c++11 csp/41/2.cpp -o test && ./test
g++ -std=c++11 csp/41/3.cpp -o test && ./test
g++ -std=c++11 deliver_takeout.cpp -o test && ./test
g++ -std=c++11 gplt/2026/all-things-i-can.cpp -o test && ./test
g++ -std=c++11 gplt/2026/check-homework.cpp -o test && ./test
g++ -std=c++11 gplt/2026/string-change.cpp -o test && ./test
g++ -std=c++11 gplt/2026/traffic-monitoring.cpp -o test && ./test
g++ -std=c++11 greedy_multi_round_selection.cpp -o test && ./test
g++ -std=c++11 guacaipiao.cpp -o test && ./test
g++ -std=c++11 nursing-center.cpp -o test && ./test
g++ -std=c++11 nursing-center-plus.cpp -o test && ./test
g++ -std=c++11 nursing-center-pro.cpp -o test && ./test
g++ -std=c++11 qinshidangan.cpp -o test && ./test
gcc random-fail.cpp -o test && ./test
g++ -std=c++11 safe-cell.cpp -o test && ./test
g++ -std=c++11 stack-calculator.cpp -o test && ./test
g++ -std=c++11 stack_sequence_builder.cpp.cpp -o test && ./test
```

## 注意事项

- 每个题目的输入格式都由对应文件中的 `main` 决定，运行前建议先阅读源码。
- `bestAttract.cpp` 的边输入使用 `编号:距离` 形式，结果分两行输出女性和男性候选编号。
- `boss-time.cpp` 按 `HH:MM:SS - HH:MM:SS` 格式读取每个忙碌区间。
- `chihuoguo.cpp` 使用整行读取，适合处理包含空格的句子。
- `csp/` 中的题目按题号分目录保存，编译时需要带上相对路径。
- `csp/3/1.cpp` 当前改动重点是首个输出项不再额外补前导空格，适合复盘“边读边输”题目的格式控制。
- `csp/21/1.cpp` 中乘积和建议用 `long long`，再在最终输出前与 `0` 比较，避免负值直接输出。
- `csp/22/1.cpp` 的灰度值范围由 `L` 控制，计数数组长度应和输入上界保持一致。
- `csp/23/1.cpp` 当前实现一次遍历同时得到两类结果，复盘时重点看“总和上界”和“满足相邻关系的最小值”如何拆开维护。
- `csp/25/1.cpp` 只要目标变量在使用前未被标记初始化就计一次告警，之后仍然继续处理后续语句。
- `csp/27/1.cpp` 要先把每一位的权值乘积准备好，再用当前剩余值减去已还原部分，避免逐位回填时相互污染。
- `csp/29/1.cpp` 裁剪矩形时宽和高都要用 `max(0, ...)` 防止没有交集时出现负面积。
- `csp/33/1.cpp` 既要统计某编号总共出现了多少次，也要统计它出现于多少个不同集合，两个计数口径不能混用。
- `csp/36/1.cpp` 每次处理一条指令前都先判断新位置是否仍在棋盘内，适合复盘“允许撞边但不报错”的模拟写法。
- `csp/36/2.cpp` 当前实现依赖前缀和、前缀最大值和后缀最大值三组数组，复盘时重点看每个位置答案分别从哪一侧取最大值。
- `csp/36/4.cpp` 维护的是区间层而不是单点路径，`scanLeft` 只扫描上一层新加入的位置，可以避免重复遍历。
- `csp/38/1.cpp` 依赖输入区间宽度 `b` 做百分比换算，复盘时可以重点看“先线性映射、再拆成行列”的处理。
- `csp/38/2.cpp` 用队列按层扩展，`visited` 需要在入队时就标记，避免同一格子被重复统计。
- `csp/38/3.cpp` 里 12 位和 25 位哈希摘要都不能直接反推原串，必须按题意维护“最近出现代码”的历史表再做匹配。
- `csp/39/2.cpp` 的核心是先为每个 5×9 窗口计算合法阈值区间，再用差分数组统一恢复所有可行阈值。
- `csp/40/2.cpp` 先把全部 512 个状态的结果预处理出来，适合输入值范围固定且查询次数较多的题。
- `csp/40/3.cpp` 当前实现用一个全局旋转状态配合坐标映射，避免每次整体旋转整张矩阵。
- `csp/41/2.cpp` 同时使用 0/1 背包和按单位收益排序的分数贪心，适合复盘混合优化题。
- `csp/41/3.cpp` 同时维护按左端点排序和按长度排序的空闲区间，便于处理分配、删除合并和最短可用段查询。
- `deliver_takeout.cpp` 会随着订单逐步输出当前最短配送总路程。
- `gplt/` 中的题目按年份分目录保存，编译时需要带上相对路径。
- `guacaipiao.cpp` 的奖金映射由九宫格选择后的和值决定。
- `greedy_multi_round_selection.cpp` 中天梯赛分数段固定按 `175` 到 `290` 统计。
- `nursing-center-pro.cpp` 使用树状数组，下标必须保持从 `1` 开始。
- `qinshidangan.cpp` 按路径字符逐层更新完全二叉树中的节点编号。
- `random-fail.cpp` 虽然扩展名是 `.cpp`，但使用的是 C 风格输入输出，`gcc` 或 `g++` 都可编译。
- `safe-cell.cpp` 需要注意同一行或同一列被多次攻击时只能计算一次影响。
- `stack-calculator.cpp` 的除法判断分母是先弹出的 `n1`，错误输出中的分子是后弹出的 `n2`。
- `stack_sequence_builder.cpp.cpp` 文件名暂按当前源码保留，编译时请使用完整文件名。
- `csp/9/1.cpp` 当前仅保留空的 `main` 骨架，后续补题时建议同步补上题意、算法和运行示例。
- 如果后续继续扩展补充题，建议保持“一题一文件 + 当前 README 统一索引”的组织方式。
