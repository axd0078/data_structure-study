#include <stdio.h>

int main(){
    int map[3][3];
    int visited[10] = {0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&map[i][j]);
            visited[map[i][j]] = 1;
        }
    }
    int a = 0;
    for(int i = 1;i<=9;i++){
        if(visited[i]!=1){
            a = i;
            break;
        }
    }//去寻找缺哪一个 哪一个是已知的
    int row,col;
    for(int i=0;i<3;i++){
        scanf("%d %d",&row,&col);
        printf("%d\n",map[row-1][col-1]);
    }
    int choice;
    int point = 0;
    scanf("%d",&choice);
    if(choice>=1&&choice<=3){
        for(int i=0;i<3;i++){
            if(map[choice-1][i]==0) point+=a;
            else point+=map[choice-1][i];
        }
    }
    else if(choice>=4&&choice<=6){
        for(int i=0;i<3;i++){
                if(map[i][choice-4]==0) point+=a;
                else point+=map[i][choice-4];
        }
    }
    else if(choice==7){
        for(int i=0;i<3;i++){
            if(map[i][i]==0) point+=a;
            else point+=map[i][i];
        }
    }
    else if(choice==8){
        for(int i=0;i<3;i++){
            if(map[i][2-i]==0) point+=a;
            else point+=map[i][2-i];
        }
    }
    switch(point){
        case 6:printf("10000\n");break;
        case 7:printf("36\n");break;
        case 8:printf("720\n");break;
        case 9:printf("360\n");break;
        case 10:printf("80\n");break;
        case 11:printf("252\n");break;
        case 12:printf("108\n");break;
        case 13:printf("72\n");break;
        case 14:printf("54\n");break;
        case 15:printf("180\n");break;
        case 16:printf("72\n");break;
        case 17:printf("180\n");break;
        case 18:printf("119\n");break;
        case 19:printf("36\n");break;
        case 20:printf("306\n");break;
        case 21:printf("1080\n");break;
        case 22:printf("144\n");break;
        case 23:printf("1800\n");break;
        case 24:printf("3600\n");break;
    }
    return 0;
}
