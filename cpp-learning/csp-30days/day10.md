# Day 10：二分答案与单调性证明

## 今日目标

集中练第 21 次之后出现的“最小可行值/最大可行值”题型。

## 学习内容

- 先写 `check(x)`，再套二分。
- 二分方向由 `check(mid)` 的真假决定。
- 范围上界宁可保守一些，但复杂度必须能过。

## 主练真题（第 21-41 次为主）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第27次 T2 何以包邮？](../csp-certification-problems/27-%E7%AC%AC27%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-137-%E4%BD%95%E4%BB%A5%E5%8C%85%E9%82%AE%EF%BC%9F.md) | 何以包邮：可达金额。 |
| 2 | [第29次 T2 垦田计划](../csp-certification-problems/29-%E7%AC%AC29%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-147-%E5%9E%A6%E7%94%B0%E8%AE%A1%E5%88%92.md) | 垦田计划：最短工期。 |
| 3 | [第32次 T2 因子化简](../csp-certification-problems/32-%E7%AC%AC32%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-162-%E5%9B%A0%E5%AD%90%E5%8C%96%E7%AE%80.md) | 因子化简：指数阈值。 |
| 4 | [第40次 T2 数字变换 (transform)](../csp-certification-problems/40-%E7%AC%AC40%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-202-%E6%95%B0%E5%AD%97%E5%8F%98%E6%8D%A2%20%28transform%29.md) | 数字变换：阈值分析。 |

## 回顾真题（第 1-20 次补基础）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第09次 T2 工资计算](../csp-certification-problems/09-%E7%AC%AC09%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-047-%E5%B7%A5%E8%B5%84%E8%AE%A1%E7%AE%97.md) | 工资计算：反推答案。 |
| 2 | [第10次 T4 地铁修建](../csp-certification-problems/10-%E7%AC%AC10%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-054-%E5%9C%B0%E9%93%81%E4%BF%AE%E5%BB%BA.md) | 地铁修建：瓶颈路径。 |

## 验收标准

- 能独立复述题意和数据范围。
- 能说明使用的数据结构或算法为什么合适。
- 主练至少完成前三题，回顾题至少完成一题。

## 复盘记录

- 用时：
- 错因：
- 下次改进：
