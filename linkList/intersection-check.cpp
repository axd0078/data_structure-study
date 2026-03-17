#include "head.h"

LNode* findSame(linkList list1,linkList list2){
    int len1 = getLen(list1);
    int len2 = getLen(list2);
    int k = len1 - len2;
    LNode* p = list1;
    LNode* q = list2;
    if(k>0){
        for(int i=0;i<k;i++){
            p = p->next;
        }
    }
    else{
        k = -k;
        for(int i=0;i<k;i++){
            q = q->next;
        }
    }
    while(p->next!=NULL && q->next!=NULL && p->next!=q->next){
        p = p->next;
        q = q->next;
    }
    if(p->next==q->next && p->next!=NULL){
        return p->next;
    }
    else
        return NULL;
}