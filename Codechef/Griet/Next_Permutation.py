"""
An array of n integers(0 to 9) is given printing array elements gives an number.You have to find a number that is formed with the elements that are in array which is next higher number than number formed in given order.if there is no such number just print 'NO NXTBIG' without quotes.
Input

Input description.
First line of input contains an integer T denoting number of test cases
First line of each test case contains an integer n denoting number of elements in array
next line contains n space separated integers(0 to 9)
Output

Output description.
For each test case the output contains two lines in which first line contains the number formed by placing the digits in input order and the next line contains the next big number formed from the given digits
Constraints

1 ≤ T,n ≤ 105
0 ≤ array element ≤ 9
 
Example

Input:
4
6
7 6 9 3 1 2
5
1 0 7 6 2
11
2 3 5 1 2 3 8 7 5 5 4
5
5 4 3 2 1
Output:
769312
769321
10762
12067
23512387554
23512435578
54321
NO NXTBIG

Solution:

Scan the list from right to left, the first element which is greater than its left element gives the index of the 'pivot'.
List[pivot] < List[pivot + 1]


"""
import math
t = input()
for _ in range(t):
	n = input()
	a = []
	s = raw_input()
	for x in s.split(' '):
		a.append(x)
	pos = 0
	length = len(a)
	for i in range(length - 1, 0, -1):
		if a[i] > a[i - 1]:
			pos = i
			break
	print ''.join(a)
	if pos == 0 or a == ('0' * length):
		print 'NO NXTBIG'
		continue
	smallest_pos = pos
	maxi = a[pos]
	for i in range(length - 1, pos - 1, -1):
		if a[i] > a[pos - 1] and a[i] < maxi:
			smallest_pos, maxi = i, a[i]
	a[pos - 1], a[smallest_pos] = a[smallest_pos], a[pos - 1]
	a[pos:] = a[pos:][::-1]
	print ''.join(a)
