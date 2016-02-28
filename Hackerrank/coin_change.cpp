#include<bits/stdc++.h>
using namespace std;
unsigned long long coins(int n, vector<int>& a)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	unsigned long long res = 0;
	for (int i = 0; i < a.size(); i++)
		res += coins(n - a[i], a);
	return res;
}
int main()
{
	int m, n;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; i++)
		cin >> a[i];
	cout << coins(n, a);
}
