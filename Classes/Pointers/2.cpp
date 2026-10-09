#include <iostream>

using namespace std;

int *read(int size) {
    int *ptr;
    ptr = new int(size);

    for (int i = 0; i < size; i++)
        ptr[i] = i*5;

    return ptr;
}

int main() {
    int nums[5] = {4, 3, 5, 9, 15};
    cout << nums << endl; // Prints the memory address of the first element

    int *ptr = nums;
    cout << ptr << ": " << *ptr << endl;

    ptr++; // Increases the index
    cout << ptr << ": " << *ptr << endl; // Prints the memory address and value of the element at index 1

    int *nums_ptr;
    nums_ptr = read(10);
    for (int i = 0; i < 10; i++)
        cout << nums_ptr[i] << " ";
    
    cout << endl;

    return 0;
}