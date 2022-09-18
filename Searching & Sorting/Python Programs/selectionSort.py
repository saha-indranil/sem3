# Write a program to implement Selection Sort.

def selectionSort(arr):
    size = len(arr)
    for i in range(size-1):
        smallest = i
        for j in range(i + 1, size):
            if arr[j] < arr[smallest]:
                smallest = j
        (arr[i], arr[smallest]) = (arr[smallest], arr[i])


arr = [6, 2, 5, 7, 1, 4, 3]
selectionSort(arr)
print("Sorted Array is:")
print(arr)


# OUTPUT
# Sorted Array is:
# [1, 2, 3, 4, 5, 6, 7]
