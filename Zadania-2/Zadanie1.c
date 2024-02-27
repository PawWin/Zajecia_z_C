#include <stdio.h>

int main() {
    int liczba = 10;  // Zadeklarowanie int i przypisanie wartości 10
    int *wskaznik = &liczba;  // Utworzenie wskaźnika

    printf("Wartosc zmiennej: %d\n", liczba);  // Wypisanie bezpośrednio
    printf("Wartosc zmiennej przez wskaznik: %d\n", *wskaznik);  // Wypisanie przez wskaźnik

    *wskaznik = 20;  // Modyfikacja wartości za pomocą wskaźnika

    printf("Po modyfikacji:\n");
    printf("Wartosc zmiennej: %d\n", liczba);
    printf("Wartosc zmiennej przez wskaznik: %d\n", *wskaznik);

    char stayclosed[999]; 
    scanf("%s", stayclosed);
    return 0;
}