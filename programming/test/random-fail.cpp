#include <stdio.h>
#include <string.h>

void win(char* str){
    if(strcmp(str,"ChuiZi")==0){
        printf("Bu\n");
    }
    else if(strcmp(str,"Bu")==0){
        printf("JianDao\n");
    }
    else if(strcmp(str,"JianDao")==0){
        printf("ChuiZi\n");
    }
}
void fail(char* str){
    if(strcmp(str,"ChuiZi")==0){
        printf("JianDao\n");
    }
    else if(strcmp(str,"Bu")==0){
        printf("ChuiZi\n");
    }
    else if(strcmp(str,"JianDao")==0){
        printf("Bu\n");
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int k[n];
    for(int i=0;i<n;i++){
        scanf("%d",&k[i]);
    }
    char str[15];
    fgets(str, sizeof(str), stdin);
    int index = 0;//维护
    int time = 0;
    while(fgets(str, sizeof(str), stdin)){
        str[strcspn(str, "\n")] = '\0';
        if(strcmp(str,"End")==0) break;
        if(time == k[index]){
            fail(str);
            time = 0;
            index = (index+1)%n;
        }//次数够了输一把吧 time变成0 下标+1
        else{
            win(str);
            time++;
        }//我操盘了
    }
    return 0;
}

