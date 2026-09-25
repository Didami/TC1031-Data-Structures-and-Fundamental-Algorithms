/*
    Diego Flores Álvarez - A01788809
    Deliever date: 25/09/26

    Activity 1.4 - Search and Sort algorithms
*/

#include <iostream>
#include <vector>

using namespace std;

class List {
    private:
    vector<int> nums;

    // === Sorting Algorithms ===
    // == 1. Selection Sort ==

    /// It sorts an array by repeatedly selecting the smallest or largest element from the unsorted portion and swapping elements. Time Complexity: `O(n^2)`. Space Complexity: `O(1)`.
    void selectionSort() {
        int n = nums.size();
        int min;

        for (int i = 0; i < n - 1; i++) {
            min = i;

            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[min])
                    min = j;
            }

            swap(nums[i], nums[min]);
        }
    }

    // == 2. Bubble Sort ==

    /// It works by repeatedly comparing and swapping adjacent elements if they are in the wrong order. Time Complexity: `O(n^2)`. Space Complexity: `O(1)`.
    void bubbleSort() {
        int n = nums.size();
        bool checkSwap;

        for (int i = 0; i < n - 1; i++) {
            checkSwap = false;

            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    checkSwap = true;
                }
            }

            if (!checkSwap)
                break;
        }
    }

    // == 3. Insertion Sort ==

    /// It works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list. Similar to sorting playing cards in your hands. Time Complexity: `O(n^2)`. Space Complexity: `O(1)`.
    void insertionSort() {
        int curr;
        int prev;

        for (int i = 1; i < nums.size(); i++) {
            curr = nums[i];
            prev = i - 1;

            while (prev >= 0 && nums[prev] > curr) {
                nums[prev + 1] = nums[prev];
                prev--;
            }

            nums[prev + 1] = curr;
        }
    }

    // == 4. Merge Sort ==
    void merge(int left, int mid, int right) {
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

    void mergeSort(int left, int right) {
        if (left >= right)
            return;

        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        merge(left, mid, right);
    }

    // === Searching Algorithms ===
    // == 1. Sequential Search ==

    /// Iterates over all the elements of the array and check if the current element is equal to the target element. Time Complexity: `O(n)`. Space Complexity: `O(1)`.
    int sequentialSearch(int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                return i;
        }

        return -1;
    }

    // == 2. Binary Search ==

    /// The list must be sorted. It works by dividing the search space into two halves by finding the middle index. The middle element is compared with the `target`. If it is equal, the middle index is returned. If it is less than the `target`, the right side is used for the next search. If it is greater, the left side is used for the next search. This process is continued until the key is found or the total search space is exhausted. Time Complexity: `O(log n)`. Space Complexity: `O(1)`.
    int binarySearch(int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            } 
            else if (target > nums[mid]) {
                low = mid + 1;
            } 
            else {
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

        cout << endl;
    }

    void search(int target) {
        int index = sequentialSearch(target);
        if (index == -1) {
            cout << "ELEMENT " << target << " WAS NOT FOUND." << endl;
            return;
        }

        cout << "-> USING SEQUENTIAL SEARCH: " << "ELEMENT " << target << " FOUND AT INDEX: " << index << endl;

        cout << endl;

        cout << "⚠️ In order to use Binary Search, the list must be sorted." << endl;
        sort(); // sort before searching
        cout << "-> USING BINARY SEARCH: " << "ELEMENT " << target << " FOUND AT INDEX: " << binarySearch(target) << endl;
    }

    void sort() {
        cout << "Select algorithm to sort:" << endl;
        cout << "1. Selection sort" << endl;
        cout << "2. Bubble sort" << endl;
        cout << "3. Insertion sort" << endl;
        cout << "4. Merge sort" << endl;

        int option;
        cin >> option;

        switch (option) {
            case 1:
                selectionSort();
                cout << "SORTED (USING SELECTION): ";
                print();
                break;

            case 2:
                bubbleSort();
                cout << "SORTED (USING BUBBLE): ";
                print();
                break;

            case 3:
                insertionSort();
                cout << "SORTED (USING INSERTION): ";
                print();
                break;

            case 4:
                mergeSort(0, nums.size() - 1);
                cout << "SORTED (USING MERGE): ";
                print();
                break;

            default:
                cout << "Invalid option." << endl;
        }
    }
};

int main() {
    List* list = new List();

    int option;

    do {
        cout << "\nLIST ACTIONS" << endl;
        cout << "1. Search an element" << endl;
        cout << "2. Sort list" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter an option: ";
        cin >> option;

        switch (option) {
            case 1: {
                cout << "Enter element to find: ";

                int e;
                cin >> e;

                list->search(e);

                break;
            }

            case 2:
                list->sort();
                break;

            case 3:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid option. Please try again." << endl;
        }

    } while (option != 3);

    return 0;
}