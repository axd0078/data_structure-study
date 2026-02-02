#include "head.h"
bool deleteByRange(linkList list,int x,int y){
    if(list==NULL||list->next==NULL)
        return false;
    LNode* p = list;
    while(p->next!=NULL){
        if(p->next->data<=y&&p->next->data>=x){
            LNode* q = p->next;
            p->next = p->next->next;
            free(q);
            continue;//continue结束本次循环，否则会再次指针移动，因为while(p->next!=NULL)和if(p->next->data<=y&&p->next->data>=x)
        }
        p = p->next;
    }
    return true;
}
//解法2：遇到不是x就尾插该节点，遇到就解决指针问题然后释放