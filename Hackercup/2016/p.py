def interval (a, p):
    res = 0
    for i in range (0, len (a)):
        s = 0
        for j in range (i, len (a)):
            s += a[j]
            if s <= p:
                res += 1
    return res

a = [12, 3, 52, 25, 9, 83, 45, 21, 33, 3]
t = input ()
for T in range (t):
    n, p = [int (x) for x in raw_input ().split (' ')]
    a = [int (x) for x in raw_input ().split (' ')]
    if T == 20:
        print interval (a, p)
