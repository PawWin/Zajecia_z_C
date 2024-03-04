#include <stdio.h>

int main(){

    int grades[2][5]= {
        {5,5,4,3,2}, //Oceny z Matematyki
        {3,3,4,2,5}  //Oceny z Fizyki
    };
    float srednia[2] = {0};
    for(int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            srednia[i] += grades[i][j];
        }
        srednia[i] /= 5;
    }

    // Wyświetlanie średnich ocen
    printf("\nSrednie oceny:\n");
    printf("Matematyka: %.2f\n", srednia[0]);
    printf("Fizyka: %.2f\n", srednia[1]);

    char stayclosed[999]; 
    scanf("%s", stayclosed);
    return 0;
}
