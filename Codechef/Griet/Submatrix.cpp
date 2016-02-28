/*
A matrix of dimension mxn containing only 0's and 1's as it elements is given.Determine the maximum possible sub-square matrix containing only 1's as its elements
Input
Input description.
The first line of input contains an integer T,denoting the number of test cases
First line of each test case contains two space separated integers m,n denoting dimensions of matrix as mXn.
Next m lines contains n space separated integers(0's and 1's) .
Output
Output description.
For every test case , output the max possible sub-square matrix dimension.
Constraints
1 ≤ T ≤10^5
1 ≤ m,n ≤ 100
Example
Input:
3
3 3 
1 0 0
0 1 0
0 0 1
3 3
0 0 0
0 0 0
0 0 0
4 5
1 0 0 0 0
1 0 1 1 0
0 1 1 1 1
0 1 0 0 0
Output:
1
0
2
*/
#include <bits/stdc++.h>
using namespace std;
inline int min(int a, int b, int c)
{
	return ((a < b)? ((a < c)? a : c) : ((b < c)? b : c));
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a[100][100], b[100][100];
		int m, n, i, j;
		bool flag = true;
		cin >> m >> n;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				cin >> a[i][j];
				if (a[i][j])
					flag = 0;
			}
		}
		if (flag)
		{
			cout << 0 << endl;
			continue;
		}
		for (i = 0; i < n; i++)
			b[0][i] = a[0][i];
		for (i = 0; i < m; i++)
			b[i][0] = a[i][0];
		for (i = 1; i < m; i++)
		{
			for (j = 1; j < n; j++)
			{
				if (a[i][j])
					b[i][j] = min(a[i - 1][j], a[i][j - 1], a[i - 1][j - 1]) + 1;
				else
					b[i][j] = 0;
			}
		}
		int maxi = 0;
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				if (b[i][j] > maxi)
					maxi = b[i][j];
		cout << maxi << endl;

	}
	return 0;
}
