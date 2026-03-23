#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a,b,c;
}Node;

int cmp(const void* a,const void* b){
    int* pa = (int*)a;
    int* pb = (int*)b;
    return *pa - *pb;
}

int fun(int* nums,int numsSize,Node* arr){
    int n = 0;
    qsort(nums,numsSize,sizeof(int),cmp);
    for(int i=0;i<numsSize;i++){
        if(nums[i]>0)
            break;
        if(i>0 && nums[i]==nums[i-1])
            continue;
        int left = i+1,right = numsSize-1; 
        while(left<right){
            int result = nums[i] + nums[left] + nums[right];
            if(result == 0){
                arr[n].a = nums[i];
                arr[n].b = nums[left];
                arr[n].c = nums[right];
                n++;
                // 修复3: 跳过重复元素
                while(left<right && nums[left]==nums[left+1]) left++;
                while(left<right && nums[right]==nums[right-1]) right--;
                left++;
                right--;
                //还要继续找这个nums[i]还有没有解
            }
            else if(result < 0)
                left++;
            else
                right--;
        }
    }
    return n;
}

int main(){
    int n;
    scanf("%d",&n);
    int nums[n];
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    Node* arr = (Node*)malloc(sizeof(Node)*n);
    int len = fun(nums,n,arr);
    for(int i = 0;i<len;i++){
        printf("%d %d %d\n",arr[i].a,arr[i].b,arr[i].c);
    }
    free(arr);
    return 0;
}