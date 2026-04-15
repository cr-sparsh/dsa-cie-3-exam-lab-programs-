#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct BinaryTree {
    struct TreeNode* root;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int data) {
    if(root == NULL)
        return createNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void pre_order_traversal(struct TreeNode* root) {
    if(root == NULL)
        return;

    printf("%d ", root->data);
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

int main() {
    struct BinaryTree tree;
    tree.root = NULL;

    tree.root = insert(tree.root, 10);
    tree.root = insert(tree.root, 5);
    tree.root = insert(tree.root, 20);
    tree.root = insert(tree.root, 3);
    tree.root = insert(tree.root, 7);

    pre_order_traversal(tree.root);

    return 0;
}
