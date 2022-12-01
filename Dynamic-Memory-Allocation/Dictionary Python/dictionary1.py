# Convert two lists into a dictionary.

l = ["blue", "red", "yellow"]
n = [3, 1, 6]
d = {l[i]: n[i] for i in range(len(l))}
print(d)

# OUTPUT
# {'blue': 3, 'red': 1, 'yellow': 6}
