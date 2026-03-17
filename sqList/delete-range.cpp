#include <stdio.h>
#include "dynamic.h"

bool deleteByRange(sqList* list,int s,int t){
	if(t<s||list==NULL||list->data==NULL||list->length==0)
		return false;
	int deleteLength = 0;
	for(int i=0;i<list->length;i++){
		if(list->data[i]>=s&&list->data[i]<=t)
			deleteLength++;
		else
			list->data[i-deleteLength] = list->data[i];
	}
	list->length -= deleteLength;
	return true;
}

void testDeleteByRange() {
    printf("测试 deleteByRange 函数\n");
    
    sqList* list = initList();
    
    // 插入10个数：[1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
    for(int i = 0; i < 10; i++) {
        listInsert(list, i+1, 2*i + 1);
    }
    
    printf("原始数组: ");
    listPrint(list);
    
    // 删除范围 [5, 15] 内的所有元素
    deleteByRange(list, 5, 15);
    
    printf("删除范围 [5, 15] 后: ");
    listPrint(list);
    
    // 清理内存
    free(list->data);
    free(list);
}

int main() {
    testDeleteByRange();
    return 0;
}