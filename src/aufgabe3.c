#include <stdio.h>
#include <stdlib.h>

typedef struct ListElmt_ {
    int data;
    struct ListElmt_ *next;
} ListElmt;

int josephus(ListElmt *Kreis, int m) {
    if (Kreis->next == Kreis) {
        return Kreis->data;
    }

    ListElmt *prev = Kreis;
    for (int i = 0; i < m - 1; i++) {
        prev = Kreis;
        Kreis = Kreis->next;
    }
    prev->next = Kreis->next;
    free(Kreis);
    return josephus(prev->next, m);
}

int main() {
    ListElmt *head = (struct ListElmt_ *)malloc(sizeof(ListElmt));
    head->data = 1;
    head->next = NULL;
    ListElmt *prev = head;

    for (int i = 2; i < 9; i++) {
        ListElmt *node = (struct ListElmt_ *)malloc(sizeof(ListElmt));
        node->data = i;
        node->next = head;
        prev->next = node;
        prev = node;
    }
    int result = josephus(head, 3);
    printf("hi: %d", result);
}