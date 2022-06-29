#include <stdio.h>
#include <stdlib.h>

typedef struct BiTreeNode_ {
    int data;
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

// int avz(BiTreeNode *root) {
//     if (root->left == NULL && root->right == NULL) {
//         return 0;
//     } else if (root->left != NULL && root->right != NULL) {
//         return 2 + avz(root->left) + avz(root->right);
//     } else if (root->left != NULL) {
//         return 1 + avz(root->left);
//     } else if (root->right != NULL) {
//         return 1 + avz(root->right);
//     }
// }

BiTreeNode *new_node(int data) {
    BiTreeNode *tmp = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    tmp->data = data;
    tmp->left = tmp->right = NULL;
    return tmp;
}

BiTreeNode *insert_node(BiTreeNode *node, int data) // inserting nodes!
{
    if (node == NULL)
        return new_node(data);
    if (data < node->data) {
        node->left = insert_node(node->left, data);
    } else if (data > node->data) {
        node->right = insert_node(node->right, data);
    }
    return node;
}

void print(BiTreeNode *root_node) // displaying the nodes!
{
    if (root_node != NULL) {
        print(root_node->left);
        printf("%d \n", root_node->data);
        print(root_node->right);
    }
}

int main() {

    printf("TechVidvan Tutorial: Implementation of a Binary Tree in C!\n\n");
    BiTreeNode *root_node = NULL;
    root_node = insert_node(root_node, 10);
    insert_node(root_node, 10);
    insert_node(root_node, 30);
    insert_node(root_node, 25);
    insert_node(root_node, 36);
    insert_node(root_node, 56);
    insert_node(root_node, 78);
    int amount = avz(root_node);
    printf("Menge: %d \n", amount);
    print(root_node);
    return 0;
}