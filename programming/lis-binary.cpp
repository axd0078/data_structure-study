#include <stdio.h>

int search(int* arr,int len,int target){
    int low = 0,high = len;
    int mid;
    while(low < high){
        mid = low + (high - low) / 2;
        if(arr[mid]<target) low = mid + 1;
        else high = mid;
    }
    return low;
}//找第一个=>target的位置

int fun(int* nums,int numsSize){
    int tails[numsSize];
    int maxLen = 0;
    for(int i=0;i<numsSize;i++){
        int pos = search(tails,maxLen,nums[i]);
        tails[pos] = nums[i];   //替换或者拓展
        if(pos==maxLen)         //需要拓展时
            maxLen++;
    }
    return maxLen;
}
int main() {
    int n;
    scanf("%d", &n);
    
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    printf("%d\n", fun(nums, n));
    return 0;
}