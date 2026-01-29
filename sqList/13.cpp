#include "dynamic.h"
#include <stdio.h>
#include <string.h>

int findMissMin(sqList* list){
    if(list==NULL||list->data==NULL)
        return -1;
    int flags[list->length+1];  // 扩大数组大小以处理边界情况
    memset(flags,0,sizeof(int)*(list->length+1));  // 初始化数组
    int i;
    for(i=0;i<list->length;i++){
        if(list->data[i]>0&&list->data[i]<=list->length)  // 只考虑在有效范围内的正数
            flags[list->data[i]-1] = 1;  // 调整索引，使数字1对应索引0
    }
    for(i=0;i<list->length+1;i++){  // 检查完整范围
        if(flags[i]!=1)
            return i+1;  // 返回第一个缺失的正整数
    }
    return i+1;
}

void testFindMissMin() {
    printf("测试 findMissMin 函数\n");
    
    sqList* list = initList();
    
    // 插入一些数据: [3, 4, -1, 1]
    int values[] = {3, 4, -1, 1};
    for(int i = 0; i < 4; i++) {
        listInsert(list, i+1, values[i]);
    }
    
    printf("原始列表: ");
    listPrint(list);
    
    int result = findMissMin(list);
    printf("缺失的第一个最小正整数: %d\n", result);
    
    // 清理内存
    free(list->data);
    free(list);
}

int main() {
    testFindMissMin();
    return 0;
}