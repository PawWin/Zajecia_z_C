#include <stdio.h>
#include <stdlib.h>

typedef struct listElement {
    char data;
    struct listElement *next;
} listElement;

struct listElement *head;

void l_add_first(char v);

void l_add_first(char v) {
    struct listElement *p = malloc(sizeof(struct listElement));
    p->data = v;
    p->next = head;
    head = p;
}

void print_list(listElement *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    l_add_first(1);
    l_add_first(2);
    l_add_first(3);
    print_list(head);
    printf("\n");
    char stayclosed[999]; 
    scanf("%s", stayclosed);
    return 0;
}