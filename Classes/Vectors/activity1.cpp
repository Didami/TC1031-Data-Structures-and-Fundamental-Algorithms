#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums;

    if (nums.empty())
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter a number: ";
            int n;
            cin >> n;
            nums.push_back(n);
        }
    }

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << endl;

    for (int n : nums)
        cout << n << endl;

    return 0;
}