# Day 8：STL 容器组合与索引设计

## 今日目标

把新题中的多实体关系拆成容器索引，避免用一堆散乱数组。

## 学习内容

- 每个容器服务一种查询，不要重复存无意义数据。
- 多容器同步修改时，更新动作集中成函数。
- 需要顺序和查找时常用 `vector + map`。

## 主练真题（第 21-41 次为主）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第26次 T3 角色授权](../csp-certification-problems/26-%E7%AC%AC26%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-133-%E8%A7%92%E8%89%B2%E6%8E%88%E6%9D%83.md) | 角色授权：多维映射。 |
| 2 | [第27次 T4 吉祥物投票](../csp-certification-problems/27-%E7%AC%AC27%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-139-%E5%90%89%E7%A5%A5%E7%89%A9%E6%8A%95%E7%A5%A8.md) | 吉祥物投票：候选与计数。 |
| 3 | [第33次 T4 十滴水](../csp-certification-problems/33-%E7%AC%AC33%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-169-%E5%8D%81%E6%BB%B4%E6%B0%B4.md) | 十滴水：状态集合。 |
| 4 | [第40次 T1 集合 (set)](../csp-certification-problems/40-%E7%AC%AC40%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/01-201-%E9%9B%86%E5%90%88%20%28set%29.md) | 集合：集合操作。 |
| 5 | [第41次 T3 进程通信（communicate）](../csp-certification-problems/41-%E7%AC%AC41%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-208-%E8%BF%9B%E7%A8%8B%E9%80%9A%E4%BF%A1%EF%BC%88communicate%EF%BC%89.md) | 进程通信：进程关系维护。 |

## 回顾真题（第 1-20 次补基础）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第10次 T2 学生排队](../csp-certification-problems/10-%E7%AC%AC10%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-052-%E5%AD%A6%E7%94%9F%E6%8E%92%E9%98%9F.md) | 学生排队：vector 位置操作。 |
| 2 | [第11次 T2 公共钥匙盒](../csp-certification-problems/11-%E7%AC%AC11%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-057-%E5%85%AC%E5%85%B1%E9%92%A5%E5%8C%99%E7%9B%92.md) | 公共钥匙盒：排序和状态容器。 |

## 验收标准

- 能独立复述题意和数据范围。
- 能说明使用的数据结构或算法为什么合适。
- 主练至少完成前三题，回顾题至少完成一题。

## 复盘记录

- 用时：
- 错因：
- 下次改进：
