# Write a program to print the odd number and even
# number nodes separately from a single linked list

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:

    def __init__(self):
        self.head = None

    def create(self):
        print("Creating Linked List...")
        print("Enter -1 to end")
        num = int(input("Enter the data: "))
        while (num != -1):
            self.insert(num)
            num = int(input("Enter the data: "))

    def insert(self, num):
        newNode = Node(num)
        if self.head is None:
            self.head = newNode
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = newNode

    def display(self):
        if self.head is None:
            print("List is empty")
            return
        print("HEAD", end='')
        temp = self.head
        while temp:
            print(" -> " + str(temp.data), end='')
            temp = temp.next
        print(" -> NULL\n")

    def seperateOddEven(self):
        if not self.head:
            return
        odd, even = LinkedList(), LinkedList()
        count = 1
        temp = self.head
        while temp:
            if count % 2 != 0:
                odd.insert(temp.data)
            else:
                even.insert(temp.data)
            temp = temp.next
            count += 1
        return odd, even


myList = LinkedList()
myList.create()
print("Original List: ")
myList.display()
odd, even = myList.seperateOddEven()
print("Odd Nodes: ")
odd.display()
print("Even Nodes: ")
even.display()


# OUTPUT
# Creating Linked List...
# Enter - 1 to end
# Enter the data: 10
# Enter the data: 20
# Enter the data: 30
# Enter the data: 40
# Enter the data: 50
# Enter the data: -1
# Original List:
# HEAD -> 10 -> 20 -> 30 -> 40 -> 50 -> NULL

# Odd Nodes:
# HEAD -> 10 -> 30 -> 50 -> NULL

# Even Nodes:
# HEAD -> 20 -> 40 -> NULL
