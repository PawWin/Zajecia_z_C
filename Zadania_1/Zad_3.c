#include <stdio.h>

int silnia(int n) {
    if (n == 0)
        return 1;
    else
        return n * silnia(n - 1);
}

int main(){

    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    printf("Silnie dla liczb w tablicy:\n");
    for (int i = 0; i < sizeof(array); i++) {
        printf("%d! = %d\n", array[i], silnia(array[i]));
    }


    char stayclosed[999]; 
    scanf("%s", stayclosed);
    return 0;
}