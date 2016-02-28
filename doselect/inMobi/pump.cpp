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
  ull n, k;
  cin >> n >> k;
  ull sm = 0;
  vector<ll> a (n);
  FOR (i, 0, n)
  {
    cin >> a[i];
    sm += a[i];
  }
  if (k >= sm)
  {
    cout << -1 << endl;
    return 0;
  }
  int x = k / n, y = k % n;
  FOR (i, 0, n)
    a[i] -= x;
  int head = 0;
  FOR (i, 0, n)
  {
    if (a[i] <= 0)
      a[(i + 1) % n] += a[i];
  }
  int j = 0;
  for (int i = 0; i < n && j < y; i++)
  {
    if (a[i] > 0)
    {
      a[i]--;
      j++;
    }
    head++;
  }
  vi res;
  FOR (i, 0, n)
  {
    if (a[head] > 0) 
      res.push_back (head + 1);
    head = (head + 1) % n;
  }
  iterate (i, res)
    cout << (*i) << " ";
  cout << endl;
  return 0;
}
