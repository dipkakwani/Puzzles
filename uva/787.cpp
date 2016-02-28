#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> vl;
long long max_subarray_product(vl& a)
{
	long long mx = a[0];
	int size = a.size();
	for (int i = 0; i < size; i++)
	{
		long long p = 1;
		for (int j = i; j < size; j++)
			p *= a[j];
		if (p > mx)
			mx = p;
	}
	return mx;
}
int main()
{
	string str;
	while (getline(cin, str))
	{
		vl a;
		stringstream in(str);
		long long num;
		while (1)
		{
			in >> num;
			if (num == -999999)
				break;
			a.push_back(num);
		}
		cout << max_subarray_product(a) << endl;
	}
	return 0;
}
