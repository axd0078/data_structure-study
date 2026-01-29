#include <stdio.h>
#include "dynamic.h"

bool reverseList(sqList* list){
	if(list==NULL||list->length==0)
		return false;
	for(int i=0;i<list->length/2;i++){
		int temp = list->data[i];
		list->data[i] = list->data[list->length-1-i];
		list->data[list->length-1-i] = temp;
	}
	return true;
}

void testReverseList() {
    printf("测试 reverseList 函数\n");
    
    sqList* list = initList();
    
    // 插入10个数：[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    for(int i = 1; i <= 10; i++) {
        listInsert(list, i, i);
    }
    
    printf("反转前: ");
    listPrint(list);
    
    reverseList(list);
    
    printf("反转后: ");
    listPrint(list);
    
    // 清理内存
    free(list->data);
    free(list);
}

int main() {
    testReverseList();
    return 0;
}