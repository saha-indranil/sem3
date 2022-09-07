# Write a python program to merge two already sorted list.

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


def mergeLists(headA, headB):
    dummyNode = Node(0)
    tail = dummyNode
    while True:
        if headA is None:
            tail.next = headB
            break
        if headB is None:
            tail.next = headA
            break
        if headA.data <= headB.data:
            tail.next = headA
            headA = headA.next
        else:
            tail.next = headB
            headB = headB.next
        tail = tail.next
    return dummyNode.next


listA = LinkedList()
print("Enter First List")
listA.createList()
listA.displayList()

listB = LinkedList()
print("Enter Second List")
listB.createList()
listB.displayList()

listA.head = mergeLists(listA.head, listB.head)
print("Merged Linked List is:")
listA.displayList()

# OUTPUT
# Enter First List
# Creating Linked List...
# Enter - 1 to end
# Enter the data: 5
# Enter the data: 7
# Enter the data: 9
# Enter the data: -1
# HEAD -> 5 -> 7 -> 9 -> NULL

# Enter Second List
# Creating Linked List...
# Enter - 1 to end
# Enter the data: 3
# Enter the data: 4
# Enter the data: 8
# Enter the data: 10
# Enter the data: -1
# HEAD -> 3 -> 4 -> 8 -> 10 -> NULL

# Merged Linked List is :
# HEAD -> 3 -> 4 -> 5 -> 7 -> 8 -> 9 -> 10 -> NULL
