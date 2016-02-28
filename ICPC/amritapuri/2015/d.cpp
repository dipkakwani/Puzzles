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
  int n;
  ull su = 0;
  cin >> n;
  vi a (n);
  vector<ull> sm (n), l_sm (n);
  FOR (i, 0, n)
  {
    cin >> a[i];
    su += a[i];
  }
  sort (a.begin (), a.end ());
  l_sm[0] = a[0];
  FOR (i, 1, n)
  {
    l_sm[i] = l_sm[i - 1] + a[i];
  }
  int q, k;
  cin >> q;
  while (q--)
  {
    cin >> k;
    int b = n, res = 0, j = 0;
    if (k == 0)
    {
      cout << su << endl;
      continue;
    }
    else
      cout << l_sm[ceil ((n + 0.0) / (k + 1)) - 1] << endl;
  }
  return 0;
}

