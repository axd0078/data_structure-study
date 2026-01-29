#ifndef DYNAMIC_H
#define DYNAMIC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // 添加这行来支持 bool 类型

#define INITSIZE 15

typedef struct{
	int* data;
	int maxSize,length;
}sqList;

#ifdef __cplusplus
extern "C" {
#endif

sqList* initList();
void expandList(sqList* list, int extraSize);
bool listInsert(sqList* list, int i, int e);
bool listDelete(sqList* list, int i, int* e);
int listSearch(sqList* list, int e);
void listPrint(sqList* list);

#ifdef __cplusplus
}
#endif

#endif

sqList* initList(){
	sqList* list = (sqList*)malloc(sizeof(sqList));
	list->data = (int*)malloc(INITSIZE*sizeof(int));
	list->maxSize = INITSIZE;
	list->length = 0;
	return list;
}

void expandList(sqList* list,int extraSize){
	int* newData = (int*)malloc((extraSize+list->maxSize)*sizeof(int));
	for(int i=0;i<list->length;i++){
		newData[i] = list->data[i];
	}
	free(list->data);
	list->data = newData;
	list->maxSize += extraSize;
}

bool listInsert(sqList* list,int i,int e){
	if(i>list->length+1||i<1)  //from 1 to len+1 
		return false;
	if(list->length>=list->maxSize)
		expandList(list,INITSIZE);
	for(int j=list->length;j>=i;j--){
		list->data[j] = list->data[j-1];
	}
	list->data[i-1] = e;
	list->length++;
	return true;
}

bool listDelete(sqList* list,int i,int* e){
	if(i>list->length||i<1)
		return false;
	*e = list->data[i-1];
	for(int j=i;j<list->length;j++){
		list->data[j-1] = list->data[j];
	}
	list->length--;
	return true;
}

int listSearch(sqList* list,int e){
	for(int i=0;i<list->length;i++){
		if(list->data[i]==e)
			return i+1;
	}
	return 0;
}

void listPrint(sqList* list){
	for(int i=0;i<list->length;i++){
		printf("%d ",list->data[i]);
	}
	printf("\n");
}