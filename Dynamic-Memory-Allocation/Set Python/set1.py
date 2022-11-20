# Add a list of elements to a set.

num = {1, 3, 5, 7, 9}
e = [2, 4, 6, 8]

print("Before adding List:", num)
num.update(e)
print("Updated Set:", num)


# OUTPUT
# Before adding List: {1, 3, 5, 7, 9}
# Updated Set: {1, 2, 3, 4, 5, 6, 7, 8, 9}
