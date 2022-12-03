# Write a python program to search an element in an Array using dynamic memory allocation.

list1 = [1, 2, 3, 4, 5]
key = int(input("Enter the key: "))
flag = 0
for i in range(len(list1)):
    if list1[i] == key:
        flag = 1
        break
if flag == 1:
    print(key, "found in index:", i)
else:
    print("Not in list")

# OUTPUT
# Enter the key: 4
# 4 found in index: 3
