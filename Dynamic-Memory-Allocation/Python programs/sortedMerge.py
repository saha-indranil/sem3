# 7. Write a python program to merge two sorted dynamic array.

def merge(arr1, arr2, n1, n2):
    i = j = k = 0
    arr3 = [None]*(n1+n2)
    while i < n1 and j < n2:
        if arr1[i] < arr2[j]:
            arr3[k] = arr1[i]
            i += 1
            k += 1
        else:
            arr3[k] = arr2[j]
            j += 1
            k += 1

    while i < n1:
        arr3[k] = arr1[i]
        i += 1
        k += 1

    while j < n2:
        arr3[k] = arr2[j]
        j += 1
        k += 1

    return arr3


arr1 = [1, 5, 8, 9]
arr2 = [2, 3, 6, 7, 10, 11]
arr3 = merge(arr1, arr2, len(arr1), len(arr2))
print(arr3)


# OUTPUT 
# [1, 2, 3, 5, 6, 7, 8, 9, 10, 11]
