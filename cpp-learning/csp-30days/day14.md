# Day 14：BFS、DFS 与搜索建模

## 今日目标

新题里先找状态维度，再决定 BFS、DFS 或记忆化搜索。

## 学习内容

- BFS 入队即标记，避免重复。
- 状态可以包含位置、时间、方向、资源。
- 搜索前先估算状态总数。

## 主练真题（第 21-41 次为主）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第26次 T2 寻宝！大冒险！](../csp-certification-problems/26-%E7%AC%AC26%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-132-%E5%AF%BB%E5%AE%9D%EF%BC%81%E5%A4%A7%E5%86%92%E9%99%A9%EF%BC%81.md) | 寻宝！大冒险！：坐标匹配与搜索思维。 |
| 2 | [第32次 T3 树上搜索](../csp-certification-problems/32-%E7%AC%AC32%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-163-%E6%A0%91%E4%B8%8A%E6%90%9C%E7%B4%A2.md) | 树上搜索：树状态。 |
| 3 | [第36次 T2 梦境巡查](../csp-certification-problems/36-%E7%AC%AC36%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-182-%E6%A2%A6%E5%A2%83%E5%B7%A1%E6%9F%A5.md) | 梦境巡查：图上状态。 |
| 4 | [第36次 T4 跳房子](../csp-certification-problems/36-%E7%AC%AC36%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-184-%E8%B7%B3%E6%88%BF%E5%AD%90.md) | 跳房子：可达性。 |

## 回顾真题（第 1-20 次补基础）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第01次 T4 无线网络](../csp-certification-problems/01-%E7%AC%AC01%E6%AC%A1CCF%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-009-%E6%97%A0%E7%BA%BF%E7%BD%91%E7%BB%9C.md) | 无线网络：带约束搜索。 |
| 2 | [第02次 T4 最优配餐](../csp-certification-problems/02-%E7%AC%AC02%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-014-%E6%9C%80%E4%BC%98%E9%85%8D%E9%A4%90.md) | 最优配餐：多源 BFS。 |

## 验收标准

- 能独立复述题意和数据范围。
- 能说明使用的数据结构或算法为什么合适。
- 主练至少完成前三题，回顾题至少完成一题。

## 复盘记录

- 用时：
- 错因：
- 下次改进：
