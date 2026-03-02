#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#define MaxSize 50
typedef int ElemType;
typedef struct QNode{
    ElemType data;
    struct QNode* next;
}QNode;

typedef struct{
    QNode* front;
    QNode* rear;
    int size;
}*linkQueue;

bool initQueue(linkQueue* queue){
    if(queue==NULL)
        return false;
    *queue = (linkQueue)malloc(sizeof(*queue));//指针是 8 字节，但结构体需要 20 字节来存放两个指针和一个int ！
    (*queue)->front = (QNode*)malloc(sizeof(QNode));
    (*queue)->front->next = NULL;
    (*queue)->rear = (*queue)->front;
    (*queue)->size = 0;
    return true;
}

bool isEmptyQueue(linkQueue queue){
    if(queue==NULL)
        return true;
    return queue->front == queue->rear;
}

bool pushQueue(linkQueue queue,ElemType e){
    if(queue==NULL)
        return false;
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = e;
    newNode->next = NULL;
    queue->rear->next = newNode;
    queue->rear = newNode;
    queue->size++;
    return true;
}

bool popQueue(linkQueue queue,ElemType* e){
    if(queue==NULL || e==NULL)
        return false;
    QNode* temp = queue->front->next;
    *e = temp->data;
    queue->front->next = temp->next;
    if(temp==queue->rear)//出队列需要考虑只有一个节点的情况，所以出队列有可能会改变两个指针
        queue->rear = queue->front;
    free(temp);
    queue->size--;
    return true;
}

bool getHeadQueue(linkQueue queue,ElemType* e){
    if(queue==NULL || e==NULL)
        return false;
    QNode* temp = queue->front->next;
    *e = temp->data;
    return true;
}

bool getLenQueue(linkQueue queue,int* len){
    if(queue==NULL || len==NULL)
        return false;
    *len = queue->size;
    return true;
}

bool destroyQueue(linkQueue* queue){
    if(queue==NULL||*queue==NULL)
        return false;
    QNode* temp = (*queue)->front;
    while(temp!=NULL){
        QNode* p = temp->next;
        free(temp);
        temp = p;
    }
    free(*queue);
    *queue = NULL;
    return true;
}