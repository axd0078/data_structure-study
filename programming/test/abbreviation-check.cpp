#include <stdio.h>
#include <string.h>

int main(){
    char str1[1000];
    char str2[1000];
    int t;
    scanf("%d", &t);
    while (getchar() != '\n');  // 清除换行符
    
    int results[100];  // 1表示Yes，0表示No
    int count = 0;
    
    for(int i = 0; i < t; i++){
        scanf("%s", str1);
        scanf("%s", str2);
        
        char temp[1000] = {0};
        int len = strlen(str1);
        temp[0] = str1[0];
        int n = 1;
        for(int j = 1; j < len; j++){
            if(str1[j-1] == '_'){
                temp[n] = str1[j];
                n++;
            }
        }
        temp[n] = '\0';
        
        results[count++] = (strcmp(temp, str2) == 0) ? 1 : 0;
    }
    
    // 最后统一输出
    for(int i = 0; i < count; i++){
        printf("%s\n", results[i] ? "Yes" : "No");
    }
    
    return 0;
}