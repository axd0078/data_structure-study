#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
typedef struct{
	int data[MAXSIZE];
	int length;
}sqList;

void initList(sqList* list){
	list->length = 0;
}

bool listInsert(sqList* list,int i,int e){
	if(i>list->length+1||i<1)  //from 1 to len+1 
		return false;
	if(list->length>=MAXSIZE)
		return false;
	for(int j=list->length;j>=i;j--){
		list->data[j] = list->data[j-1];
	}
	list->data[i-1] = e;
	list->length++;
	return true;
}

bool listDelete(sqList* list,int i,int* e){
	if(i>list->length||i<1)  //from 1 to len
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

int main(){
	sqList* list = (sqList*)malloc(sizeof(sqList));
	initList(list);
	for(int i=1;i<=10;i++){
		listInsert(list,i,i);
	}
	listPrint(list);
	for(int i=5;i<=10;i++){
		int temp;
		listDelete(list,5,&temp); //must delete same place!
		printf("%d ",temp);
	}
	printf("\n");
	listPrint(list);
	if(listSearch(list,5)){
		printf("yes\n");
	}
	else{
		printf("no\n");
	}
	if(listSearch(list,3)){
		printf("yes\n");
	}
	else{
		printf("no\n");
	}
	
	return 0;
}
