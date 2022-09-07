# Write a function to count the number
# of node present in a linked list.

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

    def size(self):
        count = 0
        temp = self.head
        while temp:
            count += 1
            temp = temp.next
        return count


myList = LinkedList()
myList.createList()
n = myList.size()
print("Number of Nodes is: " + str(n))


# OUTPUT
# Creating Linked List...
# Enter -1 to end
# Enter the data: 6
# Enter the data: 3
# Enter the data: 8
# Enter the data: 2
# Enter the data: -1
# Number of Nodes is: 4
