#include <stdio.h>
#include <stdlib.h>

void fun(int** nums, int col, int row) {
    bool col0[col] = {false};
    bool row0[row] = {false};

    // 第一遍：找出所有0的位置，标记对应的行和列
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(nums[i][j] == 0) {
                col0[j] = true;
                row0[i] = true;
            }
        }
    }

    // 第二遍：将标记的列全部变0
    for(int j = 0; j < col; j++) {
        if(col0[j]) {
            for(int i = 0; i < row; i++) {
                nums[i][j] = 0;
            }
        }
    }

    // 第三遍：将标记的行全部变0
    for(int i = 0; i < row; i++) {
        if(row0[i]) {
            for(int j = 0; j < col; j++) {
                nums[i][j] = 0;
            }
        }
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    // 动态分配二维数组
    int** nums = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++) {
        nums[i] = (int*)malloc(n * sizeof(int));
    }

    // 输入矩阵数据
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &nums[i][j]);
        }
    }

    // 处理矩阵
    fun(nums, n, m);

    // 输出结果
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", nums[i][j]);
        }
        printf("\n");
    }

    // 释放内存
    for(int i = 0; i < m; i++) {
        free(nums[i]);
    }
    free(nums);

    return 0;
}