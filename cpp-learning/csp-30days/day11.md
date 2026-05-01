# Day 11：中等模拟：事件流与时间线

## 今日目标

把新题 T2/T3 的长规则转成事件处理表。

## 学习内容

- 先列事件类型，再列每种事件的状态变化。
- 同一时间多事件要明确优先级。
- 复杂模拟先实现核心路径，再补异常分支。

## 主练真题（第 21-41 次为主）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第25次 T2 出行计划](../csp-certification-problems/25-%E7%AC%AC25%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-127-%E5%87%BA%E8%A1%8C%E8%AE%A1%E5%88%92.md) | 出行计划：时间窗口。 |
| 2 | [第25次 T3 计算资源调度器](../csp-certification-problems/25-%E7%AC%AC25%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-128-%E8%AE%A1%E7%AE%97%E8%B5%84%E6%BA%90%E8%B0%83%E5%BA%A6%E5%99%A8.md) | 计算资源调度器：资源分配。 |
| 3 | [第36次 T3 缓存模拟](../csp-certification-problems/36-%E7%AC%AC36%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-183-%E7%BC%93%E5%AD%98%E6%A8%A1%E6%8B%9F.md) | 缓存模拟：命中和替换。 |
| 4 | [第38次 T2 机器人复健指南](../csp-certification-problems/38-%E7%AC%AC38%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-192-%E6%9C%BA%E5%99%A8%E4%BA%BA%E5%A4%8D%E5%81%A5%E6%8C%87%E5%8D%97.md) | 机器人复健指南：动作序列。 |
| 5 | [第41次 T2 机器人项目管理（crashing）](../csp-certification-problems/41-%E7%AC%AC41%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/02-207-%E6%9C%BA%E5%99%A8%E4%BA%BA%E9%A1%B9%E7%9B%AE%E7%AE%A1%E7%90%86%EF%BC%88crashing%EF%BC%89.md) | 机器人项目管理：项目状态。 |

## 回顾真题（第 1-20 次补基础）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第08次 T3 炉石传说](../csp-certification-problems/08-%E7%AC%AC08%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-043-%E7%82%89%E7%9F%B3%E4%BC%A0%E8%AF%B4.md) | 炉石传说：角色状态。 |
| 2 | [第12次 T3 Crontab](../csp-certification-problems/12-%E7%AC%AC12%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-063-Crontab.md) | Crontab：时间表达式。 |

## 验收标准

- 能独立复述题意和数据范围。
- 能说明使用的数据结构或算法为什么合适。
- 主练至少完成前三题，回顾题至少完成一题。

## 复盘记录

- 用时：
- 错因：
- 下次改进：
