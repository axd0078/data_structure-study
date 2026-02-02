#include <stdio.h>
#include "dynamic.h"

bool insertValue(sqList* list,int value){
	if(list==NULL||list->data==NULL)
		return false;
	for(int i=0;i<list->length;i++){
		if(list->data[i]>value){
			return listInsert(list,i+1,value);
		}
		if(list->data[i]==value && i+1<list->length){
			list->data[i] = list->data[i+1];
			list->data[i+1] = value;
			return true;
		}
	}
	return listInsert(list,list->length+1,value);
}//还可以使用折半查找

void testInsertValue() {
    printf("测试 insertValue 函数\n");
    
    sqList* list = initList();
    
    // 初始插入5个有序值 [1, 3, 5, 7, 9]
    for(int i = 0; i < 5; i++) {
        listInsert(list, i+1, 2*i + 1);
    }
    
    printf("初始有序列表: ");
    listPrint(list);
    
    // 插入值6，应该插入到正确位置保持有序
    insertValue(list, 6);
    
    printf("插入值6后: ");
    listPrint(list);

    // 插入值5，应该交换后继
    insertValue(list, 5);
    
    printf("插入值5后: ");
    listPrint(list);
    
    // 清理内存
    free(list->data);
    free(list);
}

int main() {
    testInsertValue();
    return 0;
}