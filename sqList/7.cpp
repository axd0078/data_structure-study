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
}//先整体逆向，再前半部分逆向，再后半部分逆向

void testExchange() {
    printf("测试 exchange 函数\n");
    
    // 创建包含10个数的数组
    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    
    printf("原始数组: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    // 移动3个元素后
    exchange(nums, 2, size);
    
    printf("移动3个元素后: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    testExchange();
    return 0;
}