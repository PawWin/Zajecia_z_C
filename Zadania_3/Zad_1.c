#include <stdio.h>
#include <stdlib.h>

int **allocate_triangle(int n) {
    int **triangle = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        triangle[i] = calloc(i + 1, sizeof(int));
    }
    return triangle;
}

void print_triangle(int **triangle, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf(" %3d ", triangle[i][j]);
        }
        printf("\n");
    }
}

void free_triangle(int **triangle, int n) {
    for (int i = 0; i < n; i++) {
        free(triangle[i]);
    }
    free(triangle);
}

int **pascal(int n) {
    int **triangle = allocate_triangle(n);

    triangle[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
    }

    return triangle;
}

int main() {
    int n;
    printf("Podaj wysokosc trojkata Pascala: ");
    scanf("%d", &n);

    int **triangle = pascal(n);
    print_triangle(triangle, n);
    free_triangle(triangle, n);

    char stayclosed[999]; 
    scanf("%s", stayclosed);
    return 0;
}