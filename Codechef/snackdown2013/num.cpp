#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			a[i] = x;
		}
		sort(a.begin(), a.end());
		int count[100001][100001];
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (j < n - 1 && a[j + 1] - 1 == a[j])
					count[i][j]++, j++;
				if (j && a[j - 1] + 1 == a[j])
					count[i][j]++;
			}
		}
		int ans1 = n, ans2 = n, k1 = 0, k2 = 0;
		
		cout << ans2 << " " << ans1 << endl;
	}
	return 0;
}