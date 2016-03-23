import random
print 100
for _ in range(100):
    V = random.randint(1, 10000)
    E = random.randint(1, 10000)
    print V, E
    for i in range(E):
        print random.randint(1, V), random.randint(1, V)
