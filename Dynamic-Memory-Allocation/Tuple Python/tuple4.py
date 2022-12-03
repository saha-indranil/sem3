# Counts the number of occurrences of item ‘x’ from a tuple.

t = (10, 20, 10, 30, 40, 50, 20, 10, 10, 30, 30)
n = len(t)
count = 0
c = int(input("Enter the number to be checked: "))
for i in range(n):
    if(t[i] == c):
        count += 1
print("Frequency: "+str(count))

# OUTPUT
# Enter the number to be checked: 10
# Frequency: 4
