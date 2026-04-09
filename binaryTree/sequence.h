#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100  // 顺序存储的最大容量

typedef struct {
    int data[MAXSIZE+1];  // 存储二叉树节点值
    int tag[MAXSIZE+1];   //0表示该节点为空节点，1反之   
    //多一个空间，编号就是下标   
} SeqBinaryTree;

void initTree(SeqBinaryTree* tree){
    for(int i=0;i<=MAXSIZE;i++)
        tree->tag[i] = 0;
}

void createTree(SeqBinaryTree *tree)
{
    int n;
    int value;

    printf("请输入节点数量:\n");
    scanf("%d",&n);

    printf("按顺序输入节点值(-1表示空节点):\n");

    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&value);

        if(value != -1)
        {
            tree->data[i] = value;
            tree->tag[i] = 1;
        }
        else
        {
            tree->tag[i] = 0;
        }
    }
}



