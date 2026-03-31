# 队列 (Queue)

## 模块简介

`queue` 目录提供顺序队列和链队列两种基础实现，主要用作教材式数据结构练习以及其他算法示例的辅助组件。

## 文件结构

| 文件 | 说明 |
|------|------|
| `sequence.h` | 顺序队列实现（循环数组） |
| `link.h` | 链队列实现（带头结点） |

## 关键接口

### 顺序队列 `sequence.h`

```c
bool initQueue(sqQueue* queue);
bool isEmptyQueue(sqQueue* queue);
bool pushQueue(sqQueue* queue, ElemType e);
bool popQueue(sqQueue* queue, ElemType* e);
bool getTopQueue(sqQueue* queue, ElemType* e);
bool getLenQueue(sqQueue* queue, int* len);
bool destroyQueue(sqQueue** queue);
```

### 链队列 `link.h`

```c
bool initQueue(linkQueue* queue);
bool isEmptyQueue(linkQueue queue);
bool pushQueue(linkQueue queue, ElemType e);
bool popQueue(linkQueue queue, ElemType* e);
bool getHeadQueue(linkQueue queue, ElemType* e);
bool getLenQueue(linkQueue queue, int* len);
bool destroyQueue(linkQueue* queue);
```

## 核心内容

- 顺序队列使用循环数组管理 `front` 与 `rear`，适合理解队满、队空和取模复用。
- 链队列使用头结点与尾指针维护入队和出队，适合练习链式存储。

## 运行方式

当前目录没有单独的 `.cpp` 演示文件，通常作为头文件被其他示例或自建测试程序包含使用：

```c
#include "queue/sequence.h"
// 或
#include "queue/link.h"
```

## 注意事项

- 顺序队列版本通过预留一个空位区分“队满”和“队空”。
- 链队列版本维护 `size` 字段，便于直接获取当前长度。
- 当前链队列接口中获取队头元素的函数名是 `getHeadQueue`，与顺序队列版本的 `getTopQueue` 不同。
