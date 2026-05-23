# CSP 本地测试环境

运行 GUI：

```powershell
cd cpp-learning\csp-test-env
python app.py
```

源码固定读取规则：

```text
programming\test\csp\<第几次>\<第几题>.cpp
```

例如第 1 次第 2 题会读取：

```text
programming\test\csp\1\2.cpp
```

判题流程：

1. GUI 只列出 `programming\test\csp` 中已有源码且已经保存 10 组 `.in/.out` 的题目。
2. 根据“第几次认证 + 第几题”定位你的 `.cpp` 文件。
3. 使用 `g++ -std=c++17 -O2 -pipe` 编译到临时目录。
4. 逐个读取 `test_data/<第几次>/<第几题>/01.in` 到 `10.in` 运行。
5. 将你的输出和对应 `01.out` 到 `10.out` 比较。
6. 每个测试点通过得 10 分，超时、运行时错误、答案错误均为 0 分。

固定测试数据：

```text
test_data\<第几次>\<第几题>\01.in
test_data\<第几次>\<第几题>\01.out
...
test_data\<第几次>\<第几题>\10.in
test_data\<第几次>\<第几题>\10.out
```

参考程序：

```text
reference_solutions\<第几次>\<第几题>.cpp
```

题解摘要：

```text
SOLUTIONS.md
```

常用校验命令：

```powershell
python -m unittest discover -s tests
python tools\validate_references.py
python tools\validate_practice_scope.py
```

重新生成固定 `.in/.out`：

```powershell
python tools\materialize_test_data.py
```

当前 `validate_practice_scope.py` 按 `programming\test\csp` 里已有的 `.cpp` 文件校验覆盖情况，确保这些题都有 10 个固定测试点、保存好的期望输出和可编译的参考程序。
