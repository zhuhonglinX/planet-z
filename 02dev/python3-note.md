## True 和 False

None，0，空字符串，空列表，空字典都算是False，所有其他值都是True。

所以可以有如下写法：

```python
## 判断 list 是否为空
foo = []
if foo:  # 不必一定写 len(foo) == 0
    pass
else:
    pass

## 判断是否为 0
a = -1
if not a:  # 不必一定写 a == 0
    pass
else:
    pass
```



## 列表

#### 初始化列表

```python
n = 0
foo = [0 for _ in range(n)]  # 创建长度为 n 的数组，并初始化所有元素为 0
foo = [[0 for _ in range(n)] for _ in range(n)]  # 创建二维数组
```

#### 其他操作

```python
foo[::-1]  # reverse
```









