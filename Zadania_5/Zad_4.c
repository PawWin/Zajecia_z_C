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

void l_remove_by_index(listElement** head, int index) {
    if (index < 0) {
        printf("Invalid index\n");
        return;
    }
    listElement* current = *head;
    listElement* previous = NULL;
    for (int i = 0; i < index && current != NULL; i++) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found\n");
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

int main() {
    l_add_first(1);
    l_add_first(2);
    l_add_first(3);
    print_list(head);
    l_remove_by_index(&head,1);
    print_list(head);
    printf("\n");
    char stayclosed[999]; 
    scanf("%s", stayclosed);
    return 0;
}