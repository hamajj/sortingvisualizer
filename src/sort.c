#include "sort.h"
#include <stdio.h>

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubble_sort_step(int arr[], int size, int *i, int *j) {
    if (*i < size - 1) {
        if (*j < size - *i - 1) {
            if (arr[*j] > arr[*j + 1]) {
                int temp = arr[*j];
                arr[*j] = arr[*j + 1];
                arr[*j + 1] = temp;
            }
            (*j)++;
        } else {
            *j = 0;
            (*i)++;
        }
    }
}

int isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0; // Array is not sorted
        }
    }
    return 1; // Array is sorted
}