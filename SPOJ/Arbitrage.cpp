#include <bits/stdc++.h>
using namespace std;
void floyd(vector<vector<double>>& graph, int n)
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				graph[i][j] = max(graph[i][j], graph[i][k] * graph[k][j]);
}
int main() {
	for (int T = 1; ; T++)
	{
		map<string, int> vertex;
		int n, m;
		string x;
		cin >> n;
		if (!n)
			break;
		vector<vector<double>> graph(n, vector<double>(n, 0.0));
		
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			vertex[x] = i;
		}
		cin >> m;
		string to, from;
		double weight;
		while (m--)
		{
			cin >> from >> weight >> to;
			graph[vertex[from]][vertex[to]] = weight;
		}
			
		floyd(graph, n);
	
		cout << "Case " << T << ": ";
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			if (graph[i][i] > 1.0)
			{
				cout << "Yes\n";
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "No\n";
	}
	return 0;
}