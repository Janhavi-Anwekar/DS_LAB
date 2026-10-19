#include <iostream>
#include <vector>

// insertion sort
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int size;

    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // Handle invalid size inputs
    if (size <= 0) {
        std::cout << "Invalid array size!" << std::endl;
        return 1;
    }

    std::vector<int> arr(size);

    std::cout << "Enter " << size << " elements: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    insertionSort(arr);

    // Print sorted array
    std::cout << "Sorted array: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
