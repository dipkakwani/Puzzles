def sel_sort (a, b, count):
    idx1 = 0
    idx2 = 0
    l = len (b)
    for i in range (count):
        if i & 1: #sort nums
            mn = b[idx1]
            mn_idx = idx1
            for j in range (idx1 + 1, l):
                if mn > b[j]:
                    mn = b[j]
                    mn_idx = j
            b[idx1], b[mn_idx] = b[mn_idx], b[idx1]
            idx1 += 1
        else:
            mn = a[idx2]
            mn_idx = idx2
            for j in range (idx2 + 1, l):
                if mn > a[j]:
                    mn = a[j]
                    mn_idx = j
            a[idx1], a[mn_idx] = a[mn_idx], a[idx1]
            idx2 += 1

n = int (input ())
for _ in range (n):
    s = input ()
    s = s.split (' ')
    a = []
    b = []
    for i in range (len(s)):
        if i & 1:
           b.append (int (s[i]))
        else:
           a.append (s[i].lower ())

    count = int (input ())
    idx1 = 0
    idx2 = 0
    sel_sort (a, b, count)
    res = []
    for i in range(len (s)):
        if i & 1:
            res.append (b[idx1])
            idx1 += 1
        else:
            res.append (a[idx1])
            idx2 += 1
    print (*res)
