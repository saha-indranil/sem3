# Write a Python program to implement the following functions for single linked list.
# • createList • deleteFromFirst • deleteFromLast • deleteFromAny • displayList

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

    def deleteFromFirst(self):
        if self.head is None:
            print("List is empty")
            return
        self.head = self.head.next

    def deleteFromLast(self):
        if self.head is None:
            print("List is empty")
            return
        temp = self.head
        while temp.next.next:
            temp = temp.next
        temp.next = None

    def deleteFromAny(self):
        if self.head is None:
            print("List is empty")
            return
        pos = int(input("Enter Position of Deletation: "))
        temp = self.head
        i = 1
        while i < pos-1 and temp is not None:
            temp = temp.next
            i += 1
        if temp is None:
            print("Index out of bound")
        else:
            temp.next = temp.next.next

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

print("Deleting from First")
myList.deleteFromFirst()
myList.displayList()

print("Deleting from Last")
myList.deleteFromLast()
myList.displayList()

print("Deleting from Any")
myList.deleteFromAny()
myList.displayList()

# OUTPUT
# Creating Linked List...
# Enter - 1 to end
# Enter the data: 2
# Enter the data: 9
# Enter the data: 6
# Enter the data: 8
# Enter the data: 4
# Enter the data: 5
# Enter the data: -1
# Initial List:
# HEAD -> 2 -> 9 -> 6 -> 8 -> 4 -> 5 -> NULL

# Deleting from First
# HEAD -> 9 -> 6 -> 8 -> 4 -> 5 -> NULL

# Deleting from Last
# HEAD -> 9 -> 6 -> 8 -> 4 -> NULL

# Deleting from Any
# Enter Position of Deletation: 3
# HEAD -> 9 -> 6 -> 4 -> NULL
