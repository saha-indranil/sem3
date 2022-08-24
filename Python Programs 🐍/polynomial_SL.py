# Write a C program to store polynomial using
# linked list. Store the term in descending order.

class Node:
    def __init__(self, coeff, expo):
        self.coeff = coeff
        self.expo = expo
        self.next = None


class Polynomial:
    def __init__(self):
        self.head = None

    def createList(self):
        n = int(input("Enter number of terms: "))
        for i in range(n):
            coeff = int(input("Enter the Coefficient of term "+str(i+1)+": "))
            expo = int(input("Enter the Exponent of term " + str(i+1) + ": "))
            self.insert(coeff, expo)

    def insert(self, co, ex):
        newNode = Node(co, ex)
        temp = self.head
        if self.head is None or ex > temp.expo:
            newNode.next = self.head
            self.head = newNode
        else:
            while temp.next is None and ex < temp.next.expo:
                temp = temp.next
            newNode.next = temp.next
            temp.next = newNode

    def display(self):
        if self.head is None:
            print("No Polynomial")
            return
        print("Your Polynomial Equation is:")
        temp = self.head
        while temp:
            print("( "+str(temp.coeff)+"x^"+str(temp.expo)+" )", end='')
            temp = temp.next
            if temp is not None:
                print(" + ", end='')


poly = Polynomial()
print("Enter the Polynomial...")
poly.createList()
poly.display()

# OUTPUT
# Enter the Polynomial...
# Enter number of terms: 4
# Enter the Coefficient of term 1: 10
# Enter the Exponent of term 1: 2
# Enter the Coefficient of term 2: 20
# Enter the Exponent of term 2: 8
# Enter the Coefficient of term 3: 30
# Enter the Exponent of term 3: 4
# Enter the Coefficient of term 4: 40
# Enter the Exponent of term 4: 6
# Your Polynomial Equation is:
# ( 20x^8 ) + ( 40x^6 ) + ( 30x^4 ) + ( 10x^2 )
