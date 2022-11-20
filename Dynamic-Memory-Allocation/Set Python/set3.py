# Remove items from the set at once.

set1 = {6, 4, 2, 7, 9}
print("Original Set:", set1)
rem = [2, 4, 8]
res = set1-set(rem)
print("Updated Set:", res)

# OUTPUT
# Original Set: {2, 4, 6, 7, 9}
# Updated Set: {9, 6, 7}
