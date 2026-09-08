#include <iostream>
#include <vector>

using namespace std;

// The `swap` function works in a similar way to this:
// void swap(int &n1, int &n2) {
//     int temp;
//     temp = n2;
//     n2 = n1;
//     n1 = temp;
// }

void selectionSort(vector<int> &nums) {
    int n = nums.size();
    int min;
    
    // n-1: because j will be pushed to the last element
    for (int i = 0; i < n-1; i++) {
        min = i;
        for (int j = i+1; j < n; j++) {
            if (nums[j] < nums[min])
                min = j;
        }
        swap(nums[i], nums[min]);
    }
}

void bubbleSort(vector<int> &nums) {
    int n = nums.size();
    bool checkSwap;
    for (int i = 0; i < n-1; i++) {
        checkSwap = false;
        for (int j = 0; j < n-i-1; j++) {
            if (nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
                checkSwap = true;
            }
        }
        if (!checkSwap)
            break;
    }
}

void print(vector<int> &nums) {
    for (int i : nums)
        cout << i << " ";
    cout << endl;
}

int main() {
    cout << "Selection Sort:" << endl;
    vector<int> n1 = {64, 25, 12, 22, 11};
    print(n1);

    selectionSort(n1);
    print(n1);

    cout << endl;

    cout << "Bubble Sort:" << endl;
    vector<int> n2 = {5, 6, 1, 3};
    print(n2);

    bubbleSort(n2);
    print(n2);

    return 0;
}