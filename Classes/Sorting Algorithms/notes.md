# Sorting Algorithms

A sorting algorithm is used to rearrange a given list of elements in an order. For example:

- Input: `a = {10, 20, 5, 2}`
- Output: `a = {2, 5, 10, 20}`

There exist different sorting algorithms for different types of inputs, for example:

- Binary array
- Character array
- Array with a large range of values
- An array with many duplicates

The algorithms may also differ according to output requirements.

## Applications

- Finding an element: once data is sorted, the smallest or largest element can be retrieved in constant time `O(1)`.
- Searching algorithms: sorting is essential for search methods like binary search, where data must be ordered.
- Data Management: sorted data is easier to search, retrieve, and analyze.
- Database optimization: databases often keep records sorted by primary index, improving query speed and performance.
- Machine Learning: sorting is used during data preprocessing ro prepare datasets for training models.
- Operating Systems: sorting algorithms assist with task scheduling, memory management, and file system organization.

## Advantages

- Efficiency
- Improved performance
- Simplified data analysis
- Reduced memory consumption
- Improved data visualization

## Disadvantages:

- Insertion: keeping data in sorted order makes insertion costly, since the order must be mantained.
- Algorithm selection: choosing the right sorting algorithm for a specific
- Alternatives to sorting: in many cases, hashing is more efficient than sorting

## 5 sorting algorithms:

- [Selection Sort](#i-selection-sort)
- [Bubble Sort](#ii-bubble-sort)
- Insertion Sort
- Merge Sort
- Quick Sort

---

## I. Selection Sort

- Comparison-based sorting algorithm
- It sorts an array by repeatedly selecting the smallest or largest element from the unsorted portion and swapping elements.

![Selection Sort](./images/selection-sort-eg.png)

```cpp
void selectionSort(vector<int> &nums) {
    int n = nums.size();
    int min;

    for (int i = 0; i < n-1; i++) {
        min = i;
        for (int j = i+1; j < n; j++) {
            if (nums[j] < nums[min])
                min = j;
        }
        swap(nums[i], nums[min]);
    }
}
```

**Time Complexity: `O(n^2)`**

**Space Complexity: `O(1)`**

### Advantages:

- Simple to understand: easy to learn and implement.
- Low memory usage: requires only a constant amount of extra memory `O(1)`.
- Fewer swaps: performs fewer swaps than many other standard sorting algorithms.

### Disadvantages:

- Slow for large databases: with a time complexity of `O(n^2)`, it is much slower than algorithms like Quick Sort or Merge Sort.
- Not stable: It does not preserve the relative order of equal elements, so it is considered an unstable sorting algorithm.

  e.g

  Original array: `[4a, 5, 3, 4b, 2]` _(two 4s, labeled, a and b)_

  After Selection Sort: `[2, 3, 4b, 4a, 5]`

  _Notice that 4a and 4b have switched positions, so the original order is not preserved._

### Applications:

- Small lists: works well for small datasets, especially when memory writes are expensive, since it performs fewer swaps than many other algorithms.
- Foundation for other algorithms: algorithms like Heap Sort are based on the same idea as Selection Sort.

[↑ Back to algorithms list](#5-sorting-algorithms)

---

## II. Bubble Sort

- Simple sorting algorithm that works by repeatedly comparing and swapping adjacent elements if they are in the wrong order.
- It is not efficient for large datasets because its average and worst-case time complexity is high `O(n^2)`

![Bubble Sort 1](./images/bubble-sort-eg/1.png)
![Bubble Sort 2](./images/bubble-sort-eg/2.png)
![Bubble Sort 3](./images/bubble-sort-eg/3.png)

```cpp
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
```

**Time Complexity: `O(n^2)`**

**Space Complexity: `O(1)`**

**Best Case (array is already ordered): `O(n)`**

### Advantages

- Simple to understand: easy to learn and implement.
- Low memory usage: does not require extra memory (in-place sorting).
- Stable algorithm: elements with the same value keep their original relative order.

### Disadvantages:

- Slow for large datasets: the time complexity of `O(n^2)`, it is inefficient for big arrays

[↑ Back to algorithms list](#5-sorting-algorithms)
