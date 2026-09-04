#include <iostream>

using namespace std;

int indexFor(int x, int arr[], int size, int index = 0)
{
    if (index >= size)
        return -1;

    if (arr[index] == x)
        return index;

    return indexFor(x, arr, size, index + 1);
}

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{

    int arr[6] = {5, 3, 2, 8, 11, 2};
    cout << "Index: " << indexFor(2, arr, 6) << endl;

    int n;
    cout << "Enter the Fibonacci size: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << fibonacci(i) << " ";
    }

    return 0;
}