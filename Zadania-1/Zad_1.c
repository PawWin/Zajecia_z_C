#include <stdlib.h>
#include <stdio.h>


int main(){
    char name[100]; 
    printf("Podaj swoje imie: ");
    scanf("%s", name);
    printf("Witaj, %s!\n", name);
    
    char stayclosed[999]; 
    scanf("%s", stayclosed);
    return 0;
}
