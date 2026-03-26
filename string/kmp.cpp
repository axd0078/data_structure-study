#include <stdio.h>
#include <string.h>
void getNext(char* str,int next[]){
	int i,j,len;
	len = strlen(str);
	i = 0;
	j = -1;
	next[0] = -1;
	while(i<len){
		if(j==-1||str[i]==str[j]){
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
int indexKmp(char* s,char* p,int pos,int next[]){
	getNext(p,next);
	int i,j,slen,plen;
	i = pos-1;
	j = -1;
	slen = strlen(s);
	plen = strlen(p);
	while(i<slen&&j<plen){
		if(j==-1||s[i]==p[j]){
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if(j>=plen)
		return i-plen;
	else
		return -1;
}
int main(){
	char s[] = "abacbcabababbcbc";
	char p[] = "abababb";
	int next[100];
	fflush(stdin);
	printf("%d\n",indexKmp(s,p,0,next));
	for(int i=0;i<=10;i++){
		printf("%d ",next[i]);
	}
	return 0;
} 
