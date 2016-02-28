MOD = 1000000007
"""def stress_free(a, b):
	if (a, b) in d:
		return d[(a, b)] % MOD
	if b == 0:
		d[(a, b)] = 1
		return 1
	if a <= 1 or b <= 0:
		return 0
	if b < a - 1:
		d[(a, b)] = (stress_free(a - 1, b) % MOD + stress_free(a, b - 1) % MOD) % MOD
		return d[(a, b)] 
	d[(a, b)] = stress_free(a, b - 1) % MOD
	return d[(a, b)]
"""
def stress_free():
	d[2][0] = 1
	for j in range(2001):
		for i in range(j + 1, 2001):
			if j < i - 1:
				d[i][j] += d[i - 1][j] % MOD + d[i][j - 1] % MOD
			else:
				d[i][j] += d[i][j - 1] % MOD
def stress_full():
	d1[2][0] = 1
	d[2][1] = 1
	for i in range(2001):
		for j in range(i + 1, 2001):
			if j < i - 1:
				d1[i][j] += d1[i - 1][j] % MOD + d1[i][j - 1] % MOD
			else:
				d1[i][j] += d1[i - 1][j] % MOD

		
d = [[0 for j in range(2001)] for i in range(2001)]
d[1][0] = 1
d1 = [[0 for j in range(2001)] for i in range(2001)]
d1[1][0] = 1
stress_free()
stress_full()

t = input()
for u in range(t):
	a, b = [int(x) for x in raw_input().split('-')]
	
	print 'Case #' + str(u + 1) + ': ' + str(d[a][b] % MOD) + ' ' + str(d1[a][b] % MOD)

