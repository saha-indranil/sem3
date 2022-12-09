# 2. Write a python program to find the 3rd/user defined position based
# maximum element in an array using dynamic memory allocation.

list = [3, 8, 4, 2, 5, 7, 9]
max = list[0]
for i in list:
    if i > max:
        max = i
print(max, "is largest in the list")

# OUTPUT 
# 9 is largest in the list
