# Day 17：动态规划入门：状态定义

## 今日目标

用新题中的选择问题练状态定义，旧题补经典 DP 直觉。

## 学习内容

- 先定义 `dp` 含义，再写转移。
- 初始化和边界比转移更容易错。
- 先用小数据手推，再写代码。

## 主练真题（第 21-41 次为主）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第27次 T2 何以包邮？](../csp-certification-problems/27-%E7%AC%AC27%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-137-%E4%BD%95%E4%BB%A5%E5%8C%85%E9%82%AE%EF%BC%9F.md) | 何以包邮：背包入门。 |
| 2 | [第28次 T2 训练计划](../csp-certification-problems/28-%E7%AC%AC28%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-142-%E8%AE%AD%E7%BB%83%E8%AE%A1%E5%88%92.md) | 训练计划：时间依赖。 |
| 3 | [第28次 T4 聚集方差](../csp-certification-problems/28-%E7%AC%AC28%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-144-%E8%81%9A%E9%9B%86%E6%96%B9%E5%B7%AE.md) | 聚集方差：状态优化。 |
| 4 | [第37次 T5 收费标准评估](../csp-certification-problems/37-%E7%AC%AC37%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/05-190-%E6%94%B6%E8%B4%B9%E6%A0%87%E5%87%86%E8%AF%84%E4%BC%B0.md) | 收费标准评估：决策 DP。 |

## 回顾真题（第 1-20 次补基础）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第05次 T5 最佳文章](../csp-certification-problems/05-%E7%AC%AC05%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/05-030-%E6%9C%80%E4%BD%B3%E6%96%87%E7%AB%A0.md) | 最佳文章：文本 DP。 |
| 2 | [第09次 T4 压缩编码](../csp-certification-problems/09-%E7%AC%AC09%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-049-%E5%8E%8B%E7%BC%A9%E7%BC%96%E7%A0%81.md) | 压缩编码：区间/代价 DP。 |

## 验收标准

- 能独立复述题意和数据范围。
- 能说明使用的数据结构或算法为什么合适。
- 主练至少完成前三题，回顾题至少完成一题。

## 复盘记录

- 用时：
- 错因：
- 下次改进：
