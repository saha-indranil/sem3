# Given a singly linked list of size N. The task is
# to swap elements in the linked list pairwise.

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

    def swapNodes(self):
        dummy = Node(0)
        curr = self.head
        if curr is None or curr.next is None:
            return
        prev = dummy
        while curr and curr.next:
            prev.next = curr.next
            curr.next = curr.next.next
            prev.next.next = curr
            curr = curr.next
            prev = prev.next.next
        self.head = dummy.next


myList = LinkedList()
myList.createList()
myList.displayList()
print("List After Swapping")
myList.swapNodes()
myList.displayList()


# OUTPUT
# Creating Linked List...
# Enter -1 to end
# Enter the data: 10
# Enter the data: 20
# Enter the data: 30
# Enter the data: 40
# Enter the data: 50
# Enter the data: -1
# HEAD -> 10 -> 20 -> 30 -> 40 -> 50 -> NULL

# List After Swapping
# HEAD -> 20 -> 10 -> 40 -> 30 -> 50 -> NULL
