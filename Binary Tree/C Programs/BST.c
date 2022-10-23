// Write a C program to implement Binary Search Tree using linked list along with the following functions:
// a. To create a binary search tree.
// b. To display tree using inorder.
// c. To display tree using preorder.
// d. To display tree using postorder.
// e. To count number of node present in the tree.
// f. To find the height of the tree.
// g. To find the number of leaf node.
// h. To find the number of internal node.
// i. To search a data present in the tree.
// j. To check complete binary tree.
// k. To insert a node.
// l. To delete a node.
// m. To check the balance factor of a node.
// n. To find the minimum value present in the tree.
// o. To find the maximum value present in the tree.
// p. To count number of NULL pointer present in the tree.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE *createNode(int);
NODE *createBST(NODE *root);
void inorder(NODE *);
void preorder(NODE *);
void postorder(NODE *);
int countNodes(NODE *);
int height(NODE *);
int countLeaf(NODE *);
int countInternal(NODE *);
bool search(NODE *, int);
bool isComplete(NODE *, int, int);
NODE *insertNode(NODE *, int);
NODE *deleteNode(NODE *, int);
int balanceFactor(NODE *, int);
int minValue(NODE *);
int maxValue(NODE *);
int countNULL(NODE *);

int main()
{
    int val;
    NODE *root = NULL;
    root = createBST(root);

    printf("\nDisplaying Tree Using Inorder\n");
    inorder(root);
    printf("\nDisplaying Tree Using Preorder\n");
    preorder(root);
    printf("\nDisplaying Tree Using Postorder\n");
    postorder(root);

    printf("\nNumber of Nodes: %d", countNodes(root));
    printf("\nHeight of the Binary Tree: %d", height(root));
    printf("\nNumber of Leaf Nodes: %d", countLeaf(root));
    printf("\nNumber of Internal Nodes: %d", countInternal(root));

    // Search In BST
    printf("\nEnter a Value to Search: ");
    scanf("%d", &val);
    if (search(root, val))
        printf("%d is present in the Tree.", val);
    else
        printf("%d is not present in the Tree.", val);

    // Check if Complete BST
    if (isComplete(root, 0, countNodes(root)))
        printf("\nThe Binary Search Tree is Complete.");
    else
        printf("\nThe Binary Search Tree is not Complete.");

    // Insertion in BST
    printf("\nEnter a Value to Insert in BST: ");
    scanf("%d", &val);
    root = insertNode(root, val);
    printf("%d is Inserted in BST", val);

    // Deletation from BST
    printf("\nEnter a Value to Delete from BST: ");
    scanf("%d", &val);
    root = deleteNode(root, val);
    printf("%d is Deleted from BST", val);

    // Balance Factor of a Node
    printf("\nEnter a Value to get Balance Factor: ");
    scanf("%d", &val);
    if (search(root, val))
        printf("Balance Factor of %d: %d", val, balanceFactor(root, val));
    else
        printf("%d is not present in the Tree.", val);

    printf("\nMinimum Value in BST: %d", minValue(root));
    printf("\nMaximum Value in BST: %d", maxValue(root));
    printf("\nNumber of NULL pointers: %d", countNULL(root));

    return 0;
}

NODE *createNode(int data)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

NODE *createBST(NODE *root)
{
    int data;
    printf("Creating Binary Search Tree");
    printf("\nEnter -1 to Stop");
    printf("\nEnter Root Data: ");
    scanf("%d", &data);
    while (data != -1)
    {
        root = insertNode(root, data);
        printf("Enter Next Data: ");
        scanf("%d", &data);
    }
    return root;
}

void inorder(NODE *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(NODE *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(NODE *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int countNodes(NODE *root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int height(NODE *root)
{
    if (root == NULL)
        return -1;
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return lHeight > rHeight ? lHeight + 1 : rHeight + 1;
}

int countLeaf(NODE *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

int countInternal(NODE *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return countInternal(root->left) + countInternal(root->right) + 1;
}

bool search(NODE *root, int val)
{
    if (root == NULL)
        return false;
    if (root->data == val)
        return true;
    if (root->data > val)
        return search(root->left, val);
    return search(root->right, val);
}

bool isComplete(NODE *root, int index, int numNodes)
{
    if (root == NULL)
        return true;
    if (index >= numNodes)
        return false;
    return (isComplete(root->left, 2 * index + 1, numNodes) && isComplete(root->right, 2 * index + 2, numNodes));
}

NODE *insertNode(NODE *root, int key)
{
    if (root == NULL)
        return createNode(key);
    if (root->data > key)
        root->left = insertNode(root->left, key);
    else
        root->right = insertNode(root->right, key);
    return root;
}

NODE *deleteNode(NODE *root, int val)
{
    if (root == NULL)
        return root;

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else
    {
        if (root->left == NULL)
        {
            NODE *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            NODE *temp = root->left;
            free(root);
            return temp;
        }

        root->data = minValue(root->right);
        root->right = deleteNode(root->right, root->data);
    }
    return root;
}

int balanceFactor(NODE *root, int val)
{
    if (root->data > val)
        return balanceFactor(root->left, val);
    if (root->data < val)
        return balanceFactor(root->right, val);

    return abs(height(root->left) - height(root->right));
}

int minValue(NODE *root)
{
    while (root && root->left != NULL)
        root = root->left;
    return root->data;
}

int maxValue(NODE *root)
{
    while (root && root->right != NULL)
        root = root->right;
    return root->data;
}

int countNULL(NODE *root)
{
    if (root == NULL)
        return 1;
    return countNULL(root->left) + countNULL(root->right);
}

// OUTPUT

// Creating Binary Search Tree
// Enter -1 to Stop
// Enter Root Data: 15
// Enter Next Data: 10
// Enter Next Data: 20
// Enter Next Data: 25
// Enter Next Data: 8
// Enter Next Data: 12
// Enter Next Data: 18
// Enter Next Data: -1

// Displaying Tree Using Inorder
// 8 10 12 15 18 20 25
// Displaying Tree Using Preorder
// 15 10 8 12 20 18 25
// Displaying Tree Using Postorder
// 8 12 10 18 25 20 15
// Number of Nodes: 7
// Height of the Binary Tree: 2
// Number of Leaf Nodes: 4
// Number of Internal Nodes: 3
// Enter a Value to Search: 12
// 12 is present in the Tree.
// The Binary Search Tree is Complete.
// Enter a Value to Insert in BST: 19
// 19 is Inserted in BST
// Enter a Value to Delete from BST: 20
// 20 is Deleted from BST
// Enter a Value to get Balance Factor: 25
// Balance Factor of 25: 2
// Minimum Value in BST: 8
// Maximum Value in BST: 25
// Number of NULL pointers: 8

/*

15 10 20 25 8 12 18
         ↓

        15                      15                   15             Height 0
      /    \                  /    \               /    \
    10      20      -→      10      20    -→     10      25         Height 1
   /  \    /  \            /  \    /  \         /  \    /
  8   12  18  25          8   12  18  25       8   12  18           Height 2
                                    \                    \
                                    19                   19         Height 3

                         (After Insertion)     (After Deletation)

*/