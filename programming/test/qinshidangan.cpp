#include <stdio.h>
#include <math.h>

int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    getchar(); //用这个跳过\n
    char str[N+2];
    for(int i=0;i<M;i++){
        int ans = 1;    //当前这个子树里，最左边叶子的编号 不是子树的编号!!!
        fgets(str,sizeof(str),stdin);
        for(int j=0;j<N&&str[j]!='\n';j++){
            if(str[j]=='y'){
                ans = 2*ans - 1;
            }
            else{
                ans = 2*ans;
            }
        }
        printf("%d\n",ans);
    }
}