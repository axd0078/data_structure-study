# 学习总结 (Summary)

## 模块简介

`summary` 目录用于存放学习过程中的笔记、经验总结和编码规范提醒，和各数据结构模块形成互补。

## 文件结构

| 文件 | 说明 |
|------|------|
| `ladder_input_output_guide.md` | 天梯赛常用输入输出函数总结 |
| `null_pointer_check_guide.md` | 空指针检查指南 |
| `programming_problem_solving_guide.md` | 程序设计题按算法类型分类的解题思路总结 |

## 当前内容

`null_pointer_check_guide.md` 围绕 C 语言指针安全展开，重点总结：

- 什么时候必须判空
- 公共 API 入口如何做防御性检查
- 递归、资源释放和链式访问中的常见判空模式
- 基于线索二叉树实现总结出的实际经验

`programming_problem_solving_guide.md` 补充了 `programming` 目录中程序设计题的分类解题思路，重点总结：

- 双指针、二分、动态规划、图搜索、贪心等常见算法类型的适用信号
- 不同题型的建模方式、解题步骤和易错点
- 综合题中如何把业务描述转成区间、图、树、栈队列或动态统计问题
- 树上子树统计问题中从朴素查询到 DFS 序 + 树状数组的优化思路

`ladder_input_output_guide.md` 总结了天梯赛中 C、C++、Python 常用输入输出写法，重点总结：

- 不同数据形态应该选择哪种输入函数或读取方式
- C/C++/Python 中普通数字、整行字符串、EOF、大量数据和固定格式的读法
- 小数、数组、多行结果等常见输出格式
- `getline`、`%c`、含空格字符串和 Python 大输入的常见坑

## 阅读方式

该目录以 Markdown 笔记为主，不包含需要编译的源码文件。可以直接打开对应文档阅读：

- `ladder_input_output_guide.md`
- `null_pointer_check_guide.md`
- `programming_problem_solving_guide.md`

## 学习建议

- 适合在刷链表、树、图等指针密集题目前后配合阅读。
- 适合在复习 `programming` 目录中的综合编程题时，先按算法类型定位解题方向。
- 适合在天梯赛刷题前快速复习 C、C++、Python 的输入输出模板。
- 如果后续新增新的工程经验或踩坑记录，建议继续按主题在本目录沉淀文档。
