# 查找算法 (Search)

顺序查找与二分查找的实现。

## 文件结构

| 文件 | 说明 |
|------|------|
| `squence.h` | 顺序查找、二分查找 |

## 核心算法

### 顺序查找

```c
int searchSeq(sqList* list, int key);       // 带哨兵，返回下标（0表示失败）
int searchSeqNoFlag(sqList* list, int key); // 不带哨兵，返回下标（-1表示失败）
```

**哨兵技巧**：将待查值存入 `data[0]`，从后向前遍历，省去每次判断越界的开销。

**时间复杂度**：O(n)

### 二分查找

```c
int binarySearch(sqList* list, int key);    // 返回下标（-1表示失败）
```

**前提条件**：数组必须有序（升序）

**时间复杂度**：O(log n)

## 依赖

依赖顺序表实现：
```c
#include "../sqList/dynamic.h"
```

## 使用示例

```c
#include "search/squence.h"

sqList L;
initList(L);
// ... 插入有序数据 ...

int pos = binarySearch(&L, 42);
if (pos != -1) {
    printf("找到元素，位置: %d\n", pos);
}
```
