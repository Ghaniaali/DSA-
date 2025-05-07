#include<iostream>
using namespace std;

int* leader(int arr[], int size, int &resultsize) {
    int* res = new int[size]; // Dynamically allocate memory for the result array
    resultsize = 0; // Initialize the result size to 0

    for (int i = 0; i < size; i++) {
        bool isLeader = true; // Assume the current element is a leader
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                isLeader = false; // If any element to the right is greater, it's not a leader
                break;
            }
        }
        if (isLeader) {
            res[resultsize] = arr[i]; // Add the leader to the result array
            resultsize++; // Increment the result size
        }
    }

    return res; // Return the result array
}

int main() {
    int arr[] = {16, 17, 4, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int resultsize;

    int* result = leader(arr, size, resultsize); // Find leaders

    cout << "Leaders in the array are: " << endl;
    for (int i = 0; i < resultsize; i++) {
        cout << result[i] << endl; // Print each leader
    }

    delete[] result; // Free the dynamically allocated memory

    return 0;
}