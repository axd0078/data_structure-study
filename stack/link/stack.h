#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int elemType;
typedef struct SNode{
    elemType data;
    struct SNode* next;
}SNode,*linkStack;

bool initStack(linkStack* stack){
    if(stack == NULL)
        return false;
    *stack = (SNode*)malloc(sizeof(SNode));
    if(*stack == NULL)
        return false;
    (*stack)->next = NULL;
    return true;
}

bool isEmptyStack(linkStack stack){
    if(stack == NULL)
        return true;
    return stack->next == NULL;
}

bool pushStack(linkStack stack, elemType e){
    if(stack == NULL)
        return false;
    SNode* newNode = (SNode*)malloc(sizeof(SNode));
    if(newNode == NULL)
        return false;
    newNode->data = e;
    newNode->next = stack->next;
    stack->next = newNode;
    return true;
}

bool popStack(linkStack stack, elemType* e){
    if(stack == NULL || e == NULL || stack->next == NULL)
        return false;
    SNode* temp = stack->next;
    *e = temp->data;
    stack->next = temp->next;
    free(temp);
    return true;
}

bool getTopStack(linkStack stack, elemType* e){
    if(stack == NULL || e == NULL || stack->next == NULL)
        return false;
    *e = stack->next->data;
    return true;
}

bool destroyStack(linkStack* stack){
    if(stack == NULL || *stack == NULL)
        return false;
    SNode* temp = *stack;
    while(temp != NULL){
        SNode* p = temp->next;
        free(temp);
        temp = p;
    }
    *stack = NULL;
    return true;
}


