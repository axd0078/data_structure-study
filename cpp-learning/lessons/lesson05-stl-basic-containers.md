# 第 5 课：stack、queue、deque 与 priority_queue

## 本课目标

理解几种基础容器分别维护什么顺序：

- `stack`：后进先出
- `queue`：先进先出
- `deque`：两端都能操作
- `priority_queue`：每次取优先级最高的元素

## stack

适合括号匹配、撤销、路径回退。

```cpp
stack<char> st;
st.push('(');
st.top();
st.pop();
```

## queue

适合排队、层序处理。

```cpp
queue<int> q;
q.push(1);
q.front();
q.pop();
```

## priority_queue

默认是大根堆。小根堆写法：

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

## 本课练习

### 练习 1：括号匹配

输入一个只包含 `(`、`)`、`[`、`]` 的字符串，判断括号是否匹配。匹配输出 `YES`，否则输出 `NO`。

测试输入：

```text
([][])
```

测试输出：

```text
YES
```

边界测试输入：

```text
([)]
```

边界测试输出：

```text
NO
```

### 练习 2：队列模拟

输入 `q` 个操作：

- `push x`：将 `x` 入队
- `pop`：如果队列非空，弹出队首
- `front`：如果队列非空，输出队首，否则输出 `EMPTY`

测试输入：

```text
6
push 3
push 5
front
pop
front
pop
```

测试输出：

```text
3
5
```

### 练习 3：最小值优先

输入 `n` 个整数，每次取出当前最小值并输出。

测试输入：

```text
5
5 1 3 1 4
```

测试输出：

```text
1 1 3 4 5
```

## 复盘点

- `stack` 没有遍历能力，重点是 `top`。
- `queue` 只能看队首。
- `priority_queue` 不是排序数组，它只保证堆顶最优。
