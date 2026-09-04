#include <iostream>

using namespace std;

int fact(int num)
{
    if (num == 1)
        return 1;
    return num * fact(num - 1);
}

int count_char(string s, char x, int index = 0)
{
    if (index > s.length())
        return 0;

    char c = tolower(s[index]);
    if (c == x)
        return 1 + count_char(s, x, index + 1) return count_char(s, x, index + 1)
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
    cout << "The factorial is: " << fact(num);

    return 0;
}