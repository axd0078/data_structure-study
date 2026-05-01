# Day 20：区间修改与高级数据结构

## 今日目标

用第 21 次之后的区间/文件操作题建立线段树和懒标记意识。

## 学习内容

- 离线批量修改用差分，在线修改查询用树状数组或线段树。
- 线段树节点保存区间信息，懒标记延迟下传。
- 先写朴素版对拍，再替换数据结构。

## 主练真题（第 21-41 次为主）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第24次 T4 磁盘文件操作](../csp-certification-problems/24-%E7%AC%AC24%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-124-%E7%A3%81%E7%9B%98%E6%96%87%E4%BB%B6%E6%93%8D%E4%BD%9C.md) | 磁盘文件操作：区间状态。 |
| 2 | [第27次 T4 吉祥物投票](../csp-certification-problems/27-%E7%AC%AC27%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-139-%E5%90%89%E7%A5%A5%E7%89%A9%E6%8A%95%E7%A5%A8.md) | 吉祥物投票：区间统计。 |
| 3 | [第33次 T4 十滴水](../csp-certification-problems/33-%E7%AC%AC33%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-169-%E5%8D%81%E6%BB%B4%E6%B0%B4.md) | 十滴水：区间影响。 |
| 4 | [第35次 T4 通讯延迟](../csp-certification-problems/35-%E7%AC%AC35%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-179-%E9%80%9A%E8%AE%AF%E5%BB%B6%E8%BF%9F.md) | 通讯延迟：区间传播。 |

## 回顾真题（第 1-20 次补基础）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第11次 T5 除法](../csp-certification-problems/11-%E7%AC%AC11%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/05-060-%E9%99%A4%E6%B3%95.md) | 除法：区间查询。 |
| 2 | [第14次 T4 再卖菜](../csp-certification-problems/14-%E7%AC%AC14%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-074-%E5%86%8D%E5%8D%96%E8%8F%9C.md) | 再卖菜：区间约束。 |

## 验收标准

- 能独立复述题意和数据范围。
- 能说明使用的数据结构或算法为什么合适。
- 主练至少完成前三题，回顾题至少完成一题。

## 复盘记录

- 用时：
- 错因：
- 下次改进：
