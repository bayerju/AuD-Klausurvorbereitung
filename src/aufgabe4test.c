#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int key;
    struct node *next;
} Node;
// Initialisierung
Node *stackinit(void) {
    Node *tmp;
    tmp = (struct node *)malloc(sizeof(Node));
    tmp->next = NULL;
    tmp->key = 0;
    return tmp;
}
// Ablegen
void push(int in, Node *listHead) {
    Node *tmp;
    tmp = (struct node *)malloc(sizeof *tmp);
    tmp->key = in;
    tmp->next = listHead->next;
    listHead->next = tmp;
}
// Auslesen
int pop(Node *listHead) {
    int value;
    Node *tmp;
    tmp = listHead->next;
    listHead->next = tmp->next;
    value = tmp->key;
    free(tmp);
    return value;
}
// Gesamte Liste ausgeben
void listOut(Node *list) {
    list = list->next; // Kopfelement ueberspringen
    while (list != NULL) {
        printf("%d ", list->key);
        list = list->next;
    }
    printf("\n");
}
// Listen vermischen: Einfuegen von Liste 2 in Liste 1
Node *combineLists(Node *head1, Node *head2) {
    Node *node1 = head1->next;
    Node *node2 = head2->next;
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

// Hauptprogramm
int main(void) {
    int i;
    Node *list1, *list2, *list3; // Liste mit Pseudo Kopf- & Ende-Element
    list1 = stackinit();
    list2 = stackinit();
    /* Liste 2 erzeugen */
    for (i = 20; i > 0; i = i - 2) {
        push(i, list2);
    }
    /* Liste 1 erzeugen */
    for (i = 29; i > 0; i = i - 2) {
        push(i, list1);
    }
    /* Liste 1 ausgeben */
    printf("Liste 1:\n");
    listOut(list1);
    printf("\n\nListe 2:\n");
    listOut(list2);
    /* Listen mischen */
    list3 = combineLists(list1, list2);
    /* Liste 3 ausgeben */
    printf("\n\nVerschmolzene Liste:\n");
    listOut(list3);
    return 0;
}