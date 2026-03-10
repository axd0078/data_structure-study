#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 255

typedef struct{
    char ch[MaxSize];
    int len;
}SString;

int Index(SString s,SString t){
    int i = 0,j = 0;
    while(i<s.len && j<t.len){
        if(s.ch[i]==t.ch[j])
            i++,j++;
        else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(j==t.len) return i - t.len;
    else return -1;
}//这里的i，j都是下标，从0开始计数，返回值是匹配到的子串t在主串s中的下标，后续kmp都是如此

void getNext(SString s,int next[]){
    next[0] = -1;
    int i = 0,j = -1;
    while(i<s.len){
        if(j==-1 || s.ch[i]==s.ch[j]){
            i++,j++;
            next[i] = j; //若s.ch[i]==s.ch[j]，则next[j+1] = next[j] + 1 = j + 1，但是刚好在这之前j++了，所以可以直接使用j;
        }
        else
            j = next[j];//
    }
}//因为下标从0开始，所以初始化next[0] = -1,i = 0,j = -1;

void getNextVal(SString s,int nextval[]){
    nextval[0] = -1;
    int i = 0,j = -1;
    while(i<s.len){
        if(j==-1 || s.ch[i]==s.ch[j]){
            i++,j++;
            if(s.ch[i]==s.ch[j]) nextval[i] = nextval[j];//相同找爷爷
            else nextval[i] = j;//不同找父亲
        }
        else
            j = nextval[j];
    }
}

int IndexKmp(SString s,SString t){
    int next[t.len];
    getNextVal(t,next);
    int i=0,j=0;
    while(i<s.len && j<t.len){
        if(j==-1 || s.ch[i]==t.ch[j])
            i++,j++;
        else
            j = next[j];
    }
    if(j==t.len) return i-t.len;
    else return -1;
}