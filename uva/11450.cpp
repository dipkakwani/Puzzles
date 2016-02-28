#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< vector<bool> > vvb;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m, c, k;
		cin >> m >> c;
		vvi items;
		for (int i = 0; i < c; i++)
		{
			cin >> k;
			vi temp(k);
			for (int j = 0; j < k; j++)
				cin >> temp[j];
			items.push_back(temp);
		}
		vvb dp(201, vector<bool>(20));
		for (int i = 0; i < items[0].size(); i++) 
			if ((m - items[0][i]) >= 0)
				dp[m - items[0][i]][0] = 1;
		for (int j = 1; j < c; j++)
		{
			for (int i = 1; i <= m; i++)
			{
				if (dp[i][j - 1])
				{
					for (int k = 0; k < items[j].size(); k++)
					{
						if ((i - items[j][k]) >= 0)
						{
							dp[i -items[j][k]][j] = 1;
						}
					}
				}
			}
		}
		bool flag = 1;
		for (int i = 0; i <= m; i++)
		{
			if (dp[i][c - 1])
			{
				cout << m - i << endl;
				flag = 0;
				break;
			}
		}
		if (flag)
			cout << "no solution\n";
	}
	return 0;
}
