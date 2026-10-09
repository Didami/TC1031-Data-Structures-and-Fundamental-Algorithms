#include <iostream>

using namespace std;

int main() {
    int x = 8;
    int const *ptr = &x;

    // x = 4; // ✅ valid
    // *ptr = 4; // ❌ error

    cout << *ptr << endl;

    return 0;
}
