# Add new item to list after a specified item

list1 = []
n = int(input("Enter number of elements in list: "))
for i in range(0, n):
    ele = int(input("Enter Numbers["+str(i)+"]: "))
    list1.append(ele)
print(list1)

key = int(input("Enter Specified item: "))

flag = 0
for i in range(0, n):
    if list1[i] == key:
        val = int(input("Enter value to insert: "))
        list1.insert(i+1, val)
        flag = 1
        break

if flag == 0:
    print("Specified item not found!")
else:
    print("New list is: "+str(list1))


# OUTPUT 1
# Enter number of elements in list: 4
# Enter Numbers[0]: 1
# Enter Numbers[1]: 2
# Enter Numbers[2]: 3
# Enter Numbers[3]: 4
# [1, 2, 3, 4]
# Enter Specified item: 2
# Enter value to insert: 10
# New list is: [1, 2, 10, 3, 4]

# OUTPUT 2
# Enter number of elements in list: 3
# Enter Numbers[0]: 1
# Enter Numbers[1]: 2
# Enter Numbers[2]: 3
# [1, 2, 3]
# Enter Specified item: 6
# Specified item not found!
