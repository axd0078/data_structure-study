#include <stdio.h>
#include "dynamic.h"

bool mergeList(sqList* list1,sqList* list2){
	if(list1==NULL||list2==NULL)
		return false;
	int* temp = (int*)malloc(sizeof(int)*list1->length);
	int tempLength = list1->length;
	for(int i=0;i<list1->length;i++){
		temp[i] = list1->data[i];
	}
	expandList(list1,list2->length);//不会改变length 只会改变maxSize
	
	int i = 0,j = 0,k = 0;
	while(i<tempLength && j<list2->length){
		if(temp[i]>list2->data[j])
			list1->data[k++] = list2->data[j++];
		else
			list1->data[k++] = temp[i++];
	}
	while(i<tempLength){
		list1->data[k++] = temp[i++];
	}
	while(j<list2->length){
		list1->data[k++] = list2->data[j++];
	}
	list1->length = k;

	free(temp); /*free!!! */
	return true;
}

void testMergeList() {
    printf("测试 mergeList 函数\n");
    
    sqList* list1 = initList();
    sqList* list2 = initList();
    
    // list1: [1, 3, 5, 7, 9]
    for(int i = 0; i < 5; i++) {
        listInsert(list1, i+1, 2*i + 1);
    }
    
    // list2: [2, 4, 6, 8, 10]
    for(int i = 0; i < 5; i++) {
        listInsert(list2, i+1, 2*(i + 1));
    }
    
    printf("原始 list1: ");
    listPrint(list1);
    printf("原始 list2: ");
    listPrint(list2);
    
    mergeList(list1, list2);
    
    printf("合并后 list1: ");
    listPrint(list1);
    
    // 清理内存
    free(list1->data);
    free(list1);
    free(list2->data);
    free(list2);
}

int main() {
    testMergeList();
    return 0;
}