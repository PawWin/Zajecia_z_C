#include <stdio.h>


int sumaWielokrotnosci(int n) {
    if (n < 0)
        return 0;

    int suma = 0;
    for (int i = 3; i < n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            suma += i;
        }
    }
    return suma;
}

int main(){

    int liczba;
    printf("Podaj liczbe: ");
    scanf("%d", &liczba);
    printf("Suma wielokrotnosci 3 lub 5 ponizej %d wynosi: %d\n", liczba, sumaWielokrotnosci(liczba));


    char stayclosed[999]; 
    scanf("%s", stayclosed);
    return 0;
}
