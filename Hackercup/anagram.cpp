#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string a, b;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if (a == b)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
