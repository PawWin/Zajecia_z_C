#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **allocate_matrix(int n, int m) {
    int **matrix = malloc(n * sizeof(int *));
    if (!matrix) {
        printf("Nie udalo sie zaalokowac pamieci dla macierzy");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        matrix[i] = calloc(m, sizeof(int));
        if (!matrix[i]) {
            printf("Nie udalo sie zaalokowac pamieci dla wiersza macierzy");
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            exit(EXIT_FAILURE);
        }
    }

    return matrix;
}

void fill_matrix(int **matrix, int n, int m) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int n, m;
    printf("Podaj ilosc wierszy: ");
    scanf("%d", &n);
    printf("Podaj ilosc kolumn: ");
    scanf("%d", &m);

    int **matrix = allocate_matrix(n, m);
    fill_matrix(matrix, n, m);
    print_matrix(matrix, n, m);
    free_matrix(matrix, n);

    char stayclosed[999]; 
    scanf("%s", stayclosed);
    return 0;
}