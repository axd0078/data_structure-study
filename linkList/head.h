#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode,*linkList;

bool initLinkList(linkList* list){
    *list = (LNode*)malloc(sizeof(LNode));
    (*list)->next = NULL; //创建链表时在这里置空指针域，不置空会导致头插法的最后一个节点的指针域变成野指针
    return true;
}

bool insertListByPos(linkList list,int i,int e){//插入到第i个位置
    if(i<1) return false;
    LNode* p = list;       //getElem(list,i-1);
    int j=0; //当前在第几个节点
    while(p!=NULL&&j<i-1){//说明要找第i-1个节点
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

bool insertListByNode(linkList list,LNode* p,int e){//指定节点后插入
    if(p==NULL || list==NULL) return false;
    LNode* temp = list;//locateElem(list,p->data) -- 只可以用于数据域唯一
    while(temp!=NULL){
        if(temp==p)
            break;
        temp = temp->next;
    }
    if(temp==NULL) return false;
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return true;
}

bool insertListByNodeBefore(linkList list,LNode* p,int e){//指定节点前插入
    if(p==NULL || list==NULL || p==list) return false;
    LNode* temp = list;
    while(temp!=NULL&&temp->next!=p){
        temp = temp->next;
    }
    if(temp==NULL) return false;
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    newNode->data = e;
    newNode->next = temp->next;
    temp->next = newNode;
    return true;
}

bool deleteListByPos(linkList list,int i,int* e){
    if(i<1|| list == NULL || e == NULL) return false;
    LNode* p = list;//getElem(list,i);
    int j=0;
    while(p!=NULL&&j<i-1){//找到第i-1个节点
        p = p->next;
        j++;
    }
    if(p==NULL || p->next==NULL)  return false;
    *e = p->next->data;
    LNode* q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

bool deleteListByNode(linkList list,LNode* p,int* e){//删除指定节点
    if(p==NULL || list==NULL || p==list) return false;
    LNode* temp = list;
    while(temp!=NULL&&temp->next!=p){
        temp = temp->next;
    }
    if(temp==NULL||temp->next==NULL) return false;
    LNode* q = temp->next;
    *e = q->data;
    temp->next = q->next;
    free(q);
    return true;
}

int getLen(linkList list){
    if(list==NULL) return -1;
    int len = 0;
    LNode* p = list;
    while(p->next!=NULL){
        p = p->next;
        len++;
    }
    return len;
}

LNode* getElem(linkList list,int i){
    if(i<1) return NULL;
    LNode* p = list;
    int j=0;
    while(p!=NULL && j<i){
        p = p->next;
        j++;
    }
    return p;
}

LNode* locateElem(linkList list,int e){
    LNode* p = list->next;
    while(p!=NULL && p->data!=e){
        p = p->next;
    }
    return p;
}

bool creatListTail(linkList list,int* nums,int numsSize){
    if(list->next!=NULL) return false;
    LNode *newNode,*tail;
    tail = list;
    for(int i=0;i<numsSize;i++){
        newNode = (LNode*)malloc(sizeof(LNode));
        if(newNode==NULL) return false;
        newNode->data = nums[i];
        tail->next = newNode;
        newNode->next = NULL;
        tail = newNode;
    }
    return true;
}