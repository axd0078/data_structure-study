#include <stdio.h>
#include "dsu.h"

// 打印集合状态
void printSet(int s[], int n) {
    printf("当前集合状态: ");
    for (int i = 0; i < n; i++) {
        if (s[i] < 0) {
            printf("[%d:根，大小=%d] ", i, -s[i]);
        } else {
            printf("[%d:父=%d] ", i, s[i]);
        }
    }
    printf("\n");
}

// 打印所有集合的根节点和大小
void printRoots(int s[], int n) {
    printf("\n=== 集合信息 ===\n");
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] < 0) {
            count++;
            printf("集合 %d: 根节点=%d, 大小=%d\n", count, i, -s[i]);
        }
    }
    printf("总集合数：%d\n", count);
    printf("==================\n\n");
}

int main() {
    int test[10];
    
    printf("========== DSU 并查集测试 ==========\n\n");
    
    // 测试 1: 初始化
    printf("【测试 1】初始化操作\n");
    init(test);
    printf("初始化后:\n");
    printSet(test, 10);
    printRoots(test, 10);
    
    // 测试 2: 基础查找（无优化）
    printf("\n【测试 2】基础查找操作 (find)\n");
    unionSet(test, 0, 1);  // 0 -> 1
    unionSet(test, 1, 2);  // 1 -> 2
    unionSet(test, 3, 2);  // 3 -> 2
    printf("执行 unionSet(0,1), unionSet(1,2), unionSet(3,2) 后:\n");
    printSet(test, 10);
    printf("find(0) = %d\n", find(test, 0));
    printf("find(3) = %d\n", find(test, 3));
    printRoots(test, 10);
    
    // 重置
    init(test);
    
    // 测试 3: 优化版本 - 按大小合并 + 路径压缩
    printf("\n【测试 3】优化版本 (unionPro + findPro)\n");
    printf("初始状态:\n");
    printSet(test, 10);
    
    // 逐步合并并观察
    printf("\n--- 执行 unionPro(0, 1) ---\n");
    unionPro(test, 0, 1);
    printSet(test, 10);
    printRoots(test, 10);
    
    printf("--- 执行 unionPro(2, 3) ---\n");
    unionPro(test, 2, 3);
    printSet(test, 10);
    printRoots(test, 10);
    
    printf("--- 执行 unionPro(0, 2) ---\n");
    unionPro(test, 0, 2);
    printSet(test, 10);
    printRoots(test, 10);
    
    // 测试路径压缩
    printf("\n--- 测试路径压缩 ---\n");
    printf("执行 findPro(1) 前:\n");
    printSet(test, 10);
    int root = findPro(test, 1);
    printf("findPro(1) = %d\n", root);
    printf("执行 findPro(1) 后（应该发生路径压缩）:\n");
    printSet(test, 10);
    printRoots(test, 10);
    
    // 测试 4: 复杂场景
    printf("\n【测试 4】复杂合并场景\n");
    init(test);
    
    // 构建多个集合
    unionPro(test, 1, 2);
    unionPro(test, 3, 4);
    unionPro(test, 5, 6);
    unionPro(test, 7, 8);
    
    printf("构建 4 个小集合后:\n");
    printRoots(test, 10);
    
    // 合并成大集合
    unionPro(test, 1, 3);
    unionPro(test, 5, 7);
    unionPro(test, 1, 5);
    
    printf("全部合并后:\n");
    printRoots(test, 10);
    
    // 测试所有元素的根节点
    printf("验证所有元素的根节点:\n");
    for (int i = 1; i <= 8; i++) {
        printf("元素 %d 的根节点是 %d\n", i, findPro(test, i));
    }
    
    // 测试 5: 边界情况
    printf("\n【测试 5】边界情况测试\n");
    init(test);
    printf("单个元素的查找: findPro(5) = %d\n", findPro(test, 5));
    printf("自己和自己合并: unionPro(3, 3)\n");
    unionPro(test, 3, 3);
    printRoots(test, 10);
    
    printf("\n========== 测试完成 ==========\n");
    
    return 0;
}
