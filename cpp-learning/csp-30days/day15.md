# Day 15：最短路、生成树与图论基础

## 今日目标

新题以图建模为主，旧题用于复习 MST、最短路模板。

## 学习内容

- 边权全 1 用 BFS，非负权用 Dijkstra。
- 连通所有点且代价最小用最小生成树。
- 先确定图的点和边，再写算法。

## 主练真题（第 21-41 次为主）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第28次 T5 星际网络](../csp-certification-problems/28-%E7%AC%AC28%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/05-145-%E6%98%9F%E9%99%85%E7%BD%91%E7%BB%9C.md) | 星际网络：图模型。 |
| 2 | [第29次 T4 星际网络II](../csp-certification-problems/29-%E7%AC%AC29%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-149-%E6%98%9F%E9%99%85%E7%BD%91%E7%BB%9CII.md) | 星际网络II：复杂图。 |
| 3 | [第30次 T4 电力网络](../csp-certification-problems/30-%E7%AC%AC30%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-154-%E7%94%B5%E5%8A%9B%E7%BD%91%E7%BB%9C.md) | 电力网络：网络连通。 |
| 4 | [第32次 T4 宝藏](../csp-certification-problems/32-%E7%AC%AC32%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-164-%E5%AE%9D%E8%97%8F.md) | 宝藏：图上优化。 |
| 5 | [第40次 T5 数据抢修 (repair)](../csp-certification-problems/40-%E7%AC%AC40%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/05-205-%E6%95%B0%E6%8D%AE%E6%8A%A2%E4%BF%AE%20%28repair%29.md) | 数据抢修：图上抢修。 |

## 回顾真题（第 1-20 次补基础）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第03次 T4 最优灌溉](../csp-certification-problems/03-%E7%AC%AC03%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-019-%E6%9C%80%E4%BC%98%E7%81%8C%E6%BA%89.md) | 最优灌溉：最小生成树。 |
| 2 | [第08次 T4 交通规划](../csp-certification-problems/08-%E7%AC%AC08%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-044-%E4%BA%A4%E9%80%9A%E8%A7%84%E5%88%92.md) | 交通规划：最短路树。 |

## 验收标准

- 能独立复述题意和数据范围。
- 能说明使用的数据结构或算法为什么合适。
- 主练至少完成前三题，回顾题至少完成一题。

## 复盘记录

- 用时：
- 错因：
- 下次改进：
