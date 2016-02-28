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

/* Use greedy approach. Choose the node which has the largest minimum score
 * of all adjacent nodes. */
void bfs (graph& g, int n)
{

}
int main ()
{
  int n, a, b;
  cin >> n;
  vi score (n), min_neighbour (n);
  graph g (n);
  FOR (i, 0, n - 1)
  {
    cin >> a >> b;
    g[a - 1].push_back (ii (b - 1, 1));
    g[b - 1].push_back (ii (a - 1, 1));
  }  
  return 0;
}
