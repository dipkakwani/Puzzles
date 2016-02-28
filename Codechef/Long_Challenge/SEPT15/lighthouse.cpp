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

bool comp_sw (const pair<ll, ll>& a, const pair<ll, ll>& b)
{
  if (a.first <= b.first && a.second >= b.second)
    return true;
  return false;
}
int main ()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    ll x, y;
    cin >> n;
    vector<pair<ll, ll>> positions (n);
    FOR (i, 0, n)
    {
      cin >> x >> y;
      positions[i] = ii (x, y);
    }
    sort (positions.begin (), positions.end ());
    int sw, nw, se, ne;
    iterate (i, positions)
    {
      int sws = lower_bound (positions.begin (), positions.end (), *i, comp_sw) - positions.begin ();
      cout << sw << endl;
    }
  }
  return 0;
}

