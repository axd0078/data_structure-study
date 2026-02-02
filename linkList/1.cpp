#include "head.h"
bool deleteByValue(linkList list,int x){
    if(list==NULL||list->next==NULL)
        return false;
    LNode* p = list;
    while(p->next!=NULL){
        if(p->next->data==x){
            LNode* q = p->next;
            p->next = p->next->next;
            free(q);
            continue;//continue结束本次循环，否则会再次指针移动
        }
        p = p->next;
    }
    return true;
}
//解法2：遇到不是x就尾插该节点，遇到就解决指针问题然后释放