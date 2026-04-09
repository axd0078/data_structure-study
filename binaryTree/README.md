# 二叉树 (Binary Tree)

## 模块简介

`binaryTree` 目录包含两类典型实现：顺序存储二叉树，以及基于中序线索化的线索二叉树。适合用来理解树的存储方式和遍历优化。

## 文件结构

| 文件 | 说明 |
|------|------|
| `sequence.h` | 顺序存储二叉树 |
| `threadTree.h` | 线索二叉树（中序线索化） |
| `binarytree-demo.c` | 演示与测试程序 |

## 关键接口

### 顺序存储二叉树 `sequence.h`

```c
void initTree(SeqBinaryTree* tree);
void createTree(SeqBinaryTree* tree);
```

### 线索二叉树 `threadTree.h`

```c
ThreadNode* newThreadNode(int data);
void inThread(ThreadTree p, ThreadTree* pre);
void creatThreadTree(ThreadTree t);
ThreadNode* firstNode(ThreadNode* p);
ThreadNode* nextNode(ThreadNode* p);
ThreadNode* lastNode(ThreadNode* p);
ThreadNode* priorNode(ThreadNode* p);
void inOrder(ThreadTree t);
void reverseInOrder(ThreadTree t);
void freeThreadTree(ThreadTree root);
```

## 核心内容

- 顺序存储版本使用数组编号表示节点位置，更适合理解完全二叉树或接近完全二叉树的存储形式。
- 线索二叉树版本利用空指针保存中序前驱和后继，便于在不使用递归栈的情况下进行遍历。
- `binarytree-demo.c` 用于串联验证创建、线索化与遍历过程。

## 运行方式

```bash
gcc binarytree-demo.c -o test && ./test
```

## 注意事项

- 顺序存储版本使用的节点编号从 `1` 开始，数组下标与节点编号保持一致。
- `creatThreadTree` 的当前实现是“对已有树做线索化”，不是返回新树的工厂函数。
- `freeThreadTree` 会根据 `ltag` / `rtag` 判断是否递归释放左右子树。
