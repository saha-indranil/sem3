# Reverse a list in Python.

list1 = []
n = int(input("Enter number of elements in list: "))
for i in range(0, n):
    ele = int(input("Enter Numbers["+str(i)+"]: "))
    list1.append(ele)

list2 = []
for i in list1:
    list2.insert(0, i)
print("Reversed List is: "+str(list2))

# OUTPUT
# Enter number of elements in list: 4
# Enter List[0]: 7
# Enter List[1]: 8
# Enter List[2]: 9
# Enter List[3]: 10
# Reversed List is: [10, 9, 8, 7]
