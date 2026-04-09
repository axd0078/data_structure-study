#include <stdlib.h>

void merge(int a[],int b[],int low,int mid,int high){
    int i,j,k;
    for(k = low; k <= high; ++k){
        b[k] = a[k];
    }//复制元素

    i = low,j = mid+1,k=i;//双指针循环
    while(i<=mid&&j<=high){//有一个指针超限都停止
        if(b[i]<=b[j]){     //这里的等于为了保证排序稳定
            a[k] = b[i++];
        }
        else{
            a[k] = b[j++];
        }
        k++;
    }
    while(i<=mid) a[k++] = b[i++];
    while(j<=high) a[k++] = b[j++];
}

void mergeSort(int a[],int b[],int high,int low){
    if(high>low){
        int mid = low + (high - low) / 2;
        mergeSort(a,b,mid,low); //对左子序列操作归并排序
        mergeSort(a,b,high,mid+1);//对右子序列操作归并排序
        merge(a,b,low,mid,high);//此时左右都有序，对整个归并一次得到有序
    }
}

void countSort(int a[],int b[],int n,int k){
    int c[k];
    for(int i = 0;i<k;i++)
        c[k] = 0;
    for(int i=0;i<n;i++)
        c[a[i]]++;      //记录a[i]的出现次数
    for(int i=1;i<k;i++){
        c[i] += c[i-1];     //记录有多少个数字小于等于i
    }
    for(int i = n-1;i>=0;i--){
        b[c[a[i]]-1] = a[i];//结合一下具体来理解 -1
        c[a[i]]--;
    }
}

