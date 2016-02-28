#include <bits/stdc++.h>
using namespace std;
void bin_search(int sm, vector<int>& v)
{
	int low = 0, ans;
	int high = v.size() - 1;
	while (1)
	{
		if (high - low == 1)
		{
			ans = (abs(sm - v[high]) < abs(sm - v[low]))?v[high]:v[low];
			break;
		}
		int mid = (low + high) / 2;
		if (v[mid] == sm)
		{
			ans = sm;
			break;
		}
		else if (v[mid] > sm)
			high = mid;
		else
			low = mid;
	}
	cout << ans << "." << endl;
}
int main()
{
	int n, count = 1;
	while (cin >> n)
	{
		if (n == 0)
			break;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<int> v;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				v.push_back(a[i] + a[j]);
		sort(v.begin(), v.end());

		int m, sm;
		cin >> m;	
		cout << "Case " << count << ":\n";
		while (m--)
		{
			cin >> sm;
			cout << "Closest sum to " << sm << " is ";
			bin_search(sm, v);
		}
		count++;
	}
}
