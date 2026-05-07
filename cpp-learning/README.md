# C++ 学习路线

## 模块简介

`cpp-learning` 目录用于整理面向刷题、CSP 认证和算法训练的 C++ 学习资料。当前内容由三部分组成：10 课基础讲义、`csp-100days` 的 100 天系统学习计划，以及配套的认证题库与本地测试环境。

## 文件结构

| 目录 | 说明 |
|------|------|
| `lessons/` | 10 课 C++ 基础与常用算法写法讲义 |
| `csp-100days/` | 100 天 CSP 系统学习计划，按 `day001.md` 到 `day100.md` 平铺整理 |
| `csp-certification-problems/` | CSP 认证题目题库资料，本地阅读用，默认忽略 |
| `csp-test-env/` | CSP 本地测试与参考环境，默认忽略 |
| `solution/` | 本地练习代码目录，默认忽略 |
| `README.md` | 当前目录说明 |

## 核心内容

`lessons/` 负责补齐从 C 到 C++ 的基础迁移，包括输入输出、字符串、`vector`、函数拆分、`struct`、STL 容器、排序、`map` / `set`、模拟、前缀和和二分等高频知识点。

`csp-100days/` 按 100 天拆分第 1-41 次 CSP 认证共 205 道题，当前先完成阶段划分、每日索引和题解占位，后续可以按某一天继续补充详细知识讲解、参考代码和本地测试环境。

`csp-certification-problems/` 和 `csp-test-env/` 用于存放本地题库资料、测试脚本和参考环境，适合作为配套资源，不纳入仓库正式源码统计。

## 使用方式

建议先按 `lessons/lesson01` 到 `lessons/lesson10` 的顺序补齐 C++ 基础，再进入 [csp-100days/README.md](./csp-100days/README.md) 按日推进 CSP 训练。

如果需要本地验证代码，可以在 `solution/` 下写练习程序，或在 `csp-test-env/` 中使用你已经准备好的测试环境与数据。

## 注意事项

- `solution/`、`csp-certification-problems/` 和 `csp-test-env/` 都按本地学习资料处理，已通过 `.gitignore` 忽略。
- `csp-100days/` 当前先维护逐日索引和题目分配，后续补题时建议继续沿用 `day001.md` 到 `day100.md` 的命名方式。
- 这个模块更偏向“刷题用 C++”和“认证训练资料”，不是完整的语言教材。
