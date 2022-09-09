# Given a stack of boxes in different colors. Write a python function
# that accepts the stack of boxes and removes those boxes having
# color other than the primary colors(Red, Green and Blue) from the stack.
# The removed boxes should be en-queued into a new queue and returned.
# The original stack should have only the boxes having primary colors
# and the order must be maintained.
# Perform case sensitive string comparison wherever necessary.


def remove_color(stack):
    new_stack = []
    new_queue = []
    while stack:
        box = stack.pop()
        if box == 'Red' or box == 'Green' or box == 'Blue':
            new_stack.append(box)
            new_queue.append(box)
    return new_stack, new_queue


if __name__ == '__main__':
    a = int(input("Enter the number of boxes: "))
    stack = []
    for i in range(a):
        stack.append(input("Enter the color of the box: "))
    print("The stack is: ", stack)
    new_stack, new_queue = remove_color(stack)
    print("The new stack is: ", new_stack)
    print("The new queue is: ", new_queue)
    print("The original stack is: ", stack)
    print("The original queue is: ", stack)

# Enter the number of boxes: 5
# Enter the color of the box: Red
# Enter the color of the box: Yellow
# Enter the color of the box: Blue
# Enter the color of the box: Green
# Enter the color of the box: RedThe stack is:  ['Red', 'Yellow', 'Blue', 'Green', 'Red']
# The new stack is:  ['Red', 'Green', 'Blue', 'Red']
# The new queue is:  ['Red', 'Green', 'Blue', 'Red']
# The original stack is:  []
# The original queue is:  []
