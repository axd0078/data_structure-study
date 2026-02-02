#include "head.h"

bool findData(linkList list,int k,int* data){
    if(list==NULL||data==NULL||k==0) return false;
    LNode* p = list;
    for (int i = 0; i < k; i++) {
        if (p->next == NULL) return false;
        p = p->next;
    }
    LNode* q = list->next;
    while(p->next!=NULL){
        p = p->next;
        q = q->next;
    }
    *data = q->data;
    return true;
}