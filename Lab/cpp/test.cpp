#include <iostream>

using namespace std;

size_t next_power_of_2(size_t x) {
    return (x & (x - 1)) == 0 ? x : next_power_of_2((x | (x >> 1)) + 1);
}


int main() {
    size_t a = next_power_of_2(20);
    cout << a << endl;
    return 0;
}


