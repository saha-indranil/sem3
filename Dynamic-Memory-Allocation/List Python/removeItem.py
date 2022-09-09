# Remove all ocurrences of a specific item from a list.

def remove_items(list1, item):
    res = [i for i in list1 if i != item]
    return res


if __name__ == "__main__":
    list1 = [1, 2, 5, 1, 1, 0, 7, 1]
    item = 1
    print("Original list is: "+str(list1))
    res = remove_items(list1, item)
    print("After Removing Elements: "+str(res))

# OUTPUT
# Original list is : [1, 2, 5, 1, 1, 0, 7, 1]
# After Removing Elements: [2, 5, 0, 7]
