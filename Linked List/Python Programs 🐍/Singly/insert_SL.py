# Write a Python program to implement the following functions for single linked list.
# • createList • insertAtFirst • insertAtLast • insertAtAny • displayList

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def createList(self):
        print("Creating Linked List...")
        print("Enter -1 to end")
        num = int(input("Enter the data: "))
        while(num != -1):
            newNode = Node(num)
            if self.head is None:
                self.head = newNode
            else:
                last = self.head
                while last.next:
                    last = last.next
                last.next = newNode
            num = int(input("Enter the data: "))

    def insertAtFirst(self):
        num = int(input("Enter the data: "))
        newNode = Node(num)
        newNode.next = self.head
        self.head = newNode

    def insertAtLast(self):
        num = int(input("Enter the data: "))
        newNode = Node(num)
        if self.head is None:
            self.head = newNode
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = newNode

    def insertAtAny(self):
        pos = int(input("Enter Position of insertion: "))
        num = int(input("Enter the data: "))
        newNode = Node(num)
        temp = self.head
        i = 1
        while i < pos-1 and temp is not None:
            temp = temp.next
            i += 1
        if temp is None:
            print("Index out of bound")
        else:
            newNode.next = temp.next
            temp.next = newNode

    def displayList(self):
        if self.head is None:
            print("List is empty")
            return
        print("HEAD", end='')
        temp = self.head
        while temp:
            print(" -> " + str(temp.data), end='')
            temp = temp.next
        print(" -> NULL\n")


myList = LinkedList()
myList.createList()
print("Initial List: ")
myList.displayList()

print("Inserting at First")
myList.insertAtFirst()
myList.displayList()

print("Inserting at Last")
myList.insertAtLast()
myList.displayList()

print("Inserting at Any")
myList.insertAtAny()
myList.displayList()

# OUTPUT
# Creating Linked List...
# Enter - 1 to end
# Enter the data: 5
# Enter the data: 2
# Enter the data: -1
# Initial List:
# HEAD -> 5 -> 2 -> NULL

# Inserting at First
# Enter the data: 11
# HEAD -> 11 -> 5 -> 2 -> NULL

# Inserting at Last
# Enter the data: 72
# HEAD -> 11 -> 5 -> 2 -> 72 -> NULL

# Inserting at Any
# Enter Position of insertion: 3
# Enter the data: 50
# HEAD -> 11 -> 5 -> 50 -> 2 -> 72 -> NULL
