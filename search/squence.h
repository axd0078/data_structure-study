#include "../sqList/dynamic.h"

int searchSeq(sqList* list,int key){
    list->data[0] = key;    //哨兵，不用判断越界
    int i;
    for(i=list->length;list->data[i]!=key;i--);
    return i;
}
int searchSeqNoFlag(sqList* list,int key){
    if(list->data[0] == key){
        return 0;
    }
    list->data[0] = key;    //哨兵，不用判断越界
    int i;
    for(i=list->length;list->data[i]!=key;i--);
    if(i==0) return -1;
    else{
        return i;
    }
}

int binarySearch(sqList* list,int key){
    int low = 0 , high = list->length - 1;
    int mid;
    while(low <= high){
        mid = high + (low - high) / 2;
        if(list->data[mid] == key)  return mid;
        else if(list->data[mid] > key) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}