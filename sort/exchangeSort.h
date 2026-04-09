void swap(int* a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int nums[],int numsSize){
    for(int i=0;i<numsSize-1;i++){
        int flag = 0;
        for(int j = numsSize-1;j>i;j--){    //从后往前排序
            if(nums[j-1]>nums[j]){
                swap(&nums[j-1],&nums[j]);
                flag = 1;
            }
        }
        if(!flag)
            return;
    }
}

int partition(int nums[],int low,int high){
    int pivot = nums[low];
    while(low<high){
        while(low<high && nums[high] >= pivot) high--;
        nums[low] = nums[high];
        while(low<high && nums[low] <= pivot) low++;
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}

void quickSort(int nums[],int low ,int high){
    if(low<high){
        int pivot = partition(nums,low,high);

        quickSort(nums,low,pivot-1);
        quickSort(nums,pivot+1,high);
    }
}

void quickSort(int nums[], int numsSize){
    if(numsSize > 1){
        quickSort(nums, 0, numsSize - 1);
    }
}
