# Write a Python program to reverse a string using stack (using array). (Assignment 2)
# Write a program to reverse a string using stack. (Assignment 6)

def reverse_string(str):
    print("Original String: "+str)
    print("Reversed String: ", end='')
    stack = []
    for i in str:
        stack.append(i)
    while len(stack) > 0:
        print(stack.pop(), end="")
    print()


reverse_string("hello world")


# OUTPUT
# Original String: hello world
# Reversed String: dlrow olleh
