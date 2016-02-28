n = input ()
lst = []
groups = 1
for _ in range (n):
    x = raw_input ()
    lst.append (x)
for i in range (0, n):
    if i != n - 1:
        if lst[i][1] == lst[i + 1][0]:
            groups += 1
print groups
