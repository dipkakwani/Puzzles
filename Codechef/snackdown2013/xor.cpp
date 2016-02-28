#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int occ[100001] = {0};
		int n, x, xo = 0;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			arr[i] = x;
			xo ^= x;
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (xo ^ arr[i] == 0)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}