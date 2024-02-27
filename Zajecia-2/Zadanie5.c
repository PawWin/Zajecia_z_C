#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100  

struct Contact {
    char imie[50];
    char nazwisko[50];
    char numer_telefonu[20];
};

struct Contact ksiazka_adresowa[MAX_CONTACTS];
struct Contact *pksiazka_adresowa = &ksiazka_adresowa;
int liczba_kontaktow = 0;  

void dodajKontakt(struct Contact *ksiazka_adresowa) {
    if (liczba_kontaktow < MAX_CONTACTS) {
        struct Contact nowy_kontakt;
        struct Contact *pnowy_kontakt = &nowy_kontakt;
        printf("Podaj imie: ");
        scanf("%s", pnowy_kontakt->imie);
        printf("Podaj nazwisko: ");
        scanf("%s", pnowy_kontakt->nazwisko);
        printf("Podaj numer telefonu: ");
        scanf("%s", pnowy_kontakt->numer_telefonu);
        
        ksiazka_adresowa[liczba_kontaktow] = nowy_kontakt;
        liczba_kontaktow++;
        printf("Kontakt dodany pomyslnie.\n");
    } else {
        printf("Ksiazka adresowa jest pelna. Nie mozna dodac wiecej kontaktow.\n");
    }
}

void znajdzKontakt(char *nazwisko) {
    int znaleziono = 0;
    for (int i = 0; i < liczba_kontaktow; i++) {
        if (strcmp(ksiazka_adresowa[i].nazwisko, nazwisko) == 0) {
            printf("Znaleziono kontakt:\n");
            printf("Imie: %s, Nazwisko: %s, Numer telefonu: %s\n",
                   ksiazka_adresowa[i].imie, ksiazka_adresowa[i].nazwisko, ksiazka_adresowa[i].numer_telefonu);
            znaleziono = 1;
            break;
        }
    }
    if (!znaleziono) {
        printf("Nie znaleziono kontaktu o nazwisku %s.\n", nazwisko);
    }
}

void usunKontakt(char *nazwisko) {
    int indeks_do_usuniecia = -1;
    for (int i = 0; i < liczba_kontaktow; i++) {
        if (strcmp(ksiazka_adresowa[i].nazwisko, nazwisko) == 0) {
            indeks_do_usuniecia = i;
            break;
        }
    }
    if (indeks_do_usuniecia != -1) {
        for (int i = indeks_do_usuniecia; i < liczba_kontaktow - 1; i++) {
            ksiazka_adresowa[i] = ksiazka_adresowa[i + 1];
        }
        liczba_kontaktow--;
        printf("Kontakt o nazwisku %s zostal usuniety.\n", nazwisko);
    } else {
        printf("Nie znaleziono kontaktu o nazwisku %s.\n", nazwisko);
    }
}


void wyswietlWszystkieKontakty() {
    printf("Ksiazka adresowa:\n");
    for (int i = 0; i < liczba_kontaktow; i++) {
        printf("Imie: %s, Nazwisko: %s, Numer telefonu: %s\n",
               ksiazka_adresowa[i].imie, ksiazka_adresowa[i].nazwisko, ksiazka_adresowa[i].numer_telefonu);
    }
}

int main() {
    char opcja;
    char *pOpcja = &opcja;
    char nazwisko[50];
    char *pnazwisko = &nazwisko;

    while (1) {
        printf("\n--Menu--:\n");
        printf("1. Dodaj nowy kontakt\n");
        printf("2. Znajdz kontakt po nazwisku\n");
        printf("3. Usun kontakt po nazwisku\n");
        printf("4. Wyswietl wszystkie kontakty\n");
        printf("5. Wyjdz\n");
        printf("Wybierz opcje: ");
        scanf(" %c", pOpcja);

        switch (opcja) {
            case '1':
                dodajKontakt(pksiazka_adresowa);
                break;
            case '2':
                printf("Podaj nazwisko kontaktu do wyszukania: ");
                scanf("%s", pnazwisko);
                znajdzKontakt(pnazwisko);
                break;
            case '3':
                printf("Podaj nazwisko kontaktu do usuniecia: ");
                scanf("%s", pnazwisko);
                usunKontakt(pnazwisko);
                break;
            case '4':
                wyswietlWszystkieKontakty();
                break;
            case '5':
                printf("Do widzenia!\n");
                return 0;
            default:
                printf("Niepoprawna opcja. Wybierz ponownie.\n");
        }
    }

    char stayclosed[999]; 
    scanf("%s", stayclosed);
    return 0;
}
