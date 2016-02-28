#include<iostream>
using namespace std;
#define MAX 100001
int numarr[MAX],parr[MAX],check[MAX][10];
int main()
{
	int test,a,b,k,ans;
	int i,j;
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
	for(i = 2; i < MAX; i++)
	{
		for(j = 1; j <= 5; j++)
			check[i][j]=check[i-1][j];
		if(parr[i] == 0)
			check[i][1]++;
		else
			check[i][parr[i]]++;
	}
	cin >> test;
	while(test--)
	{
		cin >> a >> b >> k;
		cout << check[b][k]-check[a-1][k] << endl;
	}
	return 0;
} 

