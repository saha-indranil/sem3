// Write a program to implement Binary Tree using Array along with the following functions:
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
#include <math.h>
#include <stdlib.h>

void createBinaryTree(int[]);
void displayTree(int[]);
void displayInOrder(int[], int);
void displayPreOrder(int[], int);
void displayPostOrder(int[], int);
void nodeCount(int[], int);
int heightCount(int);
void leafCount(int[], int);
void internalCount(int[], int);
void nodeSearch(int[], int, int);

int count = 0;
int leaf_count = 0;
int internal_count = 0;
int flag = 0;
int j = 0;
int complete_binary_tree = 0;
int status[10] = {0};
void checkCompleteBinaryTree(int[], int);

int main()
{

    int arr[7], key; // binary tree

    createBinaryTree(arr);
    nodeCount(arr, 0);
    leafCount(arr, 0);
    internalCount(arr, 0);
    checkCompleteBinaryTree(arr, 0);

    printf("\nTree details:");
    printf("\nTotal no of node: %d", count);
    printf("\nHeight of the tree: %d", heightCount(count));
    printf("\nLeaf node count: %d", leaf_count);
    printf("\nInternal node count: %d", internal_count);
    printf("\nEnter data to be searched in the tree: ");
    scanf("%d", &key);
    nodeSearch(arr, 0, key);
    if (flag == 0)
        printf("\nElement %d not found in the tree.", key);
    if (complete_binary_tree == 1)
        printf("\nGiven Tree is not a Complete Binary Tree.");
    else
        printf("\nGiven Tree is a Complete Binary Tree.");

    printf("\nDisplaying the tree in terms of array:\n ");
    displayTree(arr);
    printf("\nInOrder Traversal of Binary Tree: ");
    displayInOrder(arr, 0);
    printf("\nPreOrder Traversal of Binary Tree: ");
    displayPreOrder(arr, 0);
    printf("\nPostOrder Traversal of Binary Tree: ");
    displayPostOrder(arr, 0);
}

void createBinaryTree(int array[])
{
    int i;
    for (i = 0; i < 3; i++)
    { // 3-> possible max parent index
        if (i == 0)
        {
            printf("Enter the root node:  ");
            scanf("%d", &array[i]);
        }
        printf("Enter the left child node of %d: ", array[i]);
        scanf("%d", &array[(2 * i) + 1]);

        printf("Enter the right child node of %d: ", array[i]);
        scanf("%d", &array[(2 * i) + 2]);
    }
    for (int j = 7; j < 15; j++)
        array[j] = -1;
}

void displayTree(int array[])
{
    int i, j, k = 0;
    printf("%d\n", array[k++]); // root node data
    for (i = 1; i < 3; i++)
    {
        for (j = 0; j < pow(2, i); j++) // per level totol no of node after level 0
        {
            printf("%d ", array[k++]);
            printf("%d  ", array[k++]);
            j = j + 2; // after inserting two children at a time
        }
        printf("\n");
    }
}

void displayInOrder(int tree[], int i)
{
    if (tree[i] != -1)
    {
        displayInOrder(tree, 2 * i + 1);
        printf("%d ", tree[i]);
        displayInOrder(tree, 2 * i + 2);
    }
}

void displayPreOrder(int tree[], int i)
{
    if (tree[i] != -1)
    {
        printf("%d ", tree[i]);
        displayPreOrder(tree, 2 * i + 1);
        displayPreOrder(tree, 2 * i + 2);
    }
}

void displayPostOrder(int tree[], int i)
{
    if (tree[i] != -1)
    {
        displayPostOrder(tree, 2 * i + 1);
        displayPostOrder(tree, 2 * i + 2);
        printf("%d ", tree[i]);
    }
}

void nodeCount(int tree[], int i)
{
    if (tree[i] != -1)
    {
        nodeCount(tree, 2 * i + 1);
        count++;
        nodeCount(tree, 2 * i + 2);
    }
}

int heightCount(int no_of_node)
{
    int h = log2(no_of_node + 1);
    return h;
}

void leafCount(int tree[], int i)
{
    if (tree[i] != -1)
    {
        if (tree[2 * i + 1] == -1 && tree[2 * i + 2] == -1)
            leaf_count++;
        else
        {
            leafCount(tree, 2 * i + 1);
            leafCount(tree, 2 * i + 2);
        }
    }
}

void internalCount(int tree[], int i)
{
    if (tree[i] != -1)
    {
        if (tree[2 * i + 1] != -1 || tree[2 * i + 2] != -1)
            internal_count++;

        internalCount(tree, 2 * i + 1);
        internalCount(tree, 2 * i + 2);
    }
}

void nodeSearch(int tree[], int i, int key)
{
    if (tree[i] != -1)
    {
        if (tree[i] == key)
        {
            printf("\nKey %d is found at %d th node.", key, i + 1);
            flag = 1;
            return;
        }
        nodeSearch(tree, 2 * i + 1, key);
        nodeSearch(tree, 2 * i + 2, key);
    }
}

void checkCompleteBinaryTree(int tree[], int i)
{
    if (tree[i] != -1)
    {
        if (tree[2 * i + 1] == -1 && tree[2 * i + 2] != -1)
        {
            complete_binary_tree = 0;
            exit(0);
        }
        else if (tree[2 * i + 1] != -1 && tree[2 * i + 2] != -1)
        {
            if (status[j - 1] == 2)
            {
                complete_binary_tree = 0;
                return;
            }
            status[j++] = 1;
        }
        else if (tree[2 * i + 1] != -1 && tree[2 * i + 2] == -1)
        {
            status[j++] = 2;
        }

        checkCompleteBinaryTree(tree, 2 * i + 1);
        checkCompleteBinaryTree(tree, 2 * i + 2);
    }
}

/*

         14(1)
        /   \
     51(2)   32(3)
     /    \
  48(4)    17(5)

*/

// OUTPUT
// Enter the root node:  14
// Enter the left child node of 14: 51
// Enter the right child node of 14: 32
// Enter the left child node of 51: 48
// Enter the right child node of 51: 17
// Enter the left child node of 32: -1
// Enter the right child node of 32: -1

// Tree details:
// Total no of node: 5
// Height of the tree: 2
// Leaf node count: 3
// Internal node count: 2
// Enter data to be searched in the tree: 17

// Key 17 is found at 5 th node.
// Given Tree is a Complete Binary Tree.
// Displaying the tree in terms of array:
//  14
// 51 32
// 48 17  -1 -1

// InOrder Traversal of Binary Tree: 48 51 17 14 32
// PreOrder Traversal of Binary Tree: 14 51 48 17 32
// PostOrder Traversal of Binary Tree: 48 17 51 32 14