#include <iostream>

using namespace std;

int multiply(int x, int y)
{
    if (x == 0 || y == 0)
        return 0;

    return x +
           multiply(x, y - 1);
}

int power(int x, int n)
{
    if (n == 0)
        return 1;

    return multiply(power(x, n - 1), x);
}

int maxValue(int arrLength, int arr[], int max = 0, int index = 0)
{
    if (index >= arrLength)
        return max;

    if (arr[index] > max)
        max = arr[index];

    return maxValue(arrLength, arr, max, index + 1);
}

int vowelsInStr(string s, int index = 0)
{
    if (index >= s.length())
        return 0;

    char c = tolower(s[index]);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1 + vowelsInStr(s, index + 1);

    return vowelsInStr(s, index + 1);
}

int indexFor(int x, int arrLength, int arr[], int index = 0)
{
    if (index >= arrLength)
        return -1;

    if (x == arr[index])
        return index;

    return indexFor(x, arrLength, arr, index + 1);
}

int main()
{
    cout << multiply(2, 8) << endl;
    cout << multiply(3, 3) << endl;
    cout << multiply(-2, 3) << endl;

    cout << power(2, 8) << endl;
    cout << power(3, 3) << endl;

    int arr[5] = {1, 10, -3, 4, 5};

    cout << maxValue(5, arr) << endl;
    cout << vowelsInStr("Hello") << endl;
    cout << indexFor(10, 5, arr) << endl;

    return 0;
}