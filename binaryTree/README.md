# 二叉树 (Binary Tree)

二叉树的顺序存储与线索化实现。

## 文件结构

| 文件 | 说明 |
|------|------|
| `sequence.h` | 顺序存储二叉树 |
| `threadTree.h` | 线索二叉树（中序线索化） |
| `binarytree-demo.c` | 测试示例 |

## 顺序存储二叉树 (sequence.h)

使用数组存储二叉树，适合完全二叉树。

```c
void initTree(SqTree &T);     // 初始化
void createTree(SqTree &T);   // 创建（按顺序输入节点值）
```

## 线索二叉树 (threadTree.h)

利用空指针存储前驱/后继信息，加速遍历。

```c
ThreadNode* newThreadNode(ElemType x);  // 创建节点
void inThread(ThreadTree &p, ThreadTree &pre);  // 中序线索化
ThreadTree creatThreadTree();           // 创建线索二叉树

// 遍历相关
ThreadNode* firstNode(ThreadTree T);    // 中序第一个节点
ThreadNode* nextNode(ThreadNode *p);    // 中序后继
ThreadNode* lastNode(ThreadTree T);     // 中序最后一个节点
ThreadNode* priorNode(ThreadNode *p);   // 中序前驱

void inOrder(ThreadTree T);             // 中序遍历
void reverseInOrder(ThreadTree T);      // 逆序中序遍历
void freeThreadTree(ThreadTree &T);     // 释放内存
```

## 运行示例

```bash
gcc binarytree-demo.c -o test && ./test
```
