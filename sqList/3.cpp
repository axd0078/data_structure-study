#include <stdio.h>
#include "dynamic.h"

bool deleteByValue(sqList* list,int value){
	if(list==NULL||list->length==0)
		return false;
	int length = 0;
	for(int i=0;i<list->length;i++){
		if(list->data[i]!=value){
			list->data[length] = list->data[i];
			length++;
		}
	}
	list->length = length;
	return true;
}

void testDeleteByValue() {
    printf("测试 deleteByValue 函数\n");
    
    sqList* list = initList();
    
    // 插入10个数：[1, 2, 3, 2, 5, 2, 7, 8, 2, 10]
    for(int i=1; i<=10; i++) {
        if(i==4 || i==6 || i==9) 
            listInsert(list, i, 2);  // 插入值为2的重复元素
        else
            listInsert(list, i, i);
    }
    
    printf("删除前: ");
    listPrint(list);
    
    // 删除所有值为2的元素
    deleteByValue(list, 2);
    
    printf("删除所有值为2的元素后: ");
    listPrint(list);
    
    // 清理内存
    free(list->data);
    free(list);
}

int main() {
    testDeleteByValue();
    return 0;
}