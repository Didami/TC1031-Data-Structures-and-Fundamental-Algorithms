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

void merge(vector<int> &nums, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = nums[i+left];

    for (int j = 0; j < n2; j++)
        R[j] = nums[j+mid+1];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            nums[k] = L[i];
            i++;
        } else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        nums[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        nums[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &nums, int left, int right) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid+1, right);
    merge(nums, left, mid, right);
}

int partition(vector<int> &nums, int low, int high) {
    int pivot = nums[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (nums[j] < pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }

    swap(nums[i+1], nums[high]);

    return i+1;
}

void quickSort(vector<int> &nums, int low, int high) {
    if (low >= high)
        return;

    int pi = partition(nums, low, high);
    quickSort(nums, low, pi-1);
    quickSort(nums, pi+1, high);
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

    cout << endl;

    cout << "Merge Sort:" << endl;
    vector<int> n4 = {38, 27, 43, 10};
    print(n4);

    mergeSort(n4, 0, n4.size() - 1);
    print(n4);

    cout << endl;

    cout << "Quick Sort:" << endl;
    vector<int> n5 = {10, 80, 30, 90, 40};
    print(n5);

    quickSort(n5, 0, n5.size() - 1);
    print(n5);

    return 0;
}