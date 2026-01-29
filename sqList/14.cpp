#include "dynamic.h"
int abs(int num){
    return num>=0?num:(-num);
}
   
int findMin(int a,int b,int c){
    return (a<b?a:b)<c?(a<b?a:b):c;
}

int findMinDistance(sqList* list1,sqList* list2,sqList* list3){
    int i=0,j=0,k=0;
    int distance = INT_MAX;
    while(i<list1->length && j<list2->length && k<list3->length){
        int temp = abs(list1->data[i]-list2->data[j]) 
                    + abs(list2->data[j]-list3->data[k]) + abs(list1->data[i]-list3->data[k]);
        if(temp<distance)
            distance = temp;
        
        int min = findMin(list1->data[i],list2->data[j],list3->data[k]);
        if(min==list1->data[i])
            i++;
        else if(min==list2->data[j])
            j++;
        else
            k++;
        
    }
    return distance;
}

void testFindMinDistance() {
    printf("测试 findMinDistance 函数\n");
    
    // 创建三个顺序表
    sqList* list1 = initList();
    sqList* list2 = initList();
    sqList* list3 = initList();
    
    // 为list1插入数据: [1, 5, 10]
    listInsert(list1, 1, 1);
    listInsert(list1, 2, 5);
    listInsert(list1, 3, 10);
    
    // 为list2插入数据: [2, 6, 12]
    listInsert(list2, 1, 2);
    listInsert(list2, 2, 6);
    listInsert(list2, 3, 12);
    
    // 为list3插入数据: [3, 8, 15]
    listInsert(list3, 1, 3);
    listInsert(list3, 2, 8);
    listInsert(list3, 3, 15);
    
    printf("list1: ");
    listPrint(list1);
    printf("list2: ");
    listPrint(list2);
    printf("list3: ");
    listPrint(list3);
    
    int minDistance = findMinDistance(list1, list2, list3);
    printf("三列表间的最小距离: %d\n", minDistance);
    
    // 测试边界情况
    printf("\n测试边界情况:\n");
    sqList* empty_list = initList();  // 空表
    
    int result = findMinDistance(empty_list, list2, list3);
    printf("其中一个表为空时的最小距离: %d\n", result);
    
    // 清理内存
    free(list1->data);
    free(list1);
    free(list2->data);
    free(list2);
    free(list3->data);
    free(list3);
    free(empty_list->data);
    free(empty_list);
}

int main() {
    testFindMinDistance();
    return 0;
}