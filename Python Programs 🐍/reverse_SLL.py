# Write a python program to reverse an
# already created single linked list.

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

    def reverse(self):
        curr = self.head
        prev = None
        while curr is not None:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        self.head = prev


myList = LinkedList()
myList.createList()
print("Original List:")
myList.displayList()
myList.reverse()
print("Reversed List:")
myList.displayList()


# OUTPUT
# Creating Linked List...
# Enter - 1 to end
# Enter the data: 1
# Enter the data: 2
# Enter the data: 3
# Enter the data: 4
# Enter the data: 5
# Enter the data: -1
# Original List:
# HEAD -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL

# Reversed List:
# HEAD -> 5 -> 4 -> 3 -> 2 -> 1 -> NULL
