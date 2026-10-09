#include <iostream>

using namespace std;

int main() {
    int x = 5;
    cout << &x << endl; // Prints: 0x16fdfe7e8
    int *ptr = &x;

    cout << "The x's value is: " << *ptr << endl;
    cout << "The x's memory address is: " << ptr << endl;

    cout << "The ptr's memory address is: " << &ptr << endl;

    *ptr = -44;
    cout << "The new x's value is: " << x << endl;

    return 0;
}