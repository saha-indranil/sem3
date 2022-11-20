# Check if two sets have any elements in common. If yes, display the common elements.

set1 = {1, 2, 3, 4, 5, 6}
set2 = {2, 4, 6}
if set1.isdisjoint(set2):
    print("No elements in common")
else:
    set3 = set1.intersection(set2)
    print(set3)

# OUTPUT
# {2, 4, 6}
