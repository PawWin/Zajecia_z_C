#include <stdio.h>

union MyUnion {
    int intVal;
    float floatVal;
    char charVal;
};

int main() {
    union MyUnion data;

    data.intVal = 42;
    printf("Wartosc int: %d\n", data.intVal);

    data.floatVal = 3.14;
    printf("Wartosc float: %f\n", data.floatVal);

    data.charVal = 'a';
    printf("Wartosc char: %c\n", data.charVal);

    char stayclosed[999];
    scanf("%s", stayclosed);
    return 0;
}