#include <stdio.h>

struct Point {
    float x;
    float y;
};


void zmienWspolrzedne(struct Point *p, int nowy_x, int nowy_y) {
    p->x = nowy_x;
    p->y = nowy_y;
}

struct Rectangle {
    struct Point *topleft;   
    struct Point *bottomright;  
};

float poleProstokata(struct Rectangle *r) {
    float width = r->bottomright->x - r->topleft->x;
    float height = r->bottomright->y - r->topleft->y;
    return width * height;
}

float obwodProstokata(struct Rectangle *r) {
    float width = r->bottomright->x - r->topleft->x;
    float height = r->bottomright->y - r->topleft->y;
    return 2* width + 2*height;
}
int main() {
    struct Point punkt = {3, 5};
    struct Point *pPunkt = &punkt;
    zmienWspolrzedne(pPunkt, 7, 9);

    printf("Nowe wspolrzedne punktu: (%.2f, %.2f)\n", punkt.x, punkt.y);
    struct Point lewyGorny = {0.0, 0.0};
    struct Point *plewyGorny = &lewyGorny;
    struct Point prawyDolny = {2.0, 2.0};
    struct Point *pprawyDolny = &prawyDolny;
    struct Rectangle prostokat = {plewyGorny, pprawyDolny};

    printf("Pole prostokata: %.2f\n", poleProstokata(&prostokat));
    printf("Obwod prostokata: %2.f\n", obwodProstokata(&prostokat));

    char stayclosed[999]; 
    scanf("%s", stayclosed);
    return 0;
}

