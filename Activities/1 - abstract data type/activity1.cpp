#include <iostream>

using namespace std;

class Array
{
private:
    int *nums;
    int size;

public:
    Array() {}
    Array(int size)
    {
        this->size = size;
        nums = new int[size];

        for (int i = 0; i < size; i++)
        {
            int num;
            cout << "Enter value " << i << ": ";
            cin >> num;
            nums[i] = num;
        }
    }

    void modifyNumAt(int index, int num)
    {
        nums[index] = num;
    }

    int sumAll()
    {
        int sum = 0;

        for (int i = 0; i < size; i++)
        {
            sum += nums[i];
        }

        return sum;
    }

    void printAll()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << ": " << nums[i] << endl;
        }
    }

    void findElement(int num)
    {
        bool found = false;
        for (int i = 0; i < size; i++)
        {
            if (num == nums[i])
            {
                found = true;
                cout << "Found " << num << " at index " << i << endl;
            }
        }

        if (!found)
            cout << "Element was not found" << endl;
    }
};

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    Array arr = Array(size);

    int option = 0;
    while (option != 5)
    {
        cout << endl;
        cout << "1.  Modify array value at index" << endl;
        cout << "2.  Summation of all array elements" << endl;
        cout << "3.  Print all array elements" << endl;
        cout << "4.  Find an array element" << endl;
        cout << "5.  Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            int index;
            int newNum;
            cout << "Enter index to edit: ";
            cin >> index;
            cout << "Enter new value: ";
            cin >> newNum;
            arr.modifyNumAt(index, newNum);
            break;

        case 2:
            cout << endl
                 << "Total array elements sum: " << arr.sumAll() << endl;
            break;

        case 3:
            cout << endl;
            arr.printAll();
            break;

        case 4:
            int num;
            cout << "Enter element to find: ";
            cin >> num;
            arr.findElement(num);
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << endl
                 << "Invalid option. Try again.";
        }
    }

    return 0;
}