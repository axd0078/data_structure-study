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
			next[i] = j;//字符相同指针前移，next值为j，因为j是从-1开始，所以next[j]放的是上一个字符的最长相同前后缀长度 
		}
		else
			j = next[j];//字符不相同，j退到离j上一个字符最近的相同的字符的下一个字符 
			//.........j.......i 
			//...B*...BA......BC
			//因为A!=C,所以
			//....j............i
			//...B*...BA......BC
	}
}
//a b a b a b b
//0 0 1 2 3 4 0
//a b a c a b a b
int indexKmp(char* s,char* p,int pos,int next[]){//pos是开始位置的下标 
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
