# Check if all items in the tuple are the same.

n = (1, 1, 1, 1)
c = n[0]
flag = 1
for i in range(4):
    if(c != n[i]):
        flag = 0
if(flag == 0):
    print("All values are not same")
else:
    print("All values are same")

# OUTPUT
# All values are same
