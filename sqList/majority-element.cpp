#include <stdio.h>
#include "dynamic.h"

int ceil_div(int a, int b) {
    return (a + b - 1) / b;
}
bool findMain(sqList* list,int* mainElem){
	if(list==NULL||list->data==NULL||mainElem==NULL)
		return false;
	int nums[list->length];
	for(int i=0;i<list->length;i++){
		nums[i] = 0;
	}
	for(int i=0;i<list->length;i++){
		nums[list->data[i]]++;
	}
	for(int i=0;i<list->length;i++){
		if(nums[i]>list->length/2){
			*mainElem = i;
			return true;
		}
			
	}
	*mainElem = -1;
	return false;
}

void testFindMain() {
    printf("测试 findMain 函数\n");
    
    sqList* list = initList();
    
    // 插入10个数，其中3出现6次，成为主元素
    int values[] = {1, 2, 3, 3, 3, 3, 3, 3, 8, 9};
    for(int i = 0; i < 10; i++) {
        listInsert(list, i+1, values[i]);
    }
    
    printf("原始列表: ");
    listPrint(list);
    
    int mainElement;
    bool result = findMain(list, &mainElement);
    
    if(result) {
        printf("找到主元素: %d\n", mainElement);
    } else {
        printf("没有找到主元素\n");
    }
    
    // 清理内存
    free(list->data);
    free(list);
}

int main() {
    testFindMain();
    return 0;
}