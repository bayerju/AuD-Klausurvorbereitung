#include <stdio.h>
#include <stdlib.h>

typedef struct BiTreeNode_ {
    void *data;
    struct BiTreeNode_ *left;
    struct BiTreeNode_ *right;
} BiTreeNode;

int avz(BiTreeNode *root) {
    BiTreeNode *node = root;
    int counter = 0;
    if (node->left) {
        counter++;
        counter += avz(node->left);
    }
    if (node->right) {
        counter++;
        counter += avz(node->right);
    }

    return counter;
}

int main() {}