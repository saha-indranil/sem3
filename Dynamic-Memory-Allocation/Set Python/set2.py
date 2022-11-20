# Get Only unique items from two sets.

set1 = {1, 3, 7}
set2 = {3, 5, 8}
diff = set1.difference(set2)
diff2 = set2.difference(set1)
diff.update(diff2)
print(diff)

# OUTPUT
# {8, 1, 5, 7}
