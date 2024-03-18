#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int duplicate(const int *array, int i, int left){
    for(int j = left; j < i; j++){
        if (array[j] == array[i]){
            return 1;
        }
    }
    return 0;
}


void generate_permutations(int *arr, int left, int right) {
    if (left == right) {
        for (int i = 0; i <= right; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = left; i <= right; i++) {
            int duplicateCheck = duplicate(arr, i, left);

            if (!duplicateCheck) {
                swap(&arr[left], &arr[i]);
                generate_permutations(arr, left + 1, right);
                // zmianna array z powrotem do oryginalnych pozycji
                swap(&arr[left], &arr[i]);
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    generate_permutations(arr, 0, size - 1);
    return 0;
}