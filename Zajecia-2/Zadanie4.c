#include <stdio.h>
#include <string.h>

struct Student {
    char imie[50];
    float ocena;
};

void sortujStudentow(struct Student *tablica, int rozmiar) {
    int i, j;
    struct Student temp;

    for (i = 0; i < rozmiar - 1; i++) { //Sortowanie bąbelkowe
        for (j = 0; j < rozmiar - 1 - i; j++) {
            if (tablica[j].ocena < tablica[j + 1].ocena) {
                // Zamiana miejscami
                temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Student studenci[] = {
        {"Oskar", 4.96},
        {"Grzegorz", 4.6},
        {"Jakub", 3.8},
        {"Kuba", 4.3},
        {"Mateusz", 4.2}
    };

    int rozmiar = sizeof(studenci) / sizeof(studenci[0]);

    sortujStudentow(studenci, rozmiar);

    printf("Posortowana lista studentow:\n");
    for (int i = 0; i < rozmiar; i++) {
        printf("Imie: %s, Ocena: %.1f\n", studenci[i].imie, studenci[i].ocena);
    }

    char stayclosed[999]; 
    scanf("%s", stayclosed);
    return 0;
}
