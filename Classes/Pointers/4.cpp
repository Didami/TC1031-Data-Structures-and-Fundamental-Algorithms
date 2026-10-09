#include <iostream>

using namespace std;

int main() {
    void *ptr;
    float x = 4.4;
    ptr = &x;
    cout << *(float*)ptr << endl;

    float *ptr1 = &x;
    float **ptr2 = &ptr1;

    cout << *ptr2 << endl; // prints: 0x16fdfe7dc
    cout << **ptr2 << endl; // prints: 4.4
    
    return 0;
}