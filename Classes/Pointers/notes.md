# Pointer

- It is a special variable that stores the memory address of another variable.
- Instead of holding a direct value, it points to the location in memory where the value is stored.
- Pointers allow programs to:
  - Access and modify data in memory efficiently
  - Support system-level programming
  - Enable dynamic memory management

e.g:

1. Print memory address of an `int` variable `x`
2. Declare a pointer `ptr` variable
3. Print `x` value and memory address. It is also possible to get the `ptr` memory address using `&ptr`

```cpp
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
```

Output:

```
0x16fdfe7e8
The x's value is: 5
The x's memory address is: 0x16fdfe7e8
The ptr's memory address is: 0x16fdfe7e0
The new x's value is: -44
```

## Array

- An array is essentially a pointer

e.g:

```cpp
int main() {
    int nums[5] = {4, 3, 5, 9, 15};
    cout << nums << endl; // Prints the memory address of the first element

    int *ptr = nums;
    cout << ptr << ": " << *ptr << endl;

    ptr++; // Increases the index
    cout << ptr << ": " << *ptr << endl; // Prints the memory address and value of the element at index 1

    return 0;
}
```

Output:

```
0x16fdfe7d0
0x16fdfe7d0: 4
0x16fdfe7d4: 3
```

An example method to create an array using pointers, where the values are their index tiems 5:

```cpp
int *read(int size) {
    int *ptr;
    ptr = new int(size);

    for (int i = 0; i < size; i++)
        ptr[i] = i*5;

    return ptr;
}

int main() {
    int *nums_ptr;
    nums_ptr = read(10);
    for (int i = 0; i < 10; i++)
        cout << nums_ptr[i] << " ";
    return 0;
}
```

Output:

```
0 5 10 15 20 25 30 35 40 45
```

---

## Pointer types

- [Null Pointer](#i-null-pointer)
- [Wild Pointer](#ii-wild-pointer)
- [Dangling Pointer](#iii-dangling-pointer)
- [Void Pointer](#iv-void-pointer)
- [Pointer to Pointer](#v-pointer-to-pointer)
- [Function Pointer](#vi-function-pointer)
- [Constant Pointer](#vii-constant-pointer)

### I. Null Pointer

- A pointer that does not point to any valid memory location but NULL.
- It is often used to initialize a pointer when you do not want it to point to any object.

e.g:

```cpp
int main() {
    int *ptr = nullptr;
    return 0;
}
```

### II. Wild Pointer

- When created, a pointer just contains a random address that may or may not be valid.
- Deferencing this pointer may lead to errors such as segmentation faults; it is always recommended to initialize a pointer;

e.g:

```cpp
int main() {
    int *ptr;
    return 0;
}
```

### III. Dangling Pointer

- A pointer that refers to memory already freed or no longer valid.

e.g:

```cpp
int *getPointer() {
    int x = 10;
    return &x; // ⚠️ allocated on the stack
}

int main() {
    int *ptr = getPointer();
    cout << *ptr;
    return 0;
}
```

**The corrected version is:**

```cpp
int *getPointer() {
    int *x = new int(10); // allocated on the heap
    return x;
}

int main() {
    int *ptr = getPointer();
    cout << *ptr;
    delete ptr; // delete after finishing
    return 0;
}
```

### IV. Void Pointer

- A pointer that is declared using the `void` keyword, it can point to any type of data.

e.g:

```cpp
void *ptr;
int x = 10;
ptr = &x;
cout << *(int*)ptr;
```

### V. Pointer to Pointer

- A pointer thsat stores the address of another pointer.
- Allows multiple levels of indirection.

e.g:

```cpp
float x = 4.4;
float *ptr1 = &x;
float **ptr2 = &ptr1;

cout << *ptr2 << endl; // Prints: 0x16fdfe7dc
cout << **ptr2 << endl; // Prints: 4.4
```

### VI. Function Pointer

- Function has address like all other variables in the program.
- The name of a function can be used to find the address of the function.
- The funtion pointer is used to point functions, similarly, the pointers are used to point variables.
- It is utilized to save a function's address.

e.g:

```cpp
int multiply(int a, int b) {
    return a * b;
}

int main() {
    int (*func)(int, int);
    func = multiply;
    int prod = func(15, 2);
    cout << "The value of the product is: " << prod << endl;
    return 0;
}
```

A useful application of function pointers is to create an array of functions that return and take the same parameters:

```cpp
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int (*operations[3])(int, int) = {add, subtract, multiply};
    int x = 6, y = 3;
    for (int i = 0; i < 3; i++) {
        cout << "Result" << i << ": " << operations[i](x, y) << endl;
    }
    return 0;
}
```

### VII. Constant Pointer

- A pointer that does not allow to modify the value that is pointing to from the pointer.

\*The value can still be modified from the original variable.

e.g.

```cpp
int main() {
    int x = 8;
    int const *ptr = &x;

    // x = 4; // ✅ valid
    // *ptr = 4; // ❌ error

    cout << *ptr << endl;

    return 0;
}
```
