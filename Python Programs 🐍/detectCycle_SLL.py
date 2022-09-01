# Write a python program to detect
# a loop in a single linked list.

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

    def detectCycle(self):
        slow = self.head
        fast = self.head
        entry = self.head
        if fast is None and fast.next is None:
            print("No Cycle in Linked List")
            return
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                while slow != entry:
                    slow = slow.next
                    entry = entry.next
                print("Cycle Detected at Node Data: "+str(entry.data))
                return
        print("No Cycle in Linked List")


if __name__ == "__main__":
    myList = LinkedList()
    print("Enter More Than 2 Data")
    myList.createList()
    myList.displayList()
    myList.detectCycle()

    size = 1
    tail = myList.head
    while tail.next:
        tail = tail.next
        size += 1

    if size >= 2:
        tail.next = myList.head.next
        print("Linked List Successfully created with Cycle")
        myList.detectCycle()


# OUTPUT
# Enter More Than 2 Data
# Creating Linked List...
# Enter - 1 to end
# Enter the data: 51
# Enter the data: 97
# Enter the data: 3
# Enter the data: 6
# Enter the data: -1
# HEAD -> 51 -> 97 -> 3 -> 6 -> NULL

# No Cycle in Linked List
# Linked List Successfully created with Cycle
# Cycle Detected at Node Data: 97
