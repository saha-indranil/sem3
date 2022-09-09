# Turn every item of a list into its square

numbers = []
n = int(input("Enter number of elements in list: "))
for i in range(0, n):
    ele = int(input("Enter Numbers["+str(i)+"]: "))
    numbers.append(ele)

sqnums = [number**2 for number in numbers]
print("Squared Number List: "+str(sqnums))

# OUTPUT
# Enter number of elements in list: 4
# Enter Numbers[0]: -5
# Enter Numbers[1]: 2
# Enter Numbers[2]: 0
# Enter Numbers[3]: 6
# Squared Number List: [25, 4, 0, 36]
