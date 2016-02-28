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
  int n, od = 0, ev = 0;
  cin >> n;
  vi a (n);
  FOR (i, 0, n)
  {
    cin >> a[i];
    if (a[i] & 1)
      od++;
    else
      ev++;
  }
  if (ev > od)
    cout << "READY FOR BATTLE\n";
  else
    cout << "NOT READY\n";
  return 0;
}

