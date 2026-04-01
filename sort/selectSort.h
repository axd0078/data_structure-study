void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectSort(int nums[], int numsSize){
    for(int i = 0; i < numsSize - 1; i++){
        int min = i;
        for(int j = i + 1; j < numsSize; j++){
            if(nums[j] < nums[min]) min = j;
        }
        if(min != i){
            swap(&nums[min], &nums[i]);
        }
    }
}

void headAdjust(int nums[], int k, int numsSize){
    int temp = nums[k];
    for(int i = 2 * k + 1; i < numsSize; i = 2 * i + 1){
        if(i < numsSize - 1 && nums[i] < nums[i + 1]){
            i++;
        }
        if(nums[i] > temp){
            nums[k] = nums[i];
            k = i;
        } else {
            break;
        }
    }
    nums[k] = temp;
}

void buildMaxHeap(int nums[], int numsSize){
    for(int i = numsSize / 2 - 1; i >= 0; i--){
        headAdjust(nums, i, numsSize);
    }
}

void heapSort(int nums[], int numsSize){
    buildMaxHeap(nums, numsSize);
    for(int i = numsSize - 1; i > 0; i--){
        swap(&nums[i], &nums[0]);
        headAdjust(nums, 0, i);
    }
}
