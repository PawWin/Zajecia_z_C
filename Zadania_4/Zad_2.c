#include <stdio.h>

int binary_search_recursive(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            return binary_search_recursive(arr, left, mid - 1, target);
        }
        return binary_search_recursive(arr, mid + 1, right, target);
    }
    return -1;
}

int main() {
    int arr[] = {45, 6, 14, 68, 99,101,25,103,49};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Podaj liczbe ktora chcesz wyszukac: \n");
    int target;
    scanf("%d",&target);
    int result = binary_search_recursive(arr, 0, n - 1, target);

    if (result == -1) {
        printf("Element nie znajduje sie w tablicy");
    } else {
        printf("Element znaleziony na indexie %d", result);
    }

    return 0;
}