# Write a program to validate the parenthesis of an expression.

open_list = ["(", "{", "["]
close_list = [")", "}", "]"]


def validate(str):
    stack = []
    for i in str:
        if i in open_list:
            stack.append(i)
        elif i in close_list:
            pos = close_list.index(i)
            if((len(stack) > 0) and (open_list[pos] == stack[len(stack)-1])):
                stack.pop()
            else:
                return "Parenthesis are not matching"
    if len(stack) == 0:
        return "Parenthesis are matching!!!"
    else:
        return "Parenthesis are not matching"


str = input("Enter Parenthesis: ")
print(validate(str))

# OUTPUT1
# Enter Parenthesis: {} () [{()}]
# Parenthesis are matching!!!

# OUTPUT2
# Enter Parenthesis: (({})
# Parenthesis are not matching
