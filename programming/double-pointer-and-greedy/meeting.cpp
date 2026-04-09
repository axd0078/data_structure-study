#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b){
    int* pa = (int*)a;
    int* pb = (int*)b;
    return *pa - *pb;
}

int minMeetingRooms(int meetings[][2],int numsSize){
    int begin[numsSize];
    int end[numsSize];
    for(int i=0;i<numsSize;i++){
        begin[i] = meetings[i][0];
        end[i] = meetings[i][1];
    }

    qsort(begin,numsSize,sizeof(int),cmp);
    qsort(end,numsSize,sizeof(int),cmp);
    //对其进行排序

    int count = 0;
    int maxCount = count;
    int i = 0,j = 0;

    /*while(time<=end[numsSize-1]){
        if(begin[i]==time){
            count++;
            i++;
        }//当前时间有会议发生 count++
            
        if(end[j]==time){
            count--;
            j++;
        }//有会议结束，count--
        if(count>maxCount)
            maxCount = count;

        time++;//time elapse
    }*/     //这个算法的时间复杂度取决于end[numsNums-1],这不好

    while(i<numsSize && j<numsSize){
        if(begin[i]<end[j]){//模拟时间轴，看哪个时间先发生
            count ++;
            i++;
        }
        else{
            count --;
            j++;
        }
        maxCount = count>maxCount?count:maxCount;
    }       //将时间分为结点，处理结点处，可以高效解决问题！

    return maxCount;
}

int main(){
    int n;
    scanf("%d",&n);
    int times[n][2];
    for(int i=0;i<n;i++){
        scanf("%d %d",&times[i][0],&times[i][1]);
    }
    printf("%d\n",minMeetingRooms(times,n));
    return 0;
}