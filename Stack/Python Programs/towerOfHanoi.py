# Write a program to solve the tower of Hanoi using stack

import sys


class Stack:
    def __init__(self, capacity):
        self.capacity = capacity
        self.top = -1
        self.array = [0]*capacity


def createStack(capacity):
    stack = Stack(capacity)
    return stack


def isFull(stack):
    return (stack.top == (stack.capacity - 1))


def isEmpty(stack):
    return (stack.top == -1)


def push(stack, item):
    if(isFull(stack)):
        return
    stack.top += 1
    stack.array[stack.top] = item


def Pop(stack):
    if(isEmpty(stack)):
        return -sys.maxsize
    Top = stack.top
    stack.top -= 1
    return stack.array[Top]


def moveDisksBetweenTwoPoles(src, dest, s, d):
    pole1TopDisk = Pop(src)
    pole2TopDisk = Pop(dest)

    if (pole1TopDisk == -sys.maxsize):
        push(src, pole2TopDisk)
        moveDisk(d, s, pole2TopDisk)

    elif (pole2TopDisk == -sys.maxsize):
        push(dest, pole1TopDisk)
        moveDisk(s, d, pole1TopDisk)

    elif (pole1TopDisk > pole2TopDisk):
        push(src, pole1TopDisk)
        push(src, pole2TopDisk)
        moveDisk(d, s, pole2TopDisk)

    else:
        push(dest, pole2TopDisk)
        push(dest, pole1TopDisk)
        moveDisk(s, d, pole1TopDisk)


def moveDisk(fromPeg, toPeg, disk):
    print("Move the disk", disk, "from '", fromPeg, "' to '", toPeg, "'")


def tohIterative(num_of_disks, src, aux, dest):
    s, d, a = 'A', 'C', 'B'

    if (num_of_disks % 2 == 0):
        temp = d
        d = a
        a = temp
    total_num_of_moves = int(pow(2, num_of_disks) - 1)

    for i in range(num_of_disks, 0, -1):
        push(src, i)

    for i in range(1, total_num_of_moves + 1):
        if (i % 3 == 1):
            moveDisksBetweenTwoPoles(src, dest, s, d)

        elif (i % 3 == 2):
            moveDisksBetweenTwoPoles(src, aux, s, a)

        elif (i % 3 == 0):
            moveDisksBetweenTwoPoles(aux, dest, a, d)


num_of_disks = int(input("Enter Number of Disks: "))
src = createStack(num_of_disks)
dest = createStack(num_of_disks)
aux = createStack(num_of_disks)

tohIterative(num_of_disks, src, aux, dest)

# OUTPUT
# Enter Number of Disks: 3
# Move the disk 1 from ' A ' to ' C '
# Move the disk 2 from ' A ' to ' B '
# Move the disk 1 from ' C ' to ' B '
# Move the disk 3 from ' A ' to ' C '
# Move the disk 1 from ' B ' to ' A '
# Move the disk 2 from ' B ' to ' C '
# Move the disk 1 from ' A ' to ' C
