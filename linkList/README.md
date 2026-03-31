# 链表 (Linked List)

## 模块简介

`linkList` 目录围绕带头结点的单链表展开，既包含基础结构实现，也包含反转、相交、判环、重排等经典链表题。

## 文件结构

| 文件 | 说明 |
|------|------|
| `head.h` | 带头结点单链表的定义与基础操作 |
| `list-no-head.h` | 无头结点链表的结构草稿 |
| 其余 `.cpp` | 链表专题独立练习题 |

## 题目列表

| 文件 | 题目 | 核心思路 |
|------|------|----------|
| `delete-by-value.cpp` | 删除值为 `x` 的节点 | 前驱指针遍历 |
| `delete-min.cpp` | 删除最小值节点 | 记录最小节点前驱 |
| `reverse-list.cpp` | 链表逆置 | 头插法或三指针 |
| `delete-range.cpp` | 删除区间节点 | 前驱指针配合条件删链 |
| `intersection-node.cpp` | 找相交节点 | 长链先走差值步 |
| `kth-from-end.cpp` | 倒数第 `k` 个节点 | 快慢指针 |
| `intersection-check.cpp` | 判断是否相交 | 长度对齐后同步扫描 |
| `remove-duplicate-abs.cpp` | 删除绝对值重复 | 标记数组去重 |
| `reorder-list.cpp` | 链表重排 | 找中点、逆置后半段再合并 |
| `merge-two-sorted-lists.cpp` | 合并两个有序链表 | 双指针归并 |
| `detect-cycle.cpp` | 环形链表检测 | Floyd 判环算法 |

## 关键接口

`head.h` 当前使用的链表类型为 `linkList`，带头结点，基础接口如下：

```c
bool initLinkList(linkList* list);
bool insertListByPos(linkList list, int i, int e);
LNode* insertListByNode(linkList list, LNode* p, int e);
bool insertListByNodeBefore(linkList list, LNode* p, int e);
bool deleteListByPos(linkList list, int i, int* e);
bool deleteListByNode(linkList list, LNode* p, int* e);
int getLen(linkList list);
LNode* getElem(linkList list, int i);
LNode* locateElem(linkList list, int e);
bool creatListTail(linkList list, int* nums, int numsSize);
void destroyList(linkList* list);
```

## 运行方式

```bash
g++ -std=c++11 reverse-list.cpp -o test && ./test
g++ -std=c++11 detect-cycle.cpp -o test && ./test
```

## 注意事项

- 链表默认带头结点，按位操作中的位置参数从 `1` 开始。
- `creatListTail` 适用于“已经初始化但尚未挂接数据节点”的空链表。
- 多数题目文件会直接复用 `head.h` 中的节点结构与辅助函数。
