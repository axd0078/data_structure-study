# Day 29：字符串算法进阶

## ▶ CSP 考情分析

CSP 对字符串算法的考察比较特殊——**不常考 KMP/AC 自动机这类传统字符串匹配算法**，而是更注重**字符串作为"格式化文本"的处理能力**。

**CSP 字符串题的两大方向：**
| 方向 | 真题 | 考点 |
|------|------|------|
| 格式化解析 | 模板生成系统(201509-3)、命令行选项(201403-3) | 字符串查找替换、按格式拆字段 |
| 编码解码 | 登机牌条码(202112-3)、短消息解码(第38次T3) | 进制转换、字段切分 |
| 字符串匹配 | 字符串匹配(201409-3) | 朴素匹配 / STL find |

**CSP 更看重的是"字符串业务处理"而非"字符串算法理论"。**

## ▶ 核心技巧

### 字符串查找（CSP 最常用）

```cpp
string s = "hello world";
size_t pos = s.find("world");    // 返回首次出现位置
if (pos != string::npos) {       // 找到了
    s.replace(pos, 5, "CSP");    // 替换
}
s.substr(pos, len);               // 取子串
```

### 字符串分割（C++ 没有 split，手动实现）

```cpp
vector<string> split(const string& s, char delim) {
    vector<string> res;
    string cur;
    for (char c : s) {
        if (c == delim) {
            if (!cur.empty()) res.push_back(cur);
            cur.clear();
        } else cur += c;
    }
    if (!cur.empty()) res.push_back(cur);
    return res;
}
```

### KMP 算法（了解即可，CSP 很少考）

```cpp
// 构建 next 数组
vector<int> getNext(string pattern) {
    int m = pattern.size();
    vector<int> next(m);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) j = next[j - 1];
        if (pattern[i] == pattern[j]) j++;
        next[i] = j;
    }
    return next;
}
// KMP 匹配
int kmp(string text, string pattern) { ... }
```

---

## ▶ 真题 1：字符串匹配

**试题编号：201409-3（第2次认证第3题）**

在给定字符串中查找匹配模式，大小写不敏感，模式中的 `*` 可以匹配任意长度字符串。

**思路：** 将模式按 `*` 分割成片段，对每个片段在文本中顺序 `find()`。注意 `*` 在开头/结尾的边界情况。

**CSP 考察点：** `*` 通配符的实现——CSP 不考理论 KMP，但会考这种"带有通配符的查找"。

---

## ▶ 真题 2：模板生成系统

**试题编号：201509-3（第5次认证第3题）**

输入一个模板文本，其中包含 `{{ 变量名 }}` 格式的占位符。根据给定的变量值表，将所有占位符替换为实际值。

**思路：**
1. 用 `find("{{")` 和 `find("}}")` 定位占位符
2. 提取变量名，查 map 获取对应值
3. 替换后继续处理下一个
4. 小心：替换后的值中可能也包含 `{{`（递归替换）

**CSP 考察点：** 字符串定位 + map 查值 + 递归/循环替换——CSP 第 3 题大模拟的典型代表作。

---

## ▶ 字符编码映射表

CSP 编码题中常出现自定义字符映射：

```
' ' = 0   '0'..'9' = 1..10   'A'..'Z' = 11..36   '_' = 37
```

这种映射表要写一对互逆函数：`charToValue(c)` 和 `valueToChar(v)`，反复测试确保互逆。

---

## ✅ 今日自检

- [ ] 能用 find/replace/substr 处理字符串
- [ ] 理解通配符 `*` 的匹配如何拆解
- [ ] 做字符串匹配 or 模板生成系统并 AC
- [ ] 写一对字符↔数值的互逆映射函数
