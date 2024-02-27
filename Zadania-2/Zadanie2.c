#include <stdio.h>

void modyfikuj(float *wskaznik) {
    *wskaznik = 2 * (*wskaznik);  
}
 
int main() {
    float liczba = 5.5;
    float *pLiczba = &liczba;   
    printf("Wartość zmiennej przed wywołaniem funkcji: %.2f\n", liczba);  
    modyfikuj(pLiczba); 
    printf("Wartość zmiennej po wywołaniu funkcji: %.2f\n", liczba);  
    
    char stayclosed[999]; 
    scanf("%s", stayclosed);
    return 0;
}
 