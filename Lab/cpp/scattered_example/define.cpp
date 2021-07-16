#include <iostream>
using namespace std;

#define WATCH_FUNC __func__
#define WATCH_FILE __FILE__
#define WATCH_LINE __LINE__

#define DEBUG_PRINT(item) printf("%s @ %s:%d, %s\n", __func__, __FILE__, __LINE__, #item)

int main() {
    cout << WATCH_FILE << endl;
    cout << WATCH_FUNC << endl;
    cout << WATCH_LINE << endl;

    DEBUG_PRINT(what);

    return 0;
}
