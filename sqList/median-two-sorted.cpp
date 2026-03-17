#include <stdio.h>
#include "dynamic.h"

int ceil_div(int a, int b) {
    return (a + b - 1) / b;
}

bool findMid(sqList* list1,sqList* list2,int* midNum){
	if(list1==NULL||list2==NULL)
		return false;
	int totalLength = list1->length + list2->length;
	int midPos = ceil_div(totalLength,2);
	int i=0,j=0,k=0,temp;//k表示将要存放的下标
	while(i<list1->length&&j<list2->length){
		if(list1->data[i]>list2->data[j]){
			temp = list2->data[j];
			j++;
		}
		else{
			temp = list1->data[i];
			i++;
		}
		if(k==midPos-1){
			*midNum = temp;
			return true;
		}
		k++;
	}
	while(i<list1->length){
		temp = list1->data[i];
		if(k==midPos-1){
			*midNum = temp;
			return true;
		}
		k++;
	}
	while(j<list2->length){
		temp = list2->data[j];
		if(k==midPos-1){
			*midNum = temp;
			return true;
		}
		k++;
	}
	return false;
}

void testFindMid() {
    printf("测试 findMid 函数\n");
    
    sqList* list1 = initList();
    sqList* list2 = initList();
    
    // list1: [1, 3, 5, 7, 9] (长度为5)
    for(int i = 0; i < 5; i++) {
        listInsert(list1, i+1, 2*i + 1);
    }
    
    // list2: [2, 4, 6, 8, 10] (长度为5)
    for(int i = 0; i < 5; i++) {
        listInsert(list2, i+1, 2*(i + 1));
    }
    
    printf("列表1: ");
    listPrint(list1);
    printf("列表2: ");
    listPrint(list2);
    
    int midValue;
    findMid(list1, list2, &midValue);
    
    printf("合并后中位数: %d\n", midValue);
    
    // 清理内存
    free(list1->data);
    free(list1);
    free(list2->data);
    free(list2);
}

int main() {
    testFindMid();
    return 0;
}