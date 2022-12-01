# Create a dictionary by extracting the keys from a given dictionary.

dict1 = {'a': 1, 'b': 2, 'c': 3, 'd': 4}
keys = ['a', 'c']
dict2 = {k: dict1[k] for k in keys}
print(dict2)

# OUTPUT
# {'a': 1, 'c': 3}
