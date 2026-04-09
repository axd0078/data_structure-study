#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void* a,const void* b){
    int* p = (int*)a;
    int* q = (int*)b;
    return *p - *q;
}
int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a<b?a:b;
}
    


double fun(int* nums1,int* nums2,int len1,int len2){//较短的数组在前
    int left = 0 ,right = len1;     //取了0-len1个
    int k = (len1 + len2 + 1) / 2;  //一共要取多少个，找第k个最小的

    while(left<=right){
        int i = (left+right) / 2;   //每次调整left和right，都会让这个区间里面的中位数增大或者减小
        int j = k - i;
        
        int nums1Left = i==0?INT_MIN:nums1[i-1];
        int nums1Right = i==len1?INT_MAX:nums1[i];
        int nums2Left = j==0?INT_MIN:nums2[j-1];
        int nums2Right = j==len2?INT_MAX:nums2[j];
        //计算分割后左右两边情况,取了i个此时分界情况如下：
        //nums[i-1]|nums[i]

        if(nums1Left <= nums2Right && nums2Left <=nums1Right){
        //如果出现这种情况，就是前k个找到了，因为右边永远大于左边，不管是nums1还是nums2，而且相互之间也成立
            if ((len1 + len2) % 2 == 1) {
                // 奇数
                return max(nums1Left, nums2Left);
            } else {
                // 偶数
                int leftMax = max(nums1Left, nums2Left);
                int rightMin = min(nums1Right, nums2Right);
                return (leftMax + rightMin) / 2.0;
            }
        }
        else if(nums1Left > nums2Right) //出现了1的左>2的右，违背了规则，说明nums1的右边又多了
            right = i - 1;
        else    //出现了2的左>1的右，说明num1的左边取少了
            left = i + 1;
    }
    return 0;
    
    
}


int main(){
    int len1,len2;
    scanf("%d %d",&len1,&len2);
    int nums1[len1],nums2[len2];
    for(int i=0;i<len1;i++){
        scanf("%d",&nums1[i]);
    }
    for(int i=0;i<len2;i++){
        scanf("%d",&nums2[i]);
    }
    qsort(nums1,len1,sizeof(int),cmp);
    qsort(nums2,len2,sizeof(int),cmp);
    // 确保较短的数组在前
    double result;
    if (len1 <= len2) {
        result = fun(nums1, nums2, len1, len2);
    } else {
        result = fun(nums2, nums1, len2, len1);
    }
    printf("%.1f\n", result);
    return 0;
}