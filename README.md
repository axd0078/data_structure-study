# 数据结构学习代码（顺序表 + 链表 + 栈 + 队列 + 字符串）

本仓库是一个 **C/C++ 风格的数据结构刷题与练习集合**，核心围绕：

- 顺序表（`sqList/`）
- 单链表（`linkList/`）
- 栈（`stack/`）
- 队列（`queue/`）
- 字符串（`string/`）

代码特点：

- 每个题目大多是独立的 `*.cpp` 文件，内含 `main` 测试入口；
- 顺序表题目统一复用 `sqList/dynamic.h` 中的动态顺序表实现；
- 链表题目复用 `linkList/head.h` 中的带头结点单链表工具函数；
- 栈包含顺序栈和链栈两种实现；
- 队列包含顺序队列和链队列两种实现；
- 字符串部分包含基础串匹配算法（朴素、KMP）及改进的 NextVal 算法；
- 注释较多，强调"指针移动逻辑"和"就地修改"思路。

---

## 目录结构

```text
.
├── README.md
├── LICENSE
├── sqList
│   ├── dynamic.h        # 动态顺序表定义与基础操作
│   ├── static.cpp       # 静态顺序表实现示例
│   ├── 1.cpp ~ 15.cpp   # 顺序表题目练习
├── linkList
│   ├── head.h           # 带头结点单链表定义与基础操作
│   ├── nohead.h         # 无头结点结构草稿
│   ├── 1.cpp ~ 5.cpp    # 链表基础题
│   └── 17.cpp ~ 20.cpp  # 链表进阶题
├── stack
│   ├── sequence
│   │   └── stack.h      # 顺序栈实现
│   ├── link
│   │   └── stack.h      # 链栈实现
│   ├── eval.cpp         # 表达式求值（栈应用）
│   └── kuohao.cpp       # 括号匹配（栈应用）
├── queue
│   ├── sequence.h       # 顺序队列实现
│   └── link.h           # 链队列实现
└── string
    ├── string.h         # 字符串定义与 KMP 算法
    └── test_kmp.c       # KMP 算法测试示例
```

---

## 如何运行

> 说明：每个 `*.cpp` 基本都自带 `main`，因此请"单文件编译运行"，不要一次性把多个题目文件链接到同一个可执行程序。

### 1）运行某个顺序表题目

```bash
g++ -std=c++11 sqList/6.cpp -o /tmp/sq6 && /tmp/sq6
```

### 2）运行某个链表题目

```bash
g++ -std=c++11 linkList/20.cpp -o /tmp/ll20 && /tmp/ll20
```

### 3）运行栈应用示例

```bash
g++ -std=c++11 stack/eval.cpp -o /tmp/eval && /tmp/eval
g++ -std=c++11 stack/kuohao.cpp -o /tmp/kuohao && /tmp/kuohao
```

### 4）运行字符串算法测试

```bash
gcc string/test_kmp.c -o /tmp/kmp && /tmp/kmp
```

---

## 公共基础代码解析

### `sqList/dynamic.h`（动态顺序表）

实现了顺序表基础能力：

- `initList()`：创建表，默认容量 `INITSIZE=15`
- `expandList()`：扩容（复制旧数据到新空间）
- `listInsert()`：按 1-based 位置插入
- `listDelete()`：按 1-based 位置删除
- `listSearch()`：查找元素（返回位置，找不到返回 0）
- `listPrint()`：打印当前元素

> 备注：该头文件中同时包含声明与实现，练习代码可直接 `#include "dynamic.h"` 使用。

### `linkList/head.h`（带头结点单链表）

实现了链表的常见基础操作：

- 初始化：`initLinkList`
- 插入：按位置插入、按节点后插、按节点前插
- 删除：按位置删、按节点删
- 查询：`getLen`、`getElem`、`locateElem`
- 构造：`creatListTail`（尾插建表）

这套工具是 `linkList/*.cpp` 题目的公共依赖。

### `stack/sequence/stack.h`（顺序栈）

实现了顺序栈（静态数组）基础操作：

- `initStack()`：初始化栈
- `isEmpty()`：判断栈是否为空
- `push()`：入栈
- `pop()`：出栈
- `getTop()`：获取栈顶元素
- `destroyStack()`：销毁栈（使用二级指针）
- `getStackLength()`：获取栈长度
- `clearStack()`：清空栈

### `stack/link/stack.h`（链栈）

实现了链栈（带头结点）基础操作：

- `initStack()`：初始化栈
- `isEmptyStack()`：判断栈是否为空
- `pushStack()`：入栈
- `popStack()`：出栈
- `getTopStack()`：获取栈顶元素
- `destroyStack()`：销毁栈

### `queue/sequence.h`（顺序队列）

实现了顺序队列（循环数组）基础操作：

- `initQueue()`：初始化队列
- `isEmptyQueue()`：判断队列是否为空
- `pushQueue()`：入队
- `popQueue()`：出队
- `getTopQueue()`：获取队头元素

### `queue/link.h`（链队列）

实现了链队列（带头结点）基础操作：

- `initQueue()`：初始化队列
- `isEmptyQueue()`：判断队列是否为空
- `pushQueue()`：入队
- `popQueue()`：出队
- `getTopQueue()`：获取队头元素

### `string/string.h`（字符串与 KMP 算法）

实现了字符串基础操作与 KMP 模式匹配：

- `Index()`：朴素串匹配算法（Brute‑Force）
- `getNext()`：计算 KMP 算法的 next 数组（下标从 0 开始）
- `getNextVal()`：计算改进的 nextval 数组（相同字符跳转优化）

---

## 顺序表题目总览（`sqList/`）

| 文件 | 主题 | 核心思路 |
|---|---|---|
| `1.cpp` | 删除最小元素 | 线性扫描最小值，末元素覆盖该位置，长度减一 |
| `2.cpp` | 就地逆置 | 首尾双指针交换 |
| `3.cpp` | 删除指定值 | 快慢指针压缩保留区 |
| `4.cpp` | 删除区间值 `[s,t]` | 统计删除数并前移非删除元素 |
| `5.cpp` | 有序表去重 | 双指针保留不同值 |
| `6.cpp` | 合并两个有序表 | 临时备份 + 双路归并 |
| `7.cpp` | 数组分段交换 | 三次逆置（整体逆置 + 局部逆置） |
| `8.cpp` | 有序表插入/命中替换 | 顺序定位插入点；命中则与后继交换 |
| `9.cpp` | 三数组公共元素 | 三指针推进，按最大值对齐 |
| `10.cpp` | 顺序表循环左移 | 复用三次逆置思想 |
| `11.cpp` | 两有序表中位数 | 归并过程定位第 `ceil((m+n)/2)` 项 |
| `12.cpp` | 主元素（多数元素） | 计数数组判定是否超过 `n/2` |
| `13.cpp` | 最小缺失正整数 | 辅助标记数组 `flags` |
| `14.cpp` | 三数组最小距离 | 三指针 + 每轮移动当前最小值所在指针 |
| `15.cpp` | 对每个 `i` 求 `a[i]*a[j]` 最大值（`j>=i`） | 反向维护后缀 `min/max` |
| `static.cpp` | 静态顺序表基础操作 | 固定容量版本增删查 |

---

## 链表题目总览（`linkList/`）

| 文件 | 主题 | 核心思路 |
|---|---|---|
| `1.cpp` | 删除值为 `x` 的节点 | 前驱指针遍历，命中即摘链释放 |
| `2.cpp` | 删除最小值节点 | 记录"最小节点前驱"，一次遍历后删除 |
| `3.cpp` | 链表逆置 | 头插法逆置 + 三指针逆置（两种实现） |
| `4.cpp` | 删除区间 `[x,y]` 节点 | 前驱指针 + 条件删链 |
| `5.cpp` | 判断并找到相交节点 | 长链先走差值步，再同步前进 |
| `17.cpp` | 找倒数第 `k` 个节点值 | 快慢指针（快指针先走 `k` 步） |
| `18.cpp` | 相交节点（与 `5.cpp` 同型） | 长度对齐 + 同步扫描 |
| `19.cpp` | 删除绝对值重复节点 | `flags[abs(x)]` 标记去重 |
| `20.cpp` | 重排链表（前后交替） | 快慢指针找中点 + 后半逆置 + 交叉插入 |
| `nohead.h` | 无头结点定义草稿 | 结构声明（未配套完整操作） |

---

## 栈实现总览（`stack/`）

### 顺序栈（`sequence/stack.h`）

| 函数 | 功能 |
|---|---|
| `initStack()` | 初始化顺序栈 |
| `isEmpty()` | 判断栈是否为空 |
| `push()` | 入栈 |
| `pop()` | 出栈 |
| `getTop()` | 获取栈顶元素 |
| `destroyStack()` | 销毁栈 |
| `getStackLength()` | 获取栈长度 |
| `clearStack()` | 清空栈 |

### 链栈（`link/stack.h`）

| 函数 | 功能 |
|---|---|
| `initStack()` | 初始化链栈 |
| `isEmptyStack()` | 判断栈是否为空 |
| `pushStack()` | 入栈 |
| `popStack()` | 出栈 |
| `getTopStack()` | 获取栈顶元素 |
| `destroyStack()` | 销毁栈 |

---

## 栈应用示例（`stack/`）

### 表达式求值（`eval.cpp`）

实现了完整的表达式求值系统，包含两个核心函数：

| 函数 | 功能 | 说明 |
|---|---|---|
| `makeExpression()` | 中缀转后缀 | 将中缀表达式转换为后缀表达式（逆波兰表示法） |
| `eval()` | 后缀表达式求值 | 计算后缀表达式的值 |

**核心算法**：
1. **中缀转后缀**：使用运算符栈，根据优先级处理括号和运算符
2. **后缀求值**：使用操作数栈，遇到运算符时弹出两个操作数计算

### 括号匹配（`kuohao.cpp`）

检查括号 `()`、`[]`、`{}` 是否匹配正确。

---

## 测试用例（`eval.cpp` 内置）

`eval.cpp` 文件中包含完整的测试代码，可直接运行测试多种表达式：

```cpp
// 测试用例包括：
testExpression("1+2");                   // 简单表达式
testExpression("123+456");               // 多位数加法  
testExpression("(1+2)*3");               // 括号运算
testExpression("(123+456)*789");         // 多位数和括号
testExpression("12*(34+56)");            // 括号内多位数
testExpression("((100-50)*2)/10");       // 嵌套括号
testExpression("3+4*2/(1-5)");           // 复杂表达式（含负数除法）
```

**运行测试**：
```bash
cd stack
g++ -std=c++11 eval.cpp -o eval_test
./eval_test
```

**预期输出**：
- 显示每个测试表达式
- 显示转换后的后缀表达式
- 显示计算结果

---

## 队列实现总览（`queue/`）

### 顺序队列（`sequence.h`）

| 函数 | 功能 |
|---|---|
| `initQueue()` | 初始化顺序队列 |
| `isEmptyQueue()` | 判断队列是否为空 |
| `pushQueue()` | 入队 |
| `popQueue()` | 出队 |
| `getTopQueue()` | 获取队头元素 |

### 链队列（`link.h`）

| 函数 | 功能 |
|---|---|
| `initQueue()` | 初始化链队列 |
| `isEmptyQueue()` | 判断队列是否为空 |
| `pushQueue()` | 入队 |
| `popQueue()` | 出队 |
| `getTopQueue()` | 获取队头元素 |

---

## 字符串算法总览（`string/`）

| 文件 | 功能 | 核心思路 |
|---|---|---|
| `string.h` | 字符串结构定义、KMP 算法实现 | 朴素匹配、next 数组、nextval 优化 |
| `test_kmp.c` | KMP 算法测试 | 验证 next 与 nextval 数组的正确性 |

---

## 重点题（推荐优先理解）

结合代码复杂度和技巧性，建议重点看：

- 顺序表：`11.cpp`（中位数归并思想）、`12.cpp`（主元素）、`14.cpp`（三指针最小距离）、`15.cpp`（后缀 min/max）
- 链表：`20.cpp`（链表重排，包含找中点 + 逆置 + 合并）
- 栈：`eval.cpp`（表达式求值，综合运用双栈）、`kuohao.cpp`（括号匹配）
- 字符串：`getNext()` 与 `getNextVal()`（KMP 核心）

---

## 学习路径建议

1. 先看基础容器实现：`sqList/dynamic.h`、`linkList/head.h`、`stack/sequence/stack.h`、`stack/link/stack.h`、`queue/sequence.h`、`queue/link.h`
2. 顺序表部分按难度：`2 -> 3/4 -> 5/6 -> 7/10 -> 11/14/15`
3. 链表部分按难度：`1/4 -> 2/3 -> 17 -> 5/18 -> 20`
4. 栈部分：顺序栈和链栈可并行学习，理解栈的"后进先出"特性，重点看两个应用示例
5. 队列部分：对照栈学习，理解"先进先出"特性，对比顺序/链式实现的差异
6. 字符串部分：先理解朴素匹配，再学习 KMP 的 next 数组构造思想，最后理解 nextval 优化
7. 对每个题目，重点追踪：
   - 循环不变量（当前已处理区间是什么）
   - 指针含义（谁是前驱、谁会移动、谁保持不动）
   - 边界条件（空表、单节点、越界位置）

---

## 当前代码可改进点（后续优化方向）

- 一些文件缺少必要头文件（如 `INT_MAX` 依赖 `<limits.h>`）。
- 个别条件判断可更严谨（例如空指针判断用 `||` 而非 `&&`）。
- `sqList/dynamic.h` 使用"头文件内实现"，工程化时建议拆分为 `.h + .c/.cpp`。
- 题目文件多为单测风格 `main`，可后续统一为测试框架（如 GoogleTest）。
- 顺序栈可考虑添加动态扩容版本。
- 队列和字符串部分可补充更多练习题目。

---

## License

MIT License - 查看 [LICENSE](LICENSE) 文件了解详情。