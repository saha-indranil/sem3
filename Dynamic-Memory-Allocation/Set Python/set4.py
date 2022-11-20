# Return a set of elements present in Set A or B, but not both.

num = {1, 2, 3, 4, 5, 6}
even = {2, 4, 6}
num.difference_update(even)
print(num)

# OUTPUT
# {1, 3, 5}
