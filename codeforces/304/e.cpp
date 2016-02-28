#include<iostream>
using namespace std;
#define MAX 5000001
long long numarr[MAX] = {0},parr[MAX] = {0};
int main()
{
	long long i, j;
	for(i = 2;i < MAX; i++)
	{
		if(numarr[i] == 0)
		{
			j = 2;
			long long y = i * j;
			while(y <= MAX)
			{
				numarr[y] = 1;
				parr[y]++;
				j++;
				y = i * j;
			}
		}
	}
	long long t;
	cin >> t;
	while (t--)
	{
		long long a, b;
		cin >> a >> b;
		long long res = 0;
		for (int i = b + 1; i <= a; i++)
		{
			res += parr[i];
			cout << parr[i] << endl;
		}
		cout << res << endl;
	}
}
