#include "head.h"

LNode* findSame(linkList list1,linkList list2){
    int len1 = getLen(list1);
    int len2 = getLen(list2);
    int k = len1-len2;
    LNode* p = list1;
    LNode* q = list2;
    if(k>0){
        while(p->next!=NULL && k>0){
            p = p->next;
            k--;
        }
    }
    else{
        k = -k;
        while(q->next!=NULL && k>0){
            q = q->next;
            k--;
        }
    }
    while(p->next!=NULL &&q ->next!=NULL && p->next!=q->next){
        p = p->next;
        q = q->next;
    }
    if (p->next==q->next && p->next!=NULL){
        return p->next;  // 返回交点
    } 
    else{
        return NULL;     // 没有交点
    }
}