# Write a Python program to implement a stack.

stack = []


def push(item):
    stack.append(item)
    return stack


def pop():
    if len(stack) == 0:
        return "Stack is empty"
    else:
        return stack.pop()


def peek():
    if len(stack) == 0:
        return "Stack is empty"
    else:
        return stack[-1]


choice = int(input("1. Push\n2. Pop\n3. Peek\n4. Exit\nEnter your choice: "))
while choice != 4:
    if choice == 1:
        item = input("Enter the item to push: ")
        push(item)
        print("Stack: ", stack)
    elif choice == 2:
        print("Popped item: ", pop())
        print("Stack: ", stack)
    elif choice == 3:
        print("Peeked item: ", peek())
        print("Stack: ", stack)
    else:
        print("Invalid choice")
    choice = int(
        input("1. Push\n2. Pop\n3. Peek\n4. Exit\nEnter your choice: "))
