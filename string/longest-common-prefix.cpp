#include <stdio.h>
#include <string.h>

// 返回字符串数组的最长公共前缀长度
// 原理：只需比较字典序最小和最大的字符串，其公共前缀即为全局最长公共前缀
int fun(const char* strs[], int strsNum) {
    if (strsNum == 0)
        return 0;
    const char* max = strs[0], *min = strs[0];
    for (int i = 1; i < strsNum; i++) {
        if (strcmp(strs[i], min) < 0) min = strs[i];
        if (strcmp(strs[i], max) > 0) max = strs[i];
    }
    int k = 0;
    while (max[k] && min[k] && max[k] == min[k])
        k++;
    return k;
}

int main() {
    // 测试1：正常情况
    const char* strs1[] = {"flower", "flow", "flight"};
    int len1 = fun(strs1, 3);
    printf("测试1: [\"flower\", \"flow\", \"flight\"] -> 最长公共前缀长度 = %d\n", len1);
    // 预期: 2 ("fl")

    // 测试2：无公共前缀
    const char* strs2[] = {"dog", "racecar", "car"};
    int len2 = fun(strs2, 3);
    printf("测试2: [\"dog\", \"racecar\", \"car\"] -> 最长公共前缀长度 = %d\n", len2);
    // 预期: 0

    // 测试3：全部相同
    const char* strs3[] = {"apple", "apple", "apple"};
    int len3 = fun(strs3, 3);
    printf("测试3: [\"apple\", \"apple\", \"apple\"] -> 最长公共前缀长度 = %d\n", len3);
    // 预期: 5

    // 测试4：只有一个字符串
    const char* strs4[] = {"hello"};
    int len4 = fun(strs4, 1);
    printf("测试4: [\"hello\"] -> 最长公共前缀长度 = %d\n", len4);
    // 预期: 5

    // 测试5：空数组
    int len5 = fun(NULL, 0);
    printf("测试5: [] -> 最长公共前缀长度 = %d\n", len5);
    // 预期: 0

    return 0;
}