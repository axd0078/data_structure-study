#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode,*linkList;

bool initLinkList(linkList* list){
    *list = (LNode*)malloc(sizeof(LNode));
    (*list)->next = NULL;
    return true;
}

bool insertListByPos(linkList list,int i,int e){
    if(i<1) return false;
    LNode* p = list;
    int j=0; //当前在第几个节点
    while(p!=NULL&&j<i-1){
        p = p->next;
        j++;
    }
    if(p==NULL) //i不合法
        return false;
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    if (newNode==NULL)
        return false;
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return true;
}//插入操作不需要修改头指针本身，只需要修改链表内部的节点链接关系

bool insertListByNode(linkList list,LNode* p,int e){
    if(p==NULL) return false;
    while(1){

    }
    

}


