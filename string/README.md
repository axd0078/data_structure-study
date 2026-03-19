# 字符串 (String)

字符串结构定义与模式匹配算法。

## 文件结构

| 文件 | 说明 |
|------|------|
| `string.h` | 字符串定义、朴素匹配、KMP 算法 |
| `kmp.cpp` | KMP 算法实现 |
| `kmp-test.c` | KMP 算法测试 |
| `longest-common-prefix.cpp` | 最长公共前缀 |

## 核心算法

### KMP 模式匹配

```c
int Index(SString S, SString T);           // 朴素匹配 (Brute-Force)
void getNext(SString T, int next[]);       // 计算 next 数组
void getNextVal(SString T, int nextval[]); // 改进的 nextval 数组
```

**next vs nextval**：
- `next`: 标准失效函数
- `nextval`: 优化版本，避免相同字符的重复比较

### 最长公共前缀

`longest-common-prefix.cpp` 使用字典序极值法：
- 只需比较字典序最小和最大的两个字符串
- 时间复杂度 O(n + L)，优于逐一比较的 O(n × L)

## 运行示例

```bash
# KMP 测试
gcc kmp-test.c -o test && ./test

# 最长公共前缀
g++ -std=c++11 longest-common-prefix.cpp -o test && ./test
```
