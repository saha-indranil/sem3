# 3. Write a python program to find the minimum element
# in an array using dynamic memory allocation.

list = [3, 8, 4, 2, 1, 7, 9]
min = list[0]
for i in list:
    if i < min:
        min = i
print(min, "is minimum in the list")

# OUTPUT
# 1 is minimum in the list
