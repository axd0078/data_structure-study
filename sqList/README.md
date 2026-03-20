# 顺序表 (Sequential List)

动态顺序表的实现与经典算法练习。

## 核心文件

| 文件 | 说明 |
|------|------|
| `dynamic.h` | 动态顺序表定义与基础操作（增删查改、扩容） |
| `static-array-demo.cpp` | 静态顺序表示例 |

## 题目列表

| 文件 | 题目 | 核心思路 |
|------|------|----------|
| `delete-min.cpp` | 删除最小元素 | 线性扫描找最小，末元素覆盖 |
| `reverse-inplace.cpp` | 就地逆置 | 首尾双指针交换 |
| `delete-by-value.cpp` | 删除指定值 | 快慢指针压缩 |
| `delete-range.cpp` | 删除区间值 | 统计删除数并前移 |
| `remove-duplicates.cpp` | 有序表去重 | 双指针保留不同值 |
| `merge-sorted.cpp` | 合并两个有序表 | 双路归并 |
| `array-swap.cpp` | 分段交换 | 三次逆置 |
| `insert-or-replace.cpp` | 插入或替换 | 顺序定位+交换 |
| `common-elements.cpp` | 三数组公共元素 | 三指针对齐 |
| `rotate-left.cpp` | 循环左移 | 三次逆置 |
| `median-two-sorted.cpp` | 两有序表中位数 | 归并定位 |
| `majority-element.cpp` | 主元素 | 计数数组 |
| `first-missing-positive.cpp` | 最小缺失正整数 | 辅助标记数组 |
| `min-distance-three-arrays.cpp` | 三数组最小距离 | 三指针+移动最小 |
| `max-product-suffix.cpp` | 后缀最大乘积 | 反向维护 min/max |
| `find-duplicate.cpp` | 寻找重复数 | Floyd判环算法 |

## dynamic.h 接口

```c
void initList(SqList &L);           // 初始化
void expandList(SqList &L);         // 扩容
bool listInsert(SqList &L, int i, ElemType e);  // 按位置插入
bool listDelete(SqList &L, int i, ElemType &e); // 按位置删除
int listSearch(SqList L, ElemType e);           // 查找元素
void listPrint(SqList L);           // 打印
```

## 运行示例

```bash
g++ -std=c++11 delete-min.cpp -o test && ./test
```
