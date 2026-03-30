void insertSort(double nums[], int numsSize){
    for(int i = 1; i < numsSize; i++){
        if(nums[i] < nums[i - 1]){
            double temp = nums[i];
            int j = i - 1;
            while(j >= 0 && temp < nums[j]){ // 用 < 而不是 <=，相等元素不后移，保持稳定性
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = temp;
        }
    }
}

// 哨兵写法：有效数据存放在 nums[1] ~ nums[numsSize]，nums[0] 仅作为哨兵位。
void insertSort(int nums[], int numsSize){
    int j;
    for(int i = 2; i <= numsSize; i++){
        if(nums[i] < nums[i - 1]){
            nums[0] = nums[i];
            for(j = i - 1; nums[0] < nums[j]; j--){ // 只移动严格大于哨兵的元素，相等元素相对次序不变
                nums[j + 1] = nums[j];
            }
            nums[j + 1] = nums[0];
        }
    }
}

void BInsertSort(int nums[],int numsSize){
    int low,high,mid;

    for(int i=2;i<=numsSize;i++){
        nums[0] = nums[i];
        low = 1;high = i-1;
        while(low<=high){
            mid = low + (high-low) / 2;
            if(nums[mid] <= nums[0]) low = mid+1;    // 相等时继续向右找，让新元素插到已有相等元素后面，保持稳定性
            else high = mid - 1;
        }
        //low 会停在“第一个大于等于哨兵的位置”
        //high 会停在“最后一个小于哨兵的位置”
        for(int j = i-1;j>=high+1;j--){//一直搬到插入位置 high + 1
            nums[j+1] = nums[j];
        }
        nums[high+1] = nums[0];//直接表达“哨兵插回插入位置”
    }
}

void BInsertSort(double nums[],int numsSize){
    int low,high,mid;
    for(int i=1;i<numsSize;i++){
        double temp = nums[i];
        low = 0;
        high = i-1;
        while(low<=high){
            mid = low + (high-low) / 2;
            if(nums[mid] <= temp)    low = mid + 1; // 相等时继续向右找，让新元素插到已有相等元素后面，保持稳定性
            else high = mid - 1;
        }
        for(int j = i-1;j>=low;j--){
            nums[j+1] = nums[j];
        }
        nums[low] = temp;
    }
}


void shellSort(int nums[],int numsSize){//带哨兵的
    for(int k = numsSize/2;k>=1;k/=2){
        for(int i=k+1;i<=numsSize;i++){//下标从1开始
            if(nums[i] < nums[i-k]){
                nums[0] = nums[i];
                int j;
                for(j = i-k;j>0 && nums[0]<nums[j];j-=k){
                    nums[j+k] = nums[j];
                }
                nums[j+k] = nums[0];
            } //这里的增量就是k，不再是比较相邻了
        }
    }
}

void shellSort(double nums[],int numsSize){
    for(int k = numsSize/2;k>=1;k/=2){
        for(int i = k;i<numsSize;i++){//下标从0开始
            if(nums[i]<nums[i-k]){
                double temp = nums[i];
                int j;
                for(j = i - k;j>=0&& nums[j] > temp;j-=k){
                    nums[j+k] = nums[j];
                }
                nums[j+k] = temp;
            }

        }
    }
}