res = 0
while 1:
    v = [int (x) for x in raw_input ().split ('x')]
    m = min (v[0] * v[1], v[1] * v[2], v[0] * v[2])
    res += m + 2 * v[0] * v[1] + 2 * v[1] * v[2] + 2 * v[0] * v[2]
    print res

