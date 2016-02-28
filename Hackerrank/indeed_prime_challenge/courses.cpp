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
#define max_ele(x) *max_element(x.begin(), x.end())
class disjointSets
{
    vector<int> parent;
 public:
    disjointSets(int v)
    {
        for (int i = 0; i < v; i++)
            parent.push_back(i);
    }
    int findSet(int u)
    {
        return (parent[u] == u)? u : (parent[u] = findSet(parent[u]));
    }
    bool isSameSet(int u, int v)
    {
        return (findSet(u) == findSet(v))?1:0;
    }
    void unionSet(int u, int v)
    {
        parent[findSet(u)] = findSet(v);
    }
    int setCount()
    {
        set<int> uniqueParents;
        for (unsigned long long i = 0; i < parent.size(); i++)
            uniqueParents.insert(findSet(i));
        return uniqueParents.size();
    }
    int maxElements()
    {
        vi count(parent.size());
        FOR(i, 0, parent.size())
            count[parent[i]]++;
        return max_ele(count);
    }
};

class directedGraph
{
    int vertices;
    vector<bool> visited;
    vector<bool> onStack;
    bool hasCycle = false;
 public: 
    graph g;
    vi inDegree;
    vector<int> count;
    directedGraph(int n) : vertices(n)
    {
        g.resize(vertices);
        visited.resize(vertices, false);
        onStack.resize(vertices, false);
        inDegree.resize(vertices, 0);
    }
    void cycle()
    {
        for (int i = 0; i < vertices; i++)
            if (!visited[i])
                visit(i);
    }
    void visit(int i)
    {
        onStack[i] = true;
        visited[i] = true;
        for (auto j = g[i].begin(); j != g[i].end(); j++)
        {
            if (!visited[(*j).first])
            {   
                visit((*j).first);
            }
            else if (onStack[(*j).first])
            {
                hasCycle = true;
                return;
            }
        }
        onStack[i] = false;
    }

    bool detectCycle()
    {
        cycle();
        return hasCycle;
    }
    int topologicalSort()
    {
        int res = 0;
        visited.assign(vertices, 0);
        while (1)
        {
            bool flag = true, vis=true;
            vi change;
            FOR(i, 0, vertices)
            {
                if (visited[i])
                    continue;
                vis = false;
                if (!inDegree[i])
                {
                    change.push_back(i);
                    visited[i] = true;
                    flag = false;
                }
            }
            if (vis || flag)
                break;
            res++;
            iterate(i, change)
            {
                iterate(j, g[*i])
                    inDegree[(*j).first]--;
            }
        }
        return res;
    }
};
int main()
{
    int t, r, x, y, n;
    cin >> t;
    for (int T = 1; T <=t; T++)
    {
        cin >> n >> r;
        directedGraph graphObject(n);
        for (int i = 0; i < r; i++)
        {
            cin >> x >> y;
            graphObject.inDegree[x]++;
            graphObject.g[y].push_back(pair<int, int>(x, 1));
        }
        cout << "Case " << T << ": ";
        if (graphObject.detectCycle())
            cout << "Never Ends\n";
        else
        {
            cout << graphObject.topologicalSort() << " semester(s)"<< endl;
        }
    }
    return 0;
}

