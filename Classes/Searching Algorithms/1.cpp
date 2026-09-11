#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) return i;
    }

    return -1;
}

int binarySearch(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid;

    while (low <= high) {
        mid = low + (high + low) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (target > nums[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int recursiveBinarySearch(vector<int> &nums, int target, int low = 0, int high = -1, int mid = 0) {
    if (high == -1) high = nums.size() - 1;
    if (low <= high) {
        mid = (high + low) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (target > nums[mid]) {
            return recursiveBinarySearch(nums, target, mid + 1, high, mid);
        } else {
            return recursiveBinarySearch(nums, target, low, mid - 1, mid);
        }
    }

    return -1;
}

int main() {
    vector<int> n = {10, 20, 5, 3, 50, 88, 100, 1};
    vector<int> nSorted = {1, 3, 5, 10, 20, 50, 88, 100};

    // LINEAR SEARCH
    cout << "Linear Search: " << endl;
    int index1 = linearSearch(n, 5);
    if (index1 == -1) {
        cout << "The target was not found." << endl;
    } else {
        cout << "The index is: " << index1 << endl;
    }

    cout << endl;

    // BINARY SEARCH
    cout << "Binary Search: " << endl;
    int index2 = binarySearch(nSorted, 5);
    cout << "The index is: " << index2 << endl;

    cout << endl;

    cout << "Recursive Binary Search: " << endl;
    int index3 = recursiveBinarySearch(nSorted, 5);
    cout << "The index is: " << index3 << endl;

    return 0;
}