#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;
typedef long long ll;
typedef unsigned long long ull;

#define FOR(i, x, y) for(auto i = x; i < y; i++)
#define TESTCASE(T) cout << "Case #" << T << ": "
#define print(x) cout << x << endl
#define iterate(i, x) for (auto i = x.begin(); i != x.end(); i++)
#define max_ele(x) max_element(x.begin(), x.end())

vector<string> res (20);
void prnt (vii& tree, int node)
{
  if (tree[node].first != -1)
    prnt (tree, tree[node].first);
   if (tree[node].second != -1)
    prnt (tree, tree[node].first); 
}

int main()
{
  int root;
  int n, a, b;
  cin >> n;
  vii tree (n);
  FOR (i, 0, n)
  {
    cin >> a >> b;
    if (a == -1 && b == -1)
      root = i;
    else
    {
      if (b)
        tree[a].second = i;
      else
        tree[a].first = i;
    }
  }
  prnt (tree, root);
  return 0;
}

