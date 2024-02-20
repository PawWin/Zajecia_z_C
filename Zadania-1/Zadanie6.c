#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROUNDS 3

// Funkcja do losowego wyboru ruchu komputera (kamień, papier, nożyce)
int komputerWybor() {
    return rand() % 3; // 0 - kamień, 1 - papier, 2 - nożyce
}

// Funkcja do porównywania ruchów gracza i komputera oraz zwracania wyniku rundy
int wynikRundy(int gracz, int komputer) {
    // Gracz wygrywa
    if ((gracz == 0 && komputer == 2) || (gracz == 1 && komputer == 0) || (gracz == 2 && komputer == 1)) {
        return 1;
    }
    // Komputer wygrywa
    else if ((komputer == 0 && gracz == 2) || (komputer == 1 && gracz == 0) || (komputer == 2 && gracz == 1)) {
        return -1;
    }
    // Remis
    else {
        return 0;
    }
}

int main() {
    srand(time(NULL));
    int wyniki[MAX_ROUNDS]; // Tablica przechowująca wyniki rund (-1 - komputer wygrywa, 0 - remis, 1 - gracz wygrywa)
    int ruchyGracza[MAX_ROUNDS]; // Tablica przechowująca ruchy gracza (0 - kamień, 1 - papier, 2 - nożyce)
    int ruchyKomputera[MAX_ROUNDS]; // Tablica przechowująca ruchy komputera (0 - kamień, 1 - papier, 2 - nożyce)
    int iloscRund = 0; // Licznik rund

    printf("Witaj w grze kamien, papier, nozyce!\n");
    //Pętla Gry
    while (iloscRund < MAX_ROUNDS) {
        printf("\nRunda %d:\n", iloscRund + 1);
        printf("Wybierz swoj ruch (0 - kamien, 1 - papier, 2 - nozyce): ");
        scanf("%d", &ruchyGracza[iloscRund]);

        if (ruchyGracza[iloscRund] < 0 || ruchyGracza[iloscRund] > 2) {
            printf("Nieprawidlowy wybor. Podaj liczbe od 0 do 2.\n");
            continue;
        }

        ruchyKomputera[iloscRund] = komputerWybor();
        printf("Komputer wybral: %d\n", ruchyKomputera[iloscRund]);

        wyniki[iloscRund] = wynikRundy(ruchyGracza[iloscRund], ruchyKomputera[iloscRund]);
        if (wyniki[iloscRund] == 1) {
            printf("Wygrales runde!\n");
        } else if (wyniki[iloscRund] == -1) {
            printf("Komputer wygral runde!\n");
        } else {
            printf("Remis w rundzie!\n");
        }

        iloscRund++;

        char komenda[10];
        printf("\nCzy chcesz zakonczyc gre(wpisz 'tak' lub 'nie')? ");
        scanf("%s", komenda);

        if (strcmp(komenda, "tak") == 0) {
            break;
        }
        printf("\nWyniki rund:\n");
        for (int i = 0; i < iloscRund; i++) {
            printf("Runda %d: Gracz %d vs Komputer %d - ", i + 1, ruchyGracza[i], ruchyKomputera[i]);
            if (wyniki[i] == 1) {
                printf("Wygrales!\n");
            } else if (wyniki[i] == -1) {
                printf("Komputer wygral!\n");
            } else {
                printf("Remis.\n");
            }
        }
    }

    printf("\nDziekujemy za gre!\n");

    return 0;
}
