# 10. Write a python program to modify the size
# of an array and utilize that during run time.

arr = [1, 2, 3, 4]
n = int(input("Enter number of extra elements: "))
print("Enter the elements: ")
for i in range(n):
    ele = int(input())
    arr.append(ele)
print(arr)

# OUTPUT
# Enter number of extra elements: 3
# Enter the elements:
# 9
# 8
# 7
# [1, 2, 3, 4, 9, 8, 7]
