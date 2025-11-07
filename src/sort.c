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
