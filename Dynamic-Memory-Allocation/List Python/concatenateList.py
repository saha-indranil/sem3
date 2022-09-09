# Concatenate two lists index-wise.

list1 = ["My ", "i", "Indranil "]
list2 = ["name", "s", "Saha"]

print("Original List1 is: "+str(list1))
print("Original List2 is: "+str(list2))

res = [i+j for i, j in zip(list1, list2)]
print("Concated List: "+str(res))

# OUTPUT
# Original List1 is : ['My ', 'i', 'Indranil ']
# Original List2 is : ['name', 's', 'Saha']
# Concated List: ['My name', 'is', 'Indranil Saha']
