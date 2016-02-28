import math
t = input()
for _ in range(t):
    a, b = [int(x) for x in raw_input().split(' ')]
    n = math.factorial(a) / math.factorial(b)
    res = 0
    i = 2
    """while n > 1:
        if n % i == 0:
            n /= i
            res += 1
        else:
            i += 1
            """
    print res
