#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxSize 255

typedef struct{
    char ch[MaxSize];
    int len;
}SString;

int Index(SString s, SString t){
    int i = 0, j = 0;
    while(i < s.len && j < t.len){
        if(s.ch[i] == t.ch[j])
            i++, j++;
        else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(j == t.len) return i - t.len;
    else return -1;
}

void getNext(SString s, int next[]){
    next[0] = -1;
    int i = 0, j = -1;
    while(i < s.len){
        if(j == -1 || s.ch[i] == s.ch[j]){
            i++, j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

void getNextVal(SString s, int nextval[]){
    nextval[0] = -1;
    int i = 0, j = -1;
    while(i < s.len){
        if(j == -1 || s.ch[i] == s.ch[j]){
            i++, j++;
            if(i < s.len && s.ch[i] == s.ch[j])
                nextval[i] = nextval[j];
            else
                nextval[i] = j;
        } else
            j = nextval[j];
    }
}

int IndexKmp(SString s, SString t){
    int* next = (int*)malloc(t.len * sizeof(int));
    getNextVal(t, next);
    int i = 0, j = 0;
    while(i < s.len && j < t.len){
        if(j == -1 || s.ch[i] == t.ch[j])
            i++, j++;
        else
            j = next[j];
    }
    free(next);
    if(j == t.len) return i - t.len;
    else return -1;
}

void printNext(SString s, int next[], int len){
    printf("模式串: %s\n", s.ch);
    printf("next:   ");
    for(int i = 0; i < len; i++)
        printf("%3d", next[i]);
    printf("\n");
}

int main(){
    printf("=== KMP 算法测试 ===\n\n");

    struct {
        char* s;  // 主串
        char* t;  // 模式串
        int expected;
    } testCases[] = {
        // 基本匹配测试
        {"abcabc", "abc", 0},
        {"abcabc", "bca", 1},
        {"abcabc", "abcd", -1},
        {"aaaaab", "b", 5},
        {"abc", "abcd", -1},
        {"", "", 0},
        {"abc", "", 0},

        // KMP 优势测试（大量回溯）
        {"ababbbbaaabbbbaabb", "aabbbbaa", 8},
        {"aaaabaaaaac", "aaaaa", 5},
        {"abcdefg", "cde", 2},

        // 边界测试
        {"a", "a", 0},
        {"a", "b", -1},
        {"ab", "ab", 0},
        {"ab", "ba", -1},
        {"ab", "abc", -1},
        {"abc", "abc", 0},
        {"abc", "abd", -1},
    };

    int n = sizeof(testCases) / sizeof(testCases[0]);
    int passed = 0, failed = 0;

    printf("--- 测试 getNext ---\n");
    SString t;
    int next[MaxSize];

    char* patterns[] = {"AAA", "ABAB", "ABCD", "AAAAAB", "ABCDEF"};
    for(int p = 0; p < 5; p++){
        strcpy(t.ch, patterns[p]);
        t.len = strlen(patterns[p]);
        getNext(t, next);
        printNext(t, next, t.len + 1);
    }

    printf("\n--- 测试 getNextVal ---\n");
    int nextval[MaxSize];
    for(int p = 0; p < 5; p++){
        strcpy(t.ch, patterns[p]);
        t.len = strlen(patterns[p]);
        getNextVal(t, nextval);
        printNext(t, nextval, t.len + 1);
    }

    printf("\n--- 测试匹配算法 ---\n");
    SString s, pat;

    for(int i = 0; i < n; i++){
        strcpy(s.ch, testCases[i].s);
        s.len = strlen(testCases[i].s);
        strcpy(pat.ch, testCases[i].t);
        pat.len = strlen(testCases[i].t);

        int resultBF = Index(s, pat);
        int resultKMP = IndexKmp(s, pat);

        int correct = (resultBF == testCases[i].expected && resultKMP == testCases[i].expected);

        if(correct){
            printf("✓ \"%s\" 在 \"%s\" 中: %d\n", testCases[i].t, testCases[i].s, resultKMP);
            passed++;
        } else{
            printf("✗ \"%s\" 在 \"%s\": 期望 %d, BF=%d, KMP=%d\n",
                   testCases[i].t, testCases[i].s, testCases[i].expected, resultBF, resultKMP);
            failed++;
        }
    }

    printf("\n=== 测试结果 ===\n");
    printf("通过: %d/%d\n", passed, n);
    printf("失败: %d/%d\n", failed, n);

    return 0;
}
