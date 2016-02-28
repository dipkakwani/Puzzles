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

void dfs (vi& gr, int i, vector<bool>& visited)
{
  visited[i] = true;
  if (!visited[gr[i]])
    dfs (gr, gr[i], visited);
}
int main ()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, a;
    cin >> n;
    vi gr (n);
    FOR (i, 0, n)
    {
      cin >> a;
      gr[i] = a - 1;
    }
    vector<bool> visited (n);
    int count = 0;
    FOR (i, 0, n)
    {
      if (!visited[i])
      {
        count++;
        dfs (gr, i, visited);
      }
    }
    cout << count - 1 << endl;
  }
  return 0;
}

