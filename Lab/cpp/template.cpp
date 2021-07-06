#include <iostream>
#include <typeinfo>

using namespace std;

template <typename _Tp, int _Np, typename = void>
struct __vector_type_n {
    using type = void;
};

// Nontype Template Parameters
template <typename _Tp, int _Np>
struct __vector_type_n<_Tp, _Np, enable_if_t<is_integral_v<_Tp> && _Np >= 2>> {
    using type = _Tp;
};

template <typename _Tp, int _Size>
using __vector_type_t = typename __vector_type_n<_Tp, _Size>::type;

int main() { 
    cout << typeid(__vector_type_t<int, 1>).name() << endl;
    cout << typeid(__vector_type_t<int, 10>).name() << endl;
    cout << typeid(__vector_type_t<uint64_t, 10>).name() << endl;
    return 0; 
}

// ./template | c++filt -t