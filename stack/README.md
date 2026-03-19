# 栈 (Stack)

顺序栈与链栈的实现，以及栈的经典应用。

## 文件结构

| 文件 | 说明 |
|------|------|
| `sequence.h` | 顺序栈实现（静态数组） |
| `link.h` | 链栈实现（带头结点） |
| `expression-eval.cpp` | 表达式求值（中缀转后缀 + 求值） |
| `bracket-match.cpp` | 括号匹配 |

## 顺序栈接口 (sequence.h)

```c
void initStack(SqStack *&S);      // 初始化
bool isEmpty(SqStack *S);         // 判空
bool push(SqStack *&S, ElemType e);   // 入栈
bool pop(SqStack *&S, ElemType &e);   // 出栈
bool getTop(SqStack *S, ElemType &e); // 获取栈顶
void destroyStack(SqStack *&S);   // 销毁
int getStackLength(SqStack *S);   // 获取长度
void clearStack(SqStack *&S);     // 清空
```

## 链栈接口 (link.h)

```c
void initStack(LinkStack *&S);    // 初始化
bool isEmptyStack(LinkStack *S);  // 判空
bool pushStack(LinkStack *&S, ElemType e);  // 入栈
bool popStack(LinkStack *&S, ElemType &e);  // 出栈
bool getTopStack(LinkStack *S, ElemType &e); // 获取栈顶
void destroyStack(LinkStack *&S); // 销毁
```

## 应用示例

### 表达式求值 (expression-eval.cpp)

- `makeExpression()`: 中缀表达式 → 后缀表达式
- `eval()`: 后缀表达式求值

```bash
g++ -std=c++11 expression-eval.cpp -o test && ./test
```

### 括号匹配 (bracket-match.cpp)

检查 `()`、`[]`、`{}` 是否匹配正确。

```bash
g++ -std=c++11 bracket-match.cpp -o test && ./test
```
