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

void l_add_at_index(listElement **head, int index, int value) {
    if (index < 0) {
        return;
    }

    if (index == 0) {
        listElement *new_head = (listElement*)malloc(sizeof(listElement));
        new_head->data = value;
        new_head->next = *head;
        *head = new_head;
    } else {
        listElement *current = *head;
        for (int i = 1; i < index && current != NULL; i++) {
            current = current->next;
        }

        if (current == NULL) {
            return;
        }

        listElement *new_listElement = (listElement*)malloc(sizeof(listElement));
        new_listElement->data = value;
        new_listElement->next = current->next;
        current->next = new_listElement;
    }
}


int main() {
    l_add_first(1);
    l_add_first(2);
    l_add_first(3);
    print_list(head);
    l_add_at_index(&head,1,4);
    print_list(head);
    printf("\n");
    char stayclosed[999]; 
    scanf("%s", stayclosed);
    return 0;
}