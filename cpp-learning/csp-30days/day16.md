# Day 16：依赖关系、拓扑与调度

## 今日目标

重点练第 25 次之后的资源调度和依赖题。

## 学习内容

- 节点表示任务/资源/进程，边表示依赖。
- 拓扑排序从入度为 0 的点开始。
- 调度题要分清“可执行”和“最优选择”。

## 主练真题（第 21-41 次为主）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第25次 T3 计算资源调度器](../csp-certification-problems/25-%E7%AC%AC25%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-128-%E8%AE%A1%E7%AE%97%E8%B5%84%E6%BA%90%E8%B0%83%E5%BA%A6%E5%99%A8.md) | 计算资源调度器：资源约束。 |
| 2 | [第34次 T4 货物调度](../csp-certification-problems/34-%E7%AC%AC34%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/04-174-%E8%B4%A7%E7%89%A9%E8%B0%83%E5%BA%A6.md) | 货物调度：依赖调度。 |
| 3 | [第35次 T3 补丁应用](../csp-certification-problems/35-%E7%AC%AC35%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-178-%E8%A1%A5%E4%B8%81%E5%BA%94%E7%94%A8.md) | 补丁应用：依赖顺序。 |
| 4 | [第41次 T3 进程通信（communicate）](../csp-certification-problems/41-%E7%AC%AC41%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-208-%E8%BF%9B%E7%A8%8B%E9%80%9A%E4%BF%A1%EF%BC%88communicate%EF%BC%89.md) | 进程通信：通信依赖。 |

## 回顾真题（第 1-20 次补基础）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第01次 T5 任务调度](../csp-certification-problems/01-%E7%AC%AC01%E6%AC%A1CCF%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/05-010-%E4%BB%BB%E5%8A%A1%E8%B0%83%E5%BA%A6.md) | 任务调度：基础依赖。 |
| 2 | [第20次 T3 点亮数字人生](../csp-certification-problems/20-%E7%AC%AC20%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-103-%E7%82%B9%E4%BA%AE%E6%95%B0%E5%AD%97%E4%BA%BA%E7%94%9F.md) | 点亮数字人生：电路依赖。 |

## 验收标准

- 能独立复述题意和数据范围。
- 能说明使用的数据结构或算法为什么合适。
- 主练至少完成前三题，回顾题至少完成一题。

## 复盘记录

- 用时：
- 错因：
- 下次改进：
