# GPLT 赛题练习

## 模块简介

`programming/test/gplt` 目录用于归档 GPLT 相关练习题，当前按年份组织。题目仍保持“一题一文件”的方式，便于单独编译、调试和复盘。

## 文件结构

| 目录 | 说明 |
|------|------|
| `2026/` | 2026 年 GPLT 练习题 |
| `README.md` | 当前目录说明 |

## 题目列表

| 文件 | 题目 | 核心算法 | 复杂度 |
|------|------|----------|--------|
| `2026/all-things-i-can.cpp` | 已出现未获赞编号筛选 | 布尔标记 + 顺序扫描 | `O(n + U)` |
| `2026/check-homework.cpp` | 作业检查分流 | 阈值分组 + 多轮筛选 | `O(n × 轮数)` |
| `2026/string-change.cpp` | 字符串变换操作 | 查找 / 插入 / 区间翻转 | `O(qL)` |
| `2026/traffic-monitoring.cpp` | 交通流量监控 | 统计最大最小平均值 + 异常筛选 | `O(n)` |

## 核心内容

`all-things-i-can.cpp` 使用两个布尔数组记录编号是否出现、是否被点赞，最后按编号升序输出出现过但未被点赞的编号。

`check-homework.cpp` 把当前待检查编号按阈值分成通过和未通过两组，未通过组继续用平均值更新阈值并进入下一轮筛选。

`string-change.cpp` 支持三类字符串操作：查找子串前三个出现位置、在指定位置插入字符串、翻转闭区间子串。

`traffic-monitoring.cpp` 统计交通流量的最大值、最小值和平均值，再输出超过平均值两倍的位置，否则输出 `Normal`。

## 运行方式

在 `programming/test` 目录下执行：

```bash
g++ -std=c++11 gplt/2026/all-things-i-can.cpp -o test && ./test
g++ -std=c++11 gplt/2026/check-homework.cpp -o test && ./test
g++ -std=c++11 gplt/2026/string-change.cpp -o test && ./test
g++ -std=c++11 gplt/2026/traffic-monitoring.cpp -o test && ./test
```

在仓库根目录下执行时，需要补全路径：

```bash
g++ -std=c++11 programming/test/gplt/2026/string-change.cpp -o test && ./test
```

## 注意事项

- `all-things-i-can.cpp` 当前按编号范围 `1..100000` 扫描，适合编号上界固定的题目。
- `check-homework.cpp` 会多轮处理未通过组，复盘时重点看阈值更新和数组清空顺序。
- `string-change.cpp` 的查找操作从上一次命中位置后一位继续，允许发现重叠匹配。
- `traffic-monitoring.cpp` 使用整数平均值，异常判断条件是严格大于平均值的两倍。
