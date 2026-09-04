#include <iostream>
#include <vector>

using namespace std;

// A vector is a sequence container in the Standard Template Library (STL) that stores elements dynamically.
int main()
{
    // Definition
    vector<int> v = {5, 10, 35};

    // Operations
    // Access
    cout << "The value at index 1 is: " << v[1] << endl;

    // Modify
    v[1] = 20;

    // Insert
    v.insert(v.begin() + 2, 17);

    v.pop_back();

    // Print with range
    for (int n : v)
        cout << n << endl;

    return 0;
}