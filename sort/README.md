# 排序 (Sort)

当前模块主要整理插入类排序算法的实现与测试，包括直接插入排序、折半插入排序和希尔排序。

代码同时演示了两种常见写法：

- 带哨兵的 `int` 数组版本：有效数据位于 `nums[1] ~ nums[numsSize]`
- 普通下标的 `double` 数组版本：有效数据位于 `nums[0] ~ nums[numsSize - 1]`

## 文件结构

| 文件 | 说明 |
|------|------|
| `insertSort.h` | 插入排序、折半插入排序、希尔排序实现 |
| `testInsertSort.cpp` | 排序结果校验与示例输出 |

## 已实现算法

### 直接插入排序 `insertSort`

通过维护前缀有序区，将当前元素插入到合适位置。

```c
void insertSort(int nums[], int numsSize);
void insertSort(double nums[], int numsSize);
```

特点：

- 稳定排序
- 适合基本有序的数据
- 时间复杂度：`O(n^2)`
- 空间复杂度：`O(1)`

### 折半插入排序 `BInsertSort`

先用二分查找确定插入位置，再整体后移元素。

```c
void BInsertSort(int nums[], int numsSize);
void BInsertSort(double nums[], int numsSize);
```

特点：

- 仍然需要移动元素，整体时间复杂度仍为 `O(n^2)`
- 比直接插入排序减少了比较次数
- 当前实现通过“相等时继续向右找”的方式保持稳定性

### 希尔排序 `shellSort`

按增量分组进行插入排序，逐步缩小增量直到 `1`。

```c
void shellSort(int nums[], int numsSize);
void shellSort(double nums[], int numsSize);
```

特点：

- 属于分组插入排序
- 通常比直接插入排序更快
- 不稳定排序
- 复杂度与增量序列有关

## 接口约定

### `int` 版本

`int` 版本使用哨兵位，调用时需要额外预留 `nums[0]`：

```cpp
int nums[] = {0, 49, 38, 65, 97, 76, 13, 27, 49};
insertSort(nums, 8);
```

说明：

- `nums[0]` 不参与最终排序结果，只作为临时哨兵
- 有效元素范围是 `nums[1]` 到 `nums[numsSize]`

### `double` 版本

`double` 版本使用普通数组下标：

```cpp
double nums[] = {4.5, 2.2, 2.2, 8.1, 3.6, 0.5};
insertSort(nums, 6);
```

说明：

- 有效元素范围是 `nums[0]` 到 `nums[numsSize - 1]`
- 更适合和 STL 容器或普通数组直接配合

## 测试说明

`testInsertSort.cpp` 会分别测试：

- `insertSort(int)`
- `BInsertSort(int)`
- `shellSort(int)`
- `insertSort(double)`
- `BInsertSort(double)`
- `shellSort(double)`

测试会输出：

- `PASS` / `FAIL`
- 排序后的数组内容

其中：

- `int` 版本通过 `isSortedIntWithSentinel` 校验有序性
- `double` 版本通过 `isSortedDouble` 校验有序性，并用 `1e-9` 处理浮点比较

## 运行示例

### Linux / macOS / Git Bash

```bash
g++ -std=c++11 testInsertSort.cpp -o test && ./test
```

### Windows PowerShell

```powershell
g++ -std=c++11 .\testInsertSort.cpp -o testInsertSort.exe
.\testInsertSort.exe
```

## 学习建议

建议按下面顺序阅读：

1. 先看 `insertSort`，理解“有序区 + 插入”思想
2. 再看 `BInsertSort`，对比“比较次数减少，但移动次数不变”
3. 最后看 `shellSort`，理解“缩小增量”的优化思路

如果后续继续扩展本模块，可以补充：

- 冒泡排序
- 选择排序
- 快速排序
- 堆排序
- 归并排序
