#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int l,r;
}interval;

int cmp(const void* a,const void* b){
    interval* pa = (interval*)a;
    interval* pb = (interval*)b;
    return pa->l - pb->l;
}

int main(){
    int n;
    interval intervals[5000];
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&intervals[i-1].l,&intervals[i-1].r);
    }
    int len = n;
    qsort(intervals,n,sizeof(interval),cmp);
    int i = 1;
    while(i<n){
        if(intervals[i].l>intervals[i-1].l && intervals[i].l <= intervals[i-1].r){
            intervals[i-1].r = intervals[i].r > intervals[i-1].r?intervals[i].r:intervals[i-1].r;
            for(int j = i;j<len;j++){
                intervals[j] = intervals[j+1];
            }
            len--;
        }//发生重叠
        else i++;
    }
    printf("%d\n",len);
    for(int i=0;i<len;i++){
        printf("%d %d\n",intervals[i].l,intervals[i].r);
    }
    return 0;
}