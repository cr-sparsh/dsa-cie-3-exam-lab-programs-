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

struct TreeNode* findNode(struct TreeNode* root, int key) {
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return findNode(root->left, key);
    else
        return findNode(root->right, key);
}

void find_grandchildren(struct TreeNode* root, int key) {
    struct TreeNode* node = findNode(root, key);

    if(node == NULL)
        return;

    if(node->left) {
        if(node->left->left)
            printf("%d ", node->left->left->data);
        if(node->left->right)
            printf("%d ", node->left->right->data);
    }

    if(node->right) {
        if(node->right->left)
            printf("%d ", node->right->left->data);
        if(node->right->right)
            printf("%d ", node->right->right->data);
    }
}

int main() {
    struct BinaryTree tree;
    tree.root = NULL;

    tree.root = insert(tree.root, 10);
    tree.root = insert(tree.root, 5);
    tree.root = insert(tree.root, 20);
    tree.root = insert(tree.root, 3);
    tree.root = insert(tree.root, 7);
    tree.root = insert(tree.root, 15);
    tree.root = insert(tree.root, 25);

    find_grandchildren(tree.root, 10);

    return 0;
}
