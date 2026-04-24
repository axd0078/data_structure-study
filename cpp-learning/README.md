# C++ 学习路线

## 模块简介

`cpp-learning` 目录用于整理面向刷题与算法学习的 C++ 分课讲义。当前包含 10 课 lesson 文档，覆盖从 C 到 C++ 的基础迁移、STL 容器、排序、映射与集合、前缀和、二分以及综合训练路线。

## 文件结构

| 目录 | 说明 |
|------|------|
| `lessons/` | 10 课 C++ 学习讲义 |
| `solution/` | 本地练习代码目录，默认不提交 |
| `README.md` | 当前目录说明 |

## 课程列表

| 文件 | 课程 | 核心内容 |
|------|------|----------|
| `lessons/lesson01-cpp-start.md` | 第 1 课：C 到 C++ 的最小迁移 | `iostream`、`string`、基础语法迁移 |
| `lessons/lesson02-io-and-string.md` | 第 2 课：输入输出与字符串处理 | 快速输入、`getline`、字符串基础 |
| `lessons/lesson03-vector-array.md` | 第 3 课：vector、数组替代与前缀和意识 | `vector`、数组建模、前缀和 |
| `lessons/lesson04-function-reference-struct.md` | 第 4 课：函数拆分、引用、struct 与记录类题目 | 函数拆分、引用、结构体 |
| `lessons/lesson05-stl-basic-containers.md` | 第 5 课：STL 基础容器、顺序维护与模拟 | `queue`、`stack`、`deque` 等容器 |
| `lessons/lesson06-sort-and-custom-compare.md` | 第 6 课：sort、比较器与多关键字排序 | `sort`、比较器、多关键字排序 |
| `lessons/lesson07-map-set-pair.md` | 第 7 课：pair、map、set 与计数建模 | `pair`、`map`、`set`、计数 |
| `lessons/lesson08-simulation-and-prefix-sum.md` | 第 8 课：模拟、前缀和与多步骤规则 | 模拟题拆解、前缀和 |
| `lessons/lesson09-search-and-binary-search.md` | 第 9 课：查找、二分与可行性判断 | 查找、二分、单调性 |
| `lessons/lesson10-comprehensive-practice-roadmap.md` | 第 10 课：综合训练路线 | 课程串联与阶段性训练建议 |

## 核心内容

前 4 课重点解决从 C 写法向 C++ 刷题写法迁移，包括输入输出、字符串、函数拆分、引用和 `struct`。

第 5 到第 7 课聚焦 STL 基础容器、排序、自定义比较器、`map` / `set` / `pair` 这些最常见的刷题工具。

第 8 到第 10 课把模拟、前缀和、二分查找和综合训练路线串起来，适合作为进入 `programming/` 和赛题目录前的过渡材料。

## 使用方式

这个目录本身以文档学习为主，没有统一可执行程序。建议按 `lesson01` 到 `lesson10` 的顺序阅读，再在本地 `solution/lessonX/` 下写对应练习代码并单文件编译。

## 注意事项

- `solution/` 目录用于本地练习，默认通过 `.gitignore` 忽略，不作为仓库正式源码统计的一部分。
- lessons 更偏向“刷题用 C++”而不是完整语言教程，重点放在比赛与练习中高频出现的语法和容器。
- 如果后续继续扩展课程，建议保持“lesson 编号 + 主题”的命名方式，方便按顺序阅读。
