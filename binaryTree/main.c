#include "threadTree.h"
#include <stdio.h>
#include <stdlib.h>

// 测试用例1：基础功能测试
void testBasicFunctionality() {
    printf("=== Test 1: Basic Functionality ===\n");
    
    // 构建二叉树：
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    ThreadNode* root = newThreadNode(1);
    root->lchild = newThreadNode(2);
    root->rchild = newThreadNode(3);
    root->lchild->lchild = newThreadNode(4);
    root->lchild->rchild = newThreadNode(5);
    root->rchild->rchild = newThreadNode(6);
    
    printf("Tree constructed.\n");
    
    // 线索化
    creatThreadTree(root);
    printf("Threading completed.\n");
    
    // 测试 firstNode 和 lastNode
    ThreadNode* first = firstNode(root);
    ThreadNode* last = lastNode(root);
    printf("First node: %d (expected: 4)\n", first ? first->data : -1);
    printf("Last node: %d (expected: 6)\n", last ? last->data : -1);
    
    // 测试中序遍历
    printf("In-order traversal: ");
    inOrder(root);
    printf("Expected: 4 2 5 1 3 6\n");
    
    // 测试逆序中序遍历
    printf("Reverse in-order traversal: ");
    reverseInOrder(root);
    printf("Expected: 6 3 1 5 2 4\n");
    
    // 测试 nextNode 序列
    printf("Forward traversal using nextNode:\n");
    ThreadNode* p = first;
    while (p != NULL) {
        printf("%d ", p->data);
        p = nextNode(p);
    }
    printf("\n");
    
    // 测试 priorNode 序列
    printf("Backward traversal using priorNode:\n");
    p = last;
    while (p != NULL) {
        printf("%d ", p->data);
        p = priorNode(p);
    }
    printf("\n");
    
    // 测试特定节点的前驱和后继
    ThreadNode* node5 = root->lchild->rchild;  // 节点5
    ThreadNode* pred5 = priorNode(node5);
    ThreadNode* succ5 = nextNode(node5);
    printf("Node 5: data=%d\n", node5->data);
    printf("  Predecessor: %d (expected: 2)\n", pred5 ? pred5->data : -1);
    printf("  Successor: %d (expected: 1)\n", succ5 ? succ5->data : -1);
    
    // 测试节点4（第一个节点）
    ThreadNode* node4 = root->lchild->lchild;
    ThreadNode* pred4 = priorNode(node4);
    ThreadNode* succ4 = nextNode(node4);
    printf("Node 4 (first node):\n");
    printf("  Predecessor: %s (expected: NULL)\n", pred4 ? "exists" : "NULL");
    printf("  Successor: %d (expected: 2)\n", succ4 ? succ4->data : -1);
    
    // 测试节点6（最后一个节点）
    ThreadNode* node6 = root->rchild->rchild;
    ThreadNode* pred6 = priorNode(node6);
    ThreadNode* succ6 = nextNode(node6);
    printf("Node 6 (last node):\n");
    printf("  Predecessor: %d (expected: 3)\n", pred6 ? pred6->data : -1);
    printf("  Successor: %s (expected: NULL)\n", succ6 ? "exists" : "NULL");
    
    // 释放内存
    freeThreadTree(root);
    printf("Memory freed.\n\n");
}

// 测试用例2：空树和单节点树
void testEdgeCases() {
    printf("=== Test 2: Edge Cases ===\n");
    
    // 测试空树
    printf("Testing empty tree:\n");
    creatThreadTree(NULL);
    ThreadNode* first = firstNode(NULL);
    ThreadNode* last = lastNode(NULL);
    printf("  firstNode(NULL) = %s\n", first ? "not NULL" : "NULL (correct)");
    printf("  lastNode(NULL) = %s\n", last ? "not NULL" : "NULL (correct)");
    printf("  inOrder(NULL): ");
    inOrder(NULL);
    
    // 测试单节点树
    printf("Testing single node tree:\n");
    ThreadNode* single = newThreadNode(42);
    creatThreadTree(single);
    
    first = firstNode(single);
    last = lastNode(single);
    printf("  First node: %d (expected: 42)\n", first ? first->data : -1);
    printf("  Last node: %d (expected: 42)\n", last ? last->data : -1);
    printf("  First == Last: %s\n", first == last ? "yes" : "no");
    
    ThreadNode* pred = priorNode(single);
    ThreadNode* succ = nextNode(single);
    printf("  Predecessor: %s (expected: NULL)\n", pred ? "exists" : "NULL");
    printf("  Successor: %s (expected: NULL)\n", succ ? "exists" : "NULL");
    
    printf("  In-order traversal: ");
    inOrder(single);
    
    freeThreadTree(single);
    printf("Memory freed.\n\n");
}

// 测试用例3：完全二叉树
void testCompleteBinaryTree() {
    printf("=== Test 3: Complete Binary Tree ===\n");
    
    // 构建完全二叉树：
    //        1
    //       / \
    //      2   3
    //     / \ / \
    //    4  5 6  7
    ThreadNode* root = newThreadNode(1);
    root->lchild = newThreadNode(2);
    root->rchild = newThreadNode(3);
    root->lchild->lchild = newThreadNode(4);
    root->lchild->rchild = newThreadNode(5);
    root->rchild->lchild = newThreadNode(6);
    root->rchild->rchild = newThreadNode(7);
    
    creatThreadTree(root);
    
    printf("In-order traversal: ");
    inOrder(root);
    printf("Expected: 4 2 5 1 6 3 7\n");
    
    printf("Reverse in-order traversal: ");
    reverseInOrder(root);
    printf("Expected: 7 3 6 1 5 2 4\n");
    
    // 验证一些节点的前驱和后继
    ThreadNode* node2 = root->lchild;
    ThreadNode* node5 = root->lchild->rchild;
    ThreadNode* node1 = root;
    ThreadNode* node6 = root->rchild->lchild;
    
    printf("Node 2:\n");
    printf("  Predecessor: %d (expected: 4)\n", priorNode(node2)->data);
    printf("  Successor: %d (expected: 5)\n", nextNode(node2)->data);
    
    printf("Node 5:\n");
    printf("  Predecessor: %d (expected: 2)\n", priorNode(node5)->data);
    printf("  Successor: %d (expected: 1)\n", nextNode(node5)->data);
    
    printf("Node 1:\n");
    printf("  Predecessor: %d (expected: 5)\n", priorNode(node1)->data);
    printf("  Successor: %d (expected: 6)\n", nextNode(node1)->data);
    
    printf("Node 6:\n");
    printf("  Predecessor: %d (expected: 1)\n", priorNode(node6)->data);
    printf("  Successor: %d (expected: 3)\n", nextNode(node6)->data);
    
    freeThreadTree(root);
    printf("Memory freed.\n\n");
}

// 测试用例4：链状树（退化的二叉树）
void testDegenerateTree() {
    printf("=== Test 4: Degenerate Tree (right-skewed) ===\n");
    
    // 构建右斜树：1 -> 2 -> 3 -> 4
    ThreadNode* root = newThreadNode(1);
    root->rchild = newThreadNode(2);
    root->rchild->rchild = newThreadNode(3);
    root->rchild->rchild->rchild = newThreadNode(4);
    
    creatThreadTree(root);
    
    printf("In-order traversal: ");
    inOrder(root);
    printf("Expected: 1 2 3 4\n");
    
    printf("Reverse in-order traversal: ");
    reverseInOrder(root);
    printf("Expected: 4 3 2 1\n");
    
    // 验证前驱和后继
    ThreadNode* p = firstNode(root);
    printf("Forward sequence: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = nextNode(p);
    }
    printf("\n");
    
    p = lastNode(root);
    printf("Backward sequence: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = priorNode(p);
    }
    printf("\n");
    
    freeThreadTree(root);
    printf("Memory freed.\n\n");
}

// 测试用例5：测试 newThreadNode 初始状态
void testNewThreadNode() {
    printf("=== Test 5: newThreadNode Initialization ===\n");
    
    ThreadNode* node = newThreadNode(99);
    
    printf("Node data: %d (expected: 99)\n", node->data);
    printf("lchild: %s (expected: NULL)\n", node->lchild ? "not NULL" : "NULL");
    printf("rchild: %s (expected: NULL)\n", node->rchild ? "not NULL" : "NULL");
    printf("ltag: %d (expected: 0)\n", node->ltag);
    printf("rtag: %d (expected: 0)\n", node->rtag);
    
    free(node);  // 直接free，不是freeThreadTree（因为不是线索树）
    printf("Memory freed.\n\n");
}

int main() {
    printf("Starting comprehensive tests for threadTree.h\n");
    printf("=============================================\n\n");
    
    testNewThreadNode();
    testBasicFunctionality();
    testEdgeCases();
    testCompleteBinaryTree();
    testDegenerateTree();
    
    printf("=============================================\n");
    printf("All tests completed.\n");
    
    return 0;
}