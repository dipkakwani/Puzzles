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

int w[200001];
class disjointSets
{
public:
    vi parent;
    vi weight;
    int mn;
    int mn_par;
    disjointSets(int v)
    {
      for (int i = 0; i < v; i++)
      {
        parent.push_back (i);
        weight.push_back (0);
      }
      mn = INT_MAX;
      mn_par = -1;
      FOR (i, 0, v)
      {
        weight[i] = w[i];
        if (mn > w[i])
        {
          mn = w[i];
          mn_par = i;
        }
      }

    }
    int findSet (int u)
    {
      return (parent[u] == u)? u : (parent[u] = findSet(parent[u]));
    }
    bool isSameSet (int u, int v)
    {
      return (findSet (u) == findSet (v))?1:0;
    }
    void unionSet (int u, int v)
    {
      parent[findSet (u)] = findSet (v);
      findWeight (u);
      findWeight (v);
      if (mn > weight[u])
        mn = weight[u];
    }
    int findWeight (int u)
    {
      if (parent[u] == u)
      {
        return weight[u];
      }
      else
      {
        weight[u] += findWeight (parent[u]);
        return weight[u];
      }
    }
};
int main ()
{
  int n, q, a, b;
  cin >> n >> q;
  FOR (i, 0, n)
    cin >> w[i];
  disjointSets d (n);
  FOR (i, 0, q)
  {
    cin >> a >> b;   
    d.unionSet (a - 1, b - 1);
    cout << d .mn << endl;
  }
  return 0;
}

