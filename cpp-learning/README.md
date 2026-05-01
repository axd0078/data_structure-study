# C++ 学习路线

## 模块简介

`cpp-learning` 目录用于整理面向刷题、CSP 认证和算法训练的 C++ 学习资料。当前内容由三部分组成：10 课基础讲义、`csp-30days` 的 30 天复习计划，以及配套的认证题库与本地测试环境。

## 文件结构

| 目录 | 说明 |
|------|------|
| `lessons/` | 10 课 C++ 基础与常用算法写法讲义 |
| `csp-30days/` | 30 天 CSP 复习计划，按 `day1.md` 到 `day30.md` 平铺整理 |
| `csp-certification-problems/` | CSP 认证题目题库资料，本地阅读用，默认忽略 |
| `csp-test-env/` | CSP 本地测试与参考环境，默认忽略 |
| `solution/` | 本地练习代码目录，默认忽略 |
| `README.md` | 当前目录说明 |

## 核心内容

`lessons/` 负责补齐从 C 到 C++ 的基础迁移，包括输入输出、字符串、`vector`、函数拆分、`struct`、STL 容器、排序、`map` / `set`、模拟、前缀和和二分等高频知识点。

`csp-30days/` 把近几次 CSP 认证题按 30 天节奏拆成逐日训练清单，强调读题流程、T1/T2 稳定拿分、按题型复盘和阶段性整套模拟。

`csp-certification-problems/` 和 `csp-test-env/` 用于存放本地题库资料、测试脚本和参考环境，适合作为配套资源，不纳入仓库正式源码统计。

## 使用方式

建议先按 `lessons/lesson01` 到 `lessons/lesson10` 的顺序补齐 C++ 基础，再进入 [csp-30days/README.md](./csp-30days/README.md) 按日推进 CSP 训练。

如果需要本地验证代码，可以在 `solution/` 下写练习程序，或在 `csp-test-env/` 中使用你已经准备好的测试环境与数据。

## 注意事项

- `solution/`、`csp-certification-problems/` 和 `csp-test-env/` 都按本地学习资料处理，已通过 `.gitignore` 忽略。
- `csp-30days/` 已从原来的“按天建目录 + 子 README”整理为平铺的 `dayX.md` 文件，更适合连续阅读和快速跳转。
- 这个模块更偏向“刷题用 C++”和“认证训练资料”，不是完整的语言教材。
