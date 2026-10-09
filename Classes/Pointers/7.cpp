#include <iostream>

using namespace std;

int main() {
    int *ptr = new int;
    *ptr = 5;

    cout << *ptr << endl;

    delete ptr;
    
    return 0;
}
