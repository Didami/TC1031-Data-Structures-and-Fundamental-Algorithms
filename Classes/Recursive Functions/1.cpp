#include <iostream>

using namespace std;

void print(int x, int size)
{
    if (x > size)
        return;
    cout << x << " ";
    print(x + 1, size);
}

int main()
{
    int size;
    cout << "Enter the loop size: ";
    cin >> size;

    print(1, size);

    return 0;
}