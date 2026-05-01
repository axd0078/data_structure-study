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
