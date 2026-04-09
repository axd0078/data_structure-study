#include <stdio.h>
#include "head.h"

/**
 * 合并两个有序链表（带头结点）
 * 核心思想：双指针归并，类似归并排序的 merge 过程
 * 
 * @param l1 第一个有序链表（带头结点）
 * @param l2 第二个有序链表（带头结点）
 * @return 合并后的新链表（带头结点），失败返回 NULL
 */
linkList mergeTwoLists(linkList l1, linkList l2) {
    // 边界情况：两个链表都为空，直接返回 NULL
    if (l1 == NULL && l2 == NULL) return NULL;
    
    // 初始化新链表的头节点
    linkList newList;
    if (!initLinkList(&newList)) return NULL;
    
    // tail 始终指向新链表的最后一个节点（用于尾插法）
    LNode* tail = newList;
    
    // 安全地获取第一个数据节点：如果链表为空则 p/q 为 NULL，避免解引用崩溃
    // 三元运算符确保即使 l1/l2 为 NULL 也不会访问 l1->next
    LNode* p = (l1 != NULL) ? l1->next : NULL;
    LNode* q = (l2 != NULL) ? l2->next : NULL;
    
    // 循环条件：只要有一个链表没遍历完就继续
    // 使用 || 而不是 &&，是为了处理一个链表先遍历完的情况
    while (p || q) {
        // 情况 1：两个链表都还有节点，比较大小取较小的
        if (p && q) {
            if (p->data < q->data) {
                // p 的数据更小，将 p 插入新链表
                tail = insertListByNode(newList, tail, p->data);
                if (!tail) {  // 内存分配失败，清理并返回
                    destroyList(&newList);
                    return NULL;
                }
                p = p->next;  // p 后移
            } else {
                // q 的数据更小或相等，将 q 插入新链表
                tail = insertListByNode(newList, tail, q->data);
                if (!tail) {
                    destroyList(&newList);
                    return NULL;
                }
                q = q->next;  // q 后移
            }
        }
        // 情况 2：q 已遍历完，p 还有剩余，直接复制 p
        else if (p) {
            tail = insertListByNode(newList, tail, p->data);
            if (!tail) {
                destroyList(&newList);
                return NULL;
            }
            p = p->next;
        }
        // 情况 3：p 已遍历完，q 还有剩余，直接复制 q
        else {
            tail = insertListByNode(newList, tail, q->data);
            if (!tail) {
                destroyList(&newList);
                return NULL;
            }
            q = q->next;
        }
    }
    
    return newList;
}

// ==================== 测试代码 ====================

// 打印链表（从第一个数据节点开始）
void printList(linkList list, const char* name) {
    printf("%s: ", name);
    if (list == NULL) {
        printf("NULL\n");
        return;
    }
    LNode* p = list->next;
    printf("[");
    while (p) {
        printf("%d", p->data);
        if (p->next) printf(", ");
        p = p->next;
    }
    printf("]\n");
}

// 创建有序链表（用于测试）
linkList createSortedList(int* nums, int n) {
    linkList list;
    if (!initLinkList(&list)) return NULL;
    
    LNode* tail = list;
    for (int i = 0; i < n; i++) {
        tail = insertListByNode(list, tail, nums[i]);
        if (!tail) {
            destroyList(&list);
            return NULL;
        }
    }
    return list;
}

int main() {
    printf("========== 合并两个有序链表测试 ==========\n\n");
    
    // 测试 1：两个正常链表
    printf("【测试 1】两个正常有序链表\n");
    int nums1[] = {1, 3, 5, 7};
    int nums2[] = {2, 4, 6, 8};
    linkList l1 = createSortedList(nums1, 4);
    linkList l2 = createSortedList(nums2, 4);
    printList(l1, "L1");
    printList(l2, "L2");
    linkList merged = mergeTwoLists(l1, l2);
    printList(merged, "合并后");
    printf("预期：[1, 2, 3, 4, 5, 6, 7, 8]\n\n");
    destroyList(&l1);
    destroyList(&l2);
    destroyList(&merged);
    
    // 测试 2：l1 为空链表
    printf("【测试 2】L1 为空链表\n");
    linkList empty = NULL;
    linkList l3 = createSortedList(nums1, 4);
    printList(empty, "L1");
    printList(l3, "L2");
    merged = mergeTwoLists(empty, l3);
    printList(merged, "合并后");
    printf("预期：[1, 3, 5, 7]（复制 L2）\n\n");
    destroyList(&l3);
    destroyList(&merged);
    
    // 测试 3：l2 为空链表
    printf("【测试 3】L2 为空链表\n");
    linkList l4 = createSortedList(nums2, 4);
    printList(l4, "L1");
    printList(empty, "L2");
    merged = mergeTwoLists(l4, empty);
    printList(merged, "合并后");
    printf("预期：[2, 4, 6, 8]（复制 L1）\n\n");
    destroyList(&l4);
    destroyList(&merged);
    
    // 测试 4：两个都为空
    printf("【测试 4】两个都为空链表\n");
    merged = mergeTwoLists(NULL, NULL);
    printList(merged, "合并后");
    printf("预期：NULL\n\n");
    
    // 测试 5：长度不同的链表
    printf("【测试 5】长度不同的有序链表\n");
    int nums3[] = {1, 5, 9};
    int nums4[] = {2, 3, 4, 10, 11};
    linkList l5 = createSortedList(nums3, 3);
    linkList l6 = createSortedList(nums4, 5);
    printList(l5, "L1");
    printList(l6, "L2");
    merged = mergeTwoLists(l5, l6);
    printList(merged, "合并后");
    printf("预期：[1, 2, 3, 4, 5, 9, 10, 11]\n\n");
    destroyList(&l5);
    destroyList(&l6);
    destroyList(&merged);
    
    // 测试 6：有重复元素
    printf("【测试 6】有重复元素的链表\n");
    int nums5[] = {1, 3, 3, 5};
    int nums6[] = {3, 5, 7};
    linkList l7 = createSortedList(nums5, 4);
    linkList l8 = createSortedList(nums6, 3);
    printList(l7, "L1");
    printList(l8, "L2");
    merged = mergeTwoLists(l7, l8);
    printList(merged, "合并后");
    printf("预期：[1, 3, 3, 3, 5, 5, 7]\n\n");
    destroyList(&l7);
    destroyList(&l8);
    destroyList(&merged);
    
    printf("========== 测试完成 ==========\n");
    
    return 0;
}
