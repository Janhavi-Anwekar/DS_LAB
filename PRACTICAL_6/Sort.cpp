#include <iostream>
#include <vector>

// Function to perform Bubble Sort
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swapping elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Merge step for Merge Sort
void conquer(std::vector<int>& arr, int s, int mid, int e) {
    std::vector<int> merged(e - s + 1);

    int idx1 = s;
    int idx2 = mid + 1;
    int x = 0;

    while (idx1 <= mid && idx2 <= e) {
        if (arr[idx1] <= arr[idx2]) {
            merged[x++] = arr[idx1++];
        } else {
            merged[x++] = arr[idx2++];
        }
    }

    while (idx1 <= mid) {
        merged[x++] = arr[idx1++];
    }

    while (idx2 <= e) {
        merged[x++] = arr[idx2++];
    }

    for (int i = 0, j = s; i < merged.size(); i++, j++) {
        arr[j] = merged[i];
    }
}

// Divide step for Merge Sort
void divide(std::vector<int>& arr, int s, int e) {
    if (s >= e) {
        return;
    }

    int mid = s + (e - s) / 2;

    divide(arr, s, mid);
    divide(arr, mid + 1, e);

    conquer(arr, s, mid, e);
}

// Helper function to print arrays easily (replaces Arrays.toString)
void printArray(const std::vector<int>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    std::vector<int> arr(size);

    std::cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        std::cout << "ele " << (i + 1) << ": ";
        std::cin >> arr[i];
    }

    std::cout << "Choose sorting algorithm 1 for Bubble Sort, 2 for Merge Sort: \n";
    std::cout << "Your choice: ";
    int choice;
    std::cin >> choice;

    std::cout << "Original array : ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    switch (choice) {
        case 1:
            bubbleSort(arr);
            std::cout << "Sorted using Bubble Sort: ";
            printArray(arr);
            break;
        case 2:
            divide(arr, 0, arr.size() - 1);
            std::cout << "Sorted using Merge Sort: ";
            printArray(arr);
            break;
        default:
            std::cout << "Invalid choice! Array was not sorted.\n";
            break;
    }

    return 0;
}
