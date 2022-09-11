# Write a program to calculate factorial with the help of stack.

stack1 = []


def push(item):
    stack1.append(item)
    return stack1


def pop():
    if len(stack1) == 0:
        return "Stack is empty"
    else:
        return stack1.pop()


if __name__ == '__main__':
    n = int(input("Enter a Number: "))
    push(1)
    for i in range(2, n+1):
        temp = pop()
        push(temp*i)
    print("Factorial: "+str(pop()))


# OUTPUT
# Enter a Number: 6
# Factorial: 720
