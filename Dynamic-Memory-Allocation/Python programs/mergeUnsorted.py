# 8. Write a python program to merge two
# unsorted dynamic array in sorted order.


def merge(arr1, arr2, n1, n2):
    i = j = k = 0
    arr3 = [None]*(n1+n2)
    while i < n1:
        arr3[k] = arr1[i]
        i += 1
        k += 1
    while j < n2:
        arr3[k] = arr2[j]
        j += 1
        k += 1
    arr3.sort()
    return arr3


arr1 = [2, 7, 3, 1]
arr2 = [5, 8, 4, 9, 6]
res = merge(arr1, arr2, len(arr1), len(arr2))
print(res)

# OUTPUT
# [1, 2, 3, 4, 5, 6, 7, 8, 9]
