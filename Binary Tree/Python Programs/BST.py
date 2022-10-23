# Write a Python program to implement Binary Search Tree using linked list along with the following functions:
# a. To create a binary search tree.
# b. To display tree using inorder.
# c. To display tree using preorder.
# d. To display tree using postorder.
# e. To count number of node present in the tree.
# f. To find the height of the tree.
# g. To find the number of leaf node.
# h. To find the number of internal node.
# i. To search a data present in the tree.
# j. To check complete binary tree.
# k. To insert a node.
# l. To delete a node.
# m. To check the balance factor of a node.
# n. To find the minimum value present in the tree.
# o. To find the maximum value present in the tree.
# p. To count number of NULL pointer present in the tree.


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def createBST(self, root):
        print("Creating Binary Search Tree")
        print("Enter -1 to Stop")
        data = int(input("Enter Root Data: "))
        while data != -1:
            root = self.insertNode(root, data)
            data = int(input("Enter Next Data: "))
        return root

    def inorder(self, root):
        if root is None:
            return
        self.inorder(root.left)
        print(root.data, end=' ')
        self.inorder(root.right)

    def preorder(self, root):
        if root is None:
            return
        print(root.data, end=' ')
        self.preorder(root.left)
        self.preorder(root.right)

    def postorder(self, root):
        if root is None:
            return
        self.postorder(root.left)
        self.postorder(root.right)
        print(root.data, end=' ')

    def countNodes(self, root):
        if root is None:
            return 0
        return self.countNodes(root.left) + self.countNodes(root.right) + 1

    def height(self, root):
        if root is None:
            return -1
        return max(self.height(root.left), self.height(root.right)) + 1

    def countLeaf(self, root):
        if root is None:
            return 0
        if root.left is None and root.right is None:
            return 1
        return self.countLeaf(root.left) + self.countLeaf(root.right)

    def countInternal(self, root):
        if root is None or (root.left is None and root.right is None):
            return 0
        return self.countInternal(root.left) + self.countInternal(root.right) + 1

    def search(self, root, val):
        if root is None:
            return False
        if root.data == val:
            return True
        if root.data > val:
            return self.search(root.left, val)
        return self.search(root.right, val)

    def isComplete(self, root, idx, numNodes):
        if root is None:
            return True
        if idx >= numNodes:
            return False
        return self.isComplete(root.left, 2*idx+1, numNodes) and self.isComplete(root.right, 2*idx+2, numNodes)

    def insertNode(self, root, data):
        if root is None:
            return Node(data)
        if(root.data > data):
            root.left = self.insertNode(root.left, data)
        else:
            root.right = self.insertNode(root.right, data)
        return root

    def deleteNode(self, root, val):
        if root is None:
            return root
        if val < root.data:
            root.left = self.deleteNode(root.left, val)
        elif val > root.data:
            root.right = self.deleteNode(root.right, val)
        else:
            if root.left is None:
                return root.right
            elif root.right is None:
                return root.left
            root.data = self.minValue(root.right)
            root.right = self.deleteNode(root.right, root.data)
        return root

    def balanceFactor(self, root, val):
        if root.data > val:
            return self.balanceFactor(root.left, val)
        if root.data < val:
            return self.balanceFactor(root.right, val)
        return abs(self.height(root.left)-self.height(root.right))

    def minValue(self, root):
        while root and root.left:
            root = root.left
        return root.data

    def maxValue(self, root):
        while root and root.right:
            root = root.right
        return root.data

    def countNone(self, root):
        if root is None:
            return 1
        return self.countNone(root.left)+self.countNone(root.right)


if __name__ == "__main__":
    tree = BinarySearchTree()
    tree.root = tree.createBST(tree.root)

    print("Displaying Tree Using Inorder")
    tree.inorder(tree.root)
    print("\nDisplaying Tree Using Preorder")
    tree.preorder(tree.root)
    print("\nDisplaying Tree Using Postorder")
    tree.postorder(tree.root)

    print("\nNumber of Nodes:", tree.countNodes(tree.root))
    print("Height of Binary Tree:", tree.height(tree.root))
    print("Number of Leaf Nodes:", tree.countLeaf(tree.root))
    print("Number of Internal Nodes:", tree.countInternal(tree.root))

    #Search in BST
    val = int(input("Enter a Value to Search: "))
    if tree.search(tree.root, val):
        print(val, "is present in the Tree")
    else:
        print(val, "is not present in the Tree")

    # Check if Complete
    if tree.isComplete(tree.root, 0, tree.countNodes(tree.root)):
        print("The Binary Search Tree is Complete.")
    else:
        print("The Binary Search Tree is not Complete.")

    # Insertion in BST
    val = int(input("Enter a Data to Insert in BST: "))
    tree.root = tree.insertNode(tree.root, val)
    print(val, "is Inserted in BST")

    # Deletation from BST
    val = int(input("Enter a Data to Delete from BST: "))
    tree.root = tree.deleteNode(tree.root, val)
    print(val, "is Deleted from BST")

    # Balance Factor of a Node
    val = int(input("Enter a Value to get Balance Factor: "))
    if tree.search(tree.root, val):
        print("Balance Factor of", val, "is",tree.balanceFactor(tree.root, val))
    else:
        print(val, "is not present in the tree")

    print("Minimum Value is BST: ", tree.minValue(tree.root))
    print("Maximum Value is BST: ", tree.maxValue(tree.root))
    print("Number of None Pointers: ", tree.countNone(tree.root))


"""
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
"""


# OUTPUT
# Creating Binary Search Tree
# Enter -1 to Stop
# Enter Root Data: 15
# Enter Next Data: 10
# Enter Next Data: 20
# Enter Next Data: 25
# Enter Next Data: 8
# Enter Next Data: 12
# Enter Next Data: 18
# Enter Next Data: -1
# Displaying Tree Using Inorder
# 8 10 12 15 18 20 25
# Displaying Tree Using Preorder
# 15 10 8 12 20 18 25
# Displaying Tree Using Postorder
# 8 12 10 18 25 20 15
# Number of Nodes: 7
# Height of Binary Tree: 2
# Number of Leaf Nodes: 4
# Number of Internal Nodes: 3
# Enter a Value to Search: 18
# 18 is present in the Tree
# The Binary Search Tree is Complete.
# Enter a Data to Insert in BST: 19
# 19 is Inserted in BST
# Enter a Data to Delete from BST: 20
# 20 is Deleted from BST
# Enter a Value to get Balance Factor: 25
# Balance Factor of 25 is 2
# Minimum Value is BST:  8
# Maximum Value is BST:  25
# Number of None Pointers:  8
