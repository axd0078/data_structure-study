#include "head.h"
#include <stdio.h>

// Floyd判环算法：检测链表是否有环，并返回环的入口节点
LNode* detectCycle(linkList list) {
    if (list == NULL) return NULL;
    
    LNode* slow = list;
    LNode* fast = list;
    
    // 快慢指针检测环
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;  // 相遇
    }
    
    // 无环
    if (fast == NULL || fast->next == NULL) return NULL;
    
    // 找环入口：一个从头开始，一个从相遇点开始，再次相遇即为入口
    fast = list;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// 测试函数
int main() {
    linkList list;
    initLinkList(&list);
    
    // 创建链表: 1->2->3->4->5
    int nums[] = {1, 2, 3, 4, 5};
    creatListTail(list, nums, 5);
    
    // 测试1: 无环
    LNode* entry = detectCycle(list);
    printf("测试1 - 无环链表: %s\n", entry == NULL ? "通过" : "失败");
    
    // 测试2: 有环，将5指向3
    LNode* node5 = getElem(list, 5);
    LNode* node3 = getElem(list, 3);
    node5->next = node3;  // 5->3形成环
    
    entry = detectCycle(list);
    printf("测试2 - 有环链表(入口应为节点3): %s\n", 
           (entry != NULL && entry == node3) ? "通过" : "失败");
    
    // 测试3: 整个链表成环，头节点指向自己
    destroyList(&list);
    initLinkList(&list);
    creatListTail(list, nums, 1);  // 只有一个节点
    LNode* node1 = getElem(list, 1);
    node1->next = node1;  // 自环
    
    entry = detectCycle(list);
    printf("测试3 - 自环节点: %s\n", 
           (entry != NULL && entry == node1) ? "通过" : "失败");
    
    return 0;
}
