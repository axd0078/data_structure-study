#include "dynamic.h"

void calMulMax(sqList* list,int* res){
    if(list==NULL && res==NULL)
        return;
    int min = list->data[list->length-1];
    int max = min;
    for(int j=list->length-1;j>=0;j--){
        if(list->data[j]>max) max = list->data[j];
        else if(list->data[j]<min) min = list->data[j];
        if(list->data[j]>=0)
            res[j] = list->data[j] * max;
        else
            res[j] = list->data[j] * min;

    }
}

void testCalMulMax() {
    printf("测试 calMulMax 函数\n");
    
    sqList* list = initList();
    
    // 插入一些测试数据: [2, -3, 5, -1, 4]
    int values[] = {2, -3, 5, -1, 4};
    for(int i = 0; i < 5; i++) {
        listInsert(list, i+1, values[i]);
    }
    
    printf("原始列表: ");
    listPrint(list);
    
    // 创建结果数组
    int res[5];
    
    // 调用函数计算结果
    calMulMax(list, res);
    
    printf("计算结果: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    
    // 清理内存
    free(list->data);
    free(list);
}

int main() {
    testCalMulMax();
    return 0;
}