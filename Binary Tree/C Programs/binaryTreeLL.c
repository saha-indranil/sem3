// Write a program to implement Binary Tree using linked list along with the following functions:
// a) To create a binary tree.
// b) To display tree using inorder.
// c) To display tree using preorder.
// d) To display tree using postorder.
// e) To count number of node present in the tree.
// f) To find the height of the tree.
// g) To find the number of leaf node.
// h) To find the number of internal node.
// i) To search a data present in the tree.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE *createNode(int);
NODE *createTree(void);
void inorder(NODE *root);
void preorder(NODE *root);
void postorder(NODE *root);
int countNodes(NODE *root);
int height(NODE *root);
int countLeaf(NODE *root);
int countInternal(NODE *root);
void search(NODE *root, int);
int flag = 0;

int main()
{
    int val;
    printf("Enter -1 for NULL\n");
    printf("Enter Root Data: ");
    NODE *root = createTree();

    printf("\nPrinting Tree Using Inorder\n");
    inorder(root);
    printf("\nPrinting Tree Using Preorder\n");
    preorder(root);
    printf("\nPrinting Tree Using Postorder\n");
    postorder(root);

    printf("\nNumber of Nodes: %d", countNodes(root));
    printf("\nHeight of the Binary Tree: %d", height(root));
    printf("\nNumber of Leaf Nodes: %d", countLeaf(root));
    printf("\nNumber of Internal Nodes: %d", countInternal(root));

    printf("\nEnter item to search: ");
    scanf("%d", &val);
    search(root, val);
    if (flag == 1)
        printf("%d is present in Binary Tree");
    else
        printf("%d is not present in Binary Tree");

    return 0;
}

NODE *createNode(int val)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

NODE *createTree(void)
{
    NODE *root = NULL;
    int data;
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    root = createNode(data);

    printf("Enter LEFT Child of %d: ", data);
    root->left = createTree();
    printf("Enter RIGHT Child of %d: ", data);
    root->right = createTree();

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
        return 0;
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
    return 1 + countInternal(root->left) + countInternal(root->right);
}

void search(NODE *root, int val)
{
    if (root == NULL)
    {
        printf("\nTree is empty");
        return;
    }
    if (root->data == val)
    {
        flag = 1;
        return;
    }
    if (root->left != NULL)
        search(root->left, val);
    if (root->right != NULL)
        search(root->right, val);
}

/*

          14
        /   \
       51    32
     /    \
    48     17
          /
         93

*/

// OUTPUT
// Enter -1 for NULL
// Enter Root Data: 14
// Enter LEFT Child of 14: 51
// Enter LEFT Child of 51: 48
// Enter LEFT Child of 48: -1
// Enter RIGHT Child of 48: -1
// Enter RIGHT Child of 51: 17
// Enter LEFT Child of 17: 93
// Enter LEFT Child of 93: -1
// Enter RIGHT Child of 93: -1
// Enter RIGHT Child of 17: -1
// Enter RIGHT Child of 14: 32
// Enter LEFT Child of 32: -1
// Enter RIGHT Child of 32: -1

// Printing Tree Using Inorder
// 48 51 93 17 14 32
// Printing Tree Using Preorder
// 14 51 48 17 93 32
// Printing Tree Using Postorder
// 48 93 17 51 32 14
// Number of Nodes: 6
// Height of the Binary Tree: 4
// Number of Leaf Nodes: 3
// Number of Internal Nodes: 3
// Enter item to search: 17
// 17 is present in Binary Tree