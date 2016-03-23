import random
print 10
for i in range(10):
    print 100000
    for j in range(100000):
        a = random.randint(0, 999999)
        b = random.randint(a + 1, 1000000)
        assert a < b
        print a, b
