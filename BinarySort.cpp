#include <iostream>
#include <algorithm> // For sort()

using namespace std;

// Binary Search Function
int binarySearch(int arr[], int size, int key) {
    int start = 0, end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2; // To avoid overflow

        if (arr[mid] == key)
            return mid; // Key found at index mid
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1; // Key not found
}

int main() {
    int size, key;

    // Input array size
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];

    // Input array elements
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    // Input key to search
    cout << "Enter the element to search: ";
    cin >> key;

    // Sort the array before binary search
    sort(arr, arr + size);

    // Perform binary search
    int result = binarySearch(arr, size, key);

    // Output the result
    if (result != -1)
        cout << "Element found at index (0-based): " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
