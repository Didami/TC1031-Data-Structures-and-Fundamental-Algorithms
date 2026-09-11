#include <iostream>
#include <vector>

using namespace std;

class List {
    private:
    vector<int> nums;

    // === Sorting Algorithms ===
    // 1. Selection Sort
    vector<int> selectionSort() {
        vector<int> sorted = nums;

        int n = sorted.size();
        int min;

        for (int i = 0; i < n-1; i++) {
            min = i;
            for (int j = i+1; j < n; j++) {
                if (sorted[j] < sorted[min])
                    min = j;
            }
            swap(sorted[i], sorted[min]);
        }

        return sorted;
    }

    // 2. Bubble Sort
    vector<int> bubbleSort() {
        vector<int> sorted = nums;

        int n = sorted.size();
        bool checkSwap;
        for (int i = 0; i < n-1; i++) {
            checkSwap = false;
            for (int j = 0; j < n-i-1; j++) {
                if (sorted[j] > sorted[j+1]) {
                    swap(sorted[j], sorted[j+1]);
                    checkSwap = true;
                }
            }
            if (!checkSwap)
                break;
        }

        return sorted;
    }

    // 3. Insertion Sort
    vector<int> insertionSort() {
        vector<int> sorted = nums;

        int curr;
        int prev;
        for (int i = 1; i < sorted.size(); i++) {
            curr = sorted[i];
            prev = i-1;

            while (prev >= 0 && sorted[prev] > curr) {
                sorted[prev+1] = sorted[prev];
                prev--;
            }
            sorted[prev+1] = curr;
        }

        return sorted;
    }

    // === Searching Algorithms ===
    // 1. Linear Search
    int linearSearch(int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) return i;
        }

        return -1;
    }

    // 2. Binary Search
    int binarySearch(int target) {
        vector<int> sorted = selectionSort();

        int low = 0;
        int high = sorted.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (sorted[mid] == target) {
                return mid;
            } else if (target > sorted[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }

    public:
    List() {
        cout << "Enter the number of elements (n): ";
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Enter element at " << i << ": ";
            int num;
            cin >> num;
            nums.push_back(num);
        }
    }

    void print() {
        for (int n : nums) {
            cout << n << " ";
        }
    }

    void search(int target) {
        cout << "Using Linear Search: " << linearSearch(target) << endl;
        cout << "Using Binary Search: " << binarySearch(target) << endl;
    }
};

int main() {
    List* list = new List();
    list->search(7);
    return 0;
}