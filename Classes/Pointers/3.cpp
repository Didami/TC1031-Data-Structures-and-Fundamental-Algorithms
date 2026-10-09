#include <iostream>

using namespace std;

int *getPointer() {
    int x = 10;
    return &x; // ⚠️ allocated on the stack
}

int main() {
    int *ptr = getPointer();
    cout << *ptr;
    return 0;
}