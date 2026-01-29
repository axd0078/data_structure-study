#include <stdio.h>
#include "dynamic.h"

bool findMin(sqList* list,int* value){
	if(list==NULL||value==NULL||list->length==0)
		return false;
	int min = 0;
	for(int i=1;i<list->length;i++){
		if(list->data[min]>list->data[i])
			min = i;
	}
	*value = list->data[min];
	list->data[min] = list->data[list->length-1];
	list->length--;
	return true;
}

int main(){
    // 创建并初始化顺序表
    sqList* list = initList();
    
    // 向顺序表中插入10个数值
    printf("向顺序表中插入元素...\n");
    for(int i = 0; i < 10; i++) {
        // 插入随机数 [10, 25, 3, 42, 15, 7, 33, 19, 8, 27]
        int vals[10] = {10, 25, 3, 42, 15, 7, 33, 19, 8, 27};
        listInsert(list, i+1, vals[i]);
    }
    
    printf("初始顺序表内容: ");
    listPrint(list);
    printf("当前长度: %d\n", list->length);
    
    // 查找并移除最小值
    int minValue;
    if(findMin(list, &minValue)) {
        printf("找到并移除最小值: %d\n", minValue);
        printf("移除后剩余元素: ");
        listPrint(list);
        printf("当前长度: %d\n", list->length);
    }
    
    return 0;
}