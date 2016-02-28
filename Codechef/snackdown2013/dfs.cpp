#include<bits/stdc++.h>
using namespace std;

int n, s1, s2, e1, e2, b1, b2;

int solve()
{
	if (e1 == s1 && b1 == s1 && ((b2 > s2 && b2 < e2) || (b2 > e2 && b2 < s2)))
		return abs(e1 - s1) + abs(e2 - s2) + 2;
	if (e2 == s2 && b2 == s2 && ((b1 > s1 && b1 < e1) || (b1 > e1 && b1 < s1)))
		return abs(e1 - s1) + abs(e2 - s2) + 2;
	return abs(e1 - s1) + abs(e2 - s2);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> s1 >> s2 >> e1 >> e2 >> b1 >> b2;
		cout << solve() << endl;
	}
}
