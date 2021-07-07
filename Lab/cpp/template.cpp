#include <iostream>
#include <typeinfo>

using namespace std;

////////// Nontype Template Parameters /////////
template <typename _Tp, int _Np, typename = void>
struct __vector_type_n {
    using type = void;
};

template <typename _Tp, int _Np>
struct __vector_type_n<_Tp, _Np, enable_if_t<is_integral_v<_Tp> && _Np >= 2>> {
    using type = _Tp;
};

template <typename _Tp, int _Size>
using __vector_type_t = typename __vector_type_n<_Tp, _Size>::type;

void testNontypeTemp() {
    cout << typeid(__vector_type_t<int, 1>).name() << endl;
    cout << typeid(__vector_type_t<int, 10>).name() << endl;
    cout << typeid(__vector_type_t<uint64_t, 10>).name() << endl;
}

////////// placeholder ////////

struct ElementAlignedTag {
    template <typename _Tp>
    static constexpr size_t s_align = alignof(_Tp);
};


////////// Variadic Template /////////
void demo_print() {
    cout << "end." << endl;
}

template <typename T, typename... Types>
void demo_print(T arg, Types... args) {
    cout << arg << endl;
    demo_print(args...);
}


int main() {
    // testNontypeTemp();
    // cout << ElementAlignedTag::s_align<int> << endl;
    // cout << ElementAlignedTag::s_align<int64_t> << endl;

    demo_print(1, 2, 3, 4, 5);

    return 0;
}
