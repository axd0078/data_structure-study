# Day 24：系统类大模拟

## 今日目标

新题中的系统模拟更接近当前 CSP 风格，要重点训练模块化。

## 学习内容

- 按命令类型拆函数。
- 状态对象集中管理，输出逻辑单独封装。
- 先通过样例，再补边界和非法输入。

## 主练真题（第 21-41 次为主）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第21次 T3 带配额的文件系统](../csp-certification-problems/21-%E7%AC%AC21%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-108-%E5%B8%A6%E9%85%8D%E9%A2%9D%E7%9A%84%E6%96%87%E4%BB%B6%E7%B3%BB%E7%BB%9F.md) | 带配额的文件系统：系统状态。 |
| 2 | [第24次 T4 磁盘文件操作](../csp-certification-problems/24-%E7%AC%AC24%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-124-%E7%A3%81%E7%9B%98%E6%96%87%E4%BB%B6%E6%93%8D%E4%BD%9C.md) | 磁盘文件操作：文件区间。 |
| 3 | [第25次 T3 计算资源调度器](../csp-certification-problems/25-%E7%AC%AC25%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-128-%E8%AE%A1%E7%AE%97%E8%B5%84%E6%BA%90%E8%B0%83%E5%BA%A6%E5%99%A8.md) | 计算资源调度器：调度系统。 |
| 4 | [第36次 T3 缓存模拟](../csp-certification-problems/36-%E7%AC%AC36%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-183-%E7%BC%93%E5%AD%98%E6%A8%A1%E6%8B%9F.md) | 缓存模拟：缓存系统。 |
| 5 | [第41次 T2 机器人项目管理（crashing）](../csp-certification-problems/41-%E7%AC%AC41%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-207-%E6%9C%BA%E5%99%A8%E4%BA%BA%E9%A1%B9%E7%9B%AE%E7%AE%A1%E7%90%86%EF%BC%88crashing%EF%BC%89.md) | 机器人项目管理：项目系统。 |

## 回顾真题（第 1-20 次补基础）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第15次 T3 CIDR 合并](../csp-certification-problems/15-%E7%AC%AC15%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-078-CIDR%20%E5%90%88%E5%B9%B6.md) | CIDR 合并：网络系统。 |
| 2 | [第16次 T4 消息传递接口](../csp-certification-problems/16-%E7%AC%AC16%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-084-%E6%B6%88%E6%81%AF%E4%BC%A0%E9%80%92%E6%8E%A5%E5%8F%A3.md) | 消息传递接口：通信模拟。 |

## 验收标准

- 能独立复述题意和数据范围。
- 能说明使用的数据结构或算法为什么合适。
- 主练至少完成前三题，回顾题至少完成一题。

## 复盘记录

- 用时：
- 错因：
- 下次改进：
