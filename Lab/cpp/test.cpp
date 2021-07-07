#include <iostream>
#include <vector>
using namespace std;

size_t next_power_of_2(size_t x) {
    return (x & (x - 1)) == 0 ? x : next_power_of_2((x | (x >> 1)) + 1);
}


template <typename... T>
constexpr auto make_vec(T&&... t) -> vector<common_type_t<T...>> {
    // cout << sizeof...(T) << endl;
    return {t...};
}


int main() {
    // size_t a = next_power_of_2(20);
    // cout << a << endl;
    auto v = make_vec(1, 2, 3);
    cout << v.size() << '\n';
    for (auto i : v)
        std::cout << i << ' ';

    return 0;
}


