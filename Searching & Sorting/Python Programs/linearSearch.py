# Write a program to implement linear search.

def linearSearch(arr, key):
    for i in range(len(arr)):
        if arr[i] == key:
            return i
    return -1


arr = [3, 9, 2, 5, 4]
key = 5
idx = linearSearch(arr, key)
if idx == -1:
    print("Item Not Found")
else:
    print(str(key), "found at index:", str(idx))


# OUTPUT
# 5 found at index: 3
