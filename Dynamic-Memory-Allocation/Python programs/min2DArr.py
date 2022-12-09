# 6. Write a python program to find the minimum element
# in a 2D-array using dynamic memory allocation.

matrix = [[7, 8, 9], [1, 2, 3], [4, 5, 6]]
min = matrix[0][0]
for i in range(len(matrix)):
    for j in range(len(matrix[i])):
        if(matrix[i][j] < min):
            min = matrix[i][j]
print("Minimum Element:", min)

# OUTPUT
# Minimum Element: 1
