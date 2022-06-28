#include <stdio.h>
#include <stdlib.h>

typedef struct ListElmt_ {
    int data;
    struct ListElmt_ *next;
} ListElmt;

ListElmt *combineLists(ListElmt *head1, ListElmt *head2);

int main() {}

combineLists(ListElmt *head1, ListElmt *head2) {
    ListElmt *node1 = head1->next;
    ListElmt *node2 = head2->next;
    head2 = head2->next;
    while (node1->next != NULL && node2->next != NULL) {
        head2 = head2->next;
        node2->next = node1->next;
        node1->next = node2;
        node1 = node2->next;
        node2 = head2;
    }
    if (node1->next == NULL && node2->next == NULL) {
        return head1;
    }
    if (node1->next == NULL) {
        node1->next = node2;
        return head1;
    }
    if (node2->next == NULL) {
        node2->next = node1->next;
        node1->next = node2;
        return head1;
    }
    printf("irgendwas passt nicht");

    return head1;
}
