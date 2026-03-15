#include <stdio.h>
#include <stdlib.h>
#define SIZE 100


int UFset[SIZE];

void init(int s[]){
    for(int i=0;i<SIZE;i++)
        s[i] = -1;
}

int find(int s[],int x){
    while(s[x]>=0)
        x = s[x];
    return x;
}

void unionSet(int s[],int root1,int root2){
    if(root1==root2) return;
    else s[root1] = root2;
}

void unionPro(int s[],int root1,int root2){
    if(s[root1]>s[root2]){
        s[root1] += s[root2];
        s[root2] = root1;
    }
    else{
        s[root2] += s[root1];
        s[root1] = root2;
    }
}

int findPro(int s[],int x){
    int root = x;
    while(s[root]>=0)
        root = s[root];
    while(x!=root){
        int t = s[x];
        s[x] = root;
        x = t;
    }
    return root;
}