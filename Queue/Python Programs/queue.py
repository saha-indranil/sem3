# Write a Python program to implement a queue.
# write a program to implement a queue

queue = []


def enqueue(item):
    queue.append(item)
    return queue


def dequeue():
    if len(queue) == 0:
        return "Queue is empty"
    else:
        return queue.pop(0)


def peek():
    if len(queue) == 0:
        return "Queue is empty"
    else:
        return queue[0]


choice = int(
    input("1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nEnter your choice: "))
while choice != 4:
    if choice == 1:
        item = input("Enter the item to enqueue: ")
        enqueue(item)
        print("Queue: ", queue)
    elif choice == 2:
        print("Dequeued item: ", dequeue())
        print("Queue: ", queue)
    elif choice == 3:
        print("Peeked item: ", peek())
        print("Queue: ", queue)
    else:
        print("Invalid choice")
    choice = int(
        input("1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nEnter your choice: "))
