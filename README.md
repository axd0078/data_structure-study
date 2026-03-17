# 数据结构学习代码（顺序表 + 链表 + 栈 + 队列 + 字符串 + 二叉树 + 并查集）

本仓库是一个 **C/C++ 风格的数据结构刷题与练习集合**，核心围绕：

- 顺序表（`sqList/`）
- 单链表（`linkList/`）
- 栈（`stack/`）
- 队列（`queue/`）
- 字符串（`string/`）
- 二叉树（`binaryTree/`）
- 并查集（`DSU/`）

代码特点：

- 每个题目大多是独立的 `*.cpp` 文件，内含 `main` 测试入口；
- 顺序表题目统一复用 `sqList/dynamic.h` 中的动态顺序表实现；
- 链表题目复用 `linkList/head.h` 中的带头结点单链表工具函数；
- 栈包含顺序栈和链栈两种实现；
- 队列包含顺序队列和链队列两种实现；
- 字符串部分包含基础串匹配算法（朴素、KMP）及改进的 NextVal 算法；
- 二叉树部分包含顺序存储和线索二叉树两种实现；
- 注释较多，强调"指针移动逻辑"和"就地修改"思路；
- 并查集部分包含基础实现与按秩合并 + 路径压缩两种优化实现。

---

## 目录结构

```
.
├── README.md
├── LICENSE
├── sqList
│   ├── dynamic.h        # 动态顺序表定义与基础操作
│   ├── static-array-demo.cpp  # 静态顺序表实现示例
│   ├── delete-min.cpp          # 删除最小元素
│   ├── reverse-inplace.cpp     # 就地逆置
│   ├── delete-by-value.cpp     # 删除指定值
│   ├── delete-range.cpp        # 删除区间值
│   ├── remove-duplicates.cpp   # 有序表去重
│   ├── merge-sorted.cpp        # 合并两个有序表
│   ├── array-swap.cpp          # 分段交换
│   ├── insert-or-replace.cpp   # 插入或替换
│   ├── common-elements.cpp     # 三数组公共元素
│   ├── rotate-left.cpp         # 循环左移
│   ├── median-two-sorted.cpp   # 两有序表中位数
│   ├── majority-element.cpp    # 主元素
│   ├── first-missing-positive.cpp  # 最小缺失正整数
│   ├── min-distance-three-arrays.cpp  # 三数组最小距离
│   └── max-product-suffix.cpp  # 后缀最大乘积
├── linkList
│   ├── head.h                      # 带头结点单链表定义与基础操作
│   ├── list-no-head.h              # 无头结点结构草稿
│   ├── delete-by-value.cpp         # 删除值为 x 的节点
│   ├── delete-min.cpp              # 删除最小值节点
│   ├── reverse-list.cpp            # 链表逆置
│   ├── delete-range.cpp            # 删除区间节点
│   ├── intersection-node.cpp       # 相交节点查找
│   ├── kth-from-end.cpp            # 倒数第 k 个节点
│   ├── intersection-check.cpp      # 相交节点判断
│   ├── remove-duplicate-abs.cpp    # 删除绝对值重复节点
│   ├── reorder-list.cpp            # 链表重排
│   └── merge-two-sorted-lists.cpp  # 合并两个有序链表
├── stack
│   ├── sequence
│   │   └── stack.h      # 顺序栈实现
│   ├── link
│   │   └── stack.h      # 链栈实现
│   ├── expression-eval.cpp  # 表达式求值（栈应用）
│   └── bracket-match.cpp    # 括号匹配（栈应用）
├── queue
│   ├── sequence.h       # 顺序队列实现
│   └── link.h           # 链队列实现
├── string
│   ├── string.h              # 字符串定义与 KMP 算法
│   ├── kmp-test.c            # KMP 算法测试示例
│   └── longest-common-prefix.cpp  # 最长公共前缀长度（字典序极值法）
└── binaryTree
    ├── binarytree-demo.c  # 二叉树测试示例
    ├── sequence.h         # 顺序存储二叉树实现
    └── threadTree.h       # 线索二叉树实现
└── DSU
    ├── dsu.h            # 并查集定义与算法实现
    └── test_dsu.cpp     # 并查集测试示例
```

---

## 如何运行

> 说明：每个 `*.cpp` 基本都自带 `main`，因此请"单文件编译运行"，不要一次性把多个题目文件链接到同一个可执行程序。

### 1）运行某个顺序表题目

```bash
g++ -std=c++11 sqList/delete-min.cpp -o delete_min && ./delete_min
g++ -std=c++11 sqList/reverse-inplace.cpp -o reverse && ./reverse
# ... 其他题目类似，单文件编译运行
```

### 2）运行某个链表题目

```bash
g++ -std=c++11 linkList/delete-by-value.cpp -o delete_val && ./delete_val
g++ -std=c++11 linkList/merge-two-sorted-lists.cpp -o merge && ./merge
# ... 其他题目类似
```

### 3）运行栈应用示例

```bash
g++ -std=c++11 stack/expression-eval.cpp -o expr_eval && ./expr_eval
g++ -std=c++11 stack/bracket-match.cpp -o bracket && ./bracket
```

### 4）运行字符串算法测试

```bash
gcc string/kmp-test.c -o kmp_test && ./kmp_test
g++ -std=c++11 string/longest-common-prefix.cpp -o lcp && ./lcp
```

### 5）运行二叉树测试

```bash
gcc binaryTree/binarytree-demo.c -o bt_demo && ./bt_demo
```

### 6）运行并查集测试

```bash
g++ -std=c++11 DSU/test_dsu.cpp -o dsu_test && ./dsu_test
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

### `string/findmaxsuffix.cpp`（最长公共前缀）

实现了高效求解字符串数组最长公共前缀长度的算法：

- **核心思想**：只需比较字典序最小和最大的两个字符串，其公共前缀即为全局最长公共前缀
- **时间复杂度**：O(n + L)，优于逐一比较的 O(n × L)
- **测试用例**：包含正常情况、无公共前缀、全部相同、单字符串、空数组等边界测试

### `binaryTree/sequence.h`（顺序存储二叉树）

实现了二叉树的顺序存储结构：

- `initTree()`：初始化二叉树
- `createTree()`：创建二叉树，按顺序输入节点值

### `binaryTree/threadTree.h`（线索二叉树）

实现了线索二叉树的相关操作：

- `newThreadNode()`：创建新的线索二叉树节点
- `inThread()`：中序线索化二叉树
- `creatThreadTree()`：创建线索二叉树
- `firstNode()`：获取中序遍历的第一个节点
- `nextNode()`：获取中序遍历的下一个节点
- `lastNode()`：获取中序遍历的最后一个节点
- `priorNode()`：获取中序遍历的前一个节点
- `inOrder()`：中序遍历线索二叉树
- `reverseInOrder()`：逆序中序遍历线索二叉树
- `freeThreadTree()`：释放线索二叉树内存

### `DSU/dsu.h`（并查集）

实现了并查集（Disjoint Set Union）的基础与优化版本：

**基础实现：**
- `init()`：初始化并查集，所有元素各自为一个集合（用 `-1` 标记根节点）
- `find()`：查找元素所在集合的根节点（无优化）
- `unionSet()`：合并两个集合（直接将 root1 挂到 root2 下）

**优化实现（按秩合并 + 路径压缩）：**
- `unionPro()`：按大小合并，将规模较小的集合并入规模较大的集合，降低树高
- `findPro()`：查找根节点时顺带路径压缩，使后续查找更快（接近 O(1)）

> 存储规则：`s[i] < 0` 表示 `i` 是根节点，`|s[i]|` 为集合大小；`s[i] >= 0` 表示 `i` 的父节点是 `s[i]`。

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

```
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
```
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
| `findmaxsuffix.cpp` | 最长公共前缀长度 | 字典序极值法（只比较最小/最大串） |

---

## 重点题（推荐优先理解）

结合代码复杂度和技巧性，建议重点看：

- 顺序表：`median-two-sorted.cpp`（中位数归并思想）、`majority-element.cpp`（主元素）、`min-distance-three-arrays.cpp`（三指针最小距离）、`max-product-suffix.cpp`（后缀 min/max）
- 链表：`reorder-list.cpp`（链表重排，包含找中点 + 逆置 + 合并）、`merge-two-sorted-lists.cpp`（合并两个有序链表）
- 栈：`expression-eval.cpp`（表达式求值，综合运用双栈）、`bracket-match.cpp`（括号匹配）
- 字符串：`getNext()` 与 `getNextVal()`（KMP 核心）、`longest-common-prefix.cpp`（字典序极值法求最长公共前缀）
- 二叉树：`threadTree.h`（线索二叉树的实现，包括中序线索化和遍历）
- 并查集：`dsu.h` 中的 `unionPro()` + `findPro()`（按秩合并与路径压缩，理解其均摊复杂度优势）

---

## 当前代码可改进点（后续优化方向）

- 一些文件缺少必要头文件（如 `INT_MAX` 依赖 `<limits.h>`）。
- 个别条件判断可更严谨（例如空指针判断用 `||` 而非 `&&`）。
- `sqList/dynamic.h` 使用"头文件内实现"，工程化时建议拆分为 `.h + .c/.cpp`。
- 题目文件多为单测风格 `main`，可后续统一为测试框架（如 GoogleTest）。
- 顺序栈可考虑添加动态扩容版本。
- 队列和字符串部分可补充更多练习题目。
- 二叉树部分可补充更多遍历算法（如前序、后序线索化）和应用示例。
- 并查集目前固定容量为 `SIZE=100`，可改为动态分配；`unionSet` 未处理自环（`root1==root2` 时跳过），`unionPro` 在自环情况下存在 bug（双倍计数），可进一步改进。

---

## License

MIT License - 查看 [LICENSE](LICENSE) 文件了解详情。