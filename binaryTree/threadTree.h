#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ThreadNode{
    int data;
    struct ThreadNode* lchild;
    struct ThreadNode* rchild;
    int ltag,rtag;
}ThreadNode,*ThreadTree;

ThreadNode* newThreadNode(int data){
    ThreadNode* node = (ThreadNode*)malloc(sizeof(ThreadNode));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    node->ltag = 0;
    node->rtag = 0;
    return node;
}

void inThread(ThreadTree p,ThreadTree* pre){
    if(p==NULL) return;
    inThread(p->lchild,pre);
    if(p->lchild==NULL){
        p->lchild = *pre;
        p->ltag = 1;
    }
    if(*pre!=NULL&&(*pre)->rchild==NULL){
        (*pre)->rchild = p;
        (*pre)->rtag = 1;
    }
    *pre = p;//在这里pre的值被修改了，所以需要指针类型
    inThread(p->rchild,pre);
}//p不需要修改本身的值，但是pre需要

void creatThreadTree(ThreadTree t){
    if(t==NULL) return;
    ThreadTree pre = NULL;
    inThread(t,&pre);
    if(pre!=NULL && pre->rchild==NULL){
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

ThreadNode* firstNode(ThreadNode* p){
    if(p==NULL) return NULL;
    while(p->ltag==0 && p->lchild!=NULL) p = p->lchild;//有左孩子，就一直走到左下角
    return p;
}

ThreadNode* nextNode(ThreadNode* p){
    if(p==NULL) return NULL;
    if(p->rtag==0){
        if(p->rchild==NULL) return NULL;
        return firstNode(p->rchild);//有右孩子，找右子树的左下角
    } else {
        return p->rchild;//没有右孩子，后继rchild直接存的就是后继节点（可能是NULL）
    }
}

ThreadNode* lastNode(ThreadNode* p){
    if(p==NULL) return NULL;
    while(p->rtag==0 && p->rchild!=NULL) p = p->rchild;
    return p;
}//对于中序遍历，找右下角

ThreadNode* priorNode(ThreadNode* p){
    if(p==NULL) return NULL;
    if(p->ltag==0){
        if(p->lchild==NULL) return NULL;
        return lastNode(p->lchild);
    } else {
        return p->lchild;
    }
}

void inOrder(ThreadTree t){
    if(t==NULL) return;
    for(ThreadNode* p = firstNode(t);p!=NULL;p = nextNode(p))
        printf("%d ",p->data);
    printf("\n");
}

void reverseInOrder(ThreadTree t){
    if(t==NULL) return;
    for(ThreadNode* p = lastNode(t);p!=NULL;p = priorNode(p))
        printf("%d ",p->data);
    printf("\n");
}

void freeThreadTree(ThreadTree root){
    if(root==NULL) return;
    if(root->ltag==0){
        freeThreadTree(root->lchild);
    }
    if(root->rtag==0){
        freeThreadTree(root->rchild);
    }
    free(root);
}