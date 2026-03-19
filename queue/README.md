# 队列 (Queue)

顺序队列与链队列的实现。

## 文件结构

| 文件 | 说明 |
|------|------|
| `sequence.h` | 顺序队列实现（循环数组） |
| `link.h` | 链队列实现（带头结点） |

## 顺序队列接口 (sequence.h)

循环队列，通过取模实现队列复用。

```c
void initQueue(SqQueue *&Q);      // 初始化
bool isEmptyQueue(SqQueue *Q);    // 判空
bool pushQueue(SqQueue *&Q, ElemType e);  // 入队
bool popQueue(SqQueue *&Q, ElemType &e);  // 出队
bool getTopQueue(SqQueue *Q, ElemType &e); // 获取队头
```

## 链队列接口 (link.h)

带头结点的链式队列。

```c
void initQueue(LinkQueue *&Q);    // 初始化
bool isEmptyQueue(LinkQueue *Q);  // 判空
bool pushQueue(LinkQueue *&Q, ElemType e);  // 入队
bool popQueue(LinkQueue *&Q, ElemType &e);  // 出队
bool getTopQueue(LinkQueue *Q, ElemType &e); // 获取队头
```

## 使用示例

队列可作为头文件被其他文件引用：

```c
#include "queue/sequence.h"
// 或
#include "queue/link.h"
```
