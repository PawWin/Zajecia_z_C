#include <stdio.h>

int main() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ptr = arr;

    for (int i = 0; i < 10; i++) {
        printf("Element %d ma wartosc [%d] i address  @ %x\n", i, *ptr, &arr[i]);
        ptr++;
    }

    char stayclosed[999];
    scanf("%s", stayclosed);
    return 0;
}