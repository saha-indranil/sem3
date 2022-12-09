# 5. Write a python program to find the maximum element
# in a 2D-array using dynamic memory allocation.

matrix = [[1, 2, 3], [7, 8, 9], [4, 5, 6]]
max = matrix[0][0]
for i in range(len(matrix)):
    for j in range(len(matrix[i])):
        if(matrix[i][j] > max):
            max = matrix[i][j]
print("Maximum Element:", max)

# OUTPUT
# Maximum Element: 9
