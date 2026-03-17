#include "head.h"
#include <string.h>
int abs(int num){
    return num>=0?num:(-num);
}

bool deleteSame(linkList list,int n){
    if(list==NULL) return false;
    int flags[n+1];
    memset(flags,0,sizeof(flags));
    LNode* p = list;
    while(p->next!=NULL){
        if(flags[abs(p->next->data)]==0){
            flags[abs(p->next->data)] = 1;
            p = p->next;
        }
        else{
            LNode* q = p->next;
            p->next = q->next;
            free(q);
        }
    }
    return true;

}