# 顺序表 (Sequential List)

## 模块简介

`sqList` 目录包含动态顺序表的基础实现，以及围绕数组和线性表展开的经典练习题。整体以“基础结构 + 单题单文件”为组织方式，适合按题逐个编译和复习。

## 文件结构

| 文件 | 说明 |
|------|------|
| `dynamic.h` | 动态顺序表定义与基础操作 |
| `static-array-demo.cpp` | 静态顺序表示例 |
| 其余 `.cpp` | 基于顺序表或数组的独立练习题 |

## 题目列表

| 文件 | 题目 | 核心思路 |
|------|------|----------|
| `delete-min.cpp` | 删除最小元素 | 线性扫描找最小值，再用末元素覆盖 |
| `reverse-inplace.cpp` | 就地逆置 | 首尾双指针交换 |
| `delete-by-value.cpp` | 删除指定值 | 快慢指针压缩 |
| `delete-range.cpp` | 删除区间值 | 统计删除数量并整体前移 |
| `remove-duplicates.cpp` | 有序表去重 | 双指针保留不同值 |
| `merge-sorted.cpp` | 合并两个有序表 | 双路归并 |
| `array-swap.cpp` | 分段交换 | 三次逆置 |
| `insert-or-replace.cpp` | 插入或替换 | 顺序定位与局部交换 |
| `common-elements.cpp` | 三数组公共元素 | 三指针对齐 |
| `rotate-left.cpp` | 循环左移 | 三次逆置 |
| `median-two-sorted.cpp` | 两有序表中位数 | 归并定位 |
| `majority-element.cpp` | 主元素 | 计数统计 |
| `first-missing-positive.cpp` | 最小缺失正整数 | 辅助标记数组 |
| `min-distance-three-arrays.cpp` | 三数组最小距离 | 三指针移动当前最小值 |
| `max-product-suffix.cpp` | 后缀最大乘积 | 反向维护最小值与最大值 |
| `find-duplicate.cpp` | 寻找重复数 | Floyd 判环思想 |

## 关键接口

`dynamic.h` 当前提供的是基于指针的顺序表实现：

```c
sqList* initList();
void expandList(sqList* list, int extraSize);
bool listInsert(sqList* list, int i, int e);
bool listDelete(sqList* list, int i, int* e);
int listSearch(sqList* list, int e);
void listPrint(sqList* list);
```

## 运行方式

```bash
g++ -std=c++11 delete-min.cpp -o test && ./test
g++ -std=c++11 static-array-demo.cpp -o test && ./test
```

## 注意事项

- 插入和删除的位序参数采用从 `1` 开始的教材风格。
- `listSearch` 返回的位置也是从 `1` 开始，找不到时返回 `0`。
- `dynamic.h` 负责基础结构；大多数题目文件会在各自 `main` 中单独构造测试数据。
