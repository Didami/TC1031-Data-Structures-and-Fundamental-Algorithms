#include <iostream>

using namespace std;

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
    int (*func)(int, int);
    func = multiply;
    int prod = func(15, 2);
    cout << "The value of the product is: " << prod << endl;

    int (*operations[3])(int, int) = {add, subtract, multiply};
    int x = 6, y = 3;
    for (int i = 0; i < 3; i++) {
        cout << "Result " << i << ": " << operations[i](x, y) << endl;
    }

    return 0;
}
