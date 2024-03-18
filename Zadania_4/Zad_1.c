#include <stdio.h>

int factorial(int n) {
    if (n < 2) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    printf("Podaj dodatnia liczbe do wyliczenia silni: \n");
    int num;
    scanf("%d",&num);
    if(num>0){
        printf("Silnia z %d to %d\n", num, factorial(num));
    } else {
        printf("Bledna liczba \n");
    }

    return 0;
}