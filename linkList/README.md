# 链表 (Linked List)

带头结点单链表的实现与经典算法练习。

## 核心文件

| 文件 | 说明 |
|------|------|
| `head.h` | 带头结点单链表定义与基础操作 |
| `list-no-head.h` | 无头结点结构草稿 |

## 题目列表

| 文件 | 题目 | 核心思路 |
|------|------|----------|
| `delete-by-value.cpp` | 删除值为 x 的节点 | 前驱指针遍历 |
| `delete-min.cpp` | 删除最小值节点 | 记录最小节点前驱 |
| `reverse-list.cpp` | 链表逆置 | 头插法 / 三指针 |
| `delete-range.cpp` | 删除区间节点 | 前驱指针+条件删链 |
| `intersection-node.cpp` | 找相交节点 | 长链先走差值步 |
| `kth-from-end.cpp` | 倒数第 k 个节点 | 快慢指针 |
| `intersection-check.cpp` | 判断是否相交 | 长度对齐+同步扫描 |
| `remove-duplicate-abs.cpp` | 删除绝对值重复 | flags 标记去重 |
| `reorder-list.cpp` | 链表重排 | 快慢指针找中点+逆置+合并 |
| `merge-two-sorted-lists.cpp` | 合并两个有序链表 | 双指针归并 |

## head.h 接口

```c
void initLinkList(LinkList &L);              // 初始化
bool listInsert(LinkList &L, int i, ElemType e);  // 按位置插入
bool insertNextNode(LNode *p, ElemType e);   // 后插
bool insertPriorNode(LNode *p, ElemType e);  // 前插
bool listDelete(LinkList &L, int i, ElemType &e); // 按位置删除
int getLen(LinkList L);                      // 获取长度
LNode* getElem(LinkList L, int i);           // 按位查找
LNode* locateElem(LinkList L, ElemType e);   // 按值查找
void creatListTail(LinkList &L, int n);      // 尾插建表
```

## 运行示例

```bash
g++ -std=c++11 reverse-list.cpp -o test && ./test
```
