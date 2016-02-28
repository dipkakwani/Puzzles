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

int n;
vector<vi> a (2, vi (n));

long long solve (vector<vb> marked, int col)
{
  if (col == n - 1)
  {
    if (a[0][n - 1] == '.' && !marked[0][n - 1])
      return 1;
    if (a[1][n - 1] == '.' && !marked[1][n - 1])
      return 1;
    return 0;
  }
  long long res1 = -1, res2 = -1;
  if (a[0][col] == '.')
  {
    marked[0][col] = 1;
    marked[1][col] = 1;
    marked[0][col + 1] = 1;
    res1 = solve (marked, col + 1);

    marked[0][col + 1] = 0;
  }
  if (a[1][col] == '.')
  {
    marked[1][col + 1] = 1;
  }
  
}
int main ()
{
  int t;
  cin >> t;
  FOR (T, 0, t)
  {
    int n;
    cin >> n;
    vector<vb> marked (2, vb (n));
    FOR (i, 0, 2)
      FOR (j, 0, n)
        cin >> a[i][j];
    
  }
  return 0;
}
