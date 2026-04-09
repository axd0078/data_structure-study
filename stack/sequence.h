#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#define MaxSize 50
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int top;//表示当前栈顶元素下标
}sqStack;

bool initStack(sqStack* stack){
    if(stack==NULL)
        return false;
    stack->top = -1;
    return true;
}

bool isEmpty(sqStack* stack){
    if(stack == NULL)
        return true;
    return stack->top == -1;
}

bool push(sqStack* stack,ElemType e){
    if(stack == NULL)
        return false;
    if(stack->top==MaxSize-1)
        return false;
    stack->data[++stack->top] = e;
    return true;
}

bool pop(sqStack* stack,ElemType* e){ 
    if(stack == NULL || e == NULL)
        return false;
    if(stack->top==-1)
        return false;
    *e = stack->data[stack->top--];
    return true;
}

bool getTop(sqStack* stack,ElemType* e){
    if(stack == NULL || e == NULL)
        return false;
    if(stack->top==-1)
        return false;
    *e = stack->data[stack->top];
    return true;
}

bool destroyStack(sqStack** stack){
    if(stack == NULL || *stack == NULL)
        return false;
    free(*stack);
    *stack = NULL; // 避免野指针，使用二级指针是为了让主函数的实参置空，而不是副本形参置空
    return true;
}

int getStackLength(sqStack* stack){
    if(stack == NULL)
        return 0;
    return stack->top + 1;
}

bool clearStack(sqStack* stack){
    if(stack == NULL)
        return false;
    stack->top = -1;
    return true;
}

