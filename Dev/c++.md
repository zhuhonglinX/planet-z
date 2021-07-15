
#### template conditional

```c++
template< bool B, typename T, typename F >
struct conditional;

// Possible implementation
template<bool B, typename T, typename F>
struct conditional { typedef T type; };
 
template<typename T, typename F>
struct conditional<false, T, F> { typedef F type; };

template< bool B, typename T, typename F >
using conditional_t = typename conditional<B,T,F>::type;
```

If B is true, type is defined as T, else F.

使用例子：

```c++
// mytype is int
using mytype = conditional_t<true, int, float>;
```

#### template enable_if

```c++
// Possible implementation
template<bool B, typename T = void>
struct enable_if {};
 
template<typename T>
struct enable_if<true, T> { typedef T type; };

template< bool B, class T = void >
using enable_if_t = typename enable_if<B,T>::type;
```

If B is true, define a public member `type` as T.



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
