#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;
#define FOR(i, x, y) for(auto i = x; i < y; i++)
#define TESTCASE(T) cout << "Case #" << T << ": "
#define print(x) cout << x << endl
#define iterate(i, x) for (auto i = x.begin(); i != x.end(); i++)
#define max_ele(x) max_element(x.begin(), x.end())

int n, m;

void dfs(graph& g, int n, vb& visited)
{
    visited[n] = true;
    iterate(i, g[n])
        if (!visited[(*i).first])
            dfs(g, (*i).first, visited);
}

bool dfsGraph(graph& g, set<int>& removed)
{
    vb visited(n);

    //Choose any vertex as the start vertex which is not present in removed.
    int vertex = -1;
    FOR (i, 0, n)
    {
        if (find(removed.begin(), removed.end(), i) == removed.end())
        {
            vertex = i;
            break;
        }
    }
    if (vertex == -1)
        return true;

    dfs(g, vertex, visited);
    FOR(i, 0, n)
        if (!visited[i] && find(removed.begin(), removed.end(), i) == removed.end())
            return false;
    return true;
}

int main()
{
    int t, x, y;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        graph g(n), temp(n);
        FOR(i, 0, m)
        {
            cin >> x >> y;
            g[x - 1].push_back(ii(y - 1, 1));
            g[y - 1].push_back(ii(x - 1, 1));
        }
        
        bool win = 1;
        int turns = 0;
        set<int> removed;
        vb visited(n);
        while (turns < n)
        {
            FOR(i, 0, n)
            {
                if (visited[i])
                    continue;
                temp = g;
                iterate(j, temp[i])
                    temp[(*j).first].erase(find(temp[(*j).first].begin(), temp[(*j).first].end(), ii(i, 1)));

                temp[i].clear();
                removed.insert(i);
                if (dfsGraph(temp, removed))
                {
                    g = temp;
                    turns++;
                    win = !win;
                    visited[i] = true;
                }
            }

        }
        if (win)
            cout << "Alex\n";
        else
            cout << "Artur\n";
    }
    return 0;
}
