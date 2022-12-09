# 4. Write a python program to search an element in a
# 2D-Array using dynamic memory allocation.

def search(arr, target):
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if(arr[i][j] == target):
                return [i, j]
    return [-1, -1]


matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
target = 7
ans = search(matrix, target)
print(f"Element found at index: [{ans[0]} {ans[1]}]")


# OUTPUT
# Element found at index: [2 0]
