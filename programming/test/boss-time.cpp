#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int l;
    int r;
}Time;

void printTime(int t) {
    int h = t / 3600;
    int m = (t % 3600) / 60;
    int s = t % 60;
    printf("%02d:%02d:%02d", h, m, s);
}

int cmp(const void* a,const void* b){
    Time* ta = (Time*)a;
    Time* tb = (Time*)b;
    return ta->l - tb->l;
}

int main(){
    int n;
    scanf("%d",&n);
    Time time[n];
    for(int i=0;i<n;i++){
        int h1, m1, s1, h2, m2, s2;
        scanf("%d:%d:%d - %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        time[i].l = h1 * 3600 + m1 * 60 + s1;
        time[i].r = h2 * 3600 + m2 * 60 + s2;
    }

    qsort(time,n,sizeof(Time),cmp);

    int start = 0;
    int end = 60*23*60 + 59*60 + 59;

    if(time[0].l > start){
        printTime(start);
        printf(" - ");
        printTime(time[0].l);
        printf("\n");
    }
    for(int i=0;i<n-1;i++){
        if(time[i].r < time[i+1].l){
            printTime(time[i].r);
            printf(" - ");
            printTime(time[i+1].l);
            printf("\n");
        }
    }
    if(time[n-1].r<end){
        printTime(time[n-1].r);
        printf(" - ");
        printTime(end);
    }
    return 0;
}
