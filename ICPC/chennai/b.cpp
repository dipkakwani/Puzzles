#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;
typedef long long ll;
typedef unsigned long long ull;

#define FOR(i, x, y) for (auto i = x; i < y; i++)
#define TESTCASE(T) cout << "Case #" << T << ": "
#define print(x) cout << x << endl
#define iterate(i, x) for (auto i = x.begin(); i != x.end(); i++)
#define max_ele(x) max_element(x.begin(), x.end())


class disjointSets
{
    vi parent;
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
    int comp ()
    {
      set<int> par (parent.begin (), parent.end ());
      return par.size ();
    }
};
int main ()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, x, c = 0;
    cin >> n;
    vi dag (n);
    disjointSets d (n);
    vb visited (n);
    FOR (i, 0, n)
    {
      cin >> x;
      dag[i] = x;
      if (x == -1)
        c++;
      else
        d.unionSet (i, dag[i]);
    }
    //int comp = 0;
    /*for (int i = n - 1; i >= 0; i--)
    {
      if (!visited[i])
      {
        comp++;
        dfs (dag, i, visited);
      }
    }
    */
    int comp = d.comp ();
    c--;
    double res = 0.0;
    res = (2.0 * comp - c) / 2.0;
    printf ("%.6f\n", res);
  } 
  return 0;
}

