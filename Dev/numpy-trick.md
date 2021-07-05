# numpy 例子

### concatenate

用于拼接多个 ndarray

```python
# `>>` 符号表示命令行输出，下同

a = np.arange(12).reshape(3, 2, 2)
b = np.arange(12).reshape(3, 2, 2)

np.concatenate((a, b), axis=0).shape
# >> (6, 2, 2)

np.concatenate((a, b), axis=1).shape
# >> (3, 4, 2)
```



### newaxis

可以用在扩充 numpy ndarray 其中某个 axis，如对于一副 RBG 图像，扩充它的 width

```python
print(np.newaxis)
# >> None

# 假设一个 numpy array
print(x)
# >> (1, 3, 518, 774)

tmp = x[:, :, -1, :]
print(tmp.shape)
# >> (1, 3, 774)

print(tmp[:, :, np.newaxis, :].shape)
# >> (1, 3, 1, 774)

# 合并
np.concatenate((x, tmp), axis=2).shape
# >> (1, 3, 519, 774)
```

