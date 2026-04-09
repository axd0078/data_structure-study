#include "dynamic.h"

// Floyd判环算法找重复数字
// 数组长度n+1，值范围1~n，必有一个重复数字
// 把数组值当作"指针"，形成类似链表的结构
int findDuplicate(sqList* sqlist) {
    if (sqlist == NULL || sqlist->length <= 1) return -1;
    
    int slow = 0, fast = 0;
    
    // 快慢指针检测环
    do {
        slow = sqlist->data[slow];
        fast = sqlist->data[sqlist->data[fast]];
    } while (slow != fast);
    
    // 找环入口（重复数字）
    fast = 0;
    while (slow != fast) {
        slow = sqlist->data[slow];
        fast = sqlist->data[fast];
    }
    return slow;
}

int main() {
    sqList* list = initList();
    
    // 测试1: nums = [1,3,4,2,2]，长度5，值范围1~4，重复数字是2
    // 映射关系: 0->1, 1->3, 2->4, 3->2, 4->2
    // 路径: 0->1->3->2->4->2->4->... 环入口是2
    listInsert(list, 1, 1);
    listInsert(list, 2, 3);
    listInsert(list, 3, 4);
    listInsert(list, 4, 2);
    listInsert(list, 5, 2);
    
    int dup = findDuplicate(list);
    printf("测试1 - 数组[1,3,4,2,2]，重复数字应为2: %s (结果=%d)\n", 
           dup == 2 ? "通过" : "失败", dup);
    
    // 测试2: nums = [3,1,3,4,2]，长度5，值范围1~4，重复数字是3
    free(list->data);
    list->data = (int*)malloc(INITSIZE * sizeof(int));
    list->length = 0;
    listInsert(list, 1, 3);
    listInsert(list, 2, 1);
    listInsert(list, 3, 3);
    listInsert(list, 4, 4);
    listInsert(list, 5, 2);
    
    dup = findDuplicate(list);
    printf("测试2 - 数组[3,1,3,4,2]，重复数字应为3: %s (结果=%d)\n", 
           dup == 3 ? "通过" : "失败", dup);
    
    // 测试3: nums = [2,2,2,2,2]，长度5，值范围1~4，重复数字是2
    free(list->data);
    list->data = (int*)malloc(INITSIZE * sizeof(int));
    list->length = 0;
    listInsert(list, 1, 2);
    listInsert(list, 2, 2);
    listInsert(list, 3, 2);
    listInsert(list, 4, 2);
    listInsert(list, 5, 2);
    
    dup = findDuplicate(list);
    printf("测试3 - 数组[2,2,2,2,2]，重复数字应为2: %s (结果=%d)\n", 
           dup == 2 ? "通过" : "失败", dup);
    
    free(list->data);
    free(list);
    return 0;
}
