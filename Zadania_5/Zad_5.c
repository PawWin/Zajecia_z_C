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

void l_remove_by_value(listElement **head, int value) {
    if (head == NULL || *head == NULL) {
        return;
    }
    
    if ((*head)->data == value) {
        listElement *new_head = (*head)->next;
        free(*head);
        *head = new_head;
    } else {
        listElement *current = *head;
        while (current->next != NULL && current->next->data != value) {
            current = current->next;
        }
        
        if (current->next != NULL) {
            listElement *listElement_to_remove = current->next;
            current->next = current->next->next;
            free(listElement_to_remove);
        }
    }
}



int main() {
    l_add_first(1);
    l_add_first(2);
    l_add_first(3);
    l_add_first(1);
    l_add_first(2);
    l_add_first(3);
    print_list(head);
    l_remove_by_value(&head,2);
    print_list(head);
    printf("\n");
    char stayclosed[999]; 
    scanf("%s", stayclosed);
    return 0;
}