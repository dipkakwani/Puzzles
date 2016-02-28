#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector< pii > vpii;
typedef vector< vpii > g;
#define FOR(i, x, y) for(auto i = x; i < y; i++)
#define TESTCASE(T) cout << "Case #" << T << ": ";
#define print(x) cout << x << endl;
#define iterate(i, x) for (auto i = x.begin(); i != x.end(); i++)
#define max_ele(x) max_element(x.begin(), x.end())
#define MAX 10000000
vector<int> dijkstra(g& graph, vi& special)
{
	int v = graph.size();

	set<pii> Q;
	vector<int> distance(v);
	for (int i = 0; i < v; i++)
		distance[i] = MAX;	//MAX weight
	iterate(i, special)
    {
        distance[*i - 1] = 0;
    }
    FOR(i, 0, v)
        Q.insert(pii(distance[i], i));
	
	while (!Q.empty())
	{
		pii temp = *Q.begin();
		Q.erase(Q.begin());
		int dist = temp.first;
		int curVertex = temp.second;
		for (auto i = graph[curVertex].begin(); i != graph[curVertex].end(); i++)
		{
			int vertex = (*i).first;
			int weight = (*i).second;
			if (distance[vertex] > dist + weight)		//Relax edge
			{
				if (distance[vertex] != MAX)
					Q.erase(Q.find(pii(distance[vertex], vertex)));
				distance[vertex] = dist + weight;
				Q.insert(pii(distance[vertex], vertex));
			}
		}
	}
	return distance;
}
int main()
{
   	int v, e;
	cin >> v >> e;
	g graph(v);
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a - 1].push_back(pair<int, int>(b - 1, c));
		graph[b - 1].push_back(pair<int, int>(a - 1, c));
	}
    int s, x;
    vector<int> svertices;
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        cin >> x;
        svertices.push_back(x);
    }
    /*
    for (int i = 0; i < v; i++)
    {
        vector<int> dist = dijkstra(graph, i);
        int mn = 99999999;
        for (int j = 0; j < svertices.size(); j++)
        {
            if (mn > dist[svertices[j] - 1])
                mn = dist[svertices[j] - 1];
        }
        cout << mn << endl;
    }
    */
    vi res = dijkstra(graph, svertices);
    iterate(i, res)
        cout << *i << endl;
    return 0;
}
