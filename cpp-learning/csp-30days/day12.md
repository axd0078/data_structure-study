# Day 12：Markdown、模板与文本渲染

## 今日目标

新题里的模板/文本处理为主，旧 Markdown 题作为标准解析训练。

## 学习内容

- 先处理块级结构，再处理行内规则。
- 模板替换要保留未定义变量的题目规则。
- 输出格式建议集中到一个函数。

## 主练真题（第 21-41 次为主）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第34次 T3 文本分词](../csp-certification-problems/34-%E7%AC%AC34%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-173-%E6%96%87%E6%9C%AC%E5%88%86%E8%AF%8D.md) | 文本分词：规则拆解。 |
| 2 | [第37次 T3 模板展开](../csp-certification-problems/37-%E7%AC%AC37%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-188-%E6%A8%A1%E6%9D%BF%E5%B1%95%E5%BC%80.md) | 模板展开：变量作用域。 |
| 3 | [第39次 T3 HTTP 头信息](../csp-certification-problems/39-%E7%AC%AC39%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-198-HTTP%20%E5%A4%B4%E4%BF%A1%E6%81%AF.md) | HTTP 头信息：文本字段。 |
| 4 | [第40次 T3 图片解码 (decode)](../csp-certification-problems/40-%E7%AC%AC40%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-203-%E5%9B%BE%E7%89%87%E8%A7%A3%E7%A0%81%20%28decode%29.md) | 图片解码：编码文本到图像。 |

## 回顾真题（第 1-20 次补基础）

| 顺序 | 真题 | 训练重点 |
|---:|---|---|
| 1 | [第05次 T3 模板生成系统](../csp-certification-problems/05-%E7%AC%AC05%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-028-%E6%A8%A1%E6%9D%BF%E7%94%9F%E6%88%90%E7%B3%BB%E7%BB%9F.md) | 模板生成系统：变量替换。 |
| 2 | [第10次 T3 Markdown](../csp-certification-problems/10-%E7%AC%AC10%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-053-Markdown.md) | Markdown：块级解析。 |
| 3 | [第19次 T3 Markdown 渲染器](../csp-certification-problems/19-%E7%AC%AC19%E6%AC%A1CCF%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%BD%AF%E4%BB%B6%E8%83%BD%E5%8A%9B%E8%AE%A4%E8%AF%81/03-098-Markdown%20%E6%B8%B2%E6%9F%93%E5%99%A8.md) | Markdown 渲染器：完整渲染流程。 |

## 验收标准

- 能独立复述题意和数据范围。
- 能说明使用的数据结构或算法为什么合适。
- 主练至少完成前三题，回顾题至少完成一题。

## 复盘记录

- 用时：
- 错因：
- 下次改进：
