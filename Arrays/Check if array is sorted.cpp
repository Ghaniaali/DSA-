#include<iostream>
using namespace std;

// Function to check if the array is sorted in non-decreasing order
bool sorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] > arr[i]) {
            return false; // If any element is smaller than the previous one, the array is not sorted
        }
    }
    return true; // If the loop completes, the array is sorted
}

int main() {
    int arr[6] = {2, 3, 4, 5, 6, 10};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Use parentheses to ensure the ternary operator is evaluated correctly
    cout << (sorted(arr, size) ? "yes\n" : "No\n";

    return 0;
}