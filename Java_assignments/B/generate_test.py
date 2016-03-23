import random
import string
print 5
for _ in range(5):
    print 100000
    for _ in range(100000):
        print ''.join([random.choice(string.ascii_lowercase) for n in xrange(random.randint(1, 32))])
