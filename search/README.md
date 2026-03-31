# 查找 (Search)

## 模块简介

`search` 目录提供顺序查找和二分查找的教材式实现，依赖 `sqList/dynamic.h` 中的顺序表结构。

## 文件结构

| 文件 | 说明 |
|------|------|
| `squence.h` | 顺序查找与二分查找实现 |

## 关键接口

```c
int searchSeq(sqList* list, int key);
int searchSeqNoFlag(sqList* list, int key);
int binarySearch(sqList* list, int key);
```

## 核心内容

- `searchSeq` 演示带哨兵的顺序查找思想。
- `searchSeqNoFlag` 提供另一种顺序查找写法。
- `binarySearch` 在有序顺序表上进行二分查找。

## 运行方式

当前目录没有单独的演示 `.cpp`，通常通过包含头文件后在自建测试程序中调用：

```c
#include "../sqList/dynamic.h"
#include "squence.h"
```

## 注意事项

- 当前实现依赖 `sqList` 结构，请先初始化并填充顺序表数据。
- `binarySearch` 要求数据已经按升序排列。
- `searchSeq` 采用哨兵思想，会直接写入 `data[0]`；这更适合算法演示，使用时需要注意它与一般顺序表首元素共享存储位置。
