#include <bits/stdc++.h>
using namespace std;
bool has_sum(int mat[20][3], int gp, int gc, int gf, int start, int n)
{
	if (gp == 0 && gc == 0 && gf == 0)
		return true;
	if (start >= n || gp < 0 || gc < 0 || gf < 0)
		return false;
	return has_sum(mat, gp, gc, gf, start + 1, n) || 
		has_sum(mat, gp - mat[start][0], gc - mat[start][1], gf - mat[start][2], start + 1, n);
}
int main()
{
	int t, u;
	cin >> t;
	for (u = 1; u <= t; u++)
	{
		int gp, gc, gf, n, i, j;
		int mat[20][3];
		cin >> gp >> gc >> gf;
		cin >> n;
		for (i = 0; i < n; i++)
			for (j = 0; j < 3; j++)
				cin >> mat[i][j];
		cout << "Case #" << u << ": ";
		if (has_sum(mat, gp, gc, gf, 0, n))
			cout << "yes\n";
		else
			cout << "no\n";
	}
}
