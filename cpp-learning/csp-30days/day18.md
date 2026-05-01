# Day 18：背包、区间 DP 与状态压缩

## 今日目标

新题为主训练高维状态，旧题用于对照基本背包和区间 DP。

## 学习内容

- 0/1 背包容量倒序，完全背包容量正序。
- 区间 DP 常按长度枚举。
- 看到 n 小于 25，要考虑状压。

## 主练真题（第 21-41 次为主）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第28次 T4 聚集方差](../csp-certification-problems/28-%E7%AC%AC28%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-144-%E8%81%9A%E9%9B%86%E6%96%B9%E5%B7%AE.md) | 聚集方差：区间/统计优化。 |
| 2 | [第31次 T5 阻击](../csp-certification-problems/31-%E7%AC%AC31%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/05-160-%E9%98%BB%E5%87%BB.md) | 阻击：状态压缩。 |
| 3 | [第32次 T5 彩色路径](../csp-certification-problems/32-%E7%AC%AC32%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/05-165-%E5%BD%A9%E8%89%B2%E8%B7%AF%E5%BE%84.md) | 彩色路径：路径状态 DP。 |
| 4 | [第35次 T5 木板切割](../csp-certification-problems/35-%E7%AC%AC35%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/05-180-%E6%9C%A8%E6%9D%BF%E5%88%87%E5%89%B2.md) | 木板切割：切割决策。 |

## 回顾真题（第 1-20 次补基础）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第14次 T5 线性递推式](../csp-certification-problems/14-%E7%AC%AC14%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/05-075-%E7%BA%BF%E6%80%A7%E9%80%92%E6%8E%A8%E5%BC%8F.md) | 线性递推式：递推优化。 |
| 2 | [第15次 T5 管道清洁](../csp-certification-problems/15-%E7%AC%AC15%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/05-080-%E7%AE%A1%E9%81%93%E6%B8%85%E6%B4%81.md) | 管道清洁：综合 DP。 |

## 验收标准

- 能独立复述题意和数据范围。
- 能说明使用的数据结构或算法为什么合适。
- 主练至少完成前三题，回顾题至少完成一题。

## 复盘记录

- 用时：
- 错因：
- 下次改进：
