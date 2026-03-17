#include <stdio.h>
#include "dynamic.h"

bool deleteRepeat(sqList* list){
	if(list==NULL||list->data==NULL||list->length==0)
		return false;
	int j = 0;
	for(int i=0;i<list->length;i++){
		if(list->data[i]!=list->data[j]){
			list->data[j+1] = list->data[i];
			j++;
		}
	}
	list->length = j+1;
	return true;
}

void testDeleteRepeat() {
    printf("测试 deleteRepeat 函数\n");
    
    sqList* list = initList();
    
    // 插入10个包含重复元素的数：[1, 2, 2, 3, 3, 3, 4, 5, 5, 6]
    int values[] = {1, 2, 2, 3, 3, 3, 4, 5, 5, 6};
    for(int i = 0; i < 10; i++) {
        listInsert(list, i+1, values[i]);
    }
    
    printf("原始数组(含重复): ");
    listPrint(list);
    
    deleteRepeat(list);
    
    printf("去重后数组: ");
    listPrint(list);
    
    // 清理内存
    free(list->data);
    free(list);
}

int main() {
    testDeleteRepeat();
    return 0;
}