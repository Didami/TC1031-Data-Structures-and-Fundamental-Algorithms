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

void insertionSort(vector<int> &nums) {
    int curr;
    int prev;
    for (int i = 1; i < nums.size(); i++) {
        curr = nums[i];
        prev = i-1;

        while (prev >= 0 && nums[prev] > curr) {
            nums[prev+1] = nums[prev];
            prev--;
        }
        nums[prev+1] = curr;
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

    cout << endl;

    cout << "Insertion Sort:" << endl;
    vector<int> n3 = {12, 11, 13, 5, 6};
    print(n3);

    insertionSort(n3);
    print(n3);

    return 0;
}