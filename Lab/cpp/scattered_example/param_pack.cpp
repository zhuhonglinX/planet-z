#include <iostream>
#include <vector>
#include <cstdint>
#include <cstddef>

using namespace std;

// class template
template <typename... T>
struct MyStruct {
    // sizeof...( parameter_pack ), return the number of elem in pack 
    size_t number = sizeof...(T);
};

// function
template<typename ... T>
void MyFunc(T ... args) {
    cout << sizeof...(args) << endl;
}


int main() {
    // MyStruct<> ms1;
    // MyStruct<int, float> ms2;
    // cout << ms1.number << endl;
    // cout << ms2.number << endl;

    MyFunc(2, 3, 4);
    MyFunc(2, 1.1, 'c');
    

    return 0;
}


