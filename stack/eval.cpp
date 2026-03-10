#include "link.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int priority(char ch){
    switch(ch){
        case '+':
        case '-':return 1;

        case '*':
        case '/':return 2;

        case '(':return 0;

        default:return -1;
    }
}

bool fun(char* str,double* result){
    if(str == NULL){
        return false;
    }
    linkStack s;
    if(!initStack(&s))
        return false;
    char temp[150] = {0};
    int i = 0,j = 0;
    while(str[i]!='\0'){
        if(isdigit(str[i]))
        {
            while(isdigit(str[i]))
            {
                temp[j++] = str[i++];
            }
            temp[j++] = ' ';
        }//遇到操作数，连续判断后续字符是否为数字，不断添加到temp，数字部分结束之后用空格隔开
        else if(str[i]=='('){
            pushStack(s,str[i]);
            i++;
        }//( --直接入栈
        else if(str[i]==')'){
            int ch;
            while(getTopStack(s,&ch) && ch!= '('){
                popStack(s,&ch);
                temp[j++] = ch;
            }
            popStack(s,&ch);
                i++;
        }//) --不断弹出栈中运算符，直到遇到(
        else{
            int ch;
            while(!isEmptyStack(s) && getTopStack(s,&ch) &&  ch!='(' && priority(str[i])<=priority(ch) ){
                popStack(s,&ch);
                temp[j++] = ch;
            }//查看栈顶元素之前需要判空
            pushStack(s,str[i]);
            i++;
        }
    }// 遇到运算符 1. 栈顶元素是( || 栈顶符号优先级高于当前运算符 --直接入栈
            //   2 当前运算符优先级低于或等于栈顶，不断弹出直到 (1)栈空 (2) '(' (3)当前高于栈顶
    while(!isEmptyStack(s)){
        int ch;
        popStack(s, &ch);
        temp[j++] = ch;
    }//将剩余运算符弹出，加入结果

    temp[j] = '\0';
}