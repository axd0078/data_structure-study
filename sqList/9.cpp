#include <stdio.h>
#include "dynamic.h"

bool findSame(int* a,int* b,int* c,int numsSize){
	int i=0,j=0,k=0;//a--i,b--j,c--k
	int flag = 0;
	while(i<numsSize&&j<numsSize&&k<numsSize){
		if(a[i]==b[j]&&b[j]==c[k]){
			printf("%d ",a[i]);
			i++,j++,k++;
			flag = 1;
		}
		else{
			int max = (a[i]>b[j]?a[i]:b[j])>c[k]?(a[i]>b[j]?a[i]:b[j]):c[k];
			if(a[i]<max) i++;
			if(b[j]<max) j++;
			if(c[k]<max) k++;
		}
	}
	if(flag==1) return true;
	else return false;
}

void testFindSame() {
    printf("测试 findSame 函数\n");
    
    // 创建三个包含公共元素的数组
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int c[10] = {1, 3, 5, 6, 8, 10, 12, 15, 18, 21};
    
    printf("数组A: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n数组B: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", b[i]);
    }
    printf("\n数组C: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");
    
    printf("三个数组的公共元素: ");
    bool result = findSame(a, b, c, 10);
    printf("\n");
}

int main() {
    testFindSame();
    return 0;
}