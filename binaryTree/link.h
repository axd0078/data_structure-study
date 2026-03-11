#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BNode{
    int data;
    struct BNode* left;
    struct BNode* right;
}BNode,*BiTree;