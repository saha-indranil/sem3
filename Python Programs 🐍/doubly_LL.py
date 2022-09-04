# Write a python program to create a Double linked list along with the following functions:
# a) to display the elements of a Double Linked List.
# b) to add an element at beginning of a Double linked list.
# c) to add an element at the end of a Double linked list.
# d) to add an element at any user given position of a Double linked list.
# e) to search a user given element in a Double linked list.
# f) to count the number of nodes in a Double linked list.
# g) to delete a node at beginning of a Double linked list.
# h) to delete a node at end of a Double linked list.
# i) to delete a node from any position of a Double linked list.
# (Create a menu bar for accessing the functions)

class Node:
    def __init__(self, data):
        self.prev = None
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def displayList(self):
        if self.head is None:
            print("List is empty")
            return
        print("HEAD", end='')
        temp = self.head
        while temp:
            print(" <-> " + str(temp.data), end='')
            temp = temp.next
        print(" -> NULL")

    def addAtBeg(self):
        num = int(input("Enter the data: "))
        newNode = Node(num)
        if self.head is None:
            self.head = newNode
        else:
            newNode.next = self.head
            self.head.prev = newNode
            self.head = newNode

    def addAtEnd(self):
        num = int(input("Enter the data: "))
        newNode = Node(num)
        if self.head is None:
            self.head = newNode
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = newNode
        newNode.prev = last

    def addAtAny(self):
        pos = int(input("Enter Position: "))
        temp = self.head
        n = self.countNodes()
        if pos <= 0 or pos > n+1:
            print("Index Out of Bound")
        elif pos == 1:
            self.addAtBeg()
        elif pos == n+1:
            self.addAtEnd()
        else:
            num = int(input("Enter the data: "))
            newNode = Node(num)
            temp1 = self.head
            while pos > 2:
                temp1 = temp1.next
                pos -= 1
            temp2 = temp1.next
            temp1.next = newNode
            temp2.prev = newNode
            newNode.prev = temp1
            newNode.next = temp2

    def searchItem(self):
        if self.head is None:
            print("List is empty")
            return
        count = 0
        val = int(input("Enter Item: "))
        temp = self.head
        while temp:
            count += 1
            if temp.data == val:
                print("Item Found at Node: "+str(count))
                return
            temp = temp.next
        print("Item Not Found!")

    def countNodes(self):
        temp = self.head
        count = 0
        while temp:
            temp = temp.next
            count += 1
        return count

    def delFromBeg(self):
        if self.head is None:
            print("List is empty")
        elif self.head.next is None:
            self.head = None
        else:
            self.head = self.head.next
            self.head.prev = None

    def delFromEnd(self):
        if self.head is None:
            print("List is empty")
        elif self.head.next is None:
            self.head = None
        else:
            temp = self.head
            while temp.next:
                temp = temp.next
            temp.prev.next = None
            temp = None

    def delFromAny(self):
        pos = int(input("Enter Position: "))
        n = self.countNodes()
        if pos <= 0 or pos > n:
            print("Index Out of Bound")
        elif pos == 1:
            self.delFromBeg()
        elif pos == n:
            self.delFromEnd()
        else:
            temp1 = self.head
            while pos > 1:
                temp1 = temp1.next
                pos -= 1
            temp2 = temp1.prev
            temp2.next = temp1.next
            temp1.next.prev = temp2
            temp1 = None


if __name__ == '__main__':
    myList = LinkedList()
    print("*** MAIN MENU ***")
    print("1. Display Double Linked List")
    print("2. Add At First")
    print("3. Add At End")
    print("4. Add At Any Position")
    print("5. Search an Element")
    print("6. Count No. Of Nodes")
    print("7. Delete From First")
    print("8. Delete From End")
    print("9. Delete From Any Position")
    print("10. Exit")
    while True:
        option = int(input("Enter Choice: "))
        if option == 1:
            myList.displayList()
        elif option == 2:
            myList.addAtBeg()
        elif option == 3:
            myList.addAtEnd()
        elif option == 4:
            myList.addAtAny()
        elif option == 5:
            myList.searchItem()
        elif option == 6:
            n = myList.countNodes()
            print("Number of Nodes is "+str(n))
        elif option == 7:
            myList.delFromBeg()
        elif option == 8:
            myList.delFromEnd()
        elif option == 9:
            myList.delFromAny()
        elif option == 10:
            break
        else:
            print("Invalid Choice!")

# OUTPUT
# *** MAIN MENU ***
# 1. Display Double Linked List
# 2. Add At First
# 3. Add At End
# 4. Add At Any Position
# 5. Search an Element
# 6. Count No. Of Nodes
# 7. Delete From First
# 8. Delete From End
# 9. Delete From Any Position
# 10. Exit
# Enter Choice: 2
# Enter the data: 10
# Enter Choice: 3
# Enter the data: 20
# Enter Choice: 4
# Enter Position: 2
# Enter the data: 30
# Enter Choice: 1
# HEAD <-> 10 <-> 30 <-> 20 -> NULL
# Enter Choice: 5
# Enter Item: 30
# Item Found at Node: 2
# Enter Choice: 6
# Number of Nodes is 3
# Enter Choice: 9
# Enter Position: 2
# Enter Choice: 1
# HEAD <-> 10 <-> 20 -> NULL
# Enter Choice: 8
# Enter Choice: 7
# Enter Choice: 1
# List is empty
# Enter Choice: 10
