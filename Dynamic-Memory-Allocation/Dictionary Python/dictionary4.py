# Delete a list of keys from a dictionary.

dict1 = {'a': 1, 'b': 2, 'c': 3, 'd': 4}
keys = ['a', 'c']
for k in keys:
    dict1.pop(k)
print(dict1)

# OUTPUT
# {'b': 2, 'd': 4}
