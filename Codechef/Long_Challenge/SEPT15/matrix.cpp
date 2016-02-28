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

int main ()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vi> mat (n, vi (n));
    vector<ii> inverted_mat (n * n + 1);
    ll res = 0;

    FOR (i, 0, n)
    {
      FOR (j, 0, n)
      {
        cin >> mat[i][j];
        inverted_mat[mat[i][j]] = ii (i, j);
      }
    }
    FOR (i, 1, (n * n + 1))
    {
      res += (abs (inverted_mat[i].first - inverted_mat[i - 1].first) +
              abs (inverted_mat[i].second - inverted_mat[i - 1].second));
    }
    print (res);
  }
  return 0;
}
