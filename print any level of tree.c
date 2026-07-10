#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// DFS function to print nodes at a given level
void DFS(struct Node* root, int currentLevel, int targetLevel)
{
    if (root == NULL)
        return;

    if (currentLevel == targetLevel)
    {
        printf("%d ", root->data);
        return;
    }

    DFS(root->left, currentLevel + 1, targetLevel);
    DFS(root->right, currentLevel + 1, targetLevel);
}

int main()
{
    // Create the binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int level;

    printf("Enter level: ");
    scanf("%d", &level);

    printf("Nodes at level %d: ", level);
    DFS(root, 1, level);

    return 0;
}
