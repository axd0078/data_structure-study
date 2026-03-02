#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#define MaxSize 50
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int front,rear;
}sqQueue;

bool initQueue(sqQueue* queue){
    if(queue==NULL)
        return false;
    queue->front = 0;
    queue->rear = 0;
    return true;
}

bool isEmptyQueue(sqQueue* queue){
    if(queue==NULL)
        return true;
    return queue->front == queue->rear;
}

bool pushQueue(sqQueue* queue,ElemType e){
    if(queue==NULL)
        return false;
    if(queue->front == (queue->rear+1)%MaxSize)
        return false;
    queue->data[queue->rear] = e;
    queue->rear = (queue->rear+1)%MaxSize;
    return true;
}

bool popQueue(sqQueue* queue,ElemType* e){
    if(queue==NULL || e==NULL)
        return false;
    if(queue->front==queue->rear)
        return false;
    *e = queue->data[queue->front];
    queue->front = (queue->front+1)%MaxSize;
    return true;
}

bool getTopQueue(sqQueue* queue,ElemType* e){
    if(queue==NULL ||e==NULL)
        return false;
    if(queue->front==queue->rear)
        return false;
    *e = queue->data[queue->front];
    return true;
}

bool getLenQueue(sqQueue* queue,int* len){
    if(queue==NULL)
        return false;
    *len = (queue->front - queue->rear + MaxSize)%MaxSize;
    return true;
}

bool destroyQueue(sqQueue** queue){
    if(queue==NULL || *queue==NULL)
        return false;
    free(*queue);
    *queue = NULL;
    return true;
}