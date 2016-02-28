#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001
ll prime_divisors[MAX] = {0};
void sieve()
{
	for (ll i = 2; i < MAX; i++)
	{
		if (!prime_divisors[i])
		{
			for (ll j = 1; j * i < MAX; j++)
				prime_divisors[j * i] += 1;

		}
	}
}
int main()
{
	sieve();
	int memo[MAX][11] = {0};
	for(int i = 2; i < MAX; i++)
	{
		for(int j = 1; j <= 5; j++)
			memo[i][j] = memo[i-1][j];
		if(prime_divisors[i]==0)
			memo[i][1]++;
		else
			memo[i][prime_divisors[i]]++;
	}
	int t;
	cin >> t;
	while (t--)
	{
		ll a, b, k, p, res = 0;
		cin >> a >> b >> k;
		cout << memo[b][k] - memo[a - 1][k] << endl;
	}
	return 0;
}
