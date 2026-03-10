#include "link.h"
#include <string.h>
#include <stdio.h>

bool fun(char* str){
    if(str == NULL)
        return false;

    linkStack s;
    if(!initStack(&s))
        return false;

    int len = strlen(str);
    for(int i=0; i<len; i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            pushStack(s, str[i]);
        }
        else if(str[i]==')' || str[i]=='}' || str[i]==']'){
            int ch;
            if(isEmptyStack(s)){
                destroyStack(&s);
                return false;
            }
            if(!getTopStack(s, &ch)){
                destroyStack(&s);
                return false;
            }
            if((ch=='(' && str[i]==')') ||
               (ch=='{' && str[i]=='}') ||
               (ch=='[' && str[i]==']'))
                popStack(s, &ch);
            else{
                destroyStack(&s);
                return false;
            }
        }
    }

    bool result = isEmptyStack(s);
    destroyStack(&s);
    return result;
}

int main() {
    printf("=== 括号匹配测试 ===\n\n");

    struct {
        char* str;
        int expected;
    } testCases[] = {
        {"()", 1},
        {"()[]{}", 1},
        {"([{}])", 1},
        {"", 1},
        {"a(b)c", 1},
        {"(]", 0},
        {"(", 0},
        {")", 0},
        {"(()", 0},
        {"())", 0},
        {"([)]", 0},
        {"{", 0},
        {"}", 0},
        {"[", 0},
        {"]", 0},
        {"((()))", 1},
        {"{[]()[]}", 1},
        {"[{()}]", 1},
        {"{[}]", 0},
        {"((((", 0},
        {"))))", 0},
        {"a(b[c{d}e]f)g", 1},
        {"a(b)c)d", 0},
    };

    int n = sizeof(testCases) / sizeof(testCases[0]);
    int passed = 0;
    int failed = 0;

    for(int i = 0; i < n; i++) {
        int result = fun(testCases[i].str);
        int expected = testCases[i].expected;

        if(result == expected) {
            printf("✓ 测试 %2d: \"%-20s\" -> %s\n", i+1, testCases[i].str, result ? "匹配" : "不匹配");
            passed++;
        } else {
            printf("✗ 测试 %2d: \"%-20s\" -> 期望: %s, 实际: %s\n",
                   i+1, testCases[i].str,
                   expected ? "匹配" : "不匹配",
                   result ? "匹配" : "不匹配");
            failed++;
        }
    }

    printf("\n=== 测试结果 ===\n");
    printf("通过: %d/%d\n", passed, n);
    printf("失败: %d/%d\n", failed, n);

    return 0;
}
