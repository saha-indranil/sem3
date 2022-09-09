class MyCircularQueue():
    def __init__(self, k):
        self.k = k  # size of the circular queue
        # array to store the elements of the circular queue
        self.queue = [0] * k
        self.front = self.rear = -1

    def enqueue(self, data):

        if ((self.rear + 1) % self.k == self.front):
            print("The circular queue is full\n")

        elif (self.front == -1):
            self.front = 0
            self.rear = 0
            self.queue[self.rear] = data
        else:
            self.rear = (self.rear + 1) % self.k
            self.queue[self.rear] = data

    def dequeue(self):
        if (self.front == -1):
            print("The circular queue is empty\n")

        elif (self.front == self.rear):
            temp = self.queue[self.front]
            self.front = -1
            self.rear = -1
            return temp
        else:
            temp = self.queue[self.front]
            self.front = (self.front + 1) % self.k
            return temp

    def printCQueue(self):
        if(self.front == -1):
            print("No element in the circular queue")

        elif (self.rear >= self.front):
            for i in range(self.front, self.rear + 1):
                print(self.queue[i], end=" ")
            print()
        else:
            for i in range(self.front, self.k):
                print(self.queue[i], end=" ")
            for i in range(0, self.rear + 1):
                print(self.queue[i], end=" ")
            print()


obj = MyCircularQueue(5)
obj.enqueue(1)
obj.enqueue(2)
obj.enqueue(3)
obj.enqueue(4)
obj.enqueue(5)
print("Initial queue")
obj.printCQueue()

obj.dequeue()
print("After removing an element from the queue")
obj.printCQueue()
