# Copy specific elements from one tuple to a new tuple.

num = (1, 2, 3, 4, 5, 6, 7, 8, 9)
n = list(num)
o = []
for i in range(0, 9, 2):
    o.append(n[i])
odd = tuple(o)
print(odd)

# OUTPUT
# (1, 3, 5, 7, 9)
