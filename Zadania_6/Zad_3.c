#include <stdio.h>

// Definicja trzech funkcji: dodawania, mnożenia i odejmowania
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    int (*ptrToFunc)(int, int);
    int a, b;
    char op;

    printf("Wybierz operacje (+, -, *): ");
    scanf(" %c", &op);

    printf("Podaj dwie liczby calkowite: ");
    scanf("%d %d", &a, &b);

    switch (op) {
        case '+':
            ptrToFunc = add;
            break;
        case '-':
            ptrToFunc = subtract;
            break;
        case '*':
            ptrToFunc = multiply;
            break;
        default:
            printf("Nieprawidlowa operacja!\n");
            return 1;
    }

    printf("Wynik: %d\n", ptrToFunc(a, b));

    return 0;
}