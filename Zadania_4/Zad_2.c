#include <stdio.h>
#include <stdbool.h>
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
int binary_search_recursive(int *arr, int left, int right, int searchValue) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == searchValue) {
            return mid;
        }
        if (arr[mid] > searchValue) {
            return binary_search_recursive(arr, left, mid - 1, searchValue);
        }
        return binary_search_recursive(arr, mid + 1, right, searchValue);
    }
    return -1;
}

int main() {
    int arr[] = {45, 6, 14, 68, 99,101,25,103,49};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Podaj liczbe ktora chcesz wyszukac: \n");
    int target;
    bubbleSort(arr,size);
    scanf("%d",&target);
    int result = binary_search_recursive(arr, 0, size - 1, target);

    if (result == -1) {
        printf("Element nie znajduje sie w tablicy");
    } else {
        printf("Element znaleziony na indexie %d", result);
    }

    return 0;
}