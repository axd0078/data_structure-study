# 排序 (Sort)

## 模块简介

`sort` 目录按排序家族整理实现，目前包含插入类排序、交换类排序、选择类排序以及其他常见排序实现，适合对照不同排序思路和接口写法。

## 文件结构

| 文件 | 说明 |
|------|------|
| `insertSort.h` | 直接插入排序、折半插入排序、希尔排序 |
| `exchangeSort.h` | 冒泡排序、快速排序 |
| `selectSort.h` | 选择排序、堆排序 |
| `otherSort.h` | 归并排序、计数排序 |
| `testInsertSort.cpp` | 插入类排序测试 |
| `testExchangeSort.cpp` | 交换类排序测试 |
| `testSelectSort.cpp` | 选择类排序测试 |

## 已实现算法

### 插入类排序

| 算法 | 接口 | 特点 |
|------|------|------|
| 直接插入排序 | `insertSort` | 稳定排序，适合基本有序数据 |
| 折半插入排序 | `BInsertSort` | 比较次数更少，但移动次数仍然较多 |
| 希尔排序 | `shellSort` | 通过缩小增量加速插入过程，不稳定 |

### 交换类排序

| 算法 | 接口 | 特点 |
|------|------|------|
| 冒泡排序 | `bubbleSort` | 稳定排序，代码直观，支持提前结束 |
| 快速排序 | `quickSort` | 通过分区递归排序，平均性能较好 |

### 选择类排序

| 算法 | 接口 | 特点 |
|------|------|------|
| 简单选择排序 | `selectSort` | 每轮选出最小值放到前面，实现直接 |
| 堆排序 | `heapSort` | 通过最大堆完成原地排序，时间复杂度稳定 |

### 其他排序

| 算法 | 接口 | 特点 |
|------|------|------|
| 归并排序 | `mergeSort` | 分治排序，稳定排序，需要辅助数组 |
| 计数排序 | `countSort` | 适合值域较小的整数序列，非比较排序 |

## 关键接口

### 插入类排序 `insertSort.h`

```c
void insertSort(int nums[], int numsSize);
void insertSort(double nums[], int numsSize);
void BInsertSort(int nums[], int numsSize);
void BInsertSort(double nums[], int numsSize);
void shellSort(int nums[], int numsSize);
void shellSort(double nums[], int numsSize);
```

### 交换类排序 `exchangeSort.h`

```c
void bubbleSort(int nums[], int numsSize);
int partition(int nums[], int low, int high);
void quickSort(int nums[], int low, int high);
void quickSort(int nums[], int numsSize);
```

### 选择类排序 `selectSort.h`

```c
void selectSort(int nums[], int numsSize);
void headAdjust(int nums[], int k, int numsSize);
void buildMaxHeap(int nums[], int numsSize);
void heapSort(int nums[], int numsSize);
```

### 其他排序 `otherSort.h`

```c
void merge(int a[], int b[], int low, int mid, int high);
void mergeSort(int a[], int b[], int high, int low);
void countSort(int a[], int b[], int n, int k);
```

## 接口约定

### 插入类中的 `int` 版本

插入类排序对 `int` 数组采用哨兵写法，有效元素位于 `nums[1] ~ nums[numsSize]`，`nums[0]` 仅作为临时哨兵位：

```cpp
int nums[] = {0, 49, 38, 65, 97, 76, 13, 27, 49};
insertSort(nums, 8);
```

### 插入类中的 `double` 版本

`double` 版本采用普通下标数组，有效元素位于 `nums[0] ~ nums[numsSize - 1]`：

```cpp
double nums[] = {4.5, 2.2, 2.2, 8.1, 3.6, 0.5};
BInsertSort(nums, 6);
```

### 交换类排序

交换类排序当前只提供普通 `int` 数组接口：

```cpp
int nums[] = {49, 38, 65, 97, 76, 13, 27, 49};
quickSort(nums, 8);
```

### 选择类排序

选择类排序当前也采用普通 `int` 数组接口：

```cpp
int nums[] = {49, 38, 65, 97, 76, 13, 27, 49};
heapSort(nums, 8);
```

### 其他排序

`otherSort.h` 当前也面向普通 `int` 数组：

```cpp
int a[] = {49, 38, 65, 97, 76, 13, 27, 49};
int b[8];
mergeSort(a, b, 7, 0);
```

## 测试说明

- `testInsertSort.cpp` 会验证 `insertSort`、`BInsertSort`、`shellSort` 在 `int` 哨兵数组和 `double` 普通数组上的表现。
- `testExchangeSort.cpp` 会验证 `bubbleSort` 与 `quickSort`，并覆盖普通输入、重复元素和已排序输入。
- `testSelectSort.cpp` 会验证 `selectSort` 与 `heapSort`，并覆盖普通输入、重复元素、单元素和已排序输入。
- `otherSort.h` 当前只提供实现，暂未配套独立测试文件。
- 测试程序统一输出 `PASS` / `FAIL` 以及排序后的数组内容。

## 运行方式

```bash
g++ -std=c++11 testInsertSort.cpp -o test && ./test
g++ -std=c++11 testExchangeSort.cpp -o test && ./test
g++ -std=c++11 testSelectSort.cpp -o test && ./test
```

## 学习建议

1. 先看 `insertSort.h`，掌握“有序区 + 插入”的基本思想。
2. 再看 `exchangeSort.h`，对比交换类排序的局部交换与分治过程。
3. 然后看 `selectSort.h`，对比“选最值”和“建堆”两类选择思想。
4. 最后看 `otherSort.h`，理解分治排序和非比较排序的差异。
5. 学习 `quickSort` 时，重点关注 `partition` 如何围绕枢轴划分区间。
