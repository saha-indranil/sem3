# Merge two Python dictionaries into one.

def merge(dict1, dict2):
    return (dict2.update(dict1))


dict1 = {'a': 1, 'b': 4}
dict2 = {'p': 3, 'q': 7}
merge(dict1, dict2)
print(dict2)

# OUTPUT
# {'p': 3, 'q': 7, 'a': 1, 'b': 4}
