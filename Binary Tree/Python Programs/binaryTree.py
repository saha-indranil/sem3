# 1. Write a program to implement Binary Tree using linked list along with the following functions:
# a) To create a binary tree.
# b) To display tree using inorder.
# c) To display tree using preorder.
# d) To display tree using postorder.
# e) To count number of node present in the tree.
# f) To find the height of the tree.
# g) To find the number of leaf node.
# h) To find the number of internal node.
# i) To search a data present in the tree.

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BinaryTree:
    def __init__(self):
        self.root = None

    def createTree(self):
        val = int(input())
        if val == -1:
            return None
        root = Node(val)
        print("Enter left child of", root.data, end=": ")
        root.left = self.createTree()
        print("Enter right child of", root.data, end=": ")
        root.right = self.createTree()
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
            return 0
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

    def search(self, root, data):
        if root is None:
            return False
        if root.data == data:
            return True
        return self.search(root.left, data) or self.search(root.right, data)


print("Enter -1 for None")
print("Enter Root Data: ", end='')
tree = BinaryTree()
tree.root = tree.createTree()

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

val = int(input("Enter a Data to Search: "))
if tree.search(tree.root, val):
    print(val, "is present in the Binary Tree")
else:
    print(val, "is not present in the Binary Tree")


"""
          14
        /   \
       51    32
     /    \
    48     17
          /
         93
"""

# OUTPUT

# Enter -1 for None
# Enter Root Data: 14
# Enter left child of 14: 51
# Enter left child of 51: 48
# Enter left child of 48: -1
# Enter right child of 48: -1
# Enter right child of 51: 17
# Enter left child of 17: 93
# Enter left child of 93: -1
# Enter right child of 93: -1
# Enter right child of 17: -1
# Enter right child of 14: 32
# Enter left child of 32: -1
# Enter right child of 32: -1
# Displaying Tree Using Inorder
# 48 51 93 17 14 32
# Displaying Tree Using Preorder
# 14 51 48 17 93 32
# Displaying Tree Using Postorder
# 48 93 17 51 32 14
# Number of Nodes: 6
# Height of Binary Tree: 4
# Number of Leaf Nodes: 3
# Number of Internal Nodes: 3
# Enter a Data to Search: 93
# 93 is present in the Binary Tree
