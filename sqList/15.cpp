#include "dynamic.h"

void calMulMax(sqList* list,int* res){
    if(list==NULL && res==NULL)
        return;
    int min = list->data[list->length-1];
    int max = min;
    for(int i=list->length-1;i>=0;i--){
        if(list->data[i]>max) max = list->data[i];
        else if(list->data[i]<min) min = list->data[i];
        if(list->data[i]>=0)
            res[i] = list->data[i] * max;
        else
            res[i] = list->data[i] * min;

    }
}//关键条件是i<j,所以可以把max和min所对应的值看作j所对应的值

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