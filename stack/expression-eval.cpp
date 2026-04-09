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

bool makeExpression(char* str,char* temp){
    if(str == NULL){
        return false;
    }
    linkStack s;
    if(!initStack(&s))
        return false;
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
    return true;

}

bool eval(char* str,int* result){
    if(str==NULL)
        return false;
    linkStack s;
    if(!initStack(&s)) return false;
    int i = 0;
    while(str[i]!='\0'){
        if(isdigit(str[i])){
            int num = 0;
            int ch;
            while(isdigit(str[i])){
                num = num*10 + (str[i]-'0');
                i++;
            }
            if(!pushStack(s, num)) {
                destroyStack(&s);
                return false;
            }
        }
        else if(str[i]==' '){
            i++;
            continue;
        }
        else{
            int x,y;
            int temp;
            if(!popStack(s,&y)||!popStack(s,&x)){
                destroyStack(&s);
                return false;
            }
            switch(str[i]){
                case '+':temp = x + y;break;
                case '-':temp = x - y;break;
                case '*':temp = x * y;break;
                case '/':if(y==0) return false; temp = x / y;break;
                default: return false;
            }
            if(!pushStack(s,temp)){
                destroyStack(&s);
                return false;
            }
            i++;
        }
    }
    bool success =  (!isEmptyStack(s)) && popStack(s,result);
    destroyStack(&s);
    return success && isEmptyStack(s);
}

// 测试函数
void testExpression(const char* expr) {
    printf("测试表达式: %s\n", expr);
    
    // 步骤1: 中缀转后缀
    char postfix[256];
    if (!makeExpression((char*)expr, postfix)) {
        printf("  转换失败!\n");
        return;
    }
    printf("  后缀表达式: %s\n", postfix);
    
    // 步骤2: 后缀表达式求值
    int result;
    if (!eval(postfix, &result)) {
        printf("  求值失败!\n");
        return;
    }
    
    printf("  结果: %d\n", result);
    printf("\n");
}

int main() {
    printf("=== 表达式求值测试 ===\n\n");
    
    // 测试用例
    testExpression("1+2");                   // 简单表达式
    testExpression("123+456");               // 多位数加法
    testExpression("(1+2)*3");               // 括号
    testExpression("(123+456)*789");         // 多位数和括号
    testExpression("12*(34+56)");            // 括号内多位数
    testExpression("((100-50)*2)/10");       // 嵌套括号
    testExpression("3+4*2/(1-5)");           // 复杂表达式
    
    return 0;
}