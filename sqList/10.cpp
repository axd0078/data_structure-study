#include <stdio.h>
#include "dynamic.h"

bool reverse(int* nums,int start,int end){//index
	if(nums==NULL||start>end)
		return false;
	while(start<end){
		int temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;

		end--;
		start++;
	}
	return true;
}

bool exchange(int* nums,int pivot,int numsSize){//index
	if(nums==NULL|| pivot < 0 || pivot >= numsSize-1)
		return false;
	reverse(nums,0,numsSize-1);
	reverse(nums,0,pivot);
	reverse(nums,pivot+1,numsSize-1);
	return true;
}
bool listMove(sqList* list,int place){//place
	if(list == NULL || list->data == NULL || list->length == 0)
	return false;
	place = place % list->length;
    if(place == 0)  // 不需要移动
        return true;
	return exchange(list->data,place-1,list->length);
}//移动可以类似于交换整体

void testListMove() {
    printf("测试 listMove 函数\n");
    
    sqList* list = initList();
    
    // 插入10个数：[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    for(int i = 1; i <= 10; i++) {
        listInsert(list, i, i);
    }
    
    printf("原始列表: ");
    listPrint(list);
    
    // 移动前3个元素到后面
    listMove(list, 3);
    
    printf("移动前3个元素到后面: ");
    listPrint(list);
    
    // 清理内存
    free(list->data);
    free(list);
}

int main() {
    testListMove();
    return 0;
}