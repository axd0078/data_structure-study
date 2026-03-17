#include "head.h"

void changeList(linkList list){
    LNode *p,*q,*s,*r;
    p = list;
    q = list;
    while(q->next!=NULL){
        p = p->next;//p走一步
        q = q->next;
        if(q->next!=NULL) q = q->next;//q走两步
    }
    q = p->next;
    p->next = NULL;//类似于头插法必须把头指针制空
    while(q!=NULL){
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }//每次循环对q进行头插法，q->next = p->next;...最后更新q为下一个节点
    s = list->next;
    q = p->next;//p在上一个循环中不改变，始终指向中间节点
    p->next = NULL;
    while(q!=NULL){
        r = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;
        q = r;
    }
}