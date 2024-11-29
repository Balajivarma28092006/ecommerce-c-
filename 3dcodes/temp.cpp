#include <stdio.h>

// Swap function to exchange two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    printf("Pivot chosen: %d\n", pivot); // Print the pivot element
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If the current element is smaller than the pivot
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Move pivot to the correct position
    return i + 1;
}

// Quicksort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index

        quickSort(arr, low, pi - 1); // Recursively sort elements before the partition
        quickSort(arr, pi + 1, high); // Recursively sort elements after the partition
    }
}

int main() {
    int arr[] = {-5,0,-9,-7,4,3,-1,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
