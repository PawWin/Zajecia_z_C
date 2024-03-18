#include <stdio.h>
void generate_permutations(int arr[], int left, int right) {
    if (left == right) {
        for (int i = 0; i <= right; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = left; i <= right; i++) {
            //zamiana elemntow na indexach "lewy" i "i"
            int temp = arr[left];
            arr[left] = arr[i];
            arr[i] = temp;
            generate_permutations(arr, left + 1, right);
            //zamiana elemntow na indexach "lewy" i "i" z powrotem na oryginalne pozycje
            temp = arr[left];
            arr[left] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3,4};
    int size = sizeof(arr) / sizeof(arr[0]);
    generate_permutations(arr, 0, size - 1);
    return 0;
}