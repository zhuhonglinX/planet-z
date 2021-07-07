
#### 打印类型

Print type:

```c++
// in test.cpp
cout << typeid(xxx).name() << endl;
```

``` bash
# in terminal
clang++ -std=c++17 test.cpp -o test
./test | c++filt -t
```
