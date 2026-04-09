# 栈 (Stack)

## 模块简介

`stack` 目录包含顺序栈、链栈两种基础实现，并提供两个典型应用示例：表达式求值与括号匹配。

## 文件结构

| 文件 | 说明 |
|------|------|
| `sequence.h` | 顺序栈实现（静态数组） |
| `link.h` | 链栈实现（带头结点） |
| `expression-eval.cpp` | 中缀转后缀与表达式求值 |
| `bracket-match.cpp` | 括号匹配示例 |

## 关键接口

### 顺序栈 `sequence.h`

```c
bool initStack(sqStack* stack);
bool isEmpty(sqStack* stack);
bool push(sqStack* stack, ElemType e);
bool pop(sqStack* stack, ElemType* e);
bool getTop(sqStack* stack, ElemType* e);
bool destroyStack(sqStack** stack);
int getStackLength(sqStack* stack);
bool clearStack(sqStack* stack);
```

### 链栈 `link.h`

```c
bool initStack(linkStack* stack);
bool isEmptyStack(linkStack stack);
bool pushStack(linkStack stack, elemType e);
bool popStack(linkStack stack, elemType* e);
bool getTopStack(linkStack stack, elemType* e);
bool destroyStack(linkStack* stack);
```

## 核心内容

- `expression-eval.cpp` 通过栈完成中缀表达式转后缀表达式，并对后缀表达式求值。
- `bracket-match.cpp` 演示如何用栈检查 `()`、`[]`、`{}` 的配对合法性。

## 运行方式

```bash
g++ -std=c++11 expression-eval.cpp -o test && ./test
g++ -std=c++11 bracket-match.cpp -o test && ./test
```

## 注意事项

- 顺序栈版本基于固定容量数组，适合学习栈的基本行为。
- `destroyStack(sqStack** stack)` 适用于堆上分配的顺序栈；如果只在栈上定义结构体，可直接复用 `clearStack` 清空。
- 链栈版本采用带头结点写法，更适合演示指针操作。
