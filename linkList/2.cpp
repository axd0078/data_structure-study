#include "head.h"

bool deleteMin(linkList list,int* min){
    if(list==NULL||list->next==NULL)
        return false;
    LNode* p = list;
    LNode* q = NULL;//记录最小值的前驱节点
    int temp = INT_MAX;
    while(p->next!=NULL){
        if(p->next->data<temp){
            temp = p->next->data;
            q = p;
        }
        p = p->next;
    }
    if(q==NULL) return false;
    p = q->next;
    q->next = p->next;
    free(p);
    *min = temp;
    return true;
}